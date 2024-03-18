/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:17:09 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/18 17:34:53 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	t_data d;

	if (argc >= 5)
	{
		init_data(argc, argv, envp, &d);
        pipe_commands(&d);
        // free_all(&d);
	}
}

void	init_data(int argc, char *argv[], char *envp[], t_data *d)
{
	init_data_null(d, argv, argc);
    set_cmd_arg(d, argv);
    set_cmd_path(envp, d);
    set_pipes(d);
    print_cmd_arg(d);
    // print_cmd_arg(d);
}

void    pipe_commands(t_data *d)
{
    // close(d->pipes[0][WRITE]);
    // int fd_file = open(d->in_fl, O_RDONLY);
    // if (dup2(fd_file, d->pipes[0][READ]) == -1)
    // {
    //     perror("dup2 READ PARENT");
    //     exit(EXIT_FAILURE);
    // }
    if (false == d->read_cl)
        pipe_from_file(d);
    else
        pipe_from_cl(d);
    // else
        printf("limiter is |%s|\n", d->limiter);
    // close(d->pipes[0][READ]);
    // fork child process
    // pid = fork();
    // if (pid == -1)
    // {
    //     perror("fork");
    //     exit(EXIT_FAILURE);
    // }
    // if (pid == 0) // 1st Child
    // {
    //     // close(d->pipes[0][READ]);
    //     // int fd_file = open(d->in_fl, O_RDONLY);
    //     // if (dup2(fd_file, STDIN_FILENO) == -1)
    //     // {
    //     //     perror("dup2 READ 1st Child");
    //     //     exit(EXIT_FAILURE);
    //     // }
    //     close(d->pipes[0][WRITE]);
    //     if (dup2(d->pipes[0][READ], STDIN_FILENO) == -1)
    //     {
    //         perror("dup2 READ 1st Child");
    //         exit(EXIT_FAILURE);
    //     }
    //     close(d->pipes[0][READ]);
    //     close(d->pipes[1][READ]);
    //     if (dup2(d->pipes[1][WRITE], STDOUT_FILENO) == -1)
    //     {
    //         perror("dup2 WRITE 1st Child ");
    //         exit(EXIT_FAILURE);
    //     }
    //     close(d->pipes[1][WRITE]);
    //     if (execve(d->cmd_path[0], d->cmd_arg[0], NULL) == -1) {
    //         perror("execve");
    //         exit(EXIT_FAILURE);
    //     }
    // }
    printf("n commands %d\n", d->n_cmd);
    int idx;
    idx = 0;
    while (idx < d->n_cmd)
    {
        child_command(d, idx);
        idx++;
    }
    // child_command(d, 1);
    // else
    // {
    //     pid = fork();
    //     if (pid == -1)
    //     {
    //         perror("fork");
    //         exit(EXIT_FAILURE);
    //     }
    //     if (pid == 0) // 2nd Child
    //     {
    //         close(d->pipes[1][WRITE]);
    //         if (dup2(d->pipes[1][READ], STDIN_FILENO) == -1)
    //         {
    //             perror("dup2 READ 2nd Child");
    //             exit(EXIT_FAILURE);
    //         }
    //         close(d->pipes[1][READ]);
    //         close(d->pipes[2][READ]);
    //         if (dup2(d->pipes[2][WRITE], STDOUT_FILENO) == -1)
    //         {
    //             perror("dup2 WRITE 2nd Child");
    //             exit(EXIT_FAILURE);
    //         }
    //         close(d->pipes[2][WRITE]);
    //             if (execve(d->cmd_path[1], d->cmd_arg[1], NULL) == -1) {
    //                 perror("execve");
    //                 exit(EXIT_FAILURE);
    //             }
    //     }
    //     else // PARENT
        // {
            // close(d->pipes[0][READ]);
            // close(d->pipes[0][WRITE]);
            // close(d->pipes[1][READ]);
            // close(d->pipes[1][WRITE]);
            // close(d->pipes[2][WRITE]);
            close_all_pipes(d);
            wait(NULL);
            // int fd_outf;
            // char buffer[BUFFER_SIZE];
            // ssize_t bytes_read;

            // fd_outf = open(d->out_fl, O_WRONLY | O_CREAT | O_TRUNC, 0666);
            // if (fd_outf == -1)
            //     perror("open or create output file");
            // while ((bytes_read = read(d->pipes[2][READ], buffer, BUFFER_SIZE)) > 0)
            // {
            //     if (write(fd_outf, buffer, bytes_read) != bytes_read)
            //     {
            //         perror("write to output file");
            //         exit(EXIT_FAILURE);
            //     }
            // }
            // if (bytes_read == -1)
            // {
            //     perror("read");
            //     exit(EXIT_FAILURE);
            // }
            // close(fd_outf);
            write_outfile(d);
            close(d->pipes[d->n_cmd][READ]);
    //     }
    // }
}

// void    write_output_file(int id, t_data *d)
// {
//     int fd_outf;
//     char buffer[BUFFER_SIZE];
//     ssize_t bytes_read;

//     fd_outf = open(d->out_fl, O_WRONLY | O_CREAT | O_TRUNC, 0666);
//     if (fd_outf == -1)
//         perror("open or create output file");
//     while ((bytes_read = read(d->pip[id][READ], buffer, BUFFER_SIZE)) > 0)
//     {
//         if (write(fd_outf, buffer, bytes_read) != bytes_read)
//         {
//             perror("write to output file");
//             exit(EXIT_FAILURE);
//         }
//     }
//     if (bytes_read == -1)
//     {
//         perror("read");
//         exit(EXIT_FAILURE);
//     }
//     close(fd_outf);
//     close(d->pip[id][READ]);
// }
