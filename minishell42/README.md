# Minishell

### Table of Content
- [Minishell](#minishell)
	- [Introduction](#introduction)
    - [The Project](#the-project)
    - [Quick Start](#quick-start)

#

## Introduction
Make your own SHELL !
To know more about the project you can read the subject


This is the first group project.
[I](https://github.com/KoganeShiro) pared with [vharatyk](https://github.com/viktorhm) who did the parsing and i, of course, did the executing.
So i won't be able to enter in the detail of the parsing.

This project is known to be the worst project because:

- Some people may have choose the wrong teammate and end up doing the project alone.

- Some other may have choose a wrong path to complete the project and needed to restart it.

- The common core because of the infinite things that we should manage

I, personnaly quite enjoy it but at the end, it's just annoying because you fix errors to only found more errors...
It's really exhausting and stressful because it take even more times than other project that you already did.

---

## The Project
If you did pipex with the bonus, the executing part is almost "finished".
The things to do are the Parsing, Manage signals, Do the builtins, Check the exit_code, the leaks and the norminette of course.

#### Parsing
You should, well do the parsing. So that into account what are needed to launch one or multiple command + the opening of files, environment variable...

It seems like the preferred way to do it is with the [tokenization](https://stackoverflow.com/questions/380455/looking-for-a-clear-definition-of-what-a-tokenizer-parser-and-lexers-are).

In order to make some builtins work like `export` or `unset` you should make a copy of the env

From my understanding, the input line shall be cut into multiple component like redirections, file_name, command, pipe...
You should be careful of the quote (single and double are different) and the environment variable (with the $ sign)

Maybe check quote errors, then expand environment variables.

You can do after that split the input and fill a tab of string with a tab of int knowing what each string in the tab mean (is it a redirections or a command ?)

#

#### Executing
Like i wrote previously, the executing part is most likely pipex with bonus. You should change the behaviour of it to stick with the parsing of your teammate (hopefully you discuss with them about it before doing anything)

For exemple if you use a linked list to go through all the command, then you should fix your pipex to manage a linked list. You should also check the files because you could receive an input like that

	Minishell~$: <infile cmd|>outfile cmd|cmd|<infile cmd

You should also take into account the exit_code of your command, if the command is not found or the execution isn't successful etc...

If you manage to finish that, that's great but it's no the end.
You should still manage signals and the execution of the builtins.

#

#### Signals
We should handle ctr-\\, ctrl-c and ctrl-d in the readline, the executing and the heredoc.

We used sigaction to handle it because it's what the man recommand.
This is also why you would need a global variable to stock the signal that you receive from the user.

There is two type of signal that you could receive:
SIGINT, which will terminate the process by pressing Ctrl+C in the terminal. Used to interrupt or cancel the current operation. It's commonly used to gracefully terminate a process when the user wants to stop it.

SIGQUIT, which terminate the process and generate a core dump by pressing Ctrl+\ in the terminal. Similar to SIGINT, but typically used for a more forceful termination. It's often used when the user wants to terminate a process and obtain a core dump for debugging purposes.

Ctrl+D signifies end-of-file (EOF) on the standard input stream and is typically used to indicate the end of input in a terminal.

#

#### Builtins
You have to implement :
```
	◦ echo with option -n
	◦ cd with only a relative or absolute path
	◦ pwd with no options
	◦ export with no options
	◦ unset with no options
	◦ env with no options or arguments
	◦ exit with no options
```
Don't forget to execute the builtins in you executing logic. Note that some of them should be done in the parent.
For exemple `export` because the add of a new environment variable in the env won't be pass on in the parent if you do it in child.

#

## Quick Start

git clone the repo and go to the OURshell directory. You can make or use the executable like that `./minishell`
Then you can test writing input !

