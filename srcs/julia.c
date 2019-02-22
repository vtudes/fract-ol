/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 04:23:46 by vtudes            #+#    #+#             */
/*   Updated: 2018/03/09 04:23:50 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		calcjul(t_mlx *st)
{
	st->c.tmp = st->c.z_r;
	st->c.z_r = st->c.z_r * st->c.z_r - st->c.z_i * st->c.z_i + st->c.c_r;
	st->c.z_i = 2 * st->c.z_i * st->c.tmp + st->c.c_i;
	st->c.i += 1;
}

void			julia(t_mlx st, int tx, int ty)
{
	int			x;
	int			y;

	x = tx - 1;
	while (++x < st.c.imgx && x < tx + BLOCK_WIDTH)
	{
		y = ty - 1;
		while (++y < st.c.imgy && y < ty + BLOCK_HEIGHT)
		{
			st.c.c_r = -1.417022285628;
			st.c.z_r = x / st.c.zoom + st.c.x1;
			st.c.z_i = y / st.c.zoom + st.c.y1;
			st.c.i = 0;
			while (st.c.z_r * st.c.z_r + st.c.z_i *
					st.c.z_i < 4 && st.c.i < st.c.iter)
				calcjul(&st);
			if (st.c.i == st.c.iter)
				*(unsigned*)(st.gda + (int)x * (st.bpx / 8)
						+ (int)y * st.size) = 0xFF000000;
			else
				*(unsigned*)(st.gda + (int)x * (st.bpx / 8) +
				(int)y * st.size) = st.actualcolor * color(st.c.color, st.c.i);
		}
	}
}

void			surprise(t_mlx *st)
{
	if (st->actualcolor == st->color4)
		st->actualcolor = st->color1;
	else if (st->actualcolor == st->color1)
		st->actualcolor = st->color2;
	else if (st->actualcolor == st->color2)
		st->actualcolor = st->color3;
	else if (st->actualcolor == st->color3)
		st->actualcolor = st->color4;
}
