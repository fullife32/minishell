/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:27:28 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 21:12:08 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Verifie si le caractère (c) est alphabetique sur la table ASCII.
*/

int	ft_isalpha(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}
