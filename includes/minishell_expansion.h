/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_expansion.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:38:57 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/29 16:52:08 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_EXPANSION_H
# define MINISHELL_EXPANSION_H

/*
** Don't keep all this for 21sh or 42sh. recode it.
*/

# define STR_ESCAPE	" \t\n"
# define STR_ESCAPE_IN_DQUOTES "$\"\\`"
# define BACKSLASH	'\\'
# define GRAVE_ACCENT '`'
# define NB_EXPANDER	3

typedef struct s_expansion	t_expansion;

/*
**	t_expansion : 
**	from a string, the expansion structure allows to get the value 
**	of the expansion.
**		start of expansion: is the index of the string where the expansion
**	must be done
**		size to remove: is the length to remove.
*/

typedef t_expansion			*(*t_ft_expand)(char *s, char **env);
struct s_expansion
{
	t_expansion	*next;
	char		**value;
	size_t		start_of_the_expand;
	size_t		size_to_remove;
};

/*
** init and free t_expansion
*/

t_expansion	*malloc_expansion(void);
t_expansion	*malloc_expansion_and_value(int size);
void		free_list_expansion(t_expansion *expansion);
t_expansion	*add_back_expansion(t_expansion *first, t_expansion *to_add);

/*
** expansing functions
*/

int			expanser(t_cmd **list_cmd, char **env);
int			expand_argv(t_cmd *cmd, char **env);
t_bool		redesign_argv(char **new, char **old,
				t_expansion *expansion, int *index);
int			expand_redirection(t_redir *redir, char **env);
char		*expand_heredoc_line(char *line, char **env);

/*
** get expansion
*/

char		*fusion_str_expansion(char *old_s, t_expansion *expansion);
t_expansion	*expand_str(char *s, char **env);
t_expansion	*get_expansion(char *s, char **env);
t_expansion	*expand_simple_quote(char *s, char **env);
t_expansion	*expand_double_quote(char *s, char **env);
t_expansion	*expand_dollar(char *s, char **env, int is_in_double_quotes);
t_expansion	*expand_dollar_in_double_quotes(char *s, char **env, int max);
t_expansion	*expand_dollar_in_argv(char *s, char **env);
t_expansion	*dollar_is_dollar(void);

/*
** Useful functions for t_expansion
*/

t_bool		is_expansion(char c);
t_bool		need_expand(char *s);
size_t		get_expand_removed_len(t_expansion *expansion);
size_t		dollar_len(char *s);
t_bool		is_dollar_env_value_syntax(char c);
char		isolate_key(char *s, t_expansion *expansion);
size_t		count_expansion_split(t_expansion *expansion);

#endif
