/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execution.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:51:54 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/23 21:44:15 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_EXECUTION_H
# define MINISHELL_EXECUTION_H

# include "minishell.h"

int		executer(t_cmd **cmd, char *env[]);
int		add_path_for_all_cmd(t_cmd *cmd, char *env[]);
pid_t	create_child_process(t_cmd *cmd, char *env[]);

/*
** find path for execve.
*/

int		setup_cmd_path(t_cmd *cmd, char **env);
int		get_cmd_path_from_path_env(t_cmd *cmd, char *path_env[]);

/*
**	Usefull
*/

t_bool	is_command_executable(t_cmd *cmd);

#endif
