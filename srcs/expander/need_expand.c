/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:34:18 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/25 16:43:38 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	need_expand_str(char *str)
{
	if (str)
	{
		if (str[0] == CHAR_DOUBLE_QUOTE
			|| str[0] == CHAR_SIMPE_QUOTE
			|| str[0] == CHAR_DOLLAR)
			return (true);
	}
	return (false);
}

t_bool	need_expand_argv(char **argv)
{
	size_t	i;

	if (!argv)
		return (false);
	i = 0;
	while (argv[i])
	{
		if (need_expand_str(argv[i]))
			return (true);
		i++;
	}
	return (false);
}