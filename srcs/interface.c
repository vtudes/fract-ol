/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 07:16:41 by vtudes            #+#    #+#             */
/*   Updated: 2018/03/09 07:16:43 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		interface3(t_mlx *mlx)
{
	char	*q;
	char	*f;
	char	*z;

	q = ft_itoa(mlx->bouton);
	f = ft_itoa(mlx->bouton3);
	z = ft_itoa(mlx->bouton4);
	mlx_string_put(mlx->mlx, mlx->win, 10, 50, 0xFFFFFF,
		"Statut de Q :");
	mlx_string_put(mlx->mlx, mlx->win, 150, 50, 0xFFFFFF, q);
	mlx_string_put(mlx->mlx, mlx->win, 10, 70, 0xFFFFFF,
		"Statut de F :");
	mlx_string_put(mlx->mlx, mlx->win, 150, 70, 0xFFFFFF, f);
	mlx_string_put(mlx->mlx, mlx->win, 10, 90, 0xFFFFFF,
		"Status de Z :");
	mlx_string_put(mlx->mlx, mlx->win, 150, 90, 0xFFFFFF, z);
	free(q);
	free(f);
	free(z);
}

void		interface2(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 10, 880, 0xFFFFFF,
		"Arreter deplacement auto avec Q");
	mlx_string_put(mlx->mlx, mlx->win, 10, 900, 0xFFFFFF,
		"Faire apparaitre le menu de fractales avec F");
	mlx_string_put(mlx->mlx, mlx->win, 10, 920, 0xFFFFFF,
		"Pour switch de fractale depuis le menu, \
cliquez sur le nom de celle-ci");
	mlx_string_put(mlx->mlx, mlx->win, 10, 940, 0xFFFFFF,
		"Surprise avec Z!");
	mlx_string_put(mlx->mlx, mlx->win, 10, 820, 0xFFFFFF,
		"Faire disparaitre l'interface avec E");
	mlx_string_put(mlx->mlx, mlx->win, 10, 800, 0xFFFFFF,
		"Changer de palette de couleur avec 1, 2. 3 et 4");
}

void		interface(t_mlx *mlx)
{
	char	*count;
	char	*iter;

	count = ft_itoa(mlx->count);
	iter = ft_itoa(mlx->c.iter);
	mlx_string_put(mlx->mlx, mlx->win, 10, 10, 0xFFFFFF,
		"Nombre de zooms     :");
	mlx_string_put(mlx->mlx, mlx->win, 225, 10, 0xFFFFFF, count);
	mlx_string_put(mlx->mlx, mlx->win, 10, 30, 0xFFFFFF,
		"Nombre d'iterations :");
	mlx_string_put(mlx->mlx, mlx->win, 225, 30, 0xFFFFFF, iter);
	mlx_string_put(mlx->mlx, mlx->win, 10, 840, 0xFFFFFF,
		"Se deplacer avec W, A, S, D");
	mlx_string_put(mlx->mlx, mlx->win, 10, 860, 0xFFFFFF,
		"Zoomer avec click gauche, click droit, et molette de la souris");
	free(count);
	free(iter);
	if (mlx->bouton3 == 1)
		print_fractal_names(mlx);
	interface2(mlx);
	interface3(mlx);
}

void		print_fractal_names(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 850, 10, 0xFFFFFF, "Mandelbrot");
	mlx_string_put(mlx->mlx, mlx->win, 850, 50, 0xFFFFFF, "Julia");
	mlx_string_put(mlx->mlx, mlx->win, 850, 90, 0xFFFFFF, "Burningship");
	mlx_string_put(mlx->mlx, mlx->win, 850, 130, 0xFFFFFF, "Bacrozus");
	mlx_string_put(mlx->mlx, mlx->win, 850, 170, 0xFFFFFF, "Pmicelius");
	mlx_string_put(mlx->mlx, mlx->win, 850, 210, 0xFFFFFF, "Hugulus");
}

void		key_function2(int kc, t_mlx *st)
{
	st->actualcolor = (kc == 18 ? st->color1 : st->actualcolor);
	st->actualcolor = (kc == 19 ? st->color2 : st->actualcolor);
	st->actualcolor = (kc == 20 ? st->color3 : st->actualcolor);
	kc == 34 ? st->c.iter++ : 0;
	kc == 31 ? st->c.iter-- : 0;
	if (st->bouton4 == 1)
		surprise(st);
	thread_launcher(st);
}
