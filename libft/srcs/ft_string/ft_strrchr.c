/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:49:48 by lvirgini          #+#    #+#             */
/*   Updated: 2019/12/12 15:57:10 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**  Recherche le caractère (c) dans la chaine de caractère (*s)
**  Retourne un pointeur sur la dernière occurence.
*/

char		*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
		++i;
	while (i >= 0 && c != s[i])
		--i;
	return (i < 0 ? (NULL) : (char *)&s[i]);
}
