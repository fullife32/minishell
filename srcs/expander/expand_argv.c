/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:09:02 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/20 19:50:57 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** add expansion and keep argv already good 
*/
/*
static char	**redesign_expansion_argv(char **old_argv, int index,
			char **expansion)
{
	size_t	old_len;
	size_t	expand_len;
	char	**new_argv;

	old_len = listlen(old_argv);
	expand_len = listlen(expansion);
	new_argv = malloc_list(old_len + expand_len);
	if (!new_argv)
		return (NULL);
	list_nmove(new_argv, old_argv, index);
	list_move(new_argv + index, expansion);
	list_move(new_argv + index + expand_len, old_argv + index + 1);
	new_argv[old_len + expand_len - 1] = NULL;
	free(old_argv[index]);
	free(old_argv);
	return (new_argv);
}*/
/*
char	**expand_argv(char **argv, char **env)
{
	size_t		i;
	char		**expansion;

	i = 0;
	while (argv[i])
	{
		if (need_expand_str(argv[i]))
		{
			expansion = NULL;
			expansion = expand_list(argv[i], env);
			argv = redesign_expansion_argv(argv, i, expansion);
			if (!argv)
				return (NULL);
		//	print_list(argv);
			free(expansion);
		}
		i++;
	}
	return (argv);
}
*/

char	**expand_argv(char **argv, char **env)
{
	(void)env;
	return (argv);
}
