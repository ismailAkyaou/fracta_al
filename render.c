/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iakyaou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:29:38 by iakyaou           #+#    #+#             */
/*   Updated: 2023/04/02 20:27:59 by iakyaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int render(t_data *data)
{
	int x = 0;
	int y = 0;

	mlx_destroy_image(data->ptr, data->img);
	mlx_clear_window(data->ptr, data->win);
	data->img = mlx_new_image(data->ptr, WIDTH, HEIGHT);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (data->status == MANDELBROT)
				mandelbrot(x, y, data);
			else if (data->status == JULIA)
				julia(x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->ptr, data->win, data->img, 0 , 0);
	return (0);
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void    ft_init(t_data *data, char **av)
{
	data->max_iteratins = 80;
	data->julia_arg.real = 0.15;
	data->julia_arg.imag = 0.58;
	data->zoom = 1;

	if (!(ft_strncmp(av[1], "mandelbrot", 11)))
	{
		if (data->ac == 2)
			data->status = MANDELBROT;
		else 
		{
			write(2, "ERROR", 5);
			exit(1);
		}
	}
	else if (!(ft_strncmp(av[1],"julia", 6)))
	{
		if (data->ac == 2)
			data->status = JULIA;
		else
		{
			write(2, "ERROR", 5);   
			exit(1);
		}
	}
	else
	{
		write (2, "ERROR\n", 5);
		exit(1);
	}
}