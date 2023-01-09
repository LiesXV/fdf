/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:34:50 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/01/07 16:00:57 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	count_nbrs(char **nbrs)
{
	int	count;

	count = 0;
	while (nbrs[count] != NULL)
		count++;
	return (count - 1);
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
		if (map->x == 0)
			map->x = size;
		else if (map->x != size)
			return (0);
		map->y++;
		free_all_char(split, line);
	}
	return (close(fd), 1);
}

int	parsing(t_map *map, char *pathname)
{
	int		fd;
	int		yy;
	int		xx;
	char	*line;
	char	**split;

	yy = 0;
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (yy < map->y)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		xx = 0;
		while (xx < map->x)
		{
			map->tab[yy][xx] = ft_atoi(split[xx]);
			xx++;
		}
		yy++;
		free_all_char(split, line);
	}
	return (close(fd), 1);
}

int	parse_map(t_map *map, char *pathname)
{
	int	xx;

	xx = 0;
	if (pathname == NULL)
		return (0);
	map->y = 0;
	map->x = 0;
	if (get_tab_size(map, pathname) == 0)
		return (0);
	map->tab = malloc(sizeof(int *) * map->y);
	if (map->tab == NULL)
		return (0);
	while (xx < map->x)
	{
		map->tab[xx] = malloc(sizeof(int) * map->x);
		if (map->tab[xx] == NULL)
			return (free_all_int(map->tab), 0);
		xx++;
	}
	if (parsing(map, pathname) == -1)
		return (ft_printf("0"), 0);
	// ft_printf("x = %d\ny = %d\n", map->x, map->y);
	return (1);
}
