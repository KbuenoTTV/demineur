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
** File name: move_function.c
** Made by: jchichep
** File created  on  Thu Sep  5 20:11:40 2013 by jchichep
** Last modified on  Fri Sep  6 11:29:10 2013 by jchichep
*/

#include	"cursor.h"
#include	"size.h"

void		go_down(t_cursor *cursor, t_size *size)
{
  cursor->x += 1;
  cursor->x %= size->h;
}

void		go_up(t_cursor *cursor, t_size *size)
{
  cursor->x -= 1;
  if (cursor->x < 0)
    cursor->x += size->h;
}

void		go_right(t_cursor *cursor, t_size *size)
{
  cursor->y += 1;
  cursor->y %= size->l;
}

void		go_left(t_cursor *cursor, t_size *size)
{
  cursor->y -= 1;
  if (cursor->y < 0)
    cursor->y += size->l;
}

