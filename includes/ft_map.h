/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:33:42 by xjose             #+#    #+#             */
/*   Updated: 2024/07/10 11:12:02 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_map
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
}					t_map;

typedef struct s_map2
{
	char			**map;
	enum e_color	exit;
	enum e_color	jaba;
	enum e_color	block;
	enum e_color	empty;
	enum e_color	player;
	int				igw;
	int				igh;
}					t_map2;

char				**ft_getmap(int fd);
char				**ft_find_player(t_window *window, char **map, int move);
void				ft_inc_map(t_window *window, t_map map,
						enum e_postion postion);
void				ft_inc_map2(t_window *window, t_map2 map,
						enum e_postion postion, bool a);
void				ft_put_map2(t_window *win, stringg line, t_map2 map,
						t_point p, bool a);
void				ft_put_img_map(t_window *win, stringg line, t_map map,
						t_point p);
t_size				ft_get_size_map_win(char **map, int size_img);
t_size				ft_get_size_map(char **map);