/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:13:49 by youchenn          #+#    #+#             */
/*   Updated: 2022/08/29 11:45:19 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	if (!access(cmd, X_OK | F_OK))
		return (cmd);
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		if (access(command, X_OK | F_OK) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

char	*find_cmd_path(t_env **our_env, char *cmd)
{
	char **paths;
	t_env *path;

	path = find_variable(our_env, "PATH");
	paths = ft_split(path->value, ':');
	if (!paths)
		return (NULL);
	return (get_cmd(paths, cmd));
}


