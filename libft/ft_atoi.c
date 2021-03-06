/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:21:01 by kromain           #+#    #+#             */
/*   Updated: 2017/01/13 16:48:08 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long long	s;
	int			n;

	n = 1;
	s = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			n = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		s = s * 10 + (*str);
		s = s - '0';
		str++;
	}
	return (n * s);
}
