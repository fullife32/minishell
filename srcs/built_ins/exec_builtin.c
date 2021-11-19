/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:37:21 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/19 12:48:52 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_export(char **arg, char **env, t_builtin *bi)
{
	(void)env;
	(void)bi;
	(void)arg;
}

void	exec_unset(char **arg, char **env, t_builtin *bi)
{
	(void)env;
	(void)bi;
	(void)arg;
}

void	exec_exit(char **arg, char **env, t_builtin *bi)
{
	(void)env;
	(void)bi;
	(void)arg;
}
