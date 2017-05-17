/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulzega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:50:06 by mulzega           #+#    #+#             */
/*   Updated: 2017/03/24 14:50:08 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_cast_nbr(char *str)
{
	double	res;
	double	dec;

	res = 0;
	while (*str && (*str >= '0') && (*str <= '9'))
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	if (*str == '.')
	{
		str++;
		dec = 10;
		while (*str && (*str >= '0') && (*str <= '9'))
		{
			res += ((*str - 48) / dec);
			dec *= 10;
			str++;
		}
	}
	return (res);
}

double			ft_atof(const char *str)
{
	char *ps;

	ps = (char *)str;
	if (ps == NULL)
		return (0);
	while (*ps && (*ps == ' ' || *ps == '\t' || *ps == '\n' || *ps == '\v' ||
			*ps == '\f' || *ps == '\r'))
		ps++;
	if (*ps && ((*ps >= '0' && *ps <= '9') || *ps == '.'))
		return (ft_cast_nbr(ps));
	else if (*ps && *ps == '+')
		return (ft_cast_nbr(++ps));
	else if (*ps && *ps == '-')
		return (ft_cast_nbr(++ps) * -1);
	else
		return (0);
}
