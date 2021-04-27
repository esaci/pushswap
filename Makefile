
CHECKF = checkerf

CHECKO = checker

PUSHF = pushswapf

PUSHO = push_swap

all				:	$(CHECKO) $(PUSHO)
					@ $(shell cp $(CHECKF)/$(CHECKO) . )
					@ $(shell cp $(PUSHF)/$(PUSHO) . )

$(CHECKO)		:
					@ $(MAKE) --silent -C $(CHECKF)

$(PUSHO)	:
					@ $(MAKE) --silent -C $(PUSHF)

clean			:
					@ $(MAKE) fclean --silent -C $(CHECKF) > /dev/null 2>&1
					@ $(MAKE) fclean --silent -C $(PUSHF) > /dev/null 2>&1

fclean			:
					@ rm -rf $(PUSHO) $(CHECKO)
					@ $(MAKE) fclean --silent -C $(CHECKF) > /dev/null 2>&1
					@ $(MAKE) fclean --silent -C $(PUSHF) > /dev/null 2>&1

re				: 	fclean all

.PHONY: 		all fclean clean re
