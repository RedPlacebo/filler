/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_strength.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:36:07 by ikarishe          #+#    #+#             */
/*   Updated: 2018/04/16 16:44:56 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	copy_board_data(t_board *board, t_board *new_board)
{
	int y;

	y = 0;
	new_board->dim_x = board->dim_x;
	new_board->dim_y = board->dim_y;
	while (y < board->dim_y)
	{
		new_board->data[y] = ft_strdup(board->data[y]);
		y++;
	}
}

void	place_piece(t_board *new_board, t_shape *piece, t_pos pos_move,
		char *player)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < piece->dim_y)
	{
		while (x < piece->dim_x)
		{
			if (piece->data[y][x] != '.')
				new_board->data[pos_move.y + y][pos_move.x + x] = *player;
			x++;
		}
		x = 0;
		y++;
	}
}

void	init_board(t_board *board)
{
	board->sum_player_pos.x = 0;
	board->sum_player_pos.y = 0;
	board->player_cell_count = 0;
	board->player_surface_area = 0;
	board->sum_enemy_pos.x = 0;
	board->sum_enemy_pos.y = 0;
	board->enemy_cell_count = 0;
	board->player_touching_area = 0;
}

void	analyze_board(t_board *board, char *player)
{
	int x;
	int y;

	x = 0;
	y = 0;
	init_board(board);
	while (y < board->dim_y)
	{
		while (x < board->dim_x)
		{
			check_char(board, player, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	board->player_avg_pos_x =
		board->sum_player_pos.x / board->player_cell_count;
	board->player_avg_pos_y =
		board->sum_player_pos.y / board->player_cell_count;
	board->enemy_avg_pos_x = board->sum_enemy_pos.x / board->enemy_cell_count;
	board->enemy_avg_pos_y = board->sum_enemy_pos.y / board->enemy_cell_count;
}

int		get_strength(t_board *board, t_shape *piece, t_pos pos_move,
		char *player)
{
	t_board		*new_board;
	int			strength;

	strength = -100;
	new_board = (t_board*)malloc(sizeof(*new_board));
	new_board->data = (char**)malloc(board->dim_x * board->dim_y * 2 *
			sizeof(char *));
	copy_board_data(board, new_board);
	place_piece(new_board, piece, pos_move, player);
	analyze_board(board, player);
	analyze_board(new_board, player);
	strength = analyze_boards(board, new_board, player);
	free_board_data(new_board);
	free(new_board->data);
	free(new_board);
	return (strength);
}
