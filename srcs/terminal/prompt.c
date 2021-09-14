/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:12:26 by lvirgini          #+#    #+#             */
/*   Updated: 2021/09/14 15:14:07 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		formatting_prompt(char *prompt, char *user, size_t size_max)
{
	char	pwd[256];
	size_t	len;

	getcwd(pwd, 256);
	len = ft_strlen(user) + ft_strlen(pwd) + PROMPT_FORMATTING_SIZE;
	if (len > size_max)
		len = size_max;
	ft_strlcpy(prompt, STR_COLOR_GREEN, 6);
	if (user)
		ft_strlcat(prompt, user, len);
	ft_strlcat(prompt, "\33[0m:", len);
	ft_strlcat(prompt, STR_COLOR_BLUE, len);
	if (pwd != '\0')
		ft_strlcat(prompt, pwd, len);
	ft_strlcat(prompt, STR_COLOR_STD, len);
	if (user && ft_strcmp(user, "root") == 0)
		ft_strlcat(prompt, "# ", len);
	else
		ft_strlcat(prompt, "$ ", len);
}