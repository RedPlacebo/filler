/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:54:18 by ikarishe          #+#    #+#             */
/*   Updated: 2018/04/16 16:25:03 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"
#include <fcntl.h>

t_list	*find_strongest(t_list *head)
{
	int		strength;
	t_pos	pos;
	t_list	*best;

	best = head;
	strength = -101;
	while (head)
	{
		pos = *(t_pos*)head->content;
		if (pos.strength > strength)
		{
			strength = pos.strength;
			best = head;
		}
		head = head->next;
	}
	return (best);
}

t_list	*create_move_list(t_board *board, t_shape *piece, char *play,
		t_list *head)
{
	t_list	*node;
	t_pos	pos_move;
	t_place	place;

	place.x_place = 0;
	place.y_place = 0;
	while (place.y_place < board->dim_y)
	{
		while (place.x_place < board->dim_x)
		{
			if (try_place(board, piece, place, play) == 1)
			{
				pos_move.x = place.x_place;
				pos_move.y = place.y_place;
				pos_move.strength = get_strength(board, piece, pos_move, play);
				node = ft_lstnew(&pos_move, sizeof(pos_move));
				ft_lstadd(&head, node);
			}
			place.x_place++;
		}
		place.x_place = 0;
		place.y_place++;
	}
	return (head);
}

void	ft_play(t_board *board, t_shape *piece, char *player)
{
	t_list	*head;
	t_list	*node;
	t_pos	pos_move;

	pos_move.x = -1;
	pos_move.y = -1;
	pos_move.strength = -100000;
	head = ft_lstnew(&pos_move, sizeof(pos_move));
	head = create_move_list(board, piece, player, head);
	pos_move = *(t_pos*)head->content;
	if (pos_move.x != -1 && pos_move.y != -1)
	{
		node = find_strongest(head);
		pos_move = *(t_pos*)node->content;
		ft_put_move(pos_move.y, pos_move.x);
	}
	else
		ft_put_move(-1, -1);
	free_board_data(board);
	free_piece_data(piece);
	free(board->data);
	free(piece->data);
	delete_list(&head);
}
