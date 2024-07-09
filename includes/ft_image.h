/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:58:52 by xjose             #+#    #+#             */
/*   Updated: 2024/07/08 19:47:06 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_image
{
	stringg	path;
	void	*date;
	int		width;
	int		height;
	int		x;
	int		y;
}			t_image;

void		ft_destroy_image(t_window *window, void *img);
t_point		ft_postion_image(t_window *window, t_size size,
				enum e_postion postion);
t_image		*ft_create_image(t_window *window, stringg path, int width,
				int height, int x, int y);
void		*ft_put_image(t_window *window, stringg path, int width, int height,
				int x, int y);
void	*ft_setdraw(t_window *window, t_size size, int px, int py,
		enum e_color cor);				