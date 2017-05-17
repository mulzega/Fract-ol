/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulzega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:54:22 by mulzega           #+#    #+#             */
/*   Updated: 2017/05/16 17:50:19 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_init(t_env *e)
{
	WIDTH_WIN = 600;
	HEIGHT_WIN = 600;
	PADG = 0;
	PAHB = 0;
	SPEED = 1;
	ZOOM = 0;
	IM = 0;
	POS_X = 0;
	POS_Y = 0;
	NX = 0;
	NY = 0;
	IM = 0;
	SX = 0;
	SY = 0;
	V = 0;
	VARCOL = 16707089;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH_WIN, HEIGHT_WIN, "fract'ol_42");
	IMG = mlx_new_image(MLX, WIDTH_WIN, HEIGHT_WIN);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
	return (0);
}

int		ft_mouse_hook(int mousecode)
{
	if (mousecode == 2)
		ft_error(2);
	return (0);
}

int		mouse_motion(int x, int y, t_env *e)
{
	if ((FRAC == 2) && 0 <= x && WIDTH_WIN > x && 0 <= y && HEIGHT_WIN > y)
	{
		CR = (float)(x + 800 - WIDTH_WIN) / 1000;
		CI = (float)(y + 800 - HEIGHT_WIN) / 1000;
		ft_choose(e, 2);
	}
	return (0);
}

int		ft_error(int i)
{
	if (i == 1)
	{
		ft_putstr("No corresponding fractals\n You mean: ./fractol\n");
		ft_putstr(" [mandelbrot]\n [julia]\n [sierpinski]\n [burningship]\n");
	}
	if (i == 2)
		ft_putstr("Good Bye");
	exit(0);
}
