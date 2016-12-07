/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:59:52 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/11 09:59:26 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "../libft/includes/libft.h"

int		test_end(char *figure)
{
	while (*figure)
	{
		if (*figure != '\n' && *figure != '.')
			return (-1);
		figure++;
	}
	return (0);
}

int		put_piece(int square, int pos, char *grid, t_tetris *list)
{
	int		i;
	char	*start;

	i = 0;
	start = grid;
	grid = grid + pos;
	while (list->figure[i])
	{
		if (list->figure[i] == list->letter)
		{
			if (*grid != '.')
				return (-1);
			*grid = list->figure[i];
		}
		if (list->figure[i] == '\n')
		{
			grid = grid + square - 4;
			if (grid > start + (square * square) + square)
				return (test_end(list->figure + i));
		}
		i++;
		grid++;
	}
	return (0);
}

int		calc_start_square(t_tetris *list)
{
	int		area;
	int		i;

	area = 0;
	while (list != NULL)
	{
		i = 0;
		while (list->figure[i])
		{
			if (list->figure[i] == list->letter)
				area++;
			i++;
		}
		list = list->next;
	}
	i = 0;
	while ((i * i) < area)
	{
		if (i * i == area)
			return (i);
		i++;
	}
	return (i);
}

int		backtracking(char *grid, t_tetris *list, int square)
{
	int		pos;

	pos = 0;
	if (list == NULL)
	{
		return (result_backtracking(grid));
	}
	while (pos < (int)ft_strlen(grid))
	{
		ft_erase_piece(grid, list);
		if (put_piece(square, pos, grid, list) == 0)
		{
			if (backtracking(grid, list->next, square) == 0)
			{
				return (0);
			}
		}
		pos++;
	}
	return (-1);
}

void	resolution(t_tetris *list)
{
	int		square;
	char	*grid;
	int		i;
	int		result;

	result = -1;
	square = calc_start_square(list) - 1;
	while (result != 0)
	{
		i = 0;
		square++;
		grid = (char*)malloc(((square * square) + square + 1) * sizeof(char));
		while (i < (square * square) + square)
		{
			if (((i + 1) % (square + 1)) == 0)
				grid[i] = '\n';
			else
				grid[i] = '.';
			i++;
		}
		grid[i] = '\0';
		result = backtracking(grid, list, square);
		free(grid);
	}
}
