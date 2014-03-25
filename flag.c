/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchichep <jchichep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 08:23:22 by jchichep          #+#    #+#             */
/*   Updated: 2014/03/25 08:35:57 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cursor.h"

void		flag(char **map, t_cursor *cursor)
{
	if (map[cursor->x][cursor->y] == 'X')
		map[cursor->x][cursor->y] = 'F';
	else if (map[cursor->x][cursor->y] == 'F')
		map[cursor->x][cursor->y] = 'X';
	else if (map[cursor->x][cursor->y] == ' ')
		map[cursor->x][cursor->y] = 'W';
	else if (map[cursor->x][cursor->y] == 'W')
		map[cursor->x][cursor->y] = ' ';
}
