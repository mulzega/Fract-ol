/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sierpinski.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulzega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 13:58:00 by mulzega           #+#    #+#             */
/*   Updated: 2017/05/11 13:58:03 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_calcski(t_env *e)
{
	ZI = fabsl(X + PADG + POS_X - NX);
	ZR = fabsl(Y + PAHB + POS_Y - NY);
	I = -1;
	while (((int)ZI % 3 != 1 || (int)ZR % 3 != 1) && ++I < ITERMAX)
	{
		ZI /= 3;
		ZR /= 3;
	}
	if (I != ITERMAX)
	{
		COLOR = 65792;
		ft_fill_img(e);
	}
	else
	{
		COLOR = (I * VARCOL / ITERMAX);
		ft_fill_img(e);
	}
}

void		ft_sierpinski(t_env *e)
{
	ITERMAX = IM + 40;
	X = -1;
	while (++X < WIDTH_WIN)
	{
		Y = -1;
		while (++Y < HEIGHT_WIN)
			ft_calcski(e);
	}
}
