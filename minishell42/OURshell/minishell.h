/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:08:38 by cejin             #+#    #+#             */
/*   Updated: 2024/06/23 14:30:22 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stddef.h>
# include <dirent.h>
# include <termios.h>

# define BUFFER_SIZE 1000

# define HEREDOC 44
# define APPEND 45
# define INREDIR 60
# define OUTREDIR 62
# define PIPE 124
# define WORD 42

//#define close(X) printf("CLOSE: %d\n", X); close(X)

/* COLORS */
# define RED		"\x1B[31m"
# define GREEN		"\x1B[32m"
# define YELLOW		"\x1B[33m"
# define BLUE		"\x1B[34m"
# define CYN		"\x1B[36m"
# define WHITE		"\x1B[37m"
# define RESET		"\x1B[0m"

/* EXIT_CODE */
# define SUCCESS		0
# define GEN_ERR		1 //impermissible operations
# define BUILTIN_KO		2 //permissions problem or a missing keyword
# define EXEC_KO		126 //no permission for exec
# define CMD_NOT_FOUND	127 //no path found
# define CTRL_C			130
# define CTRL_			131

typedef struct s_command	t_command;
typedef struct s_env		t_env;

extern int					g_sig;

/* -----parsing struct----- */
typedef struct s_command
{
	bool		has_in_redir;
	bool		first_node;
	char		*infile_name;
	int			in_fd;
	bool		infile_error;
	bool		is_heredoc;
	bool		was_heredoc;
	char		*heredoc;
	char		*limiter;
	int			limiter_flag;
//
	bool		has_out_redir;
	bool		append;
	bool		last_node;
	char		*outfile_name;
	int			out_fd;
	bool		outfile_error;
//
	char		**cmd_args;
	char		*cmd_path;
	bool		cmd_is_path;
	bool		ctrlc;
	t_command	*next;

}	t_command;

typedef struct s_input
{
	char	*str;
	int		nword_i;
	int		value_i;
	char	*nword;
	size_t	i;
	size_t	j;
	int		index;
	int		trigger;
	int		len;
	int		*tab;
	char	**lst;
}		t_input;

typedef struct s_env
{
	t_env	*next;
	char	*key;
	char	*value;
	char	*line;
}		t_env;

typedef struct s_shell
{
	char		*str;
	pid_t		pid;
	int			status;
	bool		end;
	int			exit_code;
	char		**tab_envp;
	char		**all_paths;
	int			nb_of_cmd;
	int			nb_of_node;
	int			heredoc_i;
	bool		create_node;
	bool		has_fork;
	t_command	*cmd;
	t_env		*env;
	t_input		*input;
}	t_shell;

/* MAIN.C */
void		_ft_wait(t_shell *shell);
void		_ft_input(t_shell *shell, t_input *input);
int			shell_loop(t_shell *shell, t_input *input);
int			main(int argc, char *argv[], char **envp);

/* SIGNAL.C*/
void		get_signal(int state);
void		check_exitcode(t_shell *shell);

/* IN ---PARSING--- FOLDER */
	/*ADD_VAR*/
//int			verif_special(char *str, t_shell *info);
int			add_line_var(t_input *input, t_env *env, int start);
int			add_var_line(int start, t_input *input, t_env *env, t_shell *shell);
int			ft_isalpha_num(int c);
int			remplace_special_and_char(t_input *input, char *value,
				char **nword, int i);

	/*INIT*/
int			init_shell(t_shell *shell);
void		init_cmd_bool(t_command *cmd);
void		init_command(t_command *new_cmd);
void		init_input(t_input *input);

	/*INPUT_CRATE*/
void		add_word(t_input *in, char *s);
void		add_quote(t_input *in, char *str);
void		add_unexpected(t_input *in, char *s);
void		add_unexpected_extra(t_input *in, char *s);
int			ft_split_input(char *s, t_input *in, t_shell *shell);

	/*INPUT_SIZE*/
void		count_arg(t_input *input, char *s);
int			count_quote(t_input *input, char *s, t_shell *info);
int			unexpected_token(char *str, t_input *input, t_shell *shell);
int			nb_of_words(char *str, t_input *input, t_shell *shell);

	/* PARSING */
void		remove_var(t_input *input, int start);
char		*is_this_a_quote(t_input *input, char quote, int *p,
				char *new_word);
void		remove_quote(t_input *input);
int			parsing(t_shell *shell, t_input *input);

	/*UTILS_ENV*/
t_env		*append_node(t_env **env, char *line);
t_env		*convert_envp(char **envp);

	/*VAR*/
int			add_int(int start, int len, char *word, t_input *input);
int			verif_env_valid(t_input *input, t_env *tmp_env, int *i);
int			compare_envp(t_input *input, t_shell *shell, char *str);
int			quote_is(t_input *input);
int			replace_envp(t_input *input, t_shell *shell);

	/*verif_command*/
int			verif_redirection(t_shell *shell, t_input *input, int *i);
int			verif_herdoc(t_shell *shell, t_input *input, int *i);
int			verif_pipe(t_shell *shell, t_input *input, int *i);
int			verif_command(t_input *input, t_shell *shell);

	/* CREATE CMD */
t_command	*init_first_node(t_shell *shell, t_input *input);
t_command	*init_node(t_shell *shell, int i);
void		_fill_linked_list(t_shell *shell, t_input *input);
int			create_command(t_shell *shell, t_input *input);
int			init_cmd(t_input *input, t_command *new_cmd, int i);

/*
 *
	IN ---BUILTINS--- FOLDER
*/

	/* BUILTINS */
int			is_builtins(t_command *cmd);
bool		handle_builtins(t_shell *shell, t_command *cmd);

	/* FT_ECHO */
int			ft_echo(int argc, char **argv, int newline);

	/* FT_ENV */
int			ft_env(t_shell *shell, t_command *cmd);

	/* FT_PWD */
int			ft_pwd(t_shell *shell, t_command *cmd, bool print);
void		replace_pwd(t_env *env, char *new_pwd, char *pwd);

	/* FT_CD */
int			ft_cd(t_shell *shell, t_command *cmd);

	/* FT_EXPORT */
int			ft_export(t_shell *shell, t_command	*cmd);
int			how_many_export(t_command *cmd);
int			check_key(char *arg, int i);
int			parse_key(t_shell *shell, t_command *cmd, int j);

	/* EXEC_EXPORT */
int			fill_key_value(t_shell *shell, t_command *cmd,
				char **key, char **value);
void		fill_value(t_shell *shell, char *arg,
				char *key, char **value);
void		_fill_value(t_shell *shell, char *key, char *value);

	/* FT_UNSET */
int			ft_unset(t_shell *shell, t_command *cmd, t_env *tmp);

	/* FT_EXIT */
void		ft_exit(t_shell *shell, t_command *cmd,
				bool builtin);

	/* BUILTINS_UTILS */
int			ft_tab_len(char **tab);
char		*find_strenv(t_env *env, char *key);
char		*return_value(char *key, t_env *env);
bool		is_key_existing(char *key, t_env *env);
void		create_node(t_shell *shell, char *key, char *value);

/*
*
	IN ---PIPEX--- FOLDER
*/

	/* CHECK_FILES */
// 			Will open files in order of apparition in the input
int			check_files(t_shell *shell, t_command *cmd, bool last);
int			_check_redir(t_shell *shell, t_command *cmd, int i);
int			_init_files(t_shell *shell, t_command *cmd,
				int redir, int i);

	/* OPEN_FILES */
int			check_infile(t_shell *shell, t_command *cmd);
int			check_outfile(t_shell *shell, t_command *cmd);

	/* HERE_DOC */
//		If the infile is a heredoc, it will open it
int			check_fd(int fd, char *file);
int			ft_here_doc(t_shell *shell, t_command *pipex);
void		exec_heredoc(t_shell *shell, t_command **cmd);
int			wrin_heredoc(t_command *pipex, char *line);

	/* PIPEX */
//		Start of the exec, loop through all the cmds
void		ft_exec(t_shell *shell, t_command *cmd);
void		_is_heredoc(t_command *cmd);
t_command	*ft_exec_cmd(t_shell *shell, t_command *cmd);
void		_cmd_is_path(t_shell *shell, t_command *p);

	/* REDIR */
//		Manage the redirection with dup2
void		ft_redirection(t_command *cmd, int fd[2]);
void		ft_last_redir(t_command *cmd);

	/* EXECVE */
//		Will execute the cmds or the builtins
void		_cmd_is_path(t_shell *shell, t_command *cmd);
void		ft_execve_loop(t_shell *shell, t_command *cmd);
void		ft_execve(t_shell *shell, t_command *cmd, int fd[2]);
void		ft_exec_one(t_shell *shell, t_command *cmd);

	/* CMD_UTILS */
int			list_size(t_env *envp);
char		**env_to_tab(t_env *envp);
int			get_path(t_shell *shell);
int			check_cmd(t_shell *shell, t_command	*pipex);

	/* GNL */
char		*find_next_line(char *buffer);
char		*extract_line(char *buffer);
char		*read_file(int fd, char *buffer);
char		*get_next_line(int fd);

/*
*
	IN ---UTILS--- FOLDER
*/

	/* FT_CLEANUP.C */
void		free_child(t_shell *shell, t_command *cmd);
void		ft_putstr_fd(int fd, char *s);
void		ft_cleanup(t_shell *shell, t_command *cmd, bool child);
int			ft_error(t_shell *shell, char *msg, int exit_code);

	/* FREE */
void		free_tab(char **tab);
void		free_env_node(t_env *env);
void		free_envp(t_env **env);
int			free_input(t_input *input);

	/* UTILS_PIPEX */
void		ft_bzero(void *s, size_t n);
int			ft_strncmp(char *s1, char *s2, int n);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
char		*pipex_join(char *s, char *add, char in_between);

	/* FT_SPLIT */
char		*ft_strdup(char *str);
char		*next_word(const char *str, int start, int end);
void		fill_result(char **result, const char *s, const char *sep);
char		**ft_split(char const *s, const char *sep);

	/* GNL UTILS */
char		*ft_strjoin_gnl(char *buffer, char *tmp);
int			ft_strchr_gnl(char *buffer, int new_line_ptr);
size_t		ft_strlen(char *buffer);
void		*ft_calloc(int str_len, int size);

	/* PARING UTILS*/
char		*created_word(const char *str, int start, int end);
int			test_quote(t_shell *shell, char c, t_input *input, int *value);
int			pass_quote(t_input *input, char *str);
int			ft_is_seperator(char c);

	/* PARING UTILS2*/
int			remplace_word(t_input *input, char *value, char **nword, int i);
int			no_name_condition(t_input *input, char *value, char **nword, int i);
char		*fill_input_key(t_input *input);
int			print_dellard(t_input *in);

	/* ITOA */
char		*ft_itoa(int n);

	/* UTILS */
bool		is_space(char c);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_atoi(char *n);

#endif
