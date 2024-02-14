# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rutatar <rutatar@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 15:26:01 by rutatar           #+#    #+#              #
#    Updated: 2024/01/28 15:26:06 by rutatar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS_NAME = checker

LIBFT = libft

LIBFTM = libft/libft.a

PRINTF = ft_printf

PRINTFM = ft_printf/libftprintf.a

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror

CFILES_1 = push_swap.c

CFILES_2 = 	tools_p.c \
			tools_rr.c \
			tools_r.c \
			tools_s.c \
			utils.c \
			utils0.c \
			quicksort.c \
			quick_utils.c \
			utils_1.c

BONUS_FILES = checker.c

OBJS_1 = $(CFILES_1:.c=.o)

OBJS_2 = $(CFILES_2:.c=.o)

BONUS_OBJS = $(BONUS_FILES:.c=.o)


$(NAME): $(OBJS_1) $(OBJS_2)
	@make -C $(LIBFT)
	@make -C $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS_1) $(OBJS_2) $(LIBFTM) $(PRINTFM) -o $(NAME)
	@echo "\n\033[33mPush_swap is ready ✅\033[0m\n"

$(BONUS_NAME): $(BONUS_OBJS) $(OBJS_1) $(OBJS_2)
	@make -C $(LIBFT)
	@make -C $(PRINTF)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(OBJS_2) $(LIBFTM) $(PRINTFM) -o $(BONUS_NAME)
	@echo "\n\033[33mChecker is ready ✅\033[0m\n"

all: $(NAME)
	@echo "\n\033[33mAll files compiled successfully ✅\033[0m\n"

bonus: ${BONUS_NAME}
	@echo "\n\033[33mBonus files compiled successfully ✅\033[0m\n"

clean:
		@rm -f $(OBJS_1) $(OBJS_2) $(BONUS_OBJS)
		@make clean -C $(LIBFT)
		@make clean -C $(PRINTF)
		@echo "\n\033[33mObjects files deleted ✅\033[0m\n"

fclean: clean
		@make fclean -C $(LIBFT)
		@make fclean -C $(PRINTF)
		@rm -rf $(NAME) $(BONUS_NAME)
		@echo "\n\033[33mArchive file deleted ✅\033[0m\n"

re: fclean all

.PHONY: re fclean clean bonus all
