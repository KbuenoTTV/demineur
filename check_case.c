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
** File name: check_case.c
** Made by: jchichep
** File created  on  Fri Sep  6 15:41:56 2013 by jchichep
** Last modified on  Sat Sep  7 19:02:20 2013 by jchichep
*/

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
	  if (!(i < 0 || j < 0 || i >= size->h || j >= size->l) && (map[i][j] == 'X' || map[i][j] == 'F'))
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
