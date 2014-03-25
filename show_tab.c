/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchichep <jchichep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 08:25:27 by jchichep          #+#    #+#             */
/*   Updated: 2014/03/25 08:36:59 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<time.h>
#include	"color.h"
#include	"function.h"
#include	"show_tab.h"
#include	"cursor.h"

static t_show	g_show[] =
{
    {'-', '-', BLANC},
    {'1', '1', M1},
    {'2', '2', M2},
    {'3', '3', M3},
    {'4', '4', M4},
    {'5', '5', M5},
    {'6', '6', M6},
    {'7', '7', M7},
    {'8', '8', M8},
    {'B', 'B', GO},
    {'W', 'F', FLAG},
    {'F', 'F', FLAG},
    {'X', ' ', NORMAL},
    {0, 0, NORMAL},
    {'-', '-', RBLANC},
    {'1', '1', RM1},
    {'2', '2', RM2},
    {'3', '3', RM3},
    {'4', '4', RM4},
    {'5', '5', RM5},
    {'6', '6', RM6},
    {'7', '7', RM7},
    {'8', '8', RM8},
    {'B', 'B', RGO},
    {'W', 'F', RFLAG},
    {'F', 'F', RFLAG},
    {'X', ' ', BLANC},
};

static t_show	g_finish[] =
{
    {'-', '-', BLANC},
    {'1', '1', M1},
    {'2', '2', M2},
    {'3', '3', M3},
    {'4', '4', M4},
    {'5', '5', M5},
    {'6', '6', M6},
    {'7', '7', M7},
    {'8', '8', M8},
    {'B', 'B', GO},
    {'W', 'W', RGO},
    {'F', 'F', FLAG},
    {'X', 'X', GO},
    {0, 0, NORMAL},
};

void		show_column_number(t_size *size)
{
	int		i;

	i = 1;
	if (size->l > 10)
	{
		ft_putstr("    ");
		while (i <= size->l)
		{
			ft_putchar('0' + (i / 10) % 10);
			i++;
		}
		ft_putchar('\n');
		i = 1;
	}
	ft_putstr("    ");
	while (i <= size->l)
	{
		ft_putchar('0' + i % 10);
		i++;
	}
	ft_putchar('\n');
}

#include	"color.h"

void		show_carac(char c, int r, int f)
{
	int		i;

	i = 0;
	while (g_show[i].c)
    {
		if (g_show[i].c == c)
		{
			if (r == 1)
				i += 14;
			if (f == 0)
			{
				ft_putstr(g_show[i].color);
				ft_putchar(g_show[i].show_c);
			}
			if (f == 1)
			{
				ft_putstr(g_finish[i].color);
				ft_putchar(g_finish[i].show_c);
			}
			ft_putstr(NORMAL);
			return ;
		}
		i++;
	}
	if (g_show[i].c == 0)
	{
		if (r == 1)
			ft_putstr(BLANC);
		ft_putchar(' ');
		ft_putstr(NORMAL);
    }
}

void		show_beg_of_line(int line)
{
	ft_putnbr(line);
	if (line < 10)
		ft_putstr("  |");
	else
		ft_putstr(" |");
}

void		show_border_line(t_size *size, char c)
{
  int		i;

  i = 0;
  ft_putstr("   *");
  ft_putstr(GRAS);
  while (i < size->l)
    {
      ft_putchar(c);
      i++;
    }
  ft_putstr(NORMAL);
  ft_putstr("*\n");
}

void		show_tab(char **map, t_size *size, t_cursor *cursor)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	show_column_number(size);
	show_border_line(size, '_');
	while (i < size->h)
	{
		show_beg_of_line(i + 1);
		while (j < size->l)
		{
			if (cursor->x == i && cursor->y == j)
				show_carac(map[i][j], 1 , 0);
			else
				show_carac(map[i][j], 0, 0);
			j++;
		}
		ft_putstr("|\n");
		j = 0;
		i++;
	}
	show_border_line(size, '-');
}

void		show_finish(char **map, t_size *size, int win, time_t *t)
{
	int		i;
	int		j;
	time_t	res;
	double	timer;

	res = time(&res);
	timer = difftime(res, *t);
	timer = timer;
	ft_putstr("\033[H\033[2J");
	win = win;
	i = 0;
	j = 0;
	show_column_number(size);
	show_border_line(size, '_');
	while (i < size->h)
    {
		show_beg_of_line(i + 1);
		while (j < size->l)
		{
			show_carac(map[i][j], 0, 1);
			j++;
		}
		ft_putstr("|\n");
		j = 0;
		i++;
	}
	show_border_line(size, '-');
	if (win == 0)
	{
		ft_putstr_color("You win the GAME!\n\n", M2);
		/* ft_putstr("Time taken: ");
		ft_putnbr((int)timer);
		ft_putstr(" seconds.\n");*/
	}
	else
		ft_putstr_color("You lose the GAME... 2 times!\n", M1);
	ft_putstr("Made By Jchichep alias Bueno\n");
	quit();
}
