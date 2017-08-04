/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 19:00:51 by kromain           #+#    #+#             */
/*   Updated: 2017/05/27 20:03:53 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		key_control(int key, t_env *env)
{
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_LEFT)
		env->horz -= sqrt(env->width) * 10;
	if (key == KEY_RIGHT)
		env->horz += sqrt(env->height) * 10;
	if (key == KEY_DOWN)
		env->vert += 20;
	if (key == KEY_UP)
		env->vert -= 20;
	if (key == KEY_ZOOM_IN && env->size < 33)
	{
		env->size += 4;
		env->horz -= env->size * 1.4;
		env->vert += 8;
	}
	if (key == KEY_ZOOM_OUT && env->size > 7)
	{
		env->size -= 4;
		env->horz += env->size * 1.4;
		env->vert -= 8;
	}
	image_loop(env);
	return (0);
}

t_env	parse_in(int fd)
{
	char	*line;
	t_env	env;

	ft_memset(&env, 0, sizeof(env));
	line = (char *)ft_memalloc(1);
	env.grid = (int **)ft_memalloc(sizeof(int *) * 256);
	env.height = 0;
	while (get_next_line(fd, &line) && env.height <= 255)
	{
		env.grid[env.height] = ft_atoi_array(line);
		if (env.grid[env.height][0] != env.grid[0][0])
			error_out(-3, &env);
		ft_strdel(&line);
		env.height++;
	}
	if (env.height > 255)
		error_out(-3, &env);
	env.width = env.grid[0][0];
	env.size = 8;
	env.horz = 1000 - (sqrt(pow(env.width, 2) + pow(env.height, 2)) * 2);
	env.vert = 500 + (env.height / 2);
	return (env);
}

int		main(int ac, char **av)
{
	t_env	env;
	int		fd;

	if (ac != 2)
		error_out(-1, &env);
	if ((fd = open(av[1], O_RDONLY)) < 0 || !ft_strstr(av[1], ".fdf"))
		error_out(-2, &env);
	env = parse_in(fd);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 2000, 1000, "Keenan Romain");
	mlx_expose_hook(env.win, &image_loop, &env);
	mlx_key_hook(env.win, &key_control, &env);
	mlx_loop(env.mlx);
	return (0);
}
