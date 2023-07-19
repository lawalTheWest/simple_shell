<h1> Simple Shell </h1>

<h2> Building a Simple Unix Shell Program</h2>

<h6>Isa Isa </br> Lawal Tajudeen</h6>

A Unix shell is a tool that allows users to interact with the OS through a command-line interface.
It provides a convenient way to execute programs/ commands, run programs, and manage files and processes.

This READ ME write-up explores the process of building a simple Unix shell program using the C programming language.
It covers the `basics` of a Unix shell termed `Simple Shell`, including the following:

1. Understanding the Basics:
- Basics:

	+ A shell reads commands from the user,
	+ Interprets them, and
	+ Executes the corresponding programs.

- It also handles features like:

	+ input/output redirection,
	+ piping, and
	+ command history.

The main goal is to create a simplified version of a shell that performs the essential functions of a shell.

2. Command Line Input:
- The first step:
	+ Read commands entered by the user.
		We can use the `getline()` function to read a line of input from the user, this depends on the allowed functions from the project requirements.
	+ Next we can parse the command line to separate the command and its arguments.

3. Executing Commands:
- Once we have the command and its arguments, we can create a child process using `fork()`.
In the child process, we can use `execve()` to replace the child process with the desired command.

<b>NOTE: Please man all the functions listed in this Read me file to have a better understanding of what they do and how they connect to create a simple shell process.</b>

The `execve()` function loads and executes the specified program file, and it requires the full path to the program along with the arguments.

4. Handling Built-in Commands:
- In addition to external commands, shells often support built-in commands, such as `cd` or `exit`. (make tresearch as to what these commands do)
- We can add support for these built-in commands by checking if the command matches any of the built-in commands and executing them accordingly.


5. Managing Processes:
- A shell should handle multiple processes efficiently.
- We can use system calls like `fork()`, `execve()`, `wait()`, and `waitpid()` to manage child processes and ensure proper execution and termination.
By using these functions, we can:

- Execute commands at different time intervals,
- Wait for processes to finish, and
- Handle errors gracefully.

6. Signal Handling:
Unix shells should also handle signals, such as Ctrl+D, Ctrl+Z, Ctrl+C. (Do make an extensive research to know how to handle these and what exactly they do).
We can use the custom function `_signal()` function to register signal handlers and define the desired behavior for each signal.

7. Prompt and Loop:
- We create an `interactive shell`, and our objective is to make sure it is not running in non-interractive mode. we can continuously prompt the user for input after executing a command.
This allows users to enter multiple commands one after another.
We can decide to use a loop to repeat the processes:
	- Reading input,
	- xecuting commands, and
	- Displaying the prompt
	until the user chooses to exit.(EOF)

Conclusion:
Building this simple Unix shell program provided a great opportunity to learn about:
- Process management,
- Command execution, and
- User interaction
in a Unix-like environment.

`
***********************************************************************************
`
All these are achieved By leveraging the allowed functions and understanding the principles of a shell.
Creating a functional basic simple shell program for effective interaction with the operating system.
`
***********************************************************************************
`
<h6>ALX SE</h6>
