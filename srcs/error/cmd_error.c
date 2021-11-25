/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:24:38 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/25 18:19:05 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	display_error(int error, char *object)
{
	static char	*str_error[NB_ERROR] = {
		"\n",
		": command not found\n",
		": permission denied\n",
		": No such file or directory\n",
		": ambiguous redirect\n"
	};
	static int	errno_nb[NB_ERROR] = {1, 127, 126, 127};

	ft_putstr("minishell: ");
	ft_putstr(object); // sur STDERR
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
	// fprintf(2, "%d\n", get_exit_status());
	exit(get_exit_status());
}
