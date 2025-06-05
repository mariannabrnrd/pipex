/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:44:19 by mariaber          #+#    #+#             */
/*   Updated: 2025/06/04 12:44:25 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

/* pipex */
void    ft_child(char **av, char **ev, int *fd);
void    ft_parent(char **av, char **ev, int *fd);
void    ft_child_parent(char *av, char **ev);
void    ft_heredoc(int ac, char *eof);

/* utils */
void    ft_error(void);
void    ft_error_args(void);
void    ft_exec_cmd(char *av, char **ev);
char    *ft_search_path(char *cmd, char **ev);
int     ft_file(char *filename, int flag);
int     get_line(char **line);
#endif
