/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulzega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 11:08:48 by mulzega           #+#    #+#             */
/*   Updated: 2017/05/16 17:49:18 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		ft_error(2);
	if (keycode == 12 && ZOOM >= -50)
		ZOOM = ZOOM - 50;
	if (keycode == 13)
		ZOOM = ZOOM + 50;
	if (keycode == 124)
		PADG = PADG + 25;
	if (keycode == 123)
		PADG = PADG - 25;
	if (keycode == 126)
		PAHB = PAHB - 25;
	if (keycode == 125)
		PAHB = PAHB + 25;
	if (keycode == 7)
		IM = IM + 5;
	if (keycode == 6 && IM > 5)
		IM = IM - 5;
	mlx_clear_window(MLX, WIN);
	ft_choose(e, 6);
	return (0);
}

void	ft_fill_img(t_env *e)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (COLOR)
	{
		r = COLOR >> 0;
		g = COLOR >> 8;
		b = COLOR >> 16;
	}
	else
	{
		r = 0x000000 >> 16;
		g = 0x000000 >> 8;
		b = 0x000000 >> 0;
	}
	if (X >= 0 && X < WIDTH_WIN && Y > 0 && Y < HEIGHT_WIN)
	{
		DATA[Y * SIZELINE + X * (BPP / 8)] = r;
		DATA[Y * SIZELINE + X * (BPP / 8) + 1] = g;
		DATA[Y * SIZELINE + X * (BPP / 8) + 2] = b;
	}
}

void	ft_choose(t_env *e, int i)
{
	if (i < 6 && i > 0)
		FRAC = i;
	if (FRAC == 1)
		ft_mandelbrot(e);
	if (FRAC == 2)
		ft_julia(e);
	if (FRAC == 4)
		ft_sierpinski(e);
	if (FRAC == 5)
		ft_burningship(e);
	ft_frac(e);
}

void	ft_frac(t_env *e)
{
	mlx_hook(WIN, 2, KeyPressMask, ft_key_hook, e);
	mlx_hook(WIN, 6, 2, mouse_motion, e);
	mlx_hook(WIN, 4, ButtonPressMask, ft_mouse_hook, e);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	mlx_loop(MLX);
}

int		main(int ac, char **av)
{
	t_env e;

	if (ac == 2)
	{
		ft_init(&e);
		if (ft_strequ(av[1], "mandelbrot") == 1)
			ft_choose(&e, 1);
		else if (ft_strequ(av[1], "julia") == 1)
			ft_choose(&e, 2);
		else if (ft_strequ(av[1], "sierpinski") == 1)
			ft_choose(&e, 4);
		else if (ft_strequ(av[1], "burningship") == 1)
			ft_choose(&e, 5);
		else
			ft_error(1);
	}
	if (ac != 2)
		ft_error(1);
	return (0);
}
