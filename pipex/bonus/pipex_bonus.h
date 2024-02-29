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

# define ERROR_MSG "You should execute it like that:\n\t \
`./pipex infile 'cmd1' 'cmd2' outfile`\n\n"

# define BUFFER_SIZE 10

typedef struct s_pipex
{
	int		infile_fd;
	int		outfile_fd;
	int		pipe_fd;
	int		heredoc_fd;
	char	*delimiter;
	char	**all_paths;
	char	**cmd_args;
	char	*cmd_path;
	int		cmd;
	int		nb_of_cmd;
	int		is_first_cmd;
}	t_pipex;

/* MAIN */
int		main(int argc, char **argv, char **envp);
void	ft_cleanup(t_pipex *pipex);
void	free_tab(char **tab);

/* HERE_DOC */
void	ft_here_doc(t_pipex *pipex, int argc, char **argv);

/* PIPEX */
void	ft_exec_first(t_pipex *pipex, char **argv, char **envp);
void	ft_execve_first(t_pipex *pipex, char **envp, int fd[2]);

void	ft_execve(t_pipex *pipex, char **envp, int fd[2]);
void	ft_execve_last(t_pipex *pipex, char **argv, char **envp);

/* ERROR_HANDLING */
void	check_args(int argc, char **argv, t_pipex *pipex);
void	get_path(t_pipex *pipex, char **envp);
void	ft_exec(t_pipex *pipex, char **argv, char **envp);
void	ft_exec_cmd(t_pipex *pipex, char **argv, char **envp);

/* UTILS */
void	ft_bzero(void *s, size_t n);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s, char *add);

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
char	*get_next_line(int fd);

char	*ft_strjoin_gnl(char *buffer, char *tmp);
int		ft_strchr_gnl(char *buffer, int new_line_ptr);
int		ft_strlen(char *buffer);
void	*ft_calloc(int str_len, int size);

#endif
