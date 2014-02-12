/*
**          444    222222          GGG     AAA     MM   MM EEEEE
**         4444        222       GG       AA AA    MMMMMMM EE
**        44 44          22      GG  G   AA   AA   MM M MM EEEEE
**       44  44          22      GG  G  AAAAAAAAA  MM   MM EE
**      44   44         22         GGG AA       AA MM   MM EEEEE
**     4444444444      22
**     4444444444     22      SS  TTTTTT UU    UU DDDD   II   OOOO
**           44      22      SS     TT   UU    UU DD  DD II  OO  OO
**           44     22        SS    TT   UU    UU DD  DD II OO    OO
**           44    222         SS   TT   UU    UU DD  DD II  OO  OO
**           44    22222222   SS    TT     UUUU   DDDD   II   OOOO
**
** Project name: Demineur
** File name: start_game.c
** Made by: jchichep
** File created  on  Wed Sep  4 19:48:51 2013 by jchichep
** Last modified on  Fri Jan  3 16:34:41 2014 by jchichep
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<time.h>
#include	"function.h"
#include	"option.h"
#include	"key.h"

static t_opt	g_option[]=
  {
    {UP, go_up},
    {DOWN, go_down},
    {LEFT, go_left},
    {RIGHT, go_right},
    {'q', quit},
    {'f', flag},
    {0, NULL},
  };

int		check_map(char **map, t_cursor *cursor, t_size *size)
{
  char		nb;
  t_cursor	temp;

  temp.x = cursor->x - 1;
  temp.y = cursor->y - 1;
  if (cursor->x < 0 || cursor->y < 0 || cursor->x >= size->h || cursor->y >= size->l)
    return (0);
  if (map[cursor->x][cursor->y] != ' ' && map[cursor->x][cursor->y] != 'X')
    return (0);
  nb = '0';
  if (map[cursor->x][cursor->y] == 'X')
  {
    map[cursor->x][cursor->y] = 'B';
    return (1);
  }
  nb += check_case(map, cursor, size);
  map[cursor->x][cursor->y] = nb;
  if (nb == '0')
    {
      map[cursor->x][cursor->y] = '-';
      while (temp.x < cursor->x + 2)
	{
	  temp.y = cursor->y - 1;
	  while (temp.y < cursor->y + 2)
	    {
	      check_map(map, &temp, size);
	      temp.y++;
	    }
	  temp.x++;
	}
    }
  return (0);
}

int		move(int key, t_cursor *cursor, t_size *size, char **map)
{
  int		i;

  i = 0;
  while (g_option[i].key)
    {
      if (i == 4 && g_option[i].key == key)
	quit();
      else if (i == 5 && g_option[i].key == key)
	flag(map, cursor);
      else if (g_option[i].key == key)
	{
	  g_option[i].ptr_func(cursor, size);
	  return (0);
	}
      i++;
    }
  if (g_option[i].key == 0)
    {
      return (-1);
    }
  return (0);
}

void		set_mines(char **map, t_size *size)
{
  int		mh;
  int		mw;
  int		monboard;

  srand(time(0));
  monboard = 0;
  while (monboard < size->m)
    {
      mh = rand() % size->h;
      mw = rand() % size->l;
      if (map[mh][mw] == ' ')
	{
	  map[mh][mw] = 'X';
	  monboard++;
	}
    }
}

char		**setmap(t_size *size)
{
  char		**map;
  int		i;
  int		j;

  i = 0;
  j = 0;
  map = malloc(sizeof(*map) * size->h);
  while (i < size->h)
    {
      map[i] = malloc(sizeof(**map) * (size->l + 1));
      ft_bzero(map[i], size->l + 1);
      while (j < size->l)
	{
	  map[i][j] = ' ';
	  j++;
	}
      j = 0;
      i++;
    }
  return (map);
}

void		start_game(t_size *size)
{
	char		**tab;
	t_cursor	cursor;
	int		key;
	int		setmines;
	time_t	t;

	time(&t);
	setmines = 0;
	cursor.x = 0;
	cursor.y = 0;
	tab = setmap(size);
	while (finish(tab, size) == 0)
	{
		ft_putstr("\033[H\033[2J");
		show_tab(tab, size, &cursor);
		key = get_key();
		if (key == '\n')
		{
			if (setmines == 0)
			{
				tab[cursor.x][cursor.y] = '0';
				set_mines(tab, size);
				tab[cursor.x][cursor.y] = ' ';
				setmines = 1;
			}
			check_map(tab, &cursor, size);
			if (tab[cursor.x][cursor.y] == 'B')
				show_finish(tab, size, 1, &t);
		}
		move(key, &cursor, size, tab);
    }
	show_finish(tab,size, 0, &t);
}
