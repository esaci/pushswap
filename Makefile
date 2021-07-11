NAME = checker

NAMEP = push_swap

LIBFT = libft.a

FTPRINTF = libftprintf.a

SRCD = ./checkerf/src

SRCDP = ./pushswapf/src

CUBD= ./checkerf/bibz/libcheck.a

CUBDP= ./pushswapf/bibz/libpush.a

LIBFTD = ./fct/libft/

GNL = ./fct/GNL

INCL = ./checkerf/bibz

INCLP = ./pushswapf/bibz

COMPILE = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =		$(SRCD)/action.c \
			$(SRCD)/utils3.c \
			$(SRCD)/utils2.c \
			$(SRCD)/utils.c \
			$(SRCD)/ft_ch.c \
			$(SRCD)/game_char.c \
			$(GNL)/get_next_line.c \
			$(GNL)/get_next_line_utils.c \

SRCP =		$(SRCDP)/gestrr.c \
			$(SRCDP)/utils5.c \
			$(SRCDP)/utils4.c \
			$(SRCDP)/utils3.c \
			$(SRCDP)/utils2.c \
			$(SRCDP)/utils.c \
			$(SRCDP)/median.c \
			$(SRCDP)/game_char.c \
			$(SRCDP)/instructions.c \
			$(GNL)/get_next_line.c \
			$(GNL)/get_next_line_utils.c \

OBJ = $(SRC:.c=.o)
OBJP = $(SRCP:.c=.o)

%.o: %.c
	$(COMPILE) $(CFLAGS) -c $< -o $@

all: $(NAME) $(NAMEP)

$(NAME) : $(OBJ) $(SRCD)/main.c
		rm -rf $(NAME)
		make -C $(LIBFTD)
		cp $(LIBFTD)$(LIBFT) ./$(CUBD)
		ar rc $(CUBD) $(OBJ)
		/bin/rm -f $(LIBFT)
		ranlib $(CUBD)
		$(COMPILE) -o $(NAME) $(SRCD)/main.c  $(CUBD) -I$(INCL)

$(NAMEP) : $(OBJP) $(SRCDP)/main.c
		rm -rf $(NAMEP)
		make -C $(LIBFTD)
		cp $(LIBFTD)$(LIBFT) ./$(CUBDP)
		ar rc $(CUBDP) $(OBJP)
		/bin/rm -f $(LIBFT)
		ranlib $(CUBDP)
		$(COMPILE) -o $(NAMEP) $(SRCDP)/main.c  $(CUBDP) -I$(INCLP)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJP)
	make clean -C $(LIBFTD)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAMEP)
	rm -rf $(LIBFT)
	rm -rf $(CUBD)
	rm -rf $(CUBDP)
	rm -rf ./checkerf/checker.dSYM
	make fclean -C $(LIBFTD)

re: fclean all

.PHONY: clean fclean all re

