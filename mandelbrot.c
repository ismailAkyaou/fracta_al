/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iakyaou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 03:48:43 by iakyaou           #+#    #+#             */
/*   Updated: 2023/03/29 21:19:42 by iakyaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void  mandelbrot(int a, int b, t_data *data)
{
    float zx = 0;
    float zy = 0;
    int iteration = 0;
    float cy;
    float cx;
    float tmp;
    
    cx = (a - WIDTH/2) * (4.0 / WIDTH);
    cy = (b - HEIGHT/2) * (3.0 / HEIGHT);
    while (zx * zx + zy * zy < 4  &&  iteration < 80) 
    {
        tmp = zx * zx - zy * zy + cx;
        zy = 2 * zx * zy  + cy;
        zx = tmp;
        iteration++;
    }
    if (iteration < 80)
        my_mlx_pixel_put(data, a, b, 0x362FD9 - iteration * 1080/80);
}
