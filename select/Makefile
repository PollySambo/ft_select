# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psambo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/21 09:08:16 by psambo            #+#    #+#              #
#    Updated: 2018/09/21 13:51:25 by psambo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

FILES = designs.c exiting.c keyboard_inputs.c listing.c others.c printing.c signals.c term_config.c ft_select.c

HEADER = ft_select.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

BUILD_PRINT = @echo "\033[1;31mBuilding \"$>\"..."
DONE = @echo "\033[0;33mft_select ready to use!"
CLEAN_O = @echo "\033[0;34mObject files removed!"
CLEAN_A = @echo "\033[0;32mExecutable removed!"

$(NAME):
	@gcc $(FLAGS) $(FILES) $(HEADER) -ltermcap
	@mv a.out $(NAME)
	$(DONE)

clean:
	@rm -rf $(OBJECTS)
	$(CLEAN_O)

fclean: clean
	@rm -rf $(NAME)
	$(CLEAN_A)

re: fclean all
