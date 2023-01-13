/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:20:51 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/01/13 12:34:23 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_map(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->length)
		{
			check_line(map, x, y);
			x++;
		}
		y++;
	}
}

void	check_line(t_map *map, int x, int y)
{
	t_point	xyz_start;
	t_point	xyz_end;

	if (x + 1 < map->length)
	{
		xyz_start.x = x * map->space;
		xyz_start.y = y * map->space;
		xyz_end.x = (x + 1) * map->space;
		xyz_end.y = y * map->space;
		xyz_start.z = map->tab[y][x];
		xyz_end.z = map->tab[y][x + 1];
		draw_line(map, xyz_start, xyz_end);
	}
	if (y + 1 < map->height)
	{
		xyz_start.x = x * map->space;
		xyz_start.y = y * map->space;
		xyz_end.x = x * map->space;
		xyz_end.y = (y + 1) * map->space;
		xyz_start.z = map->tab[y][x];
		xyz_end.z = map->tab[y + 1][x];
		draw_line(map, xyz_start, xyz_end);
	}
}

void	isometric_view(t_map *map, t_point *xy)
{
	xy->x = (xy->x - xy->y) * cos(map->rotation / 3);
	if (xy->z != 0)
		xy->y = (xy->x + xy->y) * sin(map->rotation / 6) \
			- ((xy->z * map->zoom_height) / 11) * map->space;
	else
		xy->y = (xy->x + xy->y) * sin(map->rotation / 6) \
			- (xy->z / 11) * map->space;
}

void	draw_line(t_map *map, t_point xyz_start, t_point xyz_end)
{
	double	delta_x;
	double	delta_y;
	int		pixels;

	isometric_view(map, &xyz_start);
	isometric_view(map, &xyz_end);
	delta_x = (xyz_end.x - xyz_start.x);
	delta_y = (xyz_end.y - xyz_start.y);
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	while (pixels--)
	{
		my_mlx_pixel_put(&map->img, xyz_start.x + (SIZEX / 4) + map->offset_x, \
						xyz_start.y + (SIZEY / 4) + map->offset_y, BLUE);
		xyz_start.x += delta_x;
		xyz_start.y += delta_y;
	}
}