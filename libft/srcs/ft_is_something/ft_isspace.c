/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 11:06:00 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 18:03:33 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Vérifie si le caractere (c) est un caractere d'espacement.
*/

int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}
