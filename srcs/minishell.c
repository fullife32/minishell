/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:25:24 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/25 10:14:07 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	
**	ATTENTION pas de doublon dans les variables d'environnements
**	ATTENTION lors de l'affichage des valeurs NULL : peut etre plus judicieux 
** de mettre "" que NULL ?
*/

int	main(int argc, char *argv[], char *env[])
{
	char	**minishell_env;

	(void)argc;
	(void)argv;
	minishell_env = make_minishell_env(env);
	make_terminal(&minishell_env);
	free_list(minishell_env);
	return (0); // EXIT STATUS
}
