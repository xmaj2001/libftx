/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:58:52 by xjose             #+#    #+#             */
/*   Updated: 2024/07/10 13:39:08 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_window
{
	stringg			title;
	int				width;
	int				height;
	enum e_color	background;
	void			*mlx;
	void			*win;
}					t_window;

void				ft_set_color(t_window *window, enum e_color cor);
void				ft_start_window(t_window *window);
void				ft_clear_window(t_window *window);
t_window			*ft_create_window(stringg title, int width, int height,
						enum e_color backgorund);
int					close_window(t_window *win);
