/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 09:10:43 by psambo            #+#    #+#             */
/*   Updated: 2018/09/21 09:46:06 by psambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_clear_terminal(void)
{
	tputs(tgetstr("cl", NULL), 1, ft_put_char);
}

int		ft_change_term_behavior(struct termios *term)
{
	if (tgetent(NULL, getenv("TERM")) == -1)
		return (-1);
	if (tcgetattr(FILE_DS, term) == -1)
		return (-1);
	term->c_lflag &= ~(ICANON | ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(FILE_DS, TCSANOW, term) == -1)
		return (-1);
	tputs(tgetstr("ti", NULL), 1, ft_put_char);
	tputs(tgetstr("vi", NULL), 1, ft_put_char);
	return (0);
}

int		ft_reset_term_behavior(struct termios *term)
{
	tputs(tgetstr("ve", NULL), 1, ft_put_char);
	tputs(tgetstr("te", NULL), 1, ft_put_char);
	term->c_lflag |= (ICANON | ECHO);
	if ((tcsetattr(FILE_DS, TCSANOW, term)) == -1)
		return (-1);
	return (0);
}
