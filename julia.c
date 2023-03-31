/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iakyaou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:53:25 by iakyaou           #+#    #+#             */
/*   Updated: 2023/03/31 20:45:57 by iakyaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void  julia(int a, int b, t_data *data)
{
    t_complex z;
    int iteration = 0;
    float tmp;

    z.real = (a - WIDTH/2) * (4.0 / WIDTH);
    z.imag = (b - HEIGHT/2) * (4.0 / HEIGHT);
    while (z.real * z.real + z.imag * z.imag < 4  &&  iteration < 80) 
    {
        tmp = z.real * z.real - z.imag * z.imag + data->julia_arg.real;
        z.imag = 2 * z.real * z.imag  + data->julia_arg.imag;
        z.real = tmp;
        iteration++;
    }
    if (iteration < 80)
    {
        my_mlx_pixel_put(data, a, b, 0x8BF5FA - iteration * 2000/80);
    }
}
