/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:56:31 by kromain           #+#    #+#             */
/*   Updated: 2017/01/06 19:03:47 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tolower(int c)
{
	int b;

	b = c;
	if (b >= 65 && b <= 90)
	{
		b += 32;
		return (b);
	}
	return (c);
}