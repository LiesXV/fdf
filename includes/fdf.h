/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:13:56 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/01/09 17:23:21 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define SIZEX 1920
# define SIZEY 1080

# include "../mlx/mlx.h"
# include <unistd.h>
# include "../libn/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

# define WHITE		0x00FFFFFF
# define GREY		0x00808080
# define BLACK		0x00000000
# define BROWN		0x00C47B1E
# define BROWN_DARK	0x007B4B0D
# define RED		0x00FF0000
# define YELLOW		0x00FFFF00
# define GREEN		0x00008000
# define GREEN_DARK	0x00175912
# define BLUE		0x000000FF
# define PURPLE		0x00800080

typedef struct s_map
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	int		**tab;
}			t_map;

int		parse_map(t_map *map, char *pathname);

void	draw_line(t_map *map, int x_start, int y_start, int x_end, int y_end, int color);

void	free_all_char(char **tab, char *line);
void	free_all_int(int **tab);
#endif