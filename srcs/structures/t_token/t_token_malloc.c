/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:50:07 by lvirgini          #+#    #+#             */
/*   Updated: 2021/10/26 16:22:46 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** malloc empty t_token
*/

t_token	*malloc_token(void)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
	{
		perror("malloc_token ()");
		return (NULL);
	}
	ft_memset(token, 0, sizeof(t_token));
	return (token);
}

t_token	**malloc_list_token(void)
{
	t_token		**token;

	token = (t_token **)malloc(sizeof(t_token *));
	if (!token)
	{
		perror("malloc_list_token()");
		return (NULL);
	}
	*token = NULL;
	return (token);
}
