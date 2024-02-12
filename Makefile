# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klakbuic <klakbuic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 12:59:23 by klakbuic          #+#    #+#              #
#    Updated: 2024/02/12 13:13:51 by klakbuic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
BONUS   = checker
HEADER  = ../inc/push_swap.h

CC       = cc
CFLAGS   = -Wall -Wextra -Werror -fsanitize=address

LIB      = libs/libft/libft.a libs/ft_containers/containersft.a

SRCS     = src/ft_atoi_enhanced.c src/ft_check_args.c src/ft_push.c src/ft_rorate.c \
           src/ft_rrotate.c src/ft_swap.c src/main.c src/ft_sort.c src/ft_qsort.c

SRCS_B   = 

OBJS    = $(SRCS:.c=.o)
OBJS_B    = $(SRCS_B:.c=.o)

all: $(NAME)

$(LIB):
	@make -C libs/libft --quiet
	@make -C libs/ft_containers --quiet


$(NAME): $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -I $(HEADER) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJS_B)
	@$(CC) $(CFLAGS) $(OBJS_B) checker.c -o $(BONUS)

clean:
	@make clean -C libs/libft --quiet
	@make clean -C libs/ft_containers --quiet
	@$(RM) $(OBJS)

clean_bonus:
	@$(RM) $(OBJS_B)

fclean: clean
	@make fclean -C libs/libft --quiet
	@make fclean -C libs/ft_containers --quiet
	@$(RM) $(NAME)

fclean_bonus: clean_bonus
	@$(RM) $(NAME)

re: fclean all

re_bonus: fclean_bonus bonus

.PHONY: all bonus clean clean_b fclean fclean_bonus re re_bonus
.SECONDARY: $(OBJS)

COMMENT := "automtic push"
push:
	git add .
	git commit -m "$(COMMENT)"
	git push