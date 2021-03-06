/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulzega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 13:58:47 by mulzega           #+#    #+#             */
/*   Updated: 2017/05/11 13:58:50 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_calcship(t_env *e)
{
	CR = (X + PADG + (ZOOM * SPEED) - NX) / (ZOOM_X) + X1;
	CI = (Y + PAHB + (ZOOM * SPEED) - NY) / (ZOOM_Y) + Y1;
	ZR = 0 + V;
	ZI = 0 + V / 2;
	I = -1;
	while ((ZR * ZR + ZI * ZI) < 4 && ++I < ITERMAX)
	{
		T = ZR;
		ZR = fabsl(ZR * ZR - ZI * ZI + CR);
		ZI = fabsl(2 * ZI * T + CI);
	}
	if (I == ITERMAX)
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

void		ft_burningship(t_env *e)
{
	X1 = -1 + POS_X;
	X2 = 1 + POS_X;
	Y1 = -1 + POS_Y;
	Y2 = 1 + POS_Y;
	ITERMAX = IM + 125;
	ZOOM_X = (WIDTH_WIN / (X2 - X1) + (ZOOM * SPEED));
	ZOOM_Y = (HEIGHT_WIN / (Y2 - Y1) + (ZOOM * SPEED));
	X = -1;
	while (++X < WIDTH_WIN)
	{
		Y = -1;
		while (++Y < HEIGHT_WIN)
			ft_calcship(e);
	}
}
