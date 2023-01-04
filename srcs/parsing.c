/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:34:50 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/01/04 16:40:29 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	convert_tabs(char **split, t_map *map)
{
	map->y_len = 0;
	while (split[0][i])
	{
		map->tab[map->y_len] = ft_atoi(split[0][map->y_len]);
		map->y_len++;
	}
	return (tab);
}

int	**parsing(t_map *map, char *pathname)
{
	char	**split;
	int		*tab;
	int		i;
	int		fd;
	char	*line;

	map->y_len = 0;
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (close(fd), 1);
		map->y_len = ft_strlen(line) / 2 + 1;
		split = ft_split(line, ' ');
		if (!split)
			return (free(split), close(fd), 0);
		tab = convert_tabs(split, &map);
		free(split);
		map->y_len++;
	}
}
