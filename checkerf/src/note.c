3
2
1

3
1
2

231 123



2
4
3

rra 324  sa 234

all		:
	@ $(MAKE) --silent -C $(CHECKF)
	@ $(MAKE) --silent -C $(PUSHF)
	@ $(shell cp $(CHECKF)/$(CHECKO)  . )
	@ $(shell cp $(PUSHF)/$(PUSHO)  . )


clean		:
	@ $(MAKE) clean --silent -C $(CHECKF)
	@ $(MAKE) clean --silent -C $(PUSHF)

fclean: clean
	@ $(MAKE) fclean --silent -C $(CHECKF)
	@ $(MAKE) fclean --silent -C $(PUSHF)
	@ rm -rf $(CHECKO)
	@ rm -rf $(PUSHO)

re: fclean all

.PHONY: clean fclean all re
