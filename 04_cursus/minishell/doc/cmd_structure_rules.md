# Command Structure Rules
The document aims to explains by which rules the bash command is executed with it's arguments and directions.

## 1. Command and Argument rules
The "**1st-word**" which is **not preceded** by a "**meta-character**" is a **command**.  
"**Every-word**" that comes after a **command** and ...  
1. … is "**not separated**" by a "**meta-character**" until the "**next meta-character**", or ...  
2. … if "**separated**" by a "**meta-character**" than the "**2nd-word**" after, until the "**next meta-character**" (Only the "**1st-word**" after an "**meta-character**" belongs to it!) ...  
… is an "**argument**".

## 2. Every command can have only one out-direction and one in-direction.
- **Out-direction** is: `>` direct-file-out, `>>` append-file-out or a `|` pipe.
- **In-direction** is: `<` direct-file-in, `<<` heredoc  
It is always the last **in-direction** or **out-direction** which is used!  
All **out-direction** files are created, if they not already exist.  
All **heredoc**s are executed (*user needs to type input*) but only the last one gets used.  
No information is passed to the **pipe** if there is an **out-direction** before it.


### Example:
![example command structure rule](./img/cmd_rule_structure_bash.png)  
There are 3 files with the following content: `file1` -> "`txt1`" , `file2` -> "`txt2`" , `file3` -> "`txt3`" .  
![diagram](./img/example_stuct_cmd.jpg)  
- `> file4` : **REDIRECT-OUT**
	- The file does not exist and is therefor created.
- `cat` : **COMMAND**
	- It does not matter if it is a "valid command", but it is structured as such, there can be only one, which is the first occurrence.  
- `file1` : **1st ARGUMENT**
- `> file5` : **REDIRECT-OUT**
	- The file does not exist and is also created, because it is the last redirection-out, it is the one which is going to be used, the other (`file4`) is not going to be used and remains empty.
- `file2` : **2nd ARGUMENT**
- `fffff` : **3rd ARGUMENT**
	- Is not a existing file nor a valid argument, but it is passed as augment to the command. When executing the command **later**, the cat command will throw an error, but still continue with the rest of the execution / command (`file3`).  
	`cat: fffff: No such file or directory`  
- `file3` : **4th ARGUMENT**
