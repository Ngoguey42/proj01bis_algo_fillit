/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 11:04:11 by ngoguey           #+#    #+#             */
/*   Updated: 2016/03/04 14:42:08 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <unistd.h>
#include <stdlib.h>

extern t_piece const g_pcs[19];

static unsigned int	adj_diff(char const val[(4 + 1) * 4])
{
	unsigned int	acc;
	int				x;
	int				y;

	acc = 0;
	y = 4;
	while (y-- > 0 && (x = 3))
		while (x-- > 0)
		{
			if (val[y * 5 + x] == '#' && val[y * 5 + x + 1] == '#')
				acc++;
			if (val[x * 5 + y] == '#' && val[(x + 1) * 5 + y] == '#')
				acc++;
		}
	return (acc);
}

static bool			match_piece(
	char const val[(4 + 1) * 4], t_piece const *pc, t_vec2i tl)
{
	int		x;
	int		y;
	int		dt;

	dt = 4;
	while (dt-- > 0)
	{
		y = tl.y + pc->dt[dt].y;
		x = tl.x + pc->dt[dt].x;
		if (x >= 4 || y >= 4 || val[y * 5 + x] != '#')
			return (false);
	}
	return (true);
}

static void			save_piece(char const val[(4 + 1) * 4], t_ppool p[1])
{
	t_piece const	*pc = g_pcs;
	t_vec2i const	topleft = calc_top_left(val);

	while ((void*)pc < END_ARRAY(g_pcs))
	{
		if (match_piece(val, pc, topleft))
		{
			p->pcs[p->lastpid] = *pc;
			return ;
		}
		pc++;
	}
	return ;
}

int					flt_parse(int fd, t_ppool p[1])
{
	char		buf1[(4 + 1) * 4];
	char		buf2[1];
	int			ret;
	int			i;

	i = 0;
	while ((ret = read(fd, buf1 + i, sizeof(buf1) - i)) > 0)
	{
		i += ret;
		if (i == sizeof(buf1))
		{
			i = 0;
			if (!chars_valid(buf1) || adj_diff(buf1) < 3)
				return (1);
			save_piece(buf1, p);
			p->lastpid++;
			if ((ret = read(fd, buf2, 1)) == 0)
				break ;
			else if (ret < 0 || *buf2 != '\n')
				return (1);
		}
	}
	p->lastpid--;
	return (close(fd) || p->lastpid < 0 || p->lastpid > 25 || ret < 0);
}
