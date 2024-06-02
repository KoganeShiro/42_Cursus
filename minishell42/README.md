# Minishell

### Table of Content
	- [Introduction](#Introduction)
    - [The Project](#The-Project)
    - [Quick Start](#Quick-Start)

<<<<<<< HEAD
#

## Introduction
Make your own SHELL !
To know more about the project you can read the subject


This is the first group project and one of the most hated project in the common core because of the infinite things that we should manage.
[I](https://github.com/KoganeShiro) pared with [vharatyk]() who did the parsing and i, of course, did the executing.
So i won't be able to enter in the detail of the parsing.

Some people may have choose the wrong teammate and end up doing the project alone.
Some other may have choose a wrong path to complete the project and needed to restart it.
That was our case, the parsing changed but in the end i enjoyed working on it.

---

## The Project
If you did pipex with the bonus, the executing part is almost finished.
The things to do are the Parsing, Manage signals, Do the builtins, Check the exit_code, the leaks and the norminette of course.

#### Parsing
You should, well do the parsing so the variable that are needed to launch one or multiple command + the opening the files are initialize correctly.
It seems like the preferred way to do it it's with the tokenization.
From my understanding, the input line that the user will write in the minishell shall be cut into multiple component like redirections, file_name, command, pipe...
You should be careful of the quote (single and double are different) and the environment variable (with the $ sign)


#

#### Executing
Like i said, or like i wrote previously, the executing part is most likely pipex with bonus. You should change the behaviour of it to stick with the parsing of your teammate (hopefully you discuss with them about it)
You should also take into account the exit_code of your command, if the command is not found or the execution isn't successful etc...

If you manage to finish that, that's great but it's no the end.
You should still manage signals and the execution of the builtins.


#

#### Signals
We should handle ctr-\, ctrl-c and ctrl-d in the readline, the executing and the heredoc.
We used sigaction to handle it because it's what the man recommand.
This is also why you would need a global variable to stock the signal that you receive from the user.
There is two type of signal that you could receive:
SIGINT, which will terminate the process by pressing Ctrl+C in the terminal. Used to interrupt or cancel the current operation. It's commonly used to gracefully terminate a process when the user wants to stop it.

SIGQUIT, which terminate the process and generate a core dump by pressing Ctrl+\ in the terminal. Similar to SIGINT, but typically used for a more forceful termination. It's often used when the user wants to terminate a process and obtain a core dump for debugging purposes.

Ctrl+D signifies end-of-file (EOF) on the standard input stream and is typically used to indicate the end of input in a terminal.

#

#### Builtins
You have to implement :
	◦ echo with option -n
	◦ cd with only a relative or absolute path
	◦ pwd with no options
	◦ export with no options
	◦ unset with no options
	◦ env with no options or arguments
	◦ exit with no options

#

## Quick Start

