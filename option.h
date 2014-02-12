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
** File name: option.h
** Made by: jchichep
** File created  on  Tue Sep  3 15:46:16 2013 by jchichep
** Last modified on  Thu Sep  5 18:35:27 2013 by jchichep
*/

#ifndef OPTION_H
# define OPTION_H

typedef struct	s_option
{
  int		key;
  void		(*ptr_func)();
}		t_opt;

int		get_option(int key, t_opt *g_option);
void		easy_level();
void		med_level();
void		hard_level();
void		custom_level();
void		quit();

#endif /* !OPTION_H */
