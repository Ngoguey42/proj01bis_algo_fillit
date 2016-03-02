/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:01:46 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/02 20:08:59 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** ...#
** ....
** ....     ->  (0,0) !!!!
** #...
*/

t_vec2i		calc_top_left(char const val[(4 + 1) * 4])
{
	int		x;
	int		y;
	int		minx;
	int		miny;

	minx = 4;
	miny = 4;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			if (val[y * 5 + x] == '#')
			{
				minx = MIN(x, minx);
				miny = MIN(y, miny);
			}
	}
	return ((t_vec2i){minx, miny});
}

bool		chars_valid(char const buf[(4 + 1) * 4])
{
	int		sharp_count;
	int		x;
	int		y;

	sharp_count = 0;
	y = 4;
	while (y-- > 0 && (x = 4))
	{
		while (x-- > 0)
			if (buf[y * 5 + x] == '#')
				sharp_count++;
			else if (buf[y * 5 + x] != '.')
				return (false);
		if (buf[y * 5 + 4] != '\n')
			return (false);
	}
	if (sharp_count != 4)
		return (false);
	return (true);
}
