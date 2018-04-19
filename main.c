/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:03:56 by ikarishe          #+#    #+#             */
/*   Updated: 2018/04/16 14:48:37 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int	main(void)
{
	t_board *board;
	t_shape *piece;
	char	player;

	board = NULL;
	piece = NULL;
	player = '0';
	board = (t_board*)malloc(sizeof(*board));
	piece = (t_shape*)malloc(sizeof(*piece));
	while (ft_read(board, piece, &player))
	{
		ft_play(board, piece, &player);
	}
	return (0);
}
