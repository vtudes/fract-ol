/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 04:23:33 by vtudes            #+#    #+#             */
/*   Updated: 2018/03/09 04:23:41 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>
# include <time.h>

# define ABS(x) (x > 0.0 ? x : -x)
# define HEIGHT 1000
# define WIDTH 1000

typedef	struct		s_mouse
{
	int				i;
	double			tmpx;
	double			tmpy;
}					t_mouse;

typedef	struct		s_calc
{
	double			x;
	double			y;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	int				imgx;
	int				imgy;
	double			tx;
	double			ty;
	int				iter;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			i;
	double			zoom;
	double			tmp;
	double			tmp2;
	int				color;
	int				ch;
}					t_calc;

typedef	struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				bpx;
	double			fx;
	double			fy;
	int				size;
	int				end;
	int				actualcolor;
	int				color1;
	int				color2;
	int				color3;
	int				color4;
	int				blocks_width;
	int				blocks_height;
	char			*gda;
	int				count;
	unsigned int	fps;
	unsigned int	start;
	int				bouton;
	int				bouton2;
	int				bouton3;
	int				bouton4;
	struct s_calc	c;
	struct s_mouse	m;
}					t_mlx;

# define BLOCK_HEIGHT 150
# define BLOCK_WIDTH 150

typedef struct		s_thread_data
{
	t_mlx			*mlx;
	int				block_id;
}					t_thread_data;

void				surprise(t_mlx *st);
void				print_fractal_names(t_mlx *mlx);
void				switch_color(t_mlx *st);
void				mandelbrot(t_mlx st, int tx, int ty);
void				bacrozus(t_mlx st, int tx, int ty);
void				julia(t_mlx st, int tx, int ty);
void				burningship(t_mlx st, int tx, int ty);
void				hugulus(t_mlx st, int tx, int ty);
void				pmicelius(t_mlx st, int tx, int ty);
t_mlx				calc(t_mlx st);
void				key_function2(int kc, t_mlx *st);
int					key_function(int kc, void *param);
int					clear(int kc, void *param);
int					mouse_function(int x, int y, void *param);
int					mouse_mouvements(int kc, int x, int y, int *param);
void				*startingpoint(void *param);
void				thread_launcher(t_mlx *mlx);
int					color(int a, int i);
void				interface(t_mlx *mlx);
int					initbonus(t_mlx *st);
int					initialisations(t_mlx *st);

#endif
