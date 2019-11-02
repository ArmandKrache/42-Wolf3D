/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clevaill <clevaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:31:51 by akrache           #+#    #+#             */
/*   Updated: 2019/05/22 15:14:33 by clevaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include "mlx.h"

# define BUFF_SIZE 4096
# define WIDTH 1440
# define HEIGHT 810
# define SIZE 64
# define FOV 60
# define TEX_MAX 13
# define RAY_ANGLE ((double)FOV / WIDTH)

typedef struct		s_coord
{
	double			x;
	double			y;
}					t_coord;

typedef struct		s_texture
{
	void			*img_ptr;
	unsigned int	*img_adr;
	int				bpp;
	int				sl;
	int				endian;
	int				w;
	int				h;
	unsigned char	id;
}					t_texture;

typedef struct		s_player
{
	t_texture		hand;
	int				pos_x;
	int				pos_y;
	int				height;
	int				pov;
	int				turn;
	int				speed;
	int				look;
	char			crouch;
}					t_player;

typedef struct		s_block
{
	int				type;
	int				north;
	int				east;
	int				south;
	int				west;
	int				floor;
	int				ceil;
}					t_block;

typedef struct		s_map
{
	int				width;
	int				height;
	t_block			**grid;
}					t_map;

typedef struct		s_wolf
{

	t_player		*player;
	t_map			*map;
	t_texture		*tex;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	unsigned int	*img_adr;
	unsigned int	null_tex[SIZE];
	double			fov_rad;
	int				cons;
	int				bpp;
	int				sl;
	int				endian;
	int				offset;
	char			pause;
}					t_wolf;

/*
** RAY
*/

double				rad(double angle);
int					get_id(t_wolf *tab, double a, t_coord v, int verti);
void				cast_ray(t_wolf *tab, double angle, int x);
void				display(t_wolf *tab);

/*
** KEYS
*/

int					mouse_move(int x, int y, t_wolf *tab);
int					key_hook(int keycode, t_wolf *tab);
int					key_pressed_esc(t_wolf *tab);
void				key_pressed_larrow(t_wolf *tab);
void				key_pressed_rarrow(t_wolf *tab);
void				key_pressed_uarrow(t_wolf *tab);
void				key_pressed_darrow(t_wolf *tab);
void				key_pressed_crouch(t_wolf *tab);
void				key_pressed_r(t_wolf *tab);
void				key_pressed_f(t_wolf *tab);
void				key_pressed_space(t_wolf *tab);
void				key_pressed_lstrafe(t_wolf *tab);
void				key_pressed_rstrafe(t_wolf *tab);

/*
** PARSING
*/

t_map				*parsing(char *arg);
int					checking(char *arg, char **file);
int					fl_strlen(char *str);

/*
** TEXTURE
*/

int					light(int color, double dist);
int					shading(int color, double dist);
t_texture			*parse_textures(t_wolf *tab);
t_texture			texture_init(t_wolf *tab, char *file, unsigned char id);
void				texturise_wall(t_wolf *tab, int x, int y, int color);

/*
** ERROR
*/

void				*free_file(char *str);
void				*free_player(t_player *player);
void				*free_grid(t_map *map, int height);
void				*free_map(t_map *map);
void				*free_tex(t_wolf *tab);
void				*free_wolf(t_wolf *tab);
void				*free_tab(t_wolf *tab, t_map *map, int x);

#endif
