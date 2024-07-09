/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:11:33 by xjose             #+#    #+#             */
/*   Updated: 2024/07/09 22:57:23 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"
#include <fcntl.h>


int	main(void)
{
	t_window	*window;
	window = ft_create_window("LIBFTX", 1000, 800, BLACK);
	ft_start_window(window);
	return (0);
}
