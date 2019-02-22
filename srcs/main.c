/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 04:23:55 by vtudes            #+#    #+#             */
/*   Updated: 2018/03/09 04:23:57 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				set_ch(int argc, char **argv, t_mlx *st)
{
	if (argc <= 1 || argc > 2)
		return (1);
	ft_strcmp(argv[1], "mandelbrot") == 0 ? st->c.ch = 1 : 0;
	ft_strcmp(argv[1], "burningship") == 0 ? st->c.ch = 2 : 0;
	ft_strcmp(argv[1], "julia") == 0 ? st->c.ch = 3 : 0;
	ft_strcmp(argv[1], "hugulus") == 0 ? st->c.ch = 4 : 0;
	ft_strcmp(argv[1], "pmicelius") == 0 ? st->c.ch = 5 : 0;
	ft_strcmp(argv[1], "bacrozus") == 0 ? st->c.ch = 6 : 0;
	if (st->c.ch == 0)
		return (1);
	return (0);
}

int				initbonus(t_mlx *st)
{
	if (st->c.ch == 4)
	{
		st->c.x1 = -1.8;
		st->c.y1 = -1.6;
		st->c.x2 = 1.6;
		st->c.y2 = 1.6;
		st->c.c_i = 0.0099534;
	}
	if (st->c.ch == 2)
	{
		st->c.x1 = -2.1;
		st->c.y1 = -1.9;
		st->c.x2 = 0.5;
		st->c.y2 = 1.2;
	}
	if (st->c.ch == 5)
	{
		st->c.x1 = -1.8;
		st->c.y1 = -1.6;
		st->c.x2 = 1.6;
		st->c.y2 = 1.6;
		st->c.c_i = 0.597845;
	}
	return (0);
}

int				initbacrozus(t_mlx *st)
{
	if (st->c.ch == 6)
	{
		st->c.x1 = -1.8;
		st->c.y1 = -1.6;
		st->c.x2 = 1.6;
		st->c.y2 = 1.6;
		st->c.c_i = 0.0009123;
	}
	st->count = 0;
	return (0);
}

int				initialisations(t_mlx *st)
{
	st->c.iter = 35;
	st->c.zoom = 280;
	if (st->c.ch == 1)
	{
		st->c.x1 = -2.2;
		st->c.y1 = -1.6;
		st->c.x2 = 0.5;
		st->c.y2 = 1.2;
	}
	if (st->c.ch == 3)
	{
		st->c.x1 = -1.8;
		st->c.y1 = -1.7;
		st->c.x2 = 1;
		st->c.y2 = 1.2;
		st->c.c_i = 0.0099534;
	}
	initbacrozus(st);
	initbonus(st);
	return (0);
}

int				main(int argc, char **argv)
{
	t_mlx		st;

	switch_color(&st);
	st.bouton = 0;
	if (set_ch(argc, argv, &st) && st.c.ch != 1 &&
	st.c.ch != 2 && st.c.ch != 3 &&
	st.c.ch != 4 && st.c.ch != 5 && st.c.ch != 6)
	{
		ft_putstr("usage: ./Fractol \"mandelbrot\", \
\"burningship\", \"julia\", \"hugulus\", \"pmicelius\" ou \"bacrozus\"\n");
		return (1);
	}
	st.mlx = mlx_init();
	st.win = mlx_new_window(st.mlx, WIDTH, HEIGHT, "Fractol");
	st.img = mlx_new_image(st.mlx, WIDTH, HEIGHT);
	st.gda = mlx_get_data_addr(st.img, &st.bpx, &st.size, &st.end);
	initialisations(&st);
	mlx_key_hook(st.win, clear, &st);
	mlx_mouse_hook(st.win, &mouse_mouvements, &st);
	mlx_hook(st.win, 6, (1L << 6), &mouse_function, &st);
	mlx_hook(st.win, 2, (1L << 0), &key_function, &st);
	thread_launcher(&st);
	mlx_loop(st.mlx);
	return (0);
}
