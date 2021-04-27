NAME = checker

LIBFT = libft.a

FTPRINTF = libftprintf.a

SRCD = ./src

CUBD= bibz/libcheck.a

LIBFTD = ../fct/libft/

GNL = ../fct/GNL

INCL = bibz

COMPILE = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =		$(SRCD)/action.c \
			$(SRCD)/utils3.c \
			$(SRCD)/utils2.c \
			$(SRCD)/utils.c \
			$(SRCD)/ft_ch.c \
			$(GNL)/get_next_line.c \
			$(GNL)/get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(COMPILE) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ) $(SRCD)/main.c
		rm -rf $(NAME)
		make -C $(LIBFTD)
		cp $(LIBFTD)$(LIBFT) ./$(CUBD)
		ar rc $(CUBD) $(OBJ)
		/bin/rm -f $(LIBFT)
		ranlib $(CUBD)
		$(COMPILE) -o $(NAME) $(SRCD)/main.c  $(CUBD) -I$(INCL)
clean:
	rm -rf $(OBJ)
	rm -rf objects
	make clean -C $(LIBFTD)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)
	rm -rf $(CUBD)
	rm -rf checker.dSYM
	make fclean -C $(LIBFTD)

re: fclean all

.PHONY: clean fclean all re
