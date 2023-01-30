/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:39:45 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/30 19:08:02 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void	type_printer(char *cmd)
{
	int	i;

	i = builtin_type(cmd);
	ft_putstr(cmd);
	if (i == 0)
		ft_putstr(" not found\n");
	else if (i == 1)
		ft_putstr(" is a shell builtin\n");
	else if (i == 2)
		ft_putstr(" is ");
}

int	main(int argc, char **argv, char **environ)
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
			type_printer(argv[i++]);
	}
	return (0);
}
