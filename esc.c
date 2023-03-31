/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iakyaou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:13:31 by iakyaou           #+#    #+#             */
/*   Updated: 2023/03/25 16:38:28 by iakyaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key_check(int key, t_data *data)
{
    if (key == ESC_KEY)
        ft_close(data);
    return 0;
}

int ft_close(t_data *data)
{
    mlx_destroy_image(data->ptr, data->img);
    mlx_destroy_window(data->ptr, data->win);
    exit(0);
}
