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
** Project name: demineur
** File name: function.h
** Made by: jchichep
** File created  on  Tue Sep  3 14:17:51 2013 by jchichep
** Last modified on  Sat Sep 14 02:15:26 2013 by jchichep
*/

#ifndef FUNCTION_H
# define FUNCTION_H

#include	<time.h>
#include	"size.h"
#include	"cursor.h"

void		catch_sigint(int sig);
void		set_raw_mode();
void		unset_raw_mode();
int		ft_atoi(char *str);
void		ft_putstr(char *str);
void		ft_putchar(char c);
void		ft_putnbr(char c);
void		ft_bzero(char *str, int len);
void		ft_putstr_color(char *str, char *color);
int		show_menu();
int		get_key();
void		show_tab(char **map, t_size *size, t_cursor *cursor);
int		finish(char **map, t_size *size);
void		show_finish(char **map, t_size *size, int win, time_t *t);
void		start_game(t_size *size);
void		go_right(t_cursor *cursor, t_size *size);
void		go_left(t_cursor *cursor, t_size *size);
void		go_up(t_cursor *cursor, t_size *size);
void		go_down(t_cursor *cursor, t_size *size);
void		flag(char **map, t_cursor *cursor);
int		check_map(char **map,t_cursor *cursor, t_size *size);
int		check_case(char **map, t_cursor *cursor, t_size *size);
void		quit();

#endif /* !FUNCTION_H */
