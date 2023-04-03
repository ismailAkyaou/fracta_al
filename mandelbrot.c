/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iakyaou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 03:48:43 by iakyaou           #+#    #+#             */
/*   Updated: 2023/04/03 20:09:23 by iakyaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(int a, int b, t_data *data)
{
	float		zx;
	float		zy;
	int			iteration;
	t_complex	z;

	zx = 0;
	zy = 0;
	iteration = 0;
	z.cx = (a - WIDTH / 2) * (4.0 / WIDTH * data->zoom);
	z.cy = (b - HEIGHT / 2) * (3.0 / HEIGHT * data->zoom);
	while (zx * zx + zy * zy < 4 && iteration < 80)
	{
		z.tmp = zx * zx - zy * zy + z.cx;
		zy = 2 * zx * zy + z.cy;
		zx = z.tmp;
		iteration++;
	}
	if (iteration < 80)
	{
		my_mlx_pixel_put(data, a, b, 0x865DFF - iteration * 1080 / 80);
	}
}
