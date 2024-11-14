# Pipex

### Table of Content
- [Pipex](#pipex)
    - [Overview](#overview)
    - [Quick Start](#quick-start)

#


In summary what is my program doing ?
Understand how pipe works

```c
check_args()
	open or create the outfile
	open the infile

get_path()
	check_cmd1()
	check_cmd2()
		if the arg is not a command but the path of the command
		if it is then fill the pipex->cmd_args1 and pipex->cmd_args2
		pipex->cmd_path and pipex->cmd2_path
	the arg is a command, so it will split it and fill the pipex->cmd_args1 and pipex->cmd_args2
	and fill pipex->all_paths

call is_cmd_exist()
	is_cmd2_exist()
		fill the pipex->cmd_path and pipex->cmd2_path

exec_cmd()
	create a pipe and a fork
	in the child exec_cmd1()
		use dup2 to redirect the output
		execute the command
	exec_cmd2()
		fork and in the child
		use dup2 to redirect the output
		execute the command

ft_cleanup()
	will free and close the fd
```





In summary what is my program doing ?
pipex bonus: manage multiple pipes and a heredoc

```c
//* multiple pipes
check_args()
	open or create the outfile
	open the infile

get_path()
	fill pipex->all_paths
	if the path doesn't exist
	check_cmd()
		check if the arg is the path of the command
		if yes than fill pipex->cmd_args and pipex->cmd_path
	else the arg is a command so split it and fill pipex->cmd_args

ft_exec()
	while (pipex->nb_of_cmd > 1)
		ft_exec_cmd()
			create a pipe and a fork
			in the child ft_execve()
			use dup2 to redirect the output
			execute the command
	ft_execve_last()
		fork in the child ft_execve()
		use dup2 to redirect the output
		execute the command
wait for all the child to finish

ft_cleanup()
	will free and close all the fd (that i have open)


//* heredoc
ft_here_doc()
	check if the limiter is nothing, if it is then when the user will '\n' this will be the delimiter
	open or create the outfile
wrin_heredoc()
	open the heredoc (tmp file)
	write things in it and if the line == to the limiter then delete the file
open the infile (which is the heredoc)

get_path
	fill pipex->all_paths
	if the path doesn't exist
	check_cmd()
		check if the arg is the path of the command
		if yes than fill pipex->cmd_args and pipex->cmd_path
	else the arg is a command so split it and fill pipex->cmd_args

exec_heredoc()
	_exec_()
		create a pipe and a fork
		in the child _execve_()
		use dup2 to redirect the output
		execute the command
		execve the first cmd with the heredoc
	while (pipex->nb_of_cmd > 1)
		ft_exec_cmd()
	ft_execve_last()
```
