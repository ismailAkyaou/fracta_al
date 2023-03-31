/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iakyaou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:37:00 by iakyaou           #+#    #+#             */
/*   Updated: 2023/03/31 20:44:44 by iakyaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_hook(int button, int x,int y, t_data *data)
{
    if (button == 1 && data->status == 2)
    {
        data->julia_arg.real = (x - WIDTH/2) * (4.0 / WIDTH);
        data->julia_arg.imag = (y - HEIGHT/2) * (4.0 / HEIGHT);
        render(data);
        // puts("yes yes");
    }
    return (0);
}

// void leaks()
// {
//     system("leaks fractal");
// }
int main(int ac, char **av)
{
    t_data data;
    data.ac = ac;
    // atexit(leaks);
    if (ac >= 2)
    {
        ft_init(&data, av);
        data.ptr = mlx_init();
        data.win = mlx_new_window(data.ptr, WIDTH, HEIGHT, "fract_ol");
        data.img = mlx_new_image(data.ptr, WIDTH, HEIGHT); //drow  Your program has to display the image in a window.
        data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,&data.line_length, &data.endian);
        data.ac = ac;
        data.av = av;
        mlx_hook(data.win, 2, 0, &ft_key_check, &data);
        mlx_hook(data.win, 17, 0, &ft_close, &data);
        render(&data);
        // mlx_loop_hook(data.ptr, &render, &data);
        mlx_mouse_hook(data.win, mouse_hook, &data);
        mlx_loop(data.ptr);
    }
    else
        write(1,"Not Valiid\n",9);
}
