/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchichep <jchichep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 08:21:55 by jchichep          #+#    #+#             */
/*   Updated: 2014/03/25 08:32:31 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"function.h"
#include	"option.h"
#include	"key.h"

int		check_case(char **map, t_cursor *cursor, t_size *size)
{
	int		ret;
	int		i;
	int		j;

	ret = 0;
	i = cursor->x - 1;
	while (i < cursor->x + 2)
	{
		j = cursor->y - 1;
		while (j < cursor->y + 2)
		{
			if (!(i < 0 || j < 0 || i >= size->h || j >= size->l)
				&& (map[i][j] == 'X' || map[i][j] == 'F'))
				ret++;
			j++;
		}
		i++;
	}
	return (ret);
}

int		finish(char **map, t_size *size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < size->h)
	{
		while (j < size->l)
		{
			if (map[i][j] == ' ' || map[i][j] == 'W')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
