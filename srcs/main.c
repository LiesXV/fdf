/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:27:45 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/01/04 16:25:15 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	deal_key(int key, t_map *map)
{
	ft_printf("%d\n", key);
	if (key == 53)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	int		x;
	int		y;
	char	*pathname;

	pathname = NULL;
	if (argc == 2)
		pathname = argv[1];
	
	ft_printf("%s\n", pathname);
	x = 0;
	y = 0;
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, 600, 600, "test" );
	while (x <= 200)
	{
		while (y <= 600)
		{
			mlx_pixel_put(map.mlx_ptr, map.win_ptr, x, y, 0x00AA00);
			y++;
		}
		y = 0;
		mlx_pixel_put(map.mlx_ptr, map.win_ptr, x, y, 0x88FF88);
		x++;
	}
	x = 200;
	y = 0;
	while (x <= 400)
	{
		while (y <= 600)
		{
			mlx_pixel_put(map.mlx_ptr, map.win_ptr, x, y, 0xFFFFFF);
			y++;
		}
		y = 0;
		mlx_pixel_put(map.mlx_ptr, map.win_ptr, x, y, 0xFFFFFF);
		x++;
	}
	x = 400;
	y = 0;
	while (x <= 600)
	{
		while (y <= 600)
		{
			mlx_pixel_put(map.mlx_ptr, map.win_ptr, x, y, 0xFF0000);
			y++;
		}
		y = 0;
		mlx_pixel_put(map.mlx_ptr, map.win_ptr, x, y, 0xFF0000);
		x++;
	}
	mlx_key_hook(map.win_ptr, deal_key, &map);
	mlx_loop(map.mlx_ptr);
}
