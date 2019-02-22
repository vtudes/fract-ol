/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 04:24:28 by vtudes            #+#    #+#             */
/*   Updated: 2018/03/09 04:24:29 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		switch_color(t_mlx *st)
{
	st->color1 = 0x889499;
	st->color2 = 0x788757;
	st->color3 = 0x948977;
	st->color4 = 0x766564;
	st->actualcolor = st->color1;
}

int			color(int a, int i)
{
	i += a;
	if (a < 14)
		return (2 * i + 2);
	if (a > 30 && a < 40)
		return (13 * i - 11);
	if (a > 50 && a < 60)
		return (7 * i + 1);
	if (a > 100)
		return (21 * i - 9);
	return (19 * i - 5);
}

void		calculus(t_mlx st, int x, int y)
{
	st.c.c_r = x / st.c.zoom + st.c.x1;
	st.c.c_i = y / st.c.zoom + st.c.y1;
	st.c.z_r = 0;
	st.c.z_i = 0;
	st.c.i = 0;
	while (st.c.z_r * st.c.z_r + st.c.z_i *
		st.c.z_i < 4 && st.c.i < st.c.iter)
	{
		st.c.tmp = st.c.z_r;
		st.c.z_r = st.c.z_r * st.c.z_r - st.c.z_i * st.c.z_i + st.c.c_r;
		st.c.z_i = 2 * st.c.z_i * st.c.tmp + st.c.c_i;
		st.c.i += 1;
	}
	if (st.c.i == st.c.iter)
		*(unsigned*)(st.gda + (int)x * (st.bpx / 8)
				+ (int)y * st.size) = 0xFF000000;
	else
		*(unsigned*)(st.gda + (int)x * (st.bpx / 8) +
		(int)y * st.size) = st.actualcolor * color(st.c.color, st.c.i);
}

void		mandelbrot(t_mlx st, int tx, int ty)
{
	int		x;
	int		y;

	x = tx - 1;
	while (++x < st.c.imgx && x < tx + BLOCK_WIDTH)
	{
		y = ty - 1;
		while (++y < st.c.imgy && y < ty + BLOCK_HEIGHT)
			calculus(st, x, y);
	}
}
