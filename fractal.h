/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iakyaou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:17:05 by iakyaou           #+#    #+#             */
/*   Updated: 2023/04/03 20:48:49 by iakyaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include	"mlx.h"
# include	<stdlib.h>
# include	<string.h>
# include	<stdio.h>
# include	<unistd.h>
# include	<math.h>

# define ESC_KEY 53
# define MANDELBROT 1
# define  JULIA 2
# define WIDTH 800
# define HEIGHT 600

typedef struct s_complex
{
	double	real;
	double	imag;
	double	cy;
	double	cx;
	float	tmp;
}	t_complex;

typedef struct s_data
{
	void		*ptr;
	void		*win;
	void		*img;
	char		*addr;
	int			end;
	int			ac;
	char		**av;
	int			max_iteratins;
	t_complex	julia_arg;
	int			lin;
	int			bt;
	int			cursor_x;
	int			cursor_y;
	int			status;
	double		zoom;
	int			x1;
	int			y1;
	int			it_max;
}		t_data;

void	mandelbrot(int a, int b, t_data *data);
void	julia(int a, int b, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_init(t_data *data, char **av);
int		ft_key_check(int key, t_data *data);
int		render(t_data *data);
int		ft_close(t_data *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		mouse_hook(int button, int x, int y, t_data *data);
#endif
