/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 14:33:36 by ikarishe          #+#    #+#             */
/*   Updated: 2018/04/16 14:43:38 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	read_board(char *line, t_board *board)
{
	int i;

	i = 0;
	while (i < board->dim_y)
	{
		get_next_line(0, &line);
		board->data[i] = ft_strdup(&line[4]);
		ft_free(&line);
		i++;
	}
}

void	read_shape(char *line, t_shape *piece)
{
	int i;

	i = 0;
	while (i < piece->dim_y)
	{
		get_next_line(0, &line);
		piece->data[i] = ft_strdup(line);
		ft_free(&line);
		i++;
	}
}
