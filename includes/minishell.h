/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:24:41 by lvirgini          #+#    #+#             */
/*   Updated: 2021/09/14 15:22:08 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** includes lib headers
*/

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>

/*
** includes minishell headers
*/

# include "libft.h"
# include "test_minishell.h" //
# include "minishell_define.h"
# include "minishell_env.h"
# include "minishell_error.h"
# include "minishell_terminal.h"

int	make_terminal(void);
void		formatting_prompt(char *prompt, char *user, size_t size_max);

#endif
