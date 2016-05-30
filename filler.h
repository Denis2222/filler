/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 13:41:17 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/30 19:27:22 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

enum	e_dir
{
	NULLDIR,
	N,
	E,
	S,
	O,
	NE,
	NO,
	SE,
	SO,
	RANDOM
};

typedef struct	s_filler
{
	int			player;
	int			map_x;
	int			map_y;
	int			piece_x;
	int			piece_y;
	char		**map;
	char		**piece;
	int			way;
	enum e_dir	dir;
}				t_filler;

int				search_position_switch(t_filler *filler);

int				search_position_so(t_filler *filler);
int				search_position_ne(t_filler *filler);
int				search_position_no(t_filler *filler);
int				search_position_se(t_filler *filler);
int				search_position_e(t_filler *filler);

t_filler		*newfiller(void);
char			**malloc_map(int x, int y);
void			free_map(t_filler *filler);
void			free_piece(t_filler *filler);
int				check_name(char *buffer);
int				check_map_case(t_filler *filler, int x, int y);
int				check_map_size(char *buffer, t_filler *filler);
int				check_piece_size(char *buffer, t_filler *filler);
int				pos_piece_valide(t_filler *filler, int x, int y);

void			setcoord(int *coord, int x, int y);
int				printresult(int x, int y);

void			seek_dir(t_filler *filler);
int				get_case_type(char c);

#endif
