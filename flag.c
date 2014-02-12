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
** File name: flag.c
** Made by: jchichep
** File created  on  Sat Sep  7 13:35:24 2013 by jchichep
** Last modified on  Sat Sep  7 13:40:21 2013 by jchichep
*/

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
