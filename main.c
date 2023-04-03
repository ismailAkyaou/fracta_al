/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iakyaou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:37:00 by iakyaou           #+#    #+#             */
/*   Updated: 2023/04/03 20:49:40 by iakyaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == 1 && data->status == 2)
	{
		data->julia_arg.real = (x - WIDTH / 2) * (4.0 / WIDTH);
		data->julia_arg.imag = (y - HEIGHT / 2) * (4.0 / HEIGHT);
		render(data);
	}
	else if (button == 4)
	{
		data->zoom += 1.5;
		render(data);
	}
	else if (button == 5)
	{
		data->zoom /= 1.5;
		render(data);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	data.ac = ac;
	if (ac >= 2)
	{
		ft_init (&data, av);
		data.ptr = mlx_init();
		data.win = mlx_new_window(data.ptr, WIDTH, HEIGHT, "fract_ol");
		data.img = mlx_new_image(data.ptr, WIDTH, HEIGHT);
		data.addr = mlx_get_data_addr(data.img, &data.bt, &data.lin, &data.end);
		data.ac = ac;
		data.av = av;
		mlx_hook(data.win, 2, 0, &ft_key_check, &data);
		mlx_hook(data.win, 17, 0, &ft_close, &data);
		render(&data);
		mlx_mouse_hook(data.win, mouse_hook, &data);
		mlx_loop(data.ptr);
	}
	else
		write (1, "Not Valiid\n", 9);
}
