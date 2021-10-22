/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_error.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:47:57 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/22 11:14:02 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_ERROR_H
# define MINISHELL_ERROR_H

# define NB_ERR_SYNTAX 2

enum	e_error
{
	ERR_SYMBOL,
	ERR_QUOTES_NOT_CLOSED,
};

enum	e_reason_cmd_not_work
{
	NOT_FOUND,
};

//void		display_command_error(t_env *env, char *cmd, int reason);
int		print_syntax_error(int err, char char_data, char *str_data);
int		syntax_error_redirection(t_token *token);

#endif
