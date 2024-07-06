/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prototype.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:58:52 by xjose             #+#    #+#             */
/*   Updated: 2024/07/05 20:17:59 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_set_color(t_window *window, enum e_color cor);
void		ft_draw(t_window *window, t_size size, enum e_color cor,
				t_point point);
void		ft_start_window(t_window *window);
void		ft_key_hook(t_window window, int (*funct_ptr)(), void *param);
void		ft_key_action(t_window window, t_key_action *kac);
void		ft_move(t_transform *t, t_basic_controller bc, int key);
void		ft_clear_window(t_window *window);
void		ft_destroy_image(t_window *window, void *img);
void		ft_destroy_image(t_window *window, void *img);
void		ft_create_map(t_window *wind, t_map map);
void		*ft_create_imag(t_window *window, t_image *img, bool put);
void		ft_hook(t_window window, t_event event, int (*funct)(),
				void *param);
void		ft_hook_keyrelease(t_window window, int (*funct)(), void *param);
void		ft_hook_keyup(t_window window, int (*funct)(), void *param);
char		**ft_getmap(int fd);
t_size		ft_get_size_map_win(char **map, int size_img);
t_window	*ft_create_windows(t_window *window);
