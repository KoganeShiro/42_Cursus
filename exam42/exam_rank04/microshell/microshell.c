#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int	ft_error(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
	return (1);
}

int ft_cd(char **argv, int i)
{
    if (i != 2)
        return (ft_error("error: cd: bad arguments\n"));
    if (chdir(argv[1]) == -1)
        return (ft_error("error: cd: cannot change directory to "),
					ft_error(argv[1]), ft_error("\n"));
    return (0);
}

int exec(char **argv, int i, char **env)
{
    int fd[2];
    int status;
    int has_pipe = argv[i] && !strcmp(argv[i], "|");

    if (!strcmp(*argv, "cd"))
        return (ft_cd(argv, i));
    if (pipe(fd) == -1)
        return (ft_error("error: fatal\n"));
    int pid = fork();
    if (pid == 0)
    {
        argv[i] = 0;
        if (has_pipe && (dup2(fd[1], 1) == -1
				|| close(fd[0]) == -1 || close(fd[1]) == -1))
            return (ft_error("error: fatal\n"));
        if (!strcmp(*argv, "cd"))
            return (ft_cd(argv, i));
        execve(*argv, argv, env);
        return (ft_error("error: cannot execute "),
				ft_error(*argv), ft_error("\n"));
    }
    waitpid(pid, &status, 0);
    if (has_pipe && (dup2(fd[0], 0) == -1
			|| close(fd[0]) == -1 || close(fd[1]) == -1))
        return (ft_error("error: fatal\n"));
    return (0);
}

int main(int argc, char **argv, char **env)
{
    int    i = 0;
    int    status = 0;

    if (argc > 1)
    {
        while (argv[i] != NULL && argv[++i] != NULL)
        {
            argv += i;
            i = 0;
            while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
                i++;
            if (i != 0)
                status = exec(argv, i, env);
        }
    }
    return (status);
}
