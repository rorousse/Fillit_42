/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 10:53:07 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/22 16:15:38 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"
#include "../libft/includes/libft.h"

int		main(int argc, char **argv)
{
	int			fd;
	int			result;
	t_tetris	*tetri_list;

	tetri_list = NULL;
	fd = open(argv[1], O_RDONLY);
	result = fill_list(&tetri_list, fd);
	if (result == -1 || argc != 2)
	{
		ft_free_tetri_list(&tetri_list);
		ft_putstr("error\n");
		return (0);
	}
	uniformisation(tetri_list);
	conversion(tetri_list);
	resolution(tetri_list);
	ft_free_tetri_list(&tetri_list);
	close(fd);
	return (0);
}
