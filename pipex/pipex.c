/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 pipex.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: cejin <marvin@42.fr>						+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/02/15 17:47:55 by cejin			   #+#	  #+#			  */
/*	 Updated: 2024/02/26 11:52:16 by cejin			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(t_pipex *pipex, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		exec_cmd1(pipex, envp, fd);
	close(fd[1]);
	exec_cmd2(pipex, envp, fd);
	waitpid(pid, NULL, 0);
	ft_cleanup(pipex);
}

void	exec_cmd1(t_pipex *pipex, char **envp, int fd[2])
{
	close(fd[0]);
	dup2(pipex->infile_fd, STDIN_FILENO);
	close(pipex->infile_fd);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execve(pipex->cmd_path, pipex->cmd_args1, envp);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	exec_cmd2(t_pipex *pipex, char **envp, int fd[2])
{
	pid_t	pid2;

	pid2 = fork();
	if (pid2 == -1)
	{
		perror("fork (bis)");
		exit(EXIT_FAILURE);
	}
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		dup2(pipex->outfile_fd, STDOUT_FILENO);
		close(pipex->outfile_fd);
		execve(pipex->cmd2_path, pipex->cmd_args2, envp);
		perror("execve (bis)");
		exit(EXIT_FAILURE);
	}
	close(fd[0]);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc == 5)
	{
		ft_bzero(&pipex, sizeof(t_pipex));
		pipex.cmd1_exist = 1;
		pipex.cmd2_exist = 1;
		check_args(argv, &pipex);
		if (argv[2][0] == '\0')
			pipex.cmd1_exist = 0;
		if (argv[3][0] == '\0')
			pipex.cmd2_exist = 0;
		if (pipex.cmd1_exist == 0 || pipex.cmd2_exist == 0)
		{
			if (pipex.cmd1_exist != 1 || pipex.cmd2_exist != 1)
				printf(": command not found\n");
			if (pipex.error_flag != 0)
				exit(EXIT_FAILURE);
		}
		else
			get_path(&pipex, argv, envp);
	}
	else
		write(1, ERROR_MSG, 75);
	return (0);
}

void	ft_cleanup(t_pipex *pipex)
{
	close(pipex->infile_fd);
	close(pipex->outfile_fd);
	free(pipex->tmp_path);
	free(pipex->tmp_path2);
	free_tab(pipex->all_paths);
	free_tab(pipex->cmd_args1);
	free_tab(pipex->cmd_args2);
}
