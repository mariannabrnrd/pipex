/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:50:44 by mariaber          #+#    #+#             */
/*   Updated: 2025/06/05 13:50:47 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int     main(int ac, char **av, char **ev)
{
    int     infile;
    int     outfile;
    int     i;

    if (ac >= 5)
    {
        if (ft_strncmp(av[1], "here_doc", 8) == 0)
        {
            i = 3;
            outfile = ft_file(av[ac - 1], 0);
            ft_heredoc(ac, av[2]);
        }
        else
        {
            i = 2;
            infile = ft_file(av[1], 1);
            outfile = ft_file(av[ac - 1], 2);
            dup2(infile, STDIN_FILENO);
        }
        while (i < ac - 2)
            ft_child_parent(av[i++], ev);
        dup2(outfile, STDOUT_FILENO);
        //ft_exec_cmd(av[ac - 2], ev);
        return 0;
    }
    ft_error_args();
}

void    ft_child_parent(char *av, char **ev)
{
    int     fd[2];
    pid_t   pid;

    if (pipe(fd) == -1)
        ft_error();
    pid = fork();
    if (pid == -1)
        ft_error();
    if (pid == 0)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        ft_exec_cmd(av, ev);
    }
    else
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        waitpid(pid, NULL, 0);
    }
}

void    ft_heredoc(int ac, char *eof)
{
    char    *line;
    int     fd[2];
    pid_t   pid;

    if (ac < 6)
        ft_error_args();
    if (pipe(fd) == -1)
        ft_error();
    pid = fork();
    if (pid == 0)
    {
        close(fd[0]);
        while(get_line(&line))
        {
            if (ft_strncmp(line, eof, ft_strlen(eof)) == 0)
                exit(0);
            write(fd[1], line, ft_strlen(line));
        }
    }
    else
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        waitpid(pid, NULL, 0);
    }
}
