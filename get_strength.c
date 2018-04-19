/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_strength.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 12:29:22 by ikarishe          #+#    #+#             */
/*   Updated: 2018/04/19 13:07:34 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

double	ft_dabs(double num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int		com_dist(t_board *new_board)
{
	int str;

	str = 1000;
	str = str - (ft_dabs(new_board->sum_enemy_pos.x -
				new_board->sum_player_pos.x) +
			ft_dabs(new_board->sum_enemy_pos.y -
				new_board->sum_player_pos.y));
	return (str);
}

int		grab_top_strength(t_board *board, t_board *new_board)
{
	int strength;

	strength = 0;
	strength = new_board->player_surface_area - board->player_surface_area;
	strength += (2 * com_dist(new_board));
	strength += (10000 * (board->dim_x * board->dim_y -
				(new_board->sum_player_pos.y - board->sum_player_pos.y)));
	return (strength);
}

int		grab_bot_strength(t_board *board, t_board *new_board)
{
	int strength;

	strength = 0;
	strength += (200 * com_dist(new_board));
	strength += (10000 * (new_board->sum_player_pos.y -
				board->sum_player_pos.y));
	return (strength);
}
