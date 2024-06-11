# Subject

- [back to README "MINISHELL"](../README.md)  
- [42 subject "MINISHELL" pdf](minishell.pdf)
---
*Create a simple version of the bash shell written in C.*

## Project Scope
### 1. Commands
Absolute path or relative path, with or without options and arguments.
#### 1.01. absolute path
|absolute path|option|argument|outcome|
|---|---|---|---|
|`/bin/ls`|||*list directories in current location*|
|`/bin/ls`|`-l`||*use a long listing format*|
|`/usr/bin/mkdir`|`-v`|`dir_name`|*create directory with "dir_name" name and **v**erbose message*|
|`/usr/bin/rm`|`-r`|`dir_name`|removes the directory *"dir_name"*|  

#### 1.02. relative path
Use the same examples as above but change the path based on your current directory e.g. `../../bin/ls`.

#### 1.03. single quotes
Single quotes preserve the literal value of variables and disable variable expansion and command substitution.
```bash
name="John"
echo 'My name is $name'
# output:
My name is $name
```
- Arguments with ...
	- **space** `mkdir ' deleteme'` *outcome* `' deleteme'` (*note:* `'` *is not part of dir*).  
	- **semicolon** `mkdir ';deleteme'` *outcome* `;dir name`.  
	- **env var** `mkdir '$HOME deleteme'` *outcome* `$HOME deleteme`.  
- Options with **quotes and space** don't work only without space. The outcome is the same for **single** and **double** quotes.
![double quotes](img/double_quote.png)

#### 1.04. double quotes
Double quotes enable variable expansion and command substitution.
```bash
name="John"
echo "My name is $name"
# output:
My name is John
```
- Arguments with ...
	- **space** `mkdir " deleteme"` *outcome* `' deleteme'` (*note:* `'` *is not part of dir*).  
	- **semicolon** `mkdir ";deleteme"` *outcome* `;dir name`.  
	- **env var** `mkdir "$HOME deleteme"` *outcome* `/home/zk deleteme`.  
	- **\\** `mkdir "\"` *outcome* opens "heredoc" and waits for input and /or `"` on a single line to mark the end.
