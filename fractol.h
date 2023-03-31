/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iakyaou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:04:54 by yagnaou           #+#    #+#             */
/*   Updated: 2023/03/31 20:41:36 by iakyaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
#include<string.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

# define ESC_KEY 53
# define MANDELBROT 1
# define JULIA 2
# define WIDTH 800
# define HEIGHT 600
// # define WIN_SIZE 800
// # define LEFT_KEY 123
// # define RIGHT_KEY 124
// # define DOWN_KEY 125
// # define UP_KEY 126
// # define MOUSE_UP 4
// # define MOUSE_DOWN 5


typedef	struct s_complex{
	double	real;
	double	imag;
	double	cy;
	double	cx;
}	t_complex;

typedef struct s_data {
	void	*ptr;
	void	*win;
	void	*img;
	char	*addr;
	int		endian;
	int		ac;
	char	**av;
	int		max_iteratins;
	t_complex	julia_arg;
	int		line_length;
	int		bits_per_pixel;
	int 	cursor_x;
	int 	cursor_y;
	int		status;
}		 t_data;

	void  	mandelbrot(int a, int b, t_data *data);
	void	julia(int a, int b, t_data *data);
	void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
	void    ft_init(t_data *data, char **av);
	int		ft_key_check(int key, t_data *data);
	int 	render(t_data *data);
	int 	ft_close(t_data *data);
	int		ft_strncmp(const char *s1, const char *s2, size_t n);
	int 	mouse_hook(int button, int x,int y, t_data *data);


#endif
