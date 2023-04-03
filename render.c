/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iakyaou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:29:38 by iakyaou           #+#    #+#             */
/*   Updated: 2023/04/03 20:50:00 by iakyaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	render(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
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
	mlx_put_image_to_window(data->ptr, data->win, data->img, 0, 0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->lin + x * (data->bt / 8));
	*(unsigned int *)dst = color;
}

void	ft_inis(t_data *data)
{
	data->max_iteratins = 80;
	data->julia_arg.real = 0.15;
	data->julia_arg.imag = 0.58;
	data->zoom = 1;
}

void	eroor(void)
{
	write(2, "ERROR", 5);
	exit(1);
}

void	ft_init(t_data *data, char **av)
{
	ft_inis(data);
	if (!(ft_strncmp(av[1], "mandelbrot", 11)))
	{
		if (data->ac == 2)
			data->status = MANDELBROT;
		else
			eroor();
	}
	else if (!(ft_strncmp(av[1], "julia", 6)))
	{
		if (data->ac == 2)
			data->status = JULIA;
		else
			eroor();
	}
	else
		eroor();
}
