/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unif.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 13:51:47 by rorousse          #+#    #+#             */
/*   Updated: 2015/12/20 14:19:42 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

void	up_figure(char *buffer)
{
	int		i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '#')
		{
			buffer[i - 5] = '#';
			buffer[i] = '.';
		}
		i++;
	}
}

void	left_figure(char *buffer)
{
	int		i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '#')
		{
			buffer[i - 1] = '#';
			buffer[i] = '.';
		}
		i++;
	}
}

void	uni_up(char *buffer)
{
	int		i;
	int		rank;

	i = 0;
	rank = 0;
	while (buffer[i] != '#')
	{
		if (buffer[i] == '\n')
			rank++;
		i++;
	}
	while (rank != 0)
	{
		up_figure(buffer);
		rank--;
	}
}

void	uni_left(char *buffer)
{
	int		i;
	int		step;
	int		rank;

	i = 0;
	step = 0;
	rank = 4;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			step = -1;
		if (buffer[i] == '#' && step < rank)
		{
			rank = step;
		}
		step++;
		i++;
	}
	while (rank != 0)
	{
		left_figure(buffer);
		rank--;
	}
}

void	uniformisation(t_tetris *list)
{
	while (list != NULL)
	{
		uni_up(list->figure);
		uni_left(list->figure);
		list = list->next;
	}
}
