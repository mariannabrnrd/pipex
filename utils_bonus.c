/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:50:24 by mariaber          #+#    #+#             */
/*   Updated: 2025/06/05 13:50:33 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*int     ft_file(char *filename, int flag)
{
    int     fd;

    fd = 0;
    if (flag == 1)
        fd = open(filename, O_RDONLY);
    else if (flag == 2)
        fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    else if (flag == 3)
        fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777);
    else
        ft_error();
    if (fd == -1)
        ft_error();
    return(fd);

}*/

void    ft_error_args(void)
{
    ft_putstr_fd("Error: Bad argument\n", 2);
    exit(1);
}

int     get_line(char **line)
{
    int     byte_read;
    char    *temp;
    char    c;
    int     i;

    i = 0;
    byte_read = 0;
    temp = (char *)malloc(10000);
    if (!temp)
        return(-1);
    byte_read = read(0, &c, 1);
    while (byte_read && (c != '\n' && c != '\0'))
    {
        temp[i] = c;
        i++;
        byte_read = read(0, &c, 1);
    }
    temp[i++] = '\n';
    temp[i] = '\0';
    *line = temp;
    free(temp);
    return(byte_read);
}

/*void    ft_close( int fd, int infile, int outfile)
{
    close(fd);
    close(infile);
    close(outfile);
}*/

void    ft_close(int fd, int infile, int outfile)
{
    if (fd != -1)
        close(fd);
    if (infile != -1)
        close(infile);
    if (outfile != -1)
        close(outfile);
}
