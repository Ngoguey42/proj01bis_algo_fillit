/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 11:02:41 by ngoguey           #+#    #+#             */
/*   Updated: 2016/03/02 19:38:57 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
** TODO:
** remplacer les for pour etre a la norme
** mettre une libft
** matcher le sujet au niveau des erreurs
** verifier le parser
** verifier les fonctions interdites
** changer les fonctions de string.h pour libft.h
*/
# include "libft.h"

typedef struct	s_vec2i
{
	int			x;
	int			y;
}				t_vec2i;

/*
** Shape ID
*/

# define MAP_W 13

typedef char	t_map[MAP_W][MAP_W];

typedef struct	s_piece
{
	int			sid;
	uintmax_t	mask;
	__uint128_t	mask128;
	int			w;
	int			h;
	t_vec2i		dt[4];
	t_vec2i		finalpos;
	char		character;
}				t_piece;

typedef struct	s_ppool
{
	t_piece		pcs[27];
	int			lastpid;
}				t_ppool;

int				flt_parse(char const *fname, t_ppool p[1]);
t_vec2i			calc_top_left(char const val[(4 + 1) * 4]);
void			flt_solve(t_ppool *pool);
bool			flt_solve64(
	uintmax_t const m, t_ppool *const pool, int const w, int const pid);
bool			flt_solve128(
	uintmax_t const m, t_ppool *const pool, int const w, int const pid);
bool			flt_solve128_plus(
	uintmax_t const m, t_ppool *const pool, int const w, int const pid);
bool			flt_solveptr(
	t_map m, t_ppool *const pool, int const w, int const pid);

/*
** 3 4.000000
** 4 4.000000
** 5 5.000000
** 6 5.000000
** 7 6.000000
** 8 6.000000
** 9 6.000000
** 10 7.000000	EASY
** 11 7.000000
** 12 7.000000	HARD
** 13 8.000000	EASY
** 14 8.000000
** 15 8.000000
** 16 8.000000	HARD
** 17 9.000000	EASY
** 18 9.000000
** 19 9.000000
** 20 9.000000	HARD
** 21 10.000000	EASY
** 22 10.000000
** 23 10.000000
** 24 10.000000
** 25 10.000000	HARD
** 26 11.000000	EASY
*/

#endif
