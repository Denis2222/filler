/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 19:24:37 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/30 19:26:14 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		search_position_so(t_filler *filler)
{
	int	x;
	int	y;
	int best[2];

	y = 0;
	setcoord(best, -1, -1);
	while (y < filler->map_y)
	{
		x = filler->map_x - 1;
		while (x >= 0)
		{
			if (pos_piece_valide(filler, x, y))
				setcoord(best, x, y);
			if (pos_piece_valide(filler, x, y) == 2)
				return (printresult(x, y));
			x--;
		}
		y++;
	}
	if (best[1] >= 0)
		return (printresult(best[0], best[1]));
	return (0);
}

int		search_position_ne(t_filler *filler)
{
	int	x;
	int	y;
	int best[2];

	y = filler->map_y - 1;
	setcoord(best, -1, -1);
	while (y >= 0)
	{
		x = 0;
		while (x < filler->map_x)
		{
			if (pos_piece_valide(filler, x, y))
				setcoord(best, x, y);
			if (pos_piece_valide(filler, x, y) == 2)
				return (printresult(x, y));
			x++;
		}
		y--;
	}
	if (best[1] >= 0)
		return (printresult(best[0], best[1]));
	return (0);
}

int		search_position_no(t_filler *filler)
{
	int	x;
	int	y;
	int best[2];

	y = filler->map_y - 1;
	setcoord(best, -1, -1);
	while (y >= 0)
	{
		x = filler->map_x - 1;
		while (x >= 0)
		{
			if (pos_piece_valide(filler, x, y))
				setcoord(best, x, y);
			if (pos_piece_valide(filler, x, y) == 2)
				return (printresult(x, y));
			x--;
		}
		y--;
	}
	if (best[1] >= 0)
		return (printresult(best[0], best[1]));
	return (0);
}

int		search_position_se(t_filler *filler)
{
	int	x;
	int	y;
	int best[2];

	y = 0;
	setcoord(best, -1, -1);
	while (y < filler->map_y)
	{
		x = 0;
		while (x < filler->map_x)
		{
			if (pos_piece_valide(filler, x, y))
				setcoord(best, x, y);
			if (pos_piece_valide(filler, x, y) == 2)
				return (printresult(x, y));
			x++;
		}
		y++;
	}
	if (best[1] >= 0)
		return (printresult(best[0], best[1]));
	return (0);
}

int		search_position_e(t_filler *filler)
{
	int	x;
	int	y;
	int best[2];

	x = 0;
	setcoord(best, -1, -1);
	while (x < filler->map_x)
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
		x++;
	}
	if (best[1] >= 0)
		return (printresult(best[0], best[1]));
	return (0);
}
