/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:21:01 by kromain           #+#    #+#             */
/*   Updated: 2017/01/13 16:48:08 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlen(const char *s)
{
	int size;

	size = 0;
	if (*s == '-')
	{
		size++;
		s++;
	}
	while (*s && ft_isdigit(*s))
	{
		size++;
		s++;
	}
	return (size);
}
