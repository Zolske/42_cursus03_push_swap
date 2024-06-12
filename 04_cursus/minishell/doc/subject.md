# Subject

- [back to README "MINISHELL"](../README.md)  
- [42 subject "MINISHELL" pdf](minishell.pdf)
---
*Create a simple version of the bash shell written in C.*

## Project Scope
Defines the features which the minishell can handle and are tested by the evaluators of the project.

### 1. Builtins
Are contained within the shell itself. The shell executes the command directly, without invoking another program.
#### 1.01 echo
> Display a line of text.
- only `-n` option

|command|option|argument|outcome|
|---|---|---|---|
|`echo`||`hello world`|*argument is printed on a new line*|
|`echo`|||*empty new line*|
|`echo`|`-n`||*no new line or output*|
|`echo`|`-n`|`hello world`|*argument is printed without a new line*|
![cmd echo](img/cmd_echo.png)

#### 1.02 cd
> Change (working) directory.
- change the "working directory", with absolute (*e.g.* `/bin`) or relative path (*e.g.* `../../`)
- the output after trying to changing to a non existing directory (*"something"*)  
`bash: cd: something: No such file or directory`

#### 1.03 pwd
> Print working directory.
- no options or arguments

#### 1.04 env
> Lists all environment variables.
- no options or arguments

#### 1.05 export
> Exports environment variable, creates new one or replaces old one.
- no options
- *e.g.* `export MY_VARIABLE="Hello World"`  
(*create env variable "MY_VARIABLE" with the value "Hello World"*),  
`export MY_VARIABLE="Hello Zolsk"`  
(*changes the value of the env variable "MY_VARIABLE"*)

#### 1.06 unset
> Remove environment variable.
- no options
- *e.g.* `unset MY_VARIABLE`

#### 1.07 exit
> Terminates a script or process (minishell).
- no options
- ends the minishell, passing an intiger determens the staus code of the terminated process *e.g.*  
`exit 3` *after run* `echo $?` *expected outcome* `3`
---
### 2. Simple Commands
Absolute path or relative path, with or without options and arguments.
#### 2.01. absolute path
|absolute path|option|argument|outcome|
|---|---|---|---|
|`/bin/ls`|||*list directories in current location*|
|`/bin/ls`|`-l`||*use a long listing format*|
|`/usr/bin/mkdir`|`-v`|`dir_name`|*create directory with "dir_name" name and **v**erbose message*|
|`/usr/bin/rm`|`-r`|`dir_name`|removes the directory *"dir_name"*|  

#### 2.02. relative path
Use the same examples as above but change the path based on your current directory e.g. `../../bin/ls`.

#### 2.03. single quotes
Single quotes **preserve the literal value** of variables and disable "variable expansion" and "command substitution".
##### variable expansion
When a variable is evaluated before the shell is processing the command.
```bash
# no variable expansion
name="John"
echo 'My name is $name'
# output:
My name is $name
```
##### command substitution
>Command substitution allows the output of a command to replace the command itself. Bash performs the expansion by executing command and replacing the command substitution with the standard output of the command, with any trailing newlines deleted. Embedded newlines are not deleted, but they may be removed during word splitting. [bash reference manual](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html#Command-Substitution)
```bash
# command substitution
echo $(seq 1 3) # echo is called 3 times, each time with an value from 1 to 3
# output:
1 2 3
# no command substitution
echo '$(seq 1 3)'
# output:
$(seq 1 4)
```

- Arguments with ...
	- **space** `mkdir ' deleteme'` *outcome* `' deleteme'` (*note:* `'` *is not part of dir*).  
	- **semicolon** `mkdir ';deleteme'` *outcome* `;dir name`.  
	- **env var** `mkdir '$HOME deleteme'` *outcome* `$HOME deleteme`.  
- Options with **quotes and space** don't work only without space. The outcome is the same for **single** and **double** quotes.
![double quotes](img/double_quote.png)

#### 2.04. double quotes
Double quotes **enable** "variable expansion" and "command substitution".
```bash
# variable expansion
name="John"
echo "My name is $name"
# output:
My name is John
```
```bash
# command substitution
echo $(seq 1 3) # echo is called 3 times, each time with an value from 1 to 3
# output:
1 2 3
# command substitution
echo "$(seq 1 3)"
# output:
1
2
3
```
- Arguments with ...
	- **space** `mkdir " deleteme"` *outcome* `' deleteme'` (*note:* `'` *is not part of dir*).  
	- **semicolon** `mkdir ";deleteme"` *outcome* `;dir name`.  
	- **env var** `mkdir "$HOME deleteme"` *outcome* `/home/zk deleteme`.  
	- **\\** `mkdir "\"` *outcome* opens "heredoc" and waits for input and `"` on a single line to mark the end.
