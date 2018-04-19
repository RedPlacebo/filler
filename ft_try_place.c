/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_place.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 13:21:20 by ikarishe          #+#    #+#             */
/*   Updated: 2018/04/16 16:23:28 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		cell_fits(t_board *board, t_shape *piece, t_place place, char *player)
{
	int x;
	int y;
	int x_place;
	int y_place;

	x = place.x;
	y = place.y;
	x_place = place.x_place;
	y_place = place.y_place;
	if (piece->data[y][x] == '.')
		return (1);
	else if (x_place + x >= board->dim_x || y_place + y >= board->dim_y)
		return (0);
	else if (board->data[y_place + y][x_place + x] == '.')
		return (1);
	else if (board->data[y_place + y][x_place + x] == *player)
		return (1);
	else if (board->data[y_place + y][x_place + x] == *player - 32)
		return (1);
	else
		return (0);
}

int		it_fits_ignore_overlap(t_board *board, t_shape *piece,
		t_place place, char *player)
{
	place.x = 0;
	place.y = 0;
	while (place.y < piece->dim_y)
	{
		while (place.x < piece->dim_x)
		{
			if (place.x == piece->dim_x - 1 && place.y == piece->dim_y - 1
					&& cell_fits(board, piece, place, player))
			{
				piece->pos.x = place.x_place;
				piece->pos.y = place.y_place;
				return (1);
			}
			if (!cell_fits(board, piece, place, player))
				return (0);
			place.x++;
		}
		place.x = 0;
		place.y++;
	}
	return (0);
}

int		cell_overlaps(t_board *board, t_shape *piece, t_place place,
		char *player)
{
	int x;
	int y;
	int x_place;
	int y_place;

	x = place.x;
	y = place.y;
	x_place = place.x_place;
	y_place = place.y_place;
	if (piece->data[y][x] == '.')
		return (0);
	else if (x_place + x >= board->dim_x || y_place + y >= board->dim_y)
		return (0);
	else if (board->data[y_place + y][x_place + x] == *player)
		return (1);
	else if (board->data[y_place + y][x_place + x] == *player - 32)
		return (1);
	return (0);
}

int		times_it_overlaps(t_board *board, t_shape *piece,
		t_place place, char *player)
{
	int overlap_count;
	int cell_x;
	int cell_y;
	int x_place;
	int y_place;

	x_place = place.x_place;
	y_place = place.y_place;
	cell_x = 0;
	cell_y = 0;
	overlap_count = 0;
	while (cell_y < piece->dim_y)
	{
		while (cell_x < piece->dim_x)
		{
			place.x = cell_x;
			place.y = cell_y;
			if (cell_overlaps(board, piece, place, player))
				overlap_count++;
			cell_x++;
		}
		cell_x = 0;
		cell_y++;
	}
	return (overlap_count);
}

int		try_place(t_board *board, t_shape *piece,
		t_place place, char *player)
{
	if (it_fits_ignore_overlap(board, piece, place, player))
	{
		if (times_it_overlaps(board, piece, place, player) == 1)
			return (1);
	}
	return (0);
}
