/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 pipex.h											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: cejin <marvin@42.fr>						+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/02/15 17:48:03 by cejin			   #+#	  #+#			  */
/*	 Updated: 2024/02/26 11:42:57 by cejin			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdbool.h>

# define ERROR_MSG "You should execute it like that:\n\t\
./pipex_bonus infile 'cmd1' 'cmd2' ... outfile\n\
or\n\t./pipex_bonus here_doc LIMITER 'cmd1' 'cmd2' ... outfile\n\n"

# define BUFFER_SIZE 1000

typedef struct s_pipex
{
	int		in_fd;
	bool	infile_error;
	int		outfile_fd;
	char	*limiter;
	int		limiter_flag;
	char	**all_paths;
	char	**cmd_args;
	char	*cmd_path;
	int		cmd_count;
	int		nb_of_cmd;
	bool	cmd_is_path;
	bool	first_cmd;
	pid_t	pid;
}	t_pipex;

/* MAIN */
int		main(int argc, char **argv, char **envp);
void	launch_heredoc(t_pipex *pipex, int argc, char **argv, char **envp);

/* HERE_DOC */
void	exec_heredoc(t_pipex *pipex, char **argv, char **envp);
void	_exec_(t_pipex *pipex, char **envp);
void	_execve_(t_pipex *pipex, char **envp, int fd[2]);
void	wrin_heredoc(t_pipex *pipex, char *line);

/* ERROR_HANDLING */
void	check_args(int argc, char **argv, t_pipex *pipex);
void	ft_here_doc(t_pipex *pipex, int argc, char **argv);
void	get_path(t_pipex *pipex, char **argv, char **envp);
void	check_cmd(t_pipex *p, char **argv);

/* PIPEX */
void	ft_exec(t_pipex *pipex, char **argv, char **envp);
int		check_infile(t_pipex *pipex, int fd[2]);
void	ft_exec_cmd(t_pipex *pipex, char **argv, char **envp);
void	_cmd_is_path(t_pipex *pipex, char **envp);

/* EXECVE */
void	exec_one_cmd(t_pipex *pipex, char **argv, char **envp);
void	execve_one_cmd(t_pipex *pipex, char **envp);
void	ft_execve(t_pipex *pipex, char **envp, int fd[2]);
void	ft_execve_last(t_pipex *pipex, char **envp);

/* FREE */
void	ft_cleanup(t_pipex *pipex);
void	free_tab(char **tab);
void	ft_putstr_fd(char *s, int fd);
void	error_free(t_pipex *pipex, char	*msg);
/* UTILS */
void	ft_bzero(void *s, size_t n);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s, char *add);
char	*_m_strdup(char *str);

/* SPLIT */
char	*ft_strdup(char *str);
int		count_word(char const *s, const char c);
char	*next_word(const char *str, int start, int end);
void	fill_result(char **result, const char *s, const char *sep);
char	**ft_split(char const *s, const char *sep);

/* GNL */
char	*find_next_line(char *buffer);
char	*extract_line(char *buffer);
char	*read_file(int fd, char *buffer);
char	*get_next_line(int fd, t_pipex *pipex);
char	*_condition_(t_pipex *pipex, char *buffer, char *line);

/* GNL UTILS */
char	*ft_strjoin_gnl(char *buffer, char *tmp);
int		ft_strchr_gnl(char *buffer, int new_line_ptr);
int		ft_strlen(char *buffer);
void	*ft_calloc(int str_len, int size);

#endif
