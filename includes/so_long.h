/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:57:59 by andi              #+#    #+#             */
/*   Updated: 2024/09/10 11:38:45 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include ".MiniLibX/mlx.h" // MiniLibX
# include <fcntl.h>  // open
# include <math.h>   // Math Functions
# include <stdarg.h> // Variadic Functions
# include <stdlib.h> // malloc, free, exit
# include <unistd.h> // write, close, read

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_game
{
	char			**map;
	int				C;
	int				E;
	int				P;

}					t_game;

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

// Utils
void				exit_function(int num);
int					ft_strcmp(char *s1, char *s2);
int					ft_strlen(char *str);

#endif
