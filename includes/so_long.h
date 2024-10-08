/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:57:59 by andi              #+#    #+#             */
/*   Updated: 2024/09/18 10:46:46 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h" // MiniLibX
# include <fcntl.h>         // open
# include <math.h>          // Math Functions
# include <stdarg.h>        // Variadic Functions
# include <stdio.h>         // printf
# include <stdlib.h>        // malloc, free, exit
# include <unistd.h>        // write, close, read

// Key codes
# define W 119
# define ARROW_UP 65362
# define A 97
# define ARROW_LEFT 65361
# define S 115
# define ARROW_DOWN 65364
# define D 100
# define ARROW_RIGHT 65363
# define ESC 65307

// General
# define BLOCK 48
# define HOUSE_H 580
# define HOUSE_W 1000

// Sprites
# define WALL "./assets/sprites/wall.xpm"
# define FLOOR "./assets/sprites/floor.xpm"
# define COLLECTIBLE "./assets/sprites/collectible.xpm"
# define PLAYER "./assets/sprites/player.xpm"
# define ENEMY "./assets/sprites/enemy.xpm"
# define EXIT "./assets/sprites/exit.xpm"

// gnl
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

// count
struct				s_count
{
	int				c;
	int				c2;
	int				e;
	int				p;
};

// position
struct				s_pos
{
	int				px;
	int				py;
};

// mlx
struct				s_mlx
{
	void			*mlx_con;
	void			*mlx_window;
	void			*wall_img;
	void			*wall;
	void			*floor;
	void			*collectible;
	void			*player;
	void			*exit;
};

// main
typedef struct s_game
{
	struct s_count	count;
	struct s_pos	pos;
	struct s_mlx	mlx;
	char			**map;
	char			**map_copy;
	int				map_width;
	int				map_height;

}					t_game;

// Display
int					close_display(t_game *game);
void				display_game(t_game *game);
void				init_display(t_game *game);
void				init_sprite(t_game *game);

// Game
int					key_binds(int key_code, t_game *game);
void				player_move(int x, int y, t_game *game);

// Map
void				free_map(t_game *game);
void				init_map(char **av, t_game *game);
//// Get_next_line
t_list				*ft_lstnew(char *content);
int					find(char *buf);
char				*get_next_line(int fd);
char				*copychar(char *buf, int i, int a);
char				*copyleft(char *buf);
int					tofree(t_list **list, t_list **firstnode, char *leftover,
						int fd);
char				*leftoverchecker(char **leftover, int fd);
void				freelist(t_list **list);

// Parsing
void				does_exist(int ac, char **av);
void				is_char(t_game *game);
void				is_closed(t_game *game);
void				is_rectangle(t_game *game);
void				floodfill_algo(t_game *game);

// Utils
void				exit_function(int num);
int					ft_strcmp(char *s1, char *s2);
int					ft_strlen(char *str);
char				*ft_strdup(char *str);
void				ft_putnbr(int nb);

#endif
