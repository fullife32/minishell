/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:24:38 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/10 16:55:53 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	display_error(int error, char *object)
{
	static char	*str_error[NB_ERROR] = {
		"\n",
		" : command not found\n",
		" : permission denied\n",
		" : aucun fichier ou dossier de ce type\n", // a mettre en anglais : ex: "/ls"
	};
	static int	errno_nb[NB_ERROR] = {1, 127, 126, 127};

	ft_putstr("minishell: ");
	ft_putstr(object);
	if (error < NB_ERROR)
	{
		ft_putstr(str_error[error]);
		errno = errno_nb[error];
	}
	else
		errno = 1;
	return (errno);
}

void	exit_minishell(t_cmd **list_cmd, char **env)
{
	free_list_cmd(list_cmd);
	free_list(env);
	exit(errno);
}
