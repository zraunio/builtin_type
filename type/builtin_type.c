/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:43:14 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/30 19:13:12 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

static void	*ft_memdel_return(void **delete)
{
	ft_memdel((void *)&delete);
	return (NULL);
}

static char	*exec_binary_path(char *path, char *cmd)
{
	struct stat		buf;
	char			*temp;
	char			*cpy;

	cpy = path;
	temp = NULL;
	while (*cpy)
	{
		temp = ft_strjoin(cpy, "/");
		temp = ft_strjoin_free(temp, cmd, 1);
		if (lstat(temp, &buf) == 0)
			break ;
		else
			ft_strdel((void *)&temp);
		cpy++;
	}
	// ft_arr_free((void *)&path);
	if (ft_is_directory(temp))
		return (ft_memdel_return((void *)&temp));
	return (temp);
}

char	*exec_find_binary(char *path, char *cmd)
{
	if (cmd == NULL || path == NULL)
		return (NULL);
	if (ft_is_directory(cmd))
	{
		ft_print_fd(STDERR_FILENO, "21sh: %s: Is a directory", cmd);
		return (NULL);
	}
	if (cmd[0] == '\0')
		return (NULL);
	return (exec_binary_path(path, cmd));
}

void	exec_slash_access(char *cmd, char **bin_path)
{
	if (access(cmd, F_OK) == -1)
	{
		perror(NO_FILE_OR_DIR);
		return ;
	}
	else if (access(cmd, X_OK) == -1)
	{
		perror(EXEC_NO_ACCESS);
		return ;
	}
	else
		*bin_path = ft_strdup(cmd);
}

char	**exec_fetch_path_var(char **env)
{
	while (*env)
	{
		if (ft_strnstr(*env, "PATH=", 5))
			return (ft_strsplit(*env + 5, ':'));
		env++;
	}
	return (NULL);
}

int	builtin_type(char *cmd)
{
	char	*bin_path;

	bin_path = NULL;
	if (is_builtin(cmd) == true)
		return (1);
	else
	{
		if (cmd[0] == '/')
			exec_slash_access(cmd, &bin_path);
		if (!bin_path)
			bin_path = exec_find_binary("/bin:/usr/bin", cmd);
		if (access(bin_path, F_OK) == -1)
			return (0);
		else
		{
			ft_putstr(bin_path);
			return (2);
		}
	}
}
