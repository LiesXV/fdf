/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:27:45 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/01/09 17:58:25 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	deal_key(int key, t_map *map)
{
	ft_printf("%d\n", key);
	if (key == 53)
	{
		//free_all_int(map->tab);
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(0);
	}
	return (0);
}

void	put_square(t_map map, int x, int y, int color)
{
	int	xx;
	int	yy;

	xx = x - 5;
	yy = y - 5;
	while (xx < x + 5)
	{
		while (yy < y + 5)
		{
			mlx_pixel_put(map.mlx_ptr, map.win_ptr, xx, yy, color);
			yy++;
		}
		yy = y - 5;
		xx++;
	}
}

int	main(int argc, char **argv)
{
	t_map	map;
	char	*pathname;
	int		y;
	int		x;
	int		ratio;
	int		ratio2;

	ratio = 100;
	ratio2 = 100;
	y = 0;
	x = 0;
	pathname = NULL;
	if (argc == 2)
		pathname = argv[1];
	ft_printf("%s\n", pathname);
	ft_printf("%d\n", parse_map(&map, pathname));
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, map.x * 100, map.y * 100, "test");
	while (y < map.y)
	{
		while (x < map.x)
		{
			ft_printf("x: %d\n", x);
			if (x < map.x - 1)
				draw_line(&map, ratio + x, ratio2 + y, ratio + x + 25, ratio2 + y, BLUE);
			if (y < map.y - 1)
				draw_line(&map, ratio + x, ratio2 + y, ratio + x, ratio2 + y + 25, BLUE);
			mlx_pixel_put(map.mlx_ptr, map.win_ptr, ratio + x, ratio2 + y, RED);
			ratio += 25;
			x++;
		}
		x = 0;
		ratio = 100;
		y++;
		ratio2 += 25;
	}
	//draw_line(&map, ratio + x, ratio2 + y, ratio + x + 25, ratio2 + y);
	mlx_key_hook(map.win_ptr, deal_key, &map);
	mlx_loop(map.mlx_ptr);
}
