/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:14:49 by ikarishe          #+#    #+#             */
/*   Updated: 2018/04/19 13:46:26 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft_Final/libft.h"
#include "Libft_Final/get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;
	char *line;
	int wins = 0;
	int loses = 0;

	int i = 0;

	while (i < 100)
	{
		printf("game - %d ", i);
		system("./filler_vm -p1 players/ikarishe.filler -p2 players/carli.filler -f maps/map04 > samplegame");
		fd = open("filler.trace", O_RDONLY);
		while (get_next_line(fd, &line) != 0)
		{
			if (strstr(line, "seed"))
				printf("%s ", line);
			if (strstr(line, "players/ikarishe.filler won"))
			{
				wins++;
				printf("WIN\n");
			}
			else if (strstr(line, "players/carli.filler won"))
			{
				loses++;
				printf("LOSE\n");
			}
		}
		close(fd);
		i++;
	}
	printf("Wins(%d), Loses(%d)\n", wins, loses);
}
