/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:00:51 by kromain           #+#    #+#             */
/*   Updated: 2017/05/20 18:04:53 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	error_out(int value, t_env *env)
{
	if (value == -1)
		ft_putstr_fd("ERROR #1: usage: ./fdf target_file\n", 2);
	else if (value == -2)
		ft_putstr_fd("ERROR #2: Bad user input\n", 2);
	else if (value == -3)
		ft_putstr_fd("ERROR #3: Bad file size\n", 2);
	if (env->grid)
		ft_memdel((void *)env->grid);
	exit(-1);
}

void	show_controls(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 25, 15, GRE, "______________________");
	mlx_string_put(env->mlx, env->win, 28, 15, GRE, "______________________");
	mlx_string_put(env->mlx, env->win, 25, 30, GRE, "|                    |");
	mlx_string_put(env->mlx, env->win, 25, 35, GRE, "|~ Controls for FDF ~|");
	mlx_string_put(env->mlx, env->win, 25, 50, GRE, "|                    |");
	mlx_string_put(env->mlx, env->win, 25, 65, GRE, "|Movement:           |");
	mlx_string_put(env->mlx, env->win, 25, 80, GRE, "|       Arrows       |");
	mlx_string_put(env->mlx, env->win, 25, 95, GRE, "|Zoom:               |");
	mlx_string_put(env->mlx, env->win, 25, 110, \
			GRE, "|       IN  = key 'Q'|");
	mlx_string_put(env->mlx, env->win, 25, 125, \
			GRE, "|       OUT = key 'W'|");
	mlx_string_put(env->mlx, env->win, 25, 140, \
			GRE, "|Quit:               |");
	mlx_string_put(env->mlx, env->win, 25, 155, \
			GRE, "|       ESC          |");
	mlx_string_put(env->mlx, env->win, 25, 160, \
			GRE, "|                    |");
	mlx_string_put(env->mlx, env->win, 25, 165, \
			GRE, "______________________");
	mlx_string_put(env->mlx, env->win, 28, 165, \
			GRE, "______________________");
}

void	show_banner(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 850, 20, \
			GRE, "/$$$$$$$$$ /$$$$$$$$  /$$$$$$$$$");
	mlx_string_put(env->mlx, env->win, 850, 35, \
			GRE, "| $$_____/ | $$__  $$ | $$_____/");
	mlx_string_put(env->mlx, env->win, 850, 50, \
			GRE, "| $$       | $$  \\ $$ | $$");
	mlx_string_put(env->mlx, env->win, 850, 65, \
			GRE, "| $$$$$    | $$  | $$ | $$$$$");
	mlx_string_put(env->mlx, env->win, 850, 80, \
			GRE, "| $$__/    | $$  | $$ | $$__/");
	mlx_string_put(env->mlx, env->win, 850, 95, \
			GRE, "| $$       | $$  | $$ | $$");
	mlx_string_put(env->mlx, env->win, 850, 110, \
			GRE, "| $$       | $$$$$$$/ | $$");
	mlx_string_put(env->mlx, env->win, 850, 125, \
			GRE, "|__/       |_______/  |__/");
}

int		image_loop(t_env *env)
{
	int i;
	int j;

	i = -1;
	mlx_clear_window(env->mlx, env->win);
	show_controls(env);
	show_banner(env);
	while (++i < env->height)
	{
		j = 0;
		while (++j < env->width)
			set_bresenham(env, i, j);
	}
	return (0);
}
