/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 10:49:54 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/22 16:14:59 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct	s_tetris
{
	char			figure[21];
	char			letter;
	struct s_tetris	*next;
}				t_tetris;

/*
** AFFICHAGE_C
*/

int				result_backtracking(char *grid);
void			ft_erase_piece(char *grid, t_tetris *list);
void			conversion(t_tetris *list);

/*
**	ERROR_C
*/

int				check_char(t_tetris tetri_list);
int				check_four_square(t_tetris tetri_list);
int				check_lines(t_tetris tetri_list);
int				check_adj(t_tetris tetri_list);
int				count_adj(t_tetris tetri_list, int i);

/*
**	LOAD_C
*/

void			ft_free_tetri_list(t_tetris **list);
t_tetris		*ft_new_tetri_list(char *buffer);
void			ft_tetri_add_elem(t_tetris **list, t_tetris *elem);
int				fill_list(t_tetris **tetri_list, int fd);
int				ft_check_error(t_tetris *tetri_list);

/*
**	RESOLVE_C
*/

int				test_end(char *figure);
int				put_piece(int square, int pos, char *grid, t_tetris *list);
int				calc_start_square(t_tetris *list);
void			resolution(t_tetris *lst);
int		backtracking(char *grid, t_tetris *list, int square);

/*
**	UNIF_C
*/
void			uniformisation(t_tetris *list);
void			uni_left(char *buffer);
void			uni_up(char *buffer);
void			up_figure(char *buffer);
void			left_figure(char *buffer);

#endif
