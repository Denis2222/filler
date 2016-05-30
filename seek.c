/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 16:33:57 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/30 19:22:22 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

enum e_dir	chartodir(char *dir)
{
	if (ft_strequ(dir, "N"))
		return (N);
	if (ft_strequ(dir, "S"))
		return (S);
	if (ft_strequ(dir, "O"))
		return (O);
	if (ft_strequ(dir, "E"))
		return (E);
	if (ft_strequ(dir, "NE"))
		return (NE);
	if (ft_strequ(dir, "NO"))
		return (NO);
	if (ft_strequ(dir, "SE"))
		return (SE);
	if (ft_strequ(dir, "SO"))
		return (SO);
	return (RANDOM);
}

enum e_dir	dir(int *me, int *enemy)
{
	char dir[3];

	bzero(dir, 3);
	if (me[1] > enemy[1])
		ft_strcat(dir, "N");
	else if (me[1] < enemy[1])
		ft_strcat(dir, "S");
	if (me[0] > enemy[0])
		ft_strcat(dir, "O");
	else if (me[0] < enemy[0])
		ft_strcat(dir, "E");
	return (chartodir(dir));
}

void		seek_dir(t_filler *filler)
{
	int	me[2];
	int	enemy[2];
	int	x;
	int	y;

	setcoord(me, 0, 0);
	setcoord(enemy, 0, 0);
	x = 0;
	while (x < filler->map_x)
	{
		y = 0;
		while (y < filler->map_y)
		{
			if (get_case_type(filler->map[y][x]) == filler->player)
				setcoord(me, x, y);
			else if (get_case_type(filler->map[y][x]) > 0 &&
						get_case_type(filler->map[y][x]) != filler->player)
				setcoord(enemy, x, y);
			y++;
		}
		x++;
	}
	filler->dir = dir(me, enemy);
	ft_dprintf(2, "[%d]", filler->dir);
}
