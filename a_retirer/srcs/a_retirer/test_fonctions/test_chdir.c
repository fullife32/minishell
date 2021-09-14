/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_chdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:10:20 by lvirgini          #+#    #+#             */
/*   Updated: 2021/05/16 14:11:00 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_minishell.h"

void		test_chdir(char **env)
{
	(void)env;
	test_get_cwd();
	int ret = chdir("/home");
	printf("return CHDIR = %d\n", ret);
	test_get_cwd();
}
