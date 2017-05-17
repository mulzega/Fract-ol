/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract'ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulzega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 11:11:22 by mulzega           #+#    #+#             */
/*   Updated: 2017/05/16 17:22:46 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "../Libs/libft/libft.h"
# include </System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h>

# define MLX e->mlx
# define WIN e->win
# define IMG e->img
# define DATA e->data
# define BPP e->bpp
# define ENDIAN e->endian
# define SIZELINE e->sizeline
# define X e->x
# define Y e->y
# define X1	e->x1
# define Y1 e->y1
# define X2 e->x2
# define Y2 e->y2
# define WIDTH_WIN e->width_win
# define HEIGHT_WIN e->height_win
# define COLOR e->color
# define ITERMAX e->itermax
# define I e->i
# define CR e->cr
# define CI e->ci
# define ZR e->zr
# define ZOOM_X e->zoom_x
# define ZOOM_Y e->zoom_y
# define ZI e->zi
# define SPEED e->speed
# define T e->t
# define V e->v
# define NX e->nx
# define IM e->im
# define SX e->sx
# define SY e->sy
# define NY e->ny
# define POS_X e->pos_x
# define POS_Y e->pos_y
# define ZOOM e->zoom
# define VARCOL e->varcol
# define PADG e->padg
# define PAHB e->pahb
# define FRAC e->frac

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bpp;
	int			endian;
	int			sizeline;
	int			x;
	int			y;
	int			i;
	int			itermax;
	int			im;
	int			padg;
	int			pahb;
	int			sx;
	int			sy;
	int			zoom;
	int			width_win;
	int			height_win;
	int			color;
	int			varcol;
	int			frac;
	double		pos_x;
	double		pos_y;
	double		nx;
	double		ny;
	double		speed;
	double		cr;
	double		zoom_x;
	double		zoom_y;
	double		ci;
	double		zr;
	double		zi;
	double		t;
	double		v;
	double		x1;
	double		y1;
	double		x2;
	double		y2;
	char		*data;
}				t_env;

int				ft_init(t_env *e);
void			ft_frac(t_env *e);
int				mouse_motion(int x, int y, t_env *e);
int				main(int ac, char **av);
void			ft_fill_img(t_env *e);
void			ft_mandelbrot(t_env *e);
void			ft_julia(t_env *e);
void			ft_sierpinski(t_env *e);
void			ft_burningship(t_env *e);
void			ft_choose(t_env *e, int i);
int				ft_mouse_hook(int mousecode);
int				ft_error(int i);

#endif
