/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:11:33 by xjose             #+#    #+#             */
/*   Updated: 2024/07/10 13:54:51 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

int	main(void)
{
	t_window	*window;
	
	window = ft_create_window("LIBFTX", 1000, 800, BLACK);
	ft_destroy_event(window, close_window, window);
	ft_start_window(window);
	return (0);
}
