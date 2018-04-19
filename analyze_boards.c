/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_boards.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:57:21 by ikarishe          #+#    #+#             */
/*   Updated: 2018/04/19 13:15:01 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		need_to_grab_top(t_board *board, char *player)
{
	int x;

	x = 0;
	while (x < board->dim_x)
	{
		if (board->data[0][x] == *player || board->data[0][x] == *player - 32)
			return (0);
		x++;
	}
	return (1);
}

int		need_to_grab_bottom(t_board *board, char *player)
{
	int x;
	int dim_y;

	x = 0;
	dim_y = board->dim_y;
	while (x < board->dim_x)
	{
		if (board->data[dim_y - 1][x] == *player ||
				board->data[dim_y - 1][x] == *player - 32)
			return (0);
		x++;
	}
	return (1);
}

int		analyze_boards(t_board *board, t_board *new_board, char *player)
{
	int strength;

	strength = 0;
	if (need_to_grab_top(board, player))
	{
		return (grab_top_strength(board, new_board));
	}
	else if (need_to_grab_bottom(board, player))
	{
		return (grab_bot_strength(board, new_board));
	}
	else if (board->enemy_avg_pos_x < board->player_avg_pos_x)
		strength += (board->dim_x * board->dim_y -
				(new_board->sum_player_pos.x - board->sum_player_pos.x));
	else
		strength += (new_board->sum_player_pos.x - board->sum_player_pos.x);
	if ((board->player_touching_area > 0) &&
			(new_board->player_touching_area != board->player_touching_area))
		strength += (board->dim_x * (new_board->player_touching_area
					- board->player_touching_area));
	return (strength);
}
