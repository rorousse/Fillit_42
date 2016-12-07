/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:20:00 by rorousse          #+#    #+#             */
/*   Updated: 2015/12/22 20:14:32 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "fillit.h"

int		result_backtracking(char *grid)
{
	ft_putstr(grid);
	return (0);
}

void	ft_erase_piece(char *grid, t_tetris *list)
{
	while (*grid)
	{
		if (*grid == list->letter)
		{
			*grid = '.';
		}
		grid++;
	}
}

void	conversion(t_tetris *list)
{
	int		i;

	while (list != NULL)
	{
		i = 0;
		while (list->figure[i])
		{
			if (list->figure[i] == '#')
				list->figure[i] = list->letter;
			i++;
		}
		list = list->next;
	}
}
