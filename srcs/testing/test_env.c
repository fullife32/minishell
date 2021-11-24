/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:29:10 by lvirgini          #+#    #+#             */
/*   Updated: 2021/11/24 17:15:50 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	testing_get_env_value(char **env)
{
	char	*ptr;

//// ATTENTION CA SEGFAULT SI NULL EST RETOURNE
//	printf("%s\n", get_env_value(env, "USER")); 

	ptr = get_env_value(env, "USER");
	ft_putstr(ptr);

	ptr = get_env_value(env, "PATH");
	ft_putstr(ptr);

	ptr = get_env_value(env, "");
	ft_putstr(ptr);

	ptr = get_env_value(env, "       ");
	ft_putstr(ptr);
}

void	testing_env(char **env)
{
	char **myenv;

	myenv = make_minishell_env(env);
	testing_get_env_value(myenv);
//	print_list_env(env);
	print_str(myenv[get_env_index(myenv, "USER")]);
	// myenv = add_env(myenv, "TEST", "test");
	print_str(myenv[get_env_index(myenv, "TEST")]);
	// myenv = add_env(myenv, "TEST", "deuxieme");
	print_str(myenv[get_env_index(myenv, "TEST")]);

	free_list(myenv);
}