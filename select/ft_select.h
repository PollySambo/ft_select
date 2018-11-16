/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 09:27:21 by psambo            #+#    #+#             */
/*   Updated: 2018/09/22 15:38:21 by psambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# define FILE_DS 2

/*
** Include headers
*/

# include <term.h>
# include <curses.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>
# include <sys/ioctl.h>

/*
** Colour codes
*/

# define YELLOW "\x1b[33m"
# define BLACK "\x1b[47m"
# define NO_COLOUR "\x1b[0m"

/*
** Struct to hold data
*/

typedef struct		s_pick
{
	struct termios	term;
	struct winsize	win;
	char			**items;
	int				*selected;
	int				n_items;
	int				pos;
}					t_pick;

t_pick			*ft_save_and_load(t_pick *pick, int mode);

/*
** list functions
*/

int					ft_strlen(char *str);
char				*ft_strdup(char *str);
void				ft_add_list(t_pick *pick, int n, char **list);
void				ft_print_list(t_pick *pick);
int					ft_get_longest_item(t_pick *pick);
void				free_memory(t_pick *pick);

/*
** Stop the procces
*/

void				exiting(void);

/*
** Printing functions
*/

int					ft_putchar(int c);
int					ft_putchar_fd(int c, int fd);
void				ft_putstr(char *str);
void				ft_putstr_fd(char *str, int fd);
void				ft_putendl(char *str);
void				yellow(char *str);
void				underline(char *str, void (*ft_pt)(char*));
void				highlight(char *str, void (*ft_pt)(char*));

/*
** Edit terminal's configuration
*/

void				clear_iterm(void);
int					change_iterm(struct termios *term);
int					reset_iterm(struct termios *term);

/*
** Handle signals
*/

void				signals_handle(void);
void				wind_chage(void);

/*
** Handle keyboard input
*/

void				keyboard(void);
void				up_cursor(t_pick *pick);
void				down_cursor(t_pick *pick);
void				ft_select_item(t_pick *pick);
void				enter(t_pick *pick);
//void				ft_remove_item(t_select *select);
void				ft_clear(char *str);

#endif
