This repo is all about a basic version of a shell program that can handle commands, execute programs, manage input/output redirection, implement some built-in commands (like cd, exit, pwd), and manage processes by forking and executing programs. This is a joint ALX project by Kennedy Wanyoike and Michael Kimulu.

***PSEUDO CODE FOR SIMPLE SHELL PROJECT***

function isInteractiveMode():
*Logic to determine if the program is running in interactive mode
 Return true if interactive, false if non-interactive*

function displayPrompt():
/*Display a prompt for the user in interactive mode*/

function executeCommand(command):
/*Execute the provided command*/

function handleInputError():
/*Handle input error and prompt the user to continue*/

function main():
	if isInteractiveMode():
		displayPrompt()
		try:
			while True:
/*Get user input*/										                userInput = getInput() 

/*Check if user wants to execute a command*/
	if isValidCommand(userInput):
		executeCommand(userInput)
		else:
			handleInputError()

		except KeyboardInterrupt:
/*Handle Ctrl+C, program exits gracefully*/
		print("\nProgram terminated.")
		else:
/*Run shell scripts for non-interactive mode*/ 
runShellScripts()

/*Helper functions*/
function getInput():
  /*Get user input from the prompt*/
	return input("Enter a command: ")

function isValidCommand(command):
/*
  Check if the entered command is valid
  You can customize this based on your specific commands
  */
	return True if command is valid else False

function runShellScripts():
  /*Logic to run shell scripts in non-interactive mode*/

/*Start the program*/
main()

