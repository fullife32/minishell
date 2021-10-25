/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:15:32 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/25 16:41:42 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** expand variable.
**
*/
/*
char	*expand_variable(char **env, char *key)
{
	char	*value;
	char	*result;

	value = get_env_value(env, key + 1);
	if (!value) //// A TESTER
	{
		result = (char *)malloc(sizeof(char));
		if (result)
			*result = "\0";
	}	
	else
		result = ft_strdup(value);
	free(key);
	if (!result)
	{
		perror("malloc in expand_variable()");
		return (NULL);
	}
	return (result);
}
*/