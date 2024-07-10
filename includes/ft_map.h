/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:33:42 by xjose             #+#    #+#             */
/*   Updated: 2024/07/10 18:08:59 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_mapi
{
	char			**map;
	int				marginx;
	int				marginy;
	stringg			exit_path;
	stringg			jaba_path;
	stringg			block_path;
	stringg			empty_path;
	stringg			player_path;
	int				igw;
	int				igh;
}					t_mapi;

typedef struct s_items
{
	t_size			size;
	int				player;
	int				block;
	int				jaba;
	int				empty;
	int				exit;
}					t_items;
typedef struct s_map
{
	char			**map;
	t_items			items;
	enum e_color	exit;
	enum e_color	jaba;
	enum e_color	block;
	enum e_color	empty;
	enum e_color	player;
	int				move;
	int				igw;
	int				igh;
}					t_map;


t_map				*ft_getmap(int fd, t_window *window, t_map *map);

void				ft_inc_img_map(t_window *window, t_mapi map,
						enum e_postion postion);
void				ft_put_img_map(t_window *win, stringg line, t_mapi map,
						t_point p);

void				ft_inc_map(t_window *window, t_map map,
						enum e_postion postion, bool a);
void				ft_put_map(t_window *win, stringg line, t_map map,
						t_point p, bool a);

t_size				ft_get_size_map_win(char **map, int size_img);
t_size				ft_get_size_map(char **map);
int					ft_count_item(char **map, char item);
void				ft_get_item_map(t_map *map);