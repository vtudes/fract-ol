/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 04:24:53 by vtudes            #+#    #+#             */
/*   Updated: 2018/03/09 04:24:59 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			key_function(int kc, void *param)
{
	t_mlx	*st;

	st = (t_mlx*)param;
	if (kc == 34 || kc == 31 || kc == 18 || kc == 19 || kc == 20)
		key_function2(kc, st);
	if (kc == 12)
	{
		st->bouton = st->bouton == 1 ? 0 : 1;
		thread_launcher(st);
	}
	if (kc == 13 || kc == 0 || kc == 1 || kc == 2 || kc == 21)
	{
		st->actualcolor = (kc == 21 ? st->color4 : st->actualcolor);
		kc == 13 ? st->c.y1 += 10 / st->c.zoom : 0;
		kc == 0 ? st->c.x1 += 10 / st->c.zoom : 0;
		kc == 1 ? st->c.y1 -= 10 / st->c.zoom : 0;
		kc == 2 ? st->c.x1 -= 10 / st->c.zoom : 0;
		thread_launcher(st);
	}
	return (0);
}

int			clear(int kc, void *param)
{
	t_mlx	*st;
	int		repaint;

	repaint = 1;
	st = (t_mlx*)param;
	kc == 53 ? exit(0) : 0;
	if (kc == 3)
		st->bouton3 = st->bouton3 == 1 ? 0 : 1;
	else if (kc == 14)
		st->bouton2 = st->bouton2 == 1 ? 0 : 1;
	else if (kc == 49)
		initialisations(st);
	else if (kc == 6)
		st->bouton4 = st->bouton4 == 1 ? 0 : 1;
	else
		repaint = 0;
	if (repaint)
		thread_launcher(st);
	return (0);
}

int			mouse_function(int x, int y, void *param)
{
	t_mlx	*st;

	st = (t_mlx *)param;
	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return (0);
	if (st->bouton == 0)
		x > 250 && x < 750 && y > 250 && y < 750 ?
		st->c.c_i += 0.005 : (st->c.c_i -= 0.005);
	thread_launcher(st);
	return (0);
}

static void	switch_fractal(t_mlx *st, int x, int y, int kc)
{
	int		ch;

	ch = st->c.ch;
	x > 840 && x < 950 && y > 2 && y &&
	kc == 1 < 20 ? st->c.ch = 1 : 0;
	x > 840 && x < 950 && y > 30 && y &&
	kc == 1 < 60 ? st->c.ch = 3 : 0;
	x > 840 && x < 950 && y > 80 && y &&
	kc == 1 < 100 ? st->c.ch = 2 : 0;
	x > 840 && x < 950 && y > 130 && y
	&& kc == 1 < 150 ? st->c.ch = 6 : 0;
	x > 840 && x < 950 && y > 160 &&
	y && kc == 1 < 190 ? st->c.ch = 5 : 0;
	x > 840 && x < 950 && y > 200
	&& y && kc == 1 < 220 ? st->c.ch = 4 : 0;
	if (ch != st->c.ch)
	{
		initialisations(st);
		thread_launcher(st);
	}
}

int			mouse_mouvements(int kc, int x, int y, int *param)
{
	t_mlx	*st;

	st = (t_mlx *)param;
	st->m.tmpx = (x / st->c.zoom) + st->c.x1;
	st->m.tmpy = (y / st->c.zoom) + st->c.y1;
	if (kc && x > 0 && y > 0 && st->bouton3 != 1)
	{
		if (st->bouton4 == 1)
			surprise(st);
		kc == 4 || kc == 1 ? st->c.zoom /= 0.8 : 0;
		kc == 4 || kc == 1 ? st->count++ : 0;
		kc == 5 || kc == 2 ? st->count-- : 0;
		kc == 5 || kc == 2 ? st->c.zoom *= 0.8 : 0;
		st->c.x1 = st->m.tmpx - (x / st->c.zoom);
		st->c.y1 = st->m.tmpy - (y / st->c.zoom);
		thread_launcher(st);
	}
	if (st->bouton3 == 1)
		switch_fractal(st, x, y, kc);
	return (0);
}
