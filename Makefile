NAME				=	ft_libc.a

CC 					=	@clang
CFLAGS 				=	-Wall -Werror -Wextra -Iincludes
INCLUDES_PATH		=	./includes

MAKE				=	make --no-print-directory\
							INCLUDES_PATH=../../$(INCLUDES_PATH)\
							NAME=../../$(NAME)
COPY				=	@cp $@ $(NAME)
AR					=	@ar

SRCS_PATH			=	./srcs

FT_PRINTF_PATH 		=	$(SRCS_PATH)/ft_printf/
LIBFT_PATH			=	$(SRCS_PATH)/libft/
GNL_PATH			=	$(SRCS_PATH)/get_next_line/

SRCS = $(LIBFT_PATH) $(FT_PRINTF_PATH) $(GNL_PATH)

all: compile

compile:
	for src in $(SRCS); do \
		echo test; \
		cd $$src && make; \
	done;

clean			:
	rm -rf $(SRCS)
	@COUNT=$(SRCS_COUNT);\
	for i in `seq 1 $$COUNT`; do \
		MAKE_TARGET=$$(echo $(SRCS) | cut -d' ' -f$$i); \
		echo $$MAKE_TARGET; \
	done;

fclean	:	clean
	rm -rf $(NAME)

re				:	fclean all

bonus			:	all

.PHONY			:	run compile all dev re fclean clean bonus
