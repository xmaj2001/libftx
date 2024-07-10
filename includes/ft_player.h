/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:32:16 by xjose             #+#    #+#             */
/*   Updated: 2024/07/10 18:09:09 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_player
{
	int	stepd;
}		t_player;

char	ft_move_player_right(t_window *win, t_map *mp, t_point point);
char	ft_move_player_left(t_window *win, t_map *mp, t_point point);
char	ft_move_player_top(t_window *win, t_map *mp, t_point point);
char	ft_move_player_down(t_window *win, t_map *mp, t_point point);
char	**ft_find_player(t_window *window, t_map *mp, int move);