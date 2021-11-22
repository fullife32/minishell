/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:58:59 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/10 16:59:09 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Init prompt : 
**
** Only used at the first time
*/

t_prompt	*init_prompt(char *user, char *pwd)
{
	t_prompt	*prompt;

	prompt = (t_prompt *)malloc(sizeof(t_prompt));
	if (!prompt)
	{
		perror("malloc init_prompt())");
		return (NULL);
	}
	ft_memset(prompt, 0,  sizeof(t_prompt));
	if (user)
	{
		prompt->user = ft_strdup(user);
		if (!prompt->user)
			perror("malloc init_prompt())");
	}
	if (pwd)
	{
		prompt->cwd = ft_strdup(pwd);
		if (!prompt->cwd)
			perror("malloc init_prompt())");
	}
	layout_prompt(prompt);
	return (prompt);
}

/*
** Free all inside the t_prompt
*/

void	free_t_prompt(t_prompt *prompt)
{
	if (prompt)
	{	
		if (prompt->user)
			free(prompt->user);
		if (prompt->cwd)
			free(prompt->cwd);
		if (prompt->formatted)
			free(prompt->formatted);
		free(prompt);
	}	
}
