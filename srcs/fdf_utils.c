/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:33:53 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/01/09 18:02:31 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_all_char(char **tab, char *line)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
    free(line);
}

void	free_all_int(int **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
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

void	draw_line(t_map *map, int x_start, int y_start, int x_end, int y_end, int color)
{
	double	delta_x;
	double	delta_y;
	int		pixels;

	delta_x = (x_end - x_start);
	delta_y = (y_end - y_start);
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	while (pixels--)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x_start, y_start, color);
		x_start += delta_x;
		y_start += delta_y;
	}
}
