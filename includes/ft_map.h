/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:33:42 by xjose             #+#    #+#             */
/*   Updated: 2024/07/08 19:21:47 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_map
{
	char	**map;
	int		marginx;
	int		marginy;
	stringg	exit_path;
	stringg	jaba_path;
	stringg	block_path;
	stringg	empty_path;
	stringg	player_path;
	int		igw;
	int		igh;
}			t_map;

char		**ft_getmap(int fd);
void		ft_inc_map(t_window *window, t_map map, enum e_postion postion);
t_size		ft_get_size_map_win(char **map, int size_img);
t_size		ft_get_size_map(char **map);
char		**ft_find_player(t_window *window, t_map the_map, int move);