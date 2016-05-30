/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 15:45:06 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/30 19:28:01 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define CMCXY check_map_case(filler, px + x, py + y)
#define PIECEXY filler->piece[py][px]
#define ENEMYTOUCH PIECEXY == '.' && CMCXY > 0 && CMCXY != filler->player

int		search_position_o(t_filler *filler)
{
	int	x;
	int	y;
	int best[2];

	x = filler->map_x - 1;
	setcoord(best, -1, -1);
	while (x >= 0)
	{
		y = filler->map_y - 1;
		while (y >= 0)
		{
			if (pos_piece_valide(filler, x, y))
				setcoord(best, x, y);
			if (pos_piece_valide(filler, x, y) == 2)
				return (printresult(x, y));
			y--;
		}
		x--;
	}
	if (best[1] >= 0)
		return (printresult(best[0], best[1]));
	return (0);
}

int		alt_search(t_filler *filler,
						int (f1)(t_filler*),
						int (f2)(t_filler*))
{
	if (filler->way % 2 == 1)
		return (f1(filler));
	else
		return (f2(filler));
}

int		search_position_switch(t_filler *filler)
{
	if (filler->dir == O)
		return (search_position_o(filler));
	if (filler->dir == E)
		return (search_position_e(filler));
	if (filler->dir == N)
		return (alt_search(filler, search_position_no, search_position_ne));
	if (filler->dir == S)
		return (alt_search(filler, search_position_so, search_position_se));
	if (filler->dir == NE)
		return (alt_search(filler, search_position_ne, search_position_e));
	if (filler->dir == NO)
		return (alt_search(filler, search_position_no, search_position_so));
	if (filler->dir == SO)
		return (alt_search(filler, search_position_so, search_position_o));
	if (filler->dir == SE)
		return (alt_search(filler, search_position_se, search_position_e));
	return (search_position_no(filler));
}

int		pos_piece_return(int touch, int enemy)
{
	if (touch == 1 && enemy)
		return (2);
	return (touch == 1 ? 1 : 0);
}

int		pos_piece_valide(t_filler *filler, int x, int y)
{
	int touch;
	int	px;
	int	py;
	int enemy;

	enemy = 0;
	py = -1;
	touch = 0;
	while (++py < filler->piece_y && (px = -1))
		while (++px < filler->piece_x)
		{
			if (PIECEXY == '*')
			{
				if (CMCXY == filler->player)
					touch++;
				else if (CMCXY != 0)
					return (0);
			}
			else if (PIECEXY == '.' && CMCXY == -1)
				return (0);
			if (ENEMYTOUCH)
				enemy++;
		}
	return (pos_piece_return(touch, enemy));
}
