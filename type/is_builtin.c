/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:27:51 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/30 18:41:01 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

bool	is_builtin(char *cmd)
{
	if (ft_strequ("echo", cmd) || ft_strequ("set", cmd)
		|| ft_strequ("unset", cmd) || ft_strequ("env", cmd)
		|| ft_strequ("cd", cmd) || ft_strequ("exit", cmd)
		|| ft_strequ("type", cmd) || ft_strequ("export", cmd)
		|| ft_strequ("alias", cmd) || ft_strequ("unalias", cmd))
		return (true);
	else
		return (false);
}
