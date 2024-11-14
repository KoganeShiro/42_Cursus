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

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdbool.h>

# define ERROR_MSG "You should execute it like that:\n\t \
`./pipex infile 'cmd1' 'cmd2' outfile`\n\n"

typedef struct s_pipex
{
	int		infile_fd;
	bool	infile_error;
	int		outfile_fd;
	char	**all_paths;
	char	**cmd_args1;
	char	**cmd_args2;
	char	*cmd_path;
	char	*cmd2_path;
	char	*tmp_path;
	char	*tmp_path2;
	bool	cmd_is_path;
	bool	cmd2_is_path;
}	t_pipex;

/* MAIN */
int		main(int argc, char **argv, char **envp);
void	ft_cleanup(t_pipex *pipex);
void	free_tab(char **tab);
char	*ft_strdup_modif(char *str);

/* PIPEX */
void	get_path(t_pipex *pipe, char **envp);
void	exec_cmd(t_pipex *pipex, char **envp);
void	exec_cmd1(t_pipex *pipex, char **envp, int fd[2]);
void	exec_cmd2(t_pipex *pipex, char **envp, int fd[2]);
void	ft_bzero(void *s, size_t n);

/* ERROR_HANDLING */
void	check_args(char **argv, t_pipex *pipex);
void	check_cmd1(t_pipex *pipex, char **argv);
void	check_cmd2(t_pipex *pipex, char **argv);
void	is_cmd_exist(t_pipex *pipex);
void	is_cmd2_exist(t_pipex *pipex);

/* UTILS */
int		ft_strncmp(char *s1, char *s2, int n);
void	*ft_calloc(int str_len, int size);
int		ft_strlen(char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s, char *add); //join with '/' between

/* SPLIT */
char	*ft_strdup(char *str);
int		count_word(char const *s, const char c);
char	*next_word(const char *str, int start, int end);
void	fill_result(char **result, const char *s, const char *sep);
char	**ft_split(char const *s, const char *sep);

#endif
