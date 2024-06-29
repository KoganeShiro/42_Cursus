# Minitalk

### Table of Content
- [Minitalk](#minitalk)
	- [What are UNIX Signals ?](#what-are-unix-signals)
    - [Overview](#overview)
    - [Quick Start](#quick-start)

#

### What are UNIX Signals
In this project you will learn about signals. What are they used for and how to use them.
Common UNIX signals include:

- **SIGKILL (128+9):** Requests immediate termination of a process.
- **SIGTERM (128+15):** Requests a graceful termination, allowing the process to perform cleanup operations before exiting.
- **SIGINT (128+2):** Sent by the interrupt key (Ctrl+C) to interrupt or terminate a running process.
- **SIGSEGV (128+11):** Indicates a segmentation fault, typically caused by a program accessing invalid memory.

The number behind in parentheses is the exit code (you will learn more about it in minishell)

#

### Overview
You will have to use SIGUSR1 and SIGUSR2 in order to imitate the binary system sending these signal from the client to the server. So in your client side, you have to convert each byte into binary and from your server side, you have to convert the binary into byte.

My project won't pass the correction because with a lot of characters, the server will crash 'cause i didn't manage to process the signals send by the client quickly enough. In order to make it work, you have two solution that i can think of.
First, you should malloc the number of character that are in the string.
Second, you should send one characters and wait for the server to says "it's ok, give me the next"

#

### Quick Start
You should compile using `make`.
Then,
		```./server```
Open another terminal and get the pid of the server and

		```./client PID "message"```

You should get the message on the server side !

