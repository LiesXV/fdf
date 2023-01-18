/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:27:45 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/01/18 13:15:04 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	render_next_frame(t_map *map)
{
	ft_memset(map->img.addr, 0, SIZEY * map->img.line_length);
	draw_map(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	char	*pathname;

	pathname = NULL;
	if (argc == 2 && !ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".fdf", 4))
		pathname = argv[1];
	else
		return (ft_printf("map non générée\n"), 0);
	if (init_map(&map, pathname) == 0)
		return (ft_printf("map non générée\n"), 0);
	mlx_key_hook(map.win_ptr, deal_key, &map);
	mlx_loop_hook(map.mlx_ptr, render_next_frame, &map);
	mlx_hook(map.win_ptr, 17, 0, ft_close, &map);
	mlx_loop(map.mlx_ptr);
}
