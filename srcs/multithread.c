/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 04:25:12 by vtudes            #+#    #+#             */
/*   Updated: 2018/03/09 04:25:13 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				*startingpoint(void *param)
{
	t_thread_data	*data;
	int				tx;
	int				ty;

	data = (t_thread_data *)param;
	tx = (data->block_id % data->mlx->blocks_width) * BLOCK_WIDTH;
	ty = (data->block_id / data->mlx->blocks_height) * BLOCK_HEIGHT;
	data->mlx->c.ch == 1 ? mandelbrot(*(data->mlx), tx, ty) : 0;
	data->mlx->c.ch == 2 ? burningship(*(data->mlx), tx, ty) : 0;
	data->mlx->c.ch == 3 ? julia(*(data->mlx), tx, ty) : 0;
	data->mlx->c.ch == 4 ? hugulus(*(data->mlx), tx, ty) : 0;
	data->mlx->c.ch == 5 ? pmicelius(*(data->mlx), tx, ty) : 0;
	data->mlx->c.ch == 6 ? bacrozus(*(data->mlx), tx, ty) : 0;
	free(data);
	pthread_exit(NULL);
}

void				thread_declarations(t_mlx *mlx)
{
	mlx->c.imgx = WIDTH;
	mlx->c.imgy = HEIGHT;
	mlx->c.color = 0;
	mlx->blocks_width = (mlx->c.imgx / BLOCK_WIDTH) +
	((mlx->c.imgx % BLOCK_WIDTH) > 0 ? 1 : 0);
	mlx->blocks_height = (mlx->c.imgy / BLOCK_HEIGHT) +
	((mlx->c.imgy % BLOCK_HEIGHT) > 0 ? 1 : 0);
}

static int			spawn_threads(int *block_id, pthread_t *thread, t_mlx *mlx)
{
	int				count;
	t_thread_data	*data;

	count = -1;
	while (++count < 8 && *block_id < mlx->blocks_width * mlx->blocks_height)
	{
		data = (t_thread_data *)ft_memalloc(sizeof(t_thread_data));
		data->mlx = mlx;
		data->block_id = *block_id;
		pthread_create(&thread[count], NULL, startingpoint, data);
		(*block_id)++;
	}
	return (count);
}

void				thread_launcher(t_mlx *mlx)
{
	int				block_id;
	int				count;
	int				count2;
	pthread_t		thread[8];

	thread_declarations(mlx);
	block_id = 0;
	while (block_id < mlx->blocks_width * mlx->blocks_height)
	{
		count = spawn_threads(&block_id, thread, mlx);
		count2 = -1;
		while (++count2 < count)
			pthread_join(thread[count2], NULL);
	}
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	if (mlx->bouton2 == 0)
		interface(mlx);
}
