/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchichep <jchichep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 08:23:34 by jchichep          #+#    #+#             */
/*   Updated: 2014/03/25 08:37:45 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include	<time.h>
# include	"size.h"
# include	"cursor.h"

void		catch_sigint(int sig);
void		set_raw_mode();
void		unset_raw_mode();
int			ft_atoi(char *str);
void		ft_putstr(char *str);
void		ft_putchar(char c);
void		ft_putnbr(char c);
void		ft_bzero(char *str, int len);
void		ft_putstr_color(char *str, char *color);
int			show_menu(void);
int			get_key(void);
void		show_tab(char **map, t_size *size, t_cursor *cursor);
int			finish(char **map, t_size *size);
void		show_finish(char **map, t_size *size, int win, time_t *t);
void		start_game(t_size *size);
void		go_right(t_cursor *cursor, t_size *size);
void		go_left(t_cursor *cursor, t_size *size);
void		go_up(t_cursor *cursor, t_size *size);
void		go_down(t_cursor *cursor, t_size *size);
void		flag(char **map, t_cursor *cursor);
int			check_map(char **map, t_cursor *cursor, t_size *size);
int			check_case(char **map, t_cursor *cursor, t_size *size);
void		quit(void);

#endif /* !FUNCTION_H */
