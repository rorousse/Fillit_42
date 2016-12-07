/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 11:00:19 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/22 16:17:38 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "../libft/includes/libft.h"
#include "fillit.h"

void		ft_free_tetri_list(t_tetris **list)
{
	if (*list != NULL)
	{
		if ((*list)->next != NULL)
		{
			ft_free_tetri_list(&((*list)->next));
		}
		free(*list);
	}
}

t_tetris	*ft_new_tetri_list(char *buffer)
{
	t_tetris	*new;

	new = (t_tetris*)malloc(sizeof(t_tetris));
	ft_strcpy(new->figure, buffer);
	new->letter = 'A';
	new->next = NULL;
	return (new);
}

void		ft_tetri_add_elem(t_tetris **list, t_tetris *elem)
{
	t_tetris	*temp;

	temp = *list;
	if (*list == NULL)
	{
		*list = elem;
	}
	else
	{
		elem->letter = (elem->letter) + 1;
		while (temp->next != NULL)
		{
			temp = temp->next;
			elem->letter = (elem->letter) + 1;
		}
		temp->next = elem;
	}
}

int			fill_list(t_tetris **tetri_list, int fd)
{
	int			i;
	char		*buffer;
	int			test;

	i = 0;
	if (!(buffer = (char*)malloc(1000)))
		return (-1);
	test = read(fd, buffer, 1000);
	while (buffer[i])
	{
		ft_tetri_add_elem(tetri_list,
		ft_new_tetri_list(ft_strsub(buffer, i, 20)));
		i = i + 20;
		if ((buffer[i] != '\n' && buffer[i] != '\0')
		|| (buffer[i] && buffer[i + 1] == '\0'))
			return (-1);
		i++;
	}
	return (ft_check_error(*tetri_list));
}

int			ft_check_error(t_tetris *tetri_list)
{
	if (tetri_list == NULL)
	{
		return (-1);
	}
	while (tetri_list != NULL)
	{
		if (check_char(*tetri_list) == -1
		|| check_four_square(*tetri_list) == -1
		|| check_lines(*tetri_list) == -1 || check_adj(*tetri_list) == -1)
			return (-1);
		tetri_list = tetri_list->next;
	}
	return (0);
}
