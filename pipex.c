#include "pipex.h"

int     main(int ac, char **av, char **ev)
{
    int     fd[2];
    pid_t   pid;

    if (ac == 5)
    {
        if (pipe(fd) == -1)
            ft_error();
        pid = fork();
        if (pid == -1)
            ft_error();
        if (pid == 0)
            ft_child(av, ev, fd);
        waitpid(pid, NULL, 0);
        ft_parent(av, ev, fd);
    }
    else
        ft_putstr_fd("Error: Bad arguments\n", 2);
    return(0);
}

void    ft_child(char **av, char **ev, int *fd)
{
    int     infile;
    
    close(fd[0]);
    infile = open(av[1], O_RDONLY);
    if (infile == -1)
        ft_error();
    dup2(fd[1], STDOUT_FILENO);
    dup2(infile, STDIN_FILENO);
    ft_exec_cmd(av[2], ev);
}

void    ft_parent(char **av, char **ev, int *fd)
{
    int     outfile;

    close(fd[1]);
    outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (outfile == -1)
        ft_error();
    dup2(fd[0], STDIN_FILENO);
    dup2(outfile, STDOUT_FILENO);
    ft_exec_cmd(av[3], ev);
}