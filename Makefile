# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 12:59:23 by klakbuic          #+#    #+#              #
#    Updated: 2024/02/22 10:45:21 by klakbuic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
BONUS   = checker
HEADER  = ../inc/push_swap.h

CC       = cc
CFLAGS   = -Wall -Wextra -Werror

LIB      = libs/libft/libft.a libs/ft_containers/containersft.a

SRCS     = src/ft_atoi_enhanced.c src/ft_check_args.c src/ft_push.c src/ft_rorate.c \
           src/ft_rrotate.c src/ft_swap.c src/main.c src/ft_sort.c src/ft_qsort.c \
		   src/ft_sort_utils.c src/ft_stack_rpush.c src/ft_small_sort.c src/ft_sort_utils2.c

SRCS_B   = src_bonus/ft_checker.c src_bonus/get_next_line.c src_bonus/get_next_line_utils.c \
		   src_bonus/ft_atoi_enhanced.c src_bonus/ft_check_args.c \
		   src_bonus/ft_stack_rpush.c src_bonus/ft_push.c src_bonus/ft_rorate.c \
           src_bonus/ft_rrotate.c src_bonus/ft_swap.c src_bonus/ft_is_sorted.c

OBJS    = $(SRCS:.c=.o)
OBJS_B    = $(SRCS_B:.c=.o)

all: $(NAME)

$(LIB):
	@make -C libs/libft --quiet
	@make -C libs/ft_containers --quiet


$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -I $(HEADER) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJS_B)
	@$(CC) $(CFLAGS) $(OBJS_B) $(LIB) -I $(HEADER) -o $(BONUS)

clean:
	@make clean -C libs/libft --quiet
	@make clean -C libs/ft_containers --quiet
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_B)


fclean: clean
	@make fclean -C libs/libft --quiet
	@make fclean -C libs/ft_containers --quiet
	@$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean clean_b fclean fclean_bonus re re_bonus
