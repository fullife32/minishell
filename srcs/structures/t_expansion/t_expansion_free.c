/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_expansion_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:30:53 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/20 15:25:16 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_expansion(t_expansion	*expansion)
{
	if (expansion)
	{
		if (expansion->value)
			free(expansion->value);
		free(expansion);
	}
}

void	free_list_expansion(t_expansion *expansion)
{
	t_expansion	*next;

	while (expansion)
	{
		next = expansion->next;
		free_expansion(expansion);
		expansion = next;
	}
}
