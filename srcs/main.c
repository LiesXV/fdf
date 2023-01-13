/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:27:45 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/01/13 12:41:01 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SIZEX || y < 0 || y >= SIZEY)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	render_next_frame(t_map *map)
{
	ft_memset(map->img.addr, 0, SIZEY * map->img.line_length);
	draw_map(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img, 0, 0);
	return (0);
}

int	init_map(t_map *map, char *pathname)
{
	int	test;

	test = 0;
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, SIZEX, SIZEY, "test");
	map->img.img = mlx_new_image(map->mlx_ptr, SIZEX, SIZEY);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel, \
									&map->img.line_length, &map->img.endian);
	test = parse_map(map, pathname);
	if (test == 0)
		return (0);
	map->space = 25;
	map->rotation = 3.14;
	map->zoom_height = 1;
	map->offset_x = 0;
	map->offset_y = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	map;
	char	*pathname;

	pathname = NULL;
	if (argc == 2 && !ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".fdf", 4))
		pathname = argv[1];
	else
		return (0);
	if (init_map(&map, pathname) == 0)
		return (ft_printf("map non générée"), 0);
	mlx_key_hook(map.win_ptr, deal_key, &map);
	mlx_loop_hook(map.mlx_ptr, render_next_frame, &map);
	mlx_hook(map.win_ptr, 17, 0, ft_close, &map);
	mlx_loop(map.mlx_ptr);
}
