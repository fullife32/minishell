/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_env.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:56:22 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/26 16:49:17 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_ENV_H
# define MINISHELL_ENV_H

/*
** get env
*/

char	*get_env_value(char **env, char *key);
int		get_env_index(char **env, char *key);
int		get_list_env_size(char **env);

/*
** create minishell env
*/

char	**make_minishell_env(char *env[]);
char	**add_env(char **env, char *key, char *value);

#endif
