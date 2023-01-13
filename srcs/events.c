/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:16:51 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/01/13 14:22:33 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	deal_key(int key, t_map *map)
{
	if (key == 53)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(0);
	}
	else if (key == 69)
		map->space += 2;
	else if (key == 78)
		map->space -= 2;
	else if (key == 123)
		map->offset_x += 10;
	else if (key == 124)
		map->offset_x -= 10;
	else if (key == 125)
		map->offset_y -= 10;
	else if (key == 126)
		map->offset_y += 10;
	else if (key == 86)
		map->rotation -= 0.2;
	else if (key == 88)
		map->rotation += 0.2;
	return (0);
}

int	ft_close(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	exit(0);
	return (0);
}
