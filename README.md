Simple Shell
Description
Simple Shell is a basic UNIX command line interpreter implemented in C. It reads user commands, executes them using the execve system call, and handles built-in commands like exit and env. This project is modular, with each functionality separated into different files, making it easier to manage and extend.

Features
Prompt Display: Shows a custom prompt (#cisfun$ ) for user interaction.
Command Execution: Executes user commands by searching for the specified executable in the provided path.
Error Handling: Prints an error message if the command cannot be found or executed.
Built-in Commands:
exit: Exits the shell.
env: Prints the current environment variables.
Modular Design: The project is organized into multiple files, each handling a specific part of the shell's functionality.
Files
main.c: The entry point of the shell program. Contains the main loop that continuously displays the prompt and handles commands.
prompt.c: Contains the prompt function that displays the shell prompt.
handle_command.c: Manages the reading of user input, execution of commands, and handling of special cases like exit and env.
print_env.c: Implements the env command by printing the current environment variables.
chora.c: Provides the chora function for printing messages to the standard output.
shell.h: Header file containing function prototypes and necessary includes.
Compilation
To compile the Simple Shell, use the following command:

sh
Copy code
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell
This will generate an executable named shell that can be run in your terminal.

Usage
Start the Shell: Run the compiled shell executable:

sh
Copy code
./shell
Enter Commands: Type a command and press Enter. The shell will attempt to execute the command. For example:

sh
Copy code
#cisfun$ /bin/ls
Use Built-in Commands:

Exit the shell: Type exit to exit the shell:
sh
Copy code
#cisfun$ exit
Print environment variables: Type env to display the current environment variables:
sh
Copy code
#cisfun$ env
Error Handling: If an invalid command is entered, the shell will display an error message:

sh
Copy code
#cisfun$ invalidcommand
./shell: No such file or directory
End-of-File Handling: The shell will terminate gracefully if the end-of-file (Ctrl+D) is detected.

Limitations
No PATH Handling: The shell does not search for executables in the system's PATH. Commands must be provided with absolute paths.
Simple Command Lines: The shell only supports single-word commands without arguments (except for the built-in commands).
No Special Characters: The shell does not handle special characters like ", ', \, *, &, #.
No Advanced Features: The shell does not support advanced features like pipes, redirections, or moving the cursor.
