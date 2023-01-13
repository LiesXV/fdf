/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:13:56 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/01/13 15:29:07 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define SIZEX 1920
# define SIZEY 1080

# include "../mlx/mlx.h"
# include "../libn/libft.h"
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

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map
{
	t_data	img;
	void	*mlx_ptr;
	void	*win_ptr;
	int		length;
	int		height;
	int		**tab;
	int		space;
	int		offset_x;
	int		offset_y;
	double	rotation;
	double	zoom_height;
}			t_map;

typedef struct s_point {
	double		x;
	double		y;
	double		z;
}				t_point;

int		init_map(t_map *map, char *pathname);
int		parse_map(t_map *map, char *pathname);

int		ft_close(t_map *map);

void	check_line(t_map *map, int x, int y);

void	draw_line(t_map *map, t_point xyz_start, t_point xyz_end);
int		init_map(t_map *map, char *pathname);
void	draw_map(t_map *map);

void	free_all_char(char **tab, char *line);
void	free_all_int(int **tab);

int		deal_key(int key, t_map *map);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif