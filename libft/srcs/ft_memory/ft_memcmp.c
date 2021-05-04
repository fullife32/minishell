/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:33:13 by lvirgini          #+#    #+#             */
/*   Updated: 2019/12/13 10:10:20 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** Compare les deux zones mémoires (*s1), (*s2) sur n octets.
** Retourne la différence de valeur.
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *p1;
	const unsigned char *p2;

	p1 = s1;
	p2 = s2;
	if (n <= 0)
		return (0);
	return (*p1 != *p2 ? *p1 - *p2 : ft_memcmp(++p1, ++p2, --n));
}
