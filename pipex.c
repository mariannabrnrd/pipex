/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:43:42 by mariaber          #+#    #+#             */
/*   Updated: 2025/06/04 12:43:45 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int     main(int ac, char **av, char **ev)
{
    int     fd[2];
    pid_t   pid1;
    pid_t   pid2;
    if (ac == 5)
    {
        if (pipe(fd) == -1)
            ft_error();
        pid1 = fork();
        if (pid1 == -1)
            ft_error();
        if (pid1 == 0)
            ft_first_child(av, ev, fd);
        waitpid(pid1, NULL, 0);
        pid2 = fork();
        if (pid2 == -1)
            ft_error();
        if (pid2 == 0)
            ft_second_child(av, ev, fd);
        close(fd[0]);
        close(fd[1]);
        waitpid(pid2, NULL, 0);
    }
    else
        ft_putstr_fd("Error: Bad arguments\n", 2);
    return(0);
}

void    ft_first_child(char **av, char **ev, int *fd)
{
    int     infile;

    close(fd[0]);
    infile = open(av[1], O_RDONLY);
    if (infile == -1)
        ft_error();
    if (dup2(fd[1], STDOUT_FILENO) == -1)
        ft_error();
    if (dup2(infile, STDIN_FILENO) == -1)
        ft_error();
    ft_exec_cmd(av[2], ev);
}

void    ft_second_child(char **av, char **ev, int *fd)
{
    int     outfile;

    close(fd[1]);
    outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (outfile == -1)
        ft_error();
    if (dup2(fd[0], STDIN_FILENO) == -1)
        ft_error();
    if (dup2(outfile, STDOUT_FILENO) == -1)
        ft_error();
    ft_exec_cmd(av[3], ev);
}
