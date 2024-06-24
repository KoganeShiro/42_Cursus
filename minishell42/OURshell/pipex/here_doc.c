/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 here_doc.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: cejin <marvin@42.fr>						+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/02/29 18:40:08 by cejin			   #+#	  #+#			  */
/*	 Updated: 2024/02/29 18:40:36 by cejin			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../minishell.h"

int	check_fd(int fd, char *file)
{
	if (fd < 0)
	{
		perror(file);
		return (GEN_ERR);
	}
	return (0);
}

int	ft_here_doc(t_shell *shell, t_command *pipex)
{
	char	*i;

	if (pipex->in_fd > 2)
	{
		if (pipex->was_heredoc == 1)
			_is_heredoc(pipex);
		close(pipex->in_fd);
	}
	if (pipex->limiter == NULL || pipex->limiter[0] == '\0')
	{
		pipex->limiter = ft_strdup("\n");
		pipex->limiter_flag = 1;
	}
	i = ft_itoa(shell->heredoc_i++);
	pipex->heredoc = pipex_join("/tmp/heredoc", i, '_');
	free(i);
	wrin_heredoc(pipex, NULL);
	check_exitcode(shell);
	pipex->was_heredoc = 1;
	if (shell->exit_code == CTRL_C)
		pipex->ctrlc = 1;
	pipex->in_fd = open(pipex->heredoc, O_RDONLY, 0644);
	check_fd(pipex->in_fd, "cmd->in_fd");
	return (SUCCESS);
}

static int	_condition(t_command *pipex, char *line)
{
	if (pipex->limiter_flag == 1)
	{
		if (ft_strlen(pipex->limiter) == ft_strlen(line)
			&& ft_strncmp(line, pipex->limiter, 1) == 0)
		{
			return (1);
		}
	}
	else
	{
		if (ft_strlen(pipex->limiter) + 1 == ft_strlen(line)
			&& ft_strncmp(line, pipex->limiter,
				ft_strlen(pipex->limiter)) == 0)
		{
			return (1);
		}
	}
	if (line == NULL)
		return (1);
	if (line[0] == '\0' && g_sig != SIGINT)
	{
		ft_putstr_fd(2, "\nWarning: heredoc delimited by EOF\n");
		return (1);
	}
	return (0);
}

int	wrin_heredoc(t_command *pipex, char *line)
{
	int	heredoc_fd;

	heredoc_fd = open(pipex->heredoc, O_CREAT
			| O_RDWR | O_TRUNC, 0644);
	check_fd(heredoc_fd, "heredoc");
	while (1)
	{
		get_signal(2);
		write(1, "heredoc☭> ", 12);
		line = get_next_line(STDIN_FILENO);
		if (_condition(pipex, line) == 1)
			break ;
		write(heredoc_fd, line, ft_strlen(line));
		free(line);
	}
	if (line)
		free(line);
	close(heredoc_fd);
	return (SUCCESS);
}
