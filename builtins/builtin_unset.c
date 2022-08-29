/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 08:30:39 by youchenn          #+#    #+#             */
/*   Updated: 2022/08/29 08:48:40 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	built_unset(char **cmd_args, t_env **our_env)
{
	t_env *var_to_unset;
	int exit_status = 0;


	while (cmd_args && *cmd_args)
	{

		if (validity_of_var_name(*cmd_args) == -1) 
			exit_status = -1;
		else 
		{
			var_to_unset = find_variable(our_env, *cmd_args);
			if (var_to_unset)
				delete_var_env(our_env, var_to_unset);
		}
	 	cmd_args++;
	}
	return (exit_status);
}