/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:53:53 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/30 18:57:00 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# include "libft/incl/libft.h"
# include <stdbool.h>
# include <signal.h>
# include <term.h>
# include <fcntl.h>
# include <time.h>
# include <curses.h>
# include <termcap.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include "errors.h"

# define NULL_BYTE '\0'
# define TRUE 1
# define FALSE 0
# define BUFFER 1024
# define S_QUOTE '\''
# define D_QUOTE '\"'
# define MAX_BUFF 4096
/*
** SHELL
*/

int		env_variable_counter(char **environ);
void	allocation_check(void **check);
char	**copy_environment(char **environ);
void	print_logo(void);
bool	is_builtin(char *cmd);
int		builtin_type(char *cmd);

#endif
