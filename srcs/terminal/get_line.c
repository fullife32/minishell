/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:10:57 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/25 10:13:05 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** il faut trouver un bon nom pour cette fonction...
*/

void	make_shell(char *line, char ***env)
{
	t_token		**token;
	t_cmd		**cmd;

	token = NULL;
	cmd = NULL;
	token = lexer_minishell(line);
	cmd = parser_minishell(token);
	free_list_token(token);
	if (expanser(cmd, *env) && cmd)
	{
		if (executer(cmd, env) == FAILURE)
			exit_minishell(cmd, *env);
	}
	free_list_cmd(cmd);
}

/*
** premier appel : get_prompt va creer t_prompt via l'environnement récuperé
** while 1 -> pour le moment pas d'arret // voir les signaux
** readline renvoi la ligne saisie
** si la ligne n'est pas vide on la rajoute a l'historique (cmd de readline)
*/

int	make_terminal(char ***env)
{
	char		*line;
	t_prompt	*prompt;

	prompt = get_prompt(*env, NULL);
	while (1)
	{
		line = NULL;
		line = readline(prompt->formatted);
		if (line)
		{
			if (*line)
			{
				if (ft_strcmp(line, "exit") == 0) // EXIT PROVISOIRE POUR VOIR LES LEAKS
				{
					free(line);
					free_t_prompt(prompt);
					rl_clear_history();
					return (SUCCESS);
				}
				add_history(line);
				make_shell(line, env);
			}
			prompt = get_prompt(*env, prompt);
			free(line);
		}
		else
			printf("\n");
	}
	free_t_prompt(prompt);
}
