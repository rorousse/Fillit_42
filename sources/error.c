/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 11:47:37 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/13 18:14:46 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_char(t_tetris tetri_list)
{
	int		i;

	i = 0;
	while (tetri_list.figure[i])
	{
		if (tetri_list.figure[i] != '.' && tetri_list.figure[i] != '#'
		&& tetri_list.figure[i] != '\n')
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

int		check_four_square(t_tetris tetri_list)
{
	int		number;
	int		i;

	number = 0;
	i = 0;
	while (tetri_list.figure[i])
	{
		if (tetri_list.figure[i] == '#')
			number++;
		i++;
	}
	if (number == 4)
		return (0);
	return (-1);
}

int		check_lines(t_tetris tetri_list)
{
	int		i;

	i = 0;
	while (tetri_list.figure[i])
	{
		if ((i + 1) % 5 != 0)
		{
			if (tetri_list.figure[i] == '\n')
				return (-1);
		}
		else
		{
			if (tetri_list.figure[i] != '\n')
				return (-1);
		}
		i++;
	}
	if (i == 20)
		return (0);
	return (-1);
}

int		check_adj(t_tetris tetri_list)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (tetri_list.figure[i])
	{
		if (tetri_list.figure[i] == '#')
			count = count + count_adj(tetri_list, i);
		i++;
	}
	if (count >= 6)
		return (0);
	return (-1);
}

int		count_adj(t_tetris tetri_list, int i)
{
	int		count;

	count = 0;
	if (i >= 5)
	{
		if (tetri_list.figure[i - 5] == '#')
			count++;
	}
	if (i > 0)
	{
		if (tetri_list.figure[i - 1] == '#')
			count++;
	}
	if (tetri_list.figure[i + 1] == '#')
		count++;
	if (i < 16)
	{
		if (tetri_list.figure[i + 5] == '#')
			count++;
	}
	return (count);
}
