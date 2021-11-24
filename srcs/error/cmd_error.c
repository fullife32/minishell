/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:24:38 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/24 19:02:13 by lvirgini         ###   ########.fr       */
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
		": ambiguous redirect\n",
	};
	static int	errno_nb[NB_ERROR] = {1, 127, 126, 127};

	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(object, STDERR_FILENO);
	if (error < NB_ERROR)
	{
		ft_putstr(str_error[error]);
		errno = errno_nb[error];
	}
	else
		errno = 1;
	return (errno);
}

void	display_heredoc_error(char *delimitor)
{
	ft_putstr_fd("minishell: warning: here-document delimited by \
end-of-file (wanted `", STDERR_FILENO);
	ft_putstr_fd(delimitor, STDERR_FILENO);
	ft_putstr_fd("')\n", STDERR_FILENO);
}
void	exit_minishell(t_cmd **list_cmd, char **env)
{
	free_list_cmd(list_cmd);
	free_list(env);
	exit(errno);
}
