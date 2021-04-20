
CHECKF = ./checkerf/

CHECKO = checker

PUSHF = ./pushswapf/

PUSHO = push_swap


all: $(NAME)

$(NAME) : rm -rf $(CHECKO)
	rm -rf $(PUSHO)
	make $(CHECKF)
	cp $(CHECKF)$(CHECKO) ./$(CHECKO)
	make $(PUSHF)
	cp $(PUSHF)$(PUSHO) ./$(PUSHO)

clean:
	make clean $(CHECKF)
	make clean $(PUSHF)

fclean: clean
	make fclean $(CHECKF)
	make fclean $(PUSHF)
	rm -rf $(CHECKO)
	rm -rf $(PUSHO)

re: fclean all

.PHONY: clean fclean all re
