/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:31:16 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/27 16:10:32 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Print an error if there are more than 1 argument
** and an error if getcwd can't find actual directory
*/

static void	pwd_error(int error)
{
	ft_putstr_fd("pwd", STDERR_FILENO);
	if (error == TOO_MANY_ARGS)
		ft_putstr_fd(S_TOO_MANY_ARGS, STDERR_FILENO);
	else if (error == NO_CWD)
		ft_putstr_fd(S_NO_CWD, STDERR_FILENO);
	set_exit_status(1, 0);
}

void	exec_pwd(char **arg, char ***env)
{
	char	*cwd;

	(void)env;
	set_exit_status(0, 0);
	if (arg[1] != NULL)
	{
		pwd_error(TOO_MANY_ARGS);
		return ;
	}
	cwd = get_current_dir();
	if (cwd)
	{
		printf("%s\n", cwd);
		free(cwd);
	}
	else
		pwd_error(NO_CWD);
}
