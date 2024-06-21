# Allowed Functions
- [back to README "MINISHELL"](../README.md)  
---
For the full list of allowed functions see the [subject](minishell.pdf).
## readline (functions)
The GNU Readline Library contains functions which take user input from the command line.  
Include the following headers:  
`#include <readline/readline.h` and/or `#include <readline/history.h>`.  
And link the "static library" `-lreadline -lhistory` **at the end** when compiling the executable program. [GNU Readline Library](https://tiswww.case.edu/php/chet/readline/readline.html).
|prototype|description|
|---|---|
|`char *readline(const char *prompt);`|Prompt the user for input which needs to be terminated with **ENTER**. Note that the finale newline is removed. A "malloc pointer" of the entered string is returned but the entered string is also saved in the global variable `rl_line_buffer`.<br>[see playground readline.c](../playground/readline.c)|
|`int add_history(const char *line)`<br>-> `line`: A pointer to a null-terminated string that represents the line of text to be added to the history.<br>**Return Value**<br>-> **The function returns 0** if the line is successfully added to the history.<br>-> **It returns a non-zero** value if the operation fails. For example, failure can occur if the provided line is NULL or empty.|Is used to keep a record of the commands or input lines entered by the user. This historical record can be utilized to recall previous inputs, making it easier for users to re-execute commands or edit them.<br>[see playground add_histor.c](../playground/add_history.c)|
|`void rl_clear_history(void)`|Clears the history of entered strings (commands).<br>[see playground rl_clear_history.c](../playground/rl_clear_history.c)|
|`void rl_replace_line(const char *text, int clear_undo)`<br>-> `*text`: A pointer to a null-terminated string containing the new line of text to replace the current line buffer.<br>-> `clear_undo`: An integer that determines whether to clear the undo list. If non-zero, the undo list is cleared. If zero, the undo list is preserved.|Replaces the value of the global variable `rl_line_buffer` which was set after getting the user input with `readline()` with a new string (*text*).<br>[see playground rl_replace_line.c](../playground/rl_replace_line.c)|
|`void rl_on_new_line (void)`|When implementing an interactive command-line application and you need to ensure that the **cursor is positioned at the start** of a new line. E.g. in interactive mode, the user is entering information but you are also printing status information.<br>**!!! In practice I could not see any difference with or without the function!!!**<br>[see playground rl_on_new_line.c](../playground/rl_on_new_line.c)|
|`void rl_redisplay(void)`|Forces the Readline library to re-render the "current line buffer" on the screen.<br>**!!Had no effect in my playground!!**<br>[playground rl_replace_line.c](../playground/rl_replace_line.c)<br>Should be useful in the following scenarios:<br>-> **Programmatically Modifying the Input Line**: When you change the contents of the line buffer using functions like `rl_replace_line` or by directly manipulating `rl_line_buffer`.<br>-> **Handling Asynchronous Events**: When your program needs to update the prompt or input line in response to asynchronous events such as receiving data from a network socket.<br>-> **Custom Prompt Display**: If you change the prompt dynamically and need to ensure it is immediately updated.|

---
## getcwd (get current working directory)
Include the header: `unistd.`
|prototype|description|
|---|---|
|`char *getcwd(char *buf, size_t size)`<br>`*buf`: A pointer to an array where the pathname of the current working directory will be stored. Needs to be large enough to hold the string of the path including the null terminator.<br>`size`: The size of the array pointed to by buf.<br>**Return Value**<br>-> **On success**, it returns a pointer to the buffer buf containing the pathname of the current working directory.<br>-> **On failure**, it returns `NULL`, and `errno` is set to indicate the error.|Is used to get the current working directory of the process.<br>[see playground getcwd.c](../playground/getcwd.c)|

---
## chdir (change current working directory)
Include the header: `unistd.h`
|prototype|description|
|---|---|
|`int chdir(const char *path)`<br>`*path`: A pointer to a string containing the path to the directory you want to change to. This can be an absolute or relative path.<br>**Return Value**<br>-> **On success**, it returns `0`.<br>-> **On failure**, it returns `-1`, and `errno` is set to indicate the error.|Is used to change the current working directory of the calling process.<br>[see playground chdir.c](../playground/chdir.c)|

---
## stat (functions, file statistic)
Include the header: `sys/stat.h`
|prototype|description|
|---|---|
|`int stat(const char *path, struct stat *buf)`<br>`*path`: A pointer to a string containing the pathname of the file to be examined.<br>`struct stat *buf`: A pointer to a `struct stat` structure where the file information will be stored.<br>**Return Value**<br>**On success**, it returns `0`.<br>**On failure**, it returns `-1`, and `errno` is set to indicate the error.|Is used to retrieve information about a file. It provides detailed information about the file, such as its size, permissions, and timestamps.<br>[see playground stat.c](../playground/stat.c)|
|`int lstat(const char *path, struct stat *buf`<br>*the same as `stat` above*|Is used to retrieve information about a file, similar to the `stat` function, but with a key difference: `lstat` does not follow symbolic links. Instead, if the file specified by the pathname is a symbolic link, `lstat` returns information about the link itself.|
|`int fstat(int fd, struct stat *buf)`<br>`fd`: The file descriptor of the file for which information is to be obtained.<br>`struct stat *buf`: A pointer to a struct stat structure where the file information will be stored.<br>**Return Value**<br>**On success**, it returns `0`.<br>**On failure**, it returns `-1`, and `errno` is set to indicate the error.|Is used to retrieve detailed information about an open file using its file descriptor.<br>[see playground fstat.c](../playground/fstat.c)|

---
## unlink (remove linke / file)
Include the header: `unistd.h`
|prototype|description|
|---|---|
|`int unlink(const char *pathname)`<br>`*pathname`: A pointer to a string containing the pathname of the file to be removed.<br>**Return Value**<br>**On success**, it returns `0`.<br>**On failure**, it returns `-1`, and `errno` is set to indicate the error.|-> The unlink function removes a link to a file. If this is the last link to the file and no process has the file open, **the file is deleted** and the space it was using is freed.<br>-> If there are other links to the file, the file itself is not deleted until all links are removed and no processes have the file open.<br>[see playground unlink.c](../playground/unlink.c)|