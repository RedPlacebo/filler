/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:04:29 by ikarishe          #+#    #+#             */
/*   Updated: 2018/04/16 15:07:55 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		count_empty_neighbors(t_board *board, int x, int y)
{
	int count;

	count = 0;
	if (!(y - 1 < 0))
		if (board->data[y - 1][x] == '.')
			count++;
	if (!(y + 1 >= board->dim_y))
		if (board->data[y + 1][x] == '.')
			count++;
	if (!(x + 1 >= board->dim_x))
		if (board->data[y][x + 1] == '.')
			count++;
	if (!(x - 1 < 0))
		if (board->data[y][x - 1] == '.')
			count++;
	return (count);
}

int		count_touching(t_board *board, int x, int y, char *player)
{
	int		count;
	char	en;

	if (*player == 'x')
		en = 'o';
	else
		en = 'x';
	count = 0;
	if (!(y - 1 < 0))
		if (board->data[y - 1][x] == en || board->data[y - 1][x] == en - 32)
			count++;
	if (!(y + 1 >= board->dim_y))
		if (board->data[y + 1][x] == en || board->data[y + 1][x] == en - 32)
			count++;
	if (!(x + 1 >= board->dim_x))
		if (board->data[y][x + 1] == en || board->data[y][x + 1] == en - 32)
			count++;
	if (!(x - 1 < 0))
		if (board->data[y][x - 1] == en || board->data[y][x - 1] == en - 32)
			count++;
	return (count);
}

void	check_char(t_board *board, char *player, int x, int y)
{
	char	enemy;

	if (*player == 'x')
		enemy = 'o';
	else
		enemy = 'x';
	if (board->data[y][x] == enemy || board->data[y][x] == enemy - 32)
	{
		board->enemy_cell_count++;
		board->sum_enemy_pos.x += x;
		board->sum_enemy_pos.y += y;
	}
	else if (board->data[y][x] == *player || board->data[y][x] == *player - 32)
	{
		board->player_cell_count++;
		board->sum_player_pos.x += x;
		board->sum_player_pos.y += y;
		board->player_surface_area += count_empty_neighbors(board, x, y);
		board->player_touching_area += count_touching(board, x, y, player);
	}
}
