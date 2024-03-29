/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:34:50 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/01/18 16:01:43 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	count_nbrs(char **nbrs)
{
	int	count;

	count = 0;
	while (nbrs[count] != NULL)
		count++;
	return (count);
}

int	get_tab_size(t_map	*map, char	*pathname)
{
	int		fd;
	char	*line;
	int		size;
	char	**split;

	size = 0;
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		split = ft_split(line, ' ');
		size = count_nbrs(split);
		if (map->length == 0)
			map->length = size;
		else if (map->length != size)
			return (free_all_char(split, line), 0);
		map->height++;
		free_all_char(split, line);
	}
	return (close(fd), 1);
}

int	parsing(t_map *map, char *pathname)
{
	int		fd;
	int		y;
	int		x;
	char	*line;
	char	**split;

	y = 0;
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (y < map->height)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		x = 0;
		while (x < map->length)
		{
			map->tab[y][x] = ft_atoi(split[x]);
			x++;
		}
		y++;
		free_all_char(split, line);
	}
	return (close(fd), 1);
}

int	parse_map(t_map *map, char *pathname)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (pathname == NULL)
		return (0);
	map->height = 0;
	map->length = 0;
	if (get_tab_size(map, pathname) == 0)
		return (0);
	map->tab = malloc(sizeof(int *) * map->height);
	if (map->tab == NULL)
		return (0);
	while (y < map->height)
	{
		map->tab[y] = malloc(sizeof(int) * map->length);
		if (map->tab[y] == NULL)
			return (free_all_int(map->tab), 0);
		y++;
	}
	if (parsing(map, pathname) == -1)
		return (ft_printf("erreur lors du parsing"), 0);
	return (1);
}
