/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_all_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:32:01 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/24 17:16:12 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** SYNTAX ERROR from redirections : 
**
** if no token after redirection : it's the end of line
** if token after is another redirection or operator
*/

int	syntax_error_redirection(t_token *token)
{
	if (!token->next)
	{
		print_syntax_error(ERR_SYMBOL, '\0', NULL);
		return (SYNTAX_ERROR);
	}
	if (is_token_words(token->next->type) == false)
	{
		print_syntax_error(ERR_SYMBOL, 0, token->next->word);
		return (SYNTAX_ERROR);
	}
	return (SUCCESS);
}

void	change_heredoc_priority(t_hdoc *heredoc, int type)
{
	if (type == INPUT_REDIRECTION || type == HERE_DOC)
	{
		while (heredoc)
		{
			heredoc->priority--;
			heredoc = heredoc->next;
		}
	}
}

int	parse_redirection(t_cmd *cmd, t_token *token)
{
	t_redir	*redir;

	if (syntax_error_redirection(token) == SYNTAX_ERROR)
		return (SYNTAX_ERROR);
	redir = create_redir(token->type, token->next->word);
	if (!redir)
		return (FAILURE);
	change_heredoc_priority(cmd->heredoc, redir->type);
	if (!cmd->redir)
		cmd->redir = redir;
	else
		struct_add_back(cmd->redir, redir);
	return (SUCCESS);
}

t_bool	is_token_redirection(int type)
{
	if (type == APPEND || type == INPUT_REDIRECTION
		|| type == OUTPUT_REDIRECTION || type == HERE_DOC)
		return (true);
	return (false);
}


int	parse_heredoc(t_cmd *cmd, t_token *token)
{
	t_hdoc	*heredoc;

	if (syntax_error_redirection(token) == SYNTAX_ERROR)
		return (SYNTAX_ERROR);
	heredoc = create_heredoc(token->next->word);
	if (!heredoc)
		return (FAILURE);
	change_heredoc_priority(cmd->heredoc, HERE_DOC);
	if (cmd->heredoc)
		struct_add_back(cmd->heredoc, heredoc);
	else
		cmd->heredoc = heredoc;
	return (SUCCESS);
}
/*
** Parser of all redirection for minishell : < << > >>
** check the syntax of each redirection
** remove used tokens
*/

int	parse_all_redirection(t_cmd *cmd, t_token **list_token)
{
	t_token	*token;
	int		syntax;

	token = *list_token;
	while (token && is_token_control_operator(token->type) == false)
	{
		syntax = SUCCESS;
		if (token->type == HERE_DOC)
		{
			syntax = parse_heredoc(cmd, token);
			token = remove_multi_token(list_token, token, 2);
		}
		else if (is_token_redirection(token->type) == true)
		{
			syntax = parse_redirection(cmd, token);
			token = remove_multi_token(list_token, token, 2);
		}
		else
			token = token->next;
		if (syntax != SUCCESS)
			return (FAILURE);
	}
	return (SUCCESS);
}

/*
int	parse_all_redirection(t_cmd *cmd, t_token **list_token)
{
	t_token	*token;
	int		syntax;

	token = *list_token;
	while (token && is_token_control_operator(token->type) == false)
	{
		syntax = SUCCESS;
		if (token->type == INPUT_REDIRECTION || token->type == HERE_DOC)
		{
			syntax = parse_input(cmd, token);
			token = remove_multi_token(list_token, token, 2);
		}	
		else if (token->type == OUTPUT_REDIRECTION || token->type == APPEND)
		{
			syntax = parse_output(cmd, token);
			token = remove_multi_token(list_token, token, 2);
		}
		else
			token = token->next;
		if (syntax != SUCCESS)
			return (FAILURE);
	}
	return (SUCCESS);
}
*/