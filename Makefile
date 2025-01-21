NAME				=	ft_libc.a

CC 					=	@clang
CFLAGS 				=	-Wall -Werror -Wextra -Iincludes
INCLUDES_PATH		=	./includes

MAKE				=	make --no-print-directory\
							INCLUDES_PATH=../../$(INCLUDES_PATH)\
							NAME=../../$(NAME) -C
COPY				=	@cp $@ $(NAME)
AR					=	@ar

SRCS_PATH			=	./srcs

FT_PRINTF_PATH 		=	$(SRCS_PATH)/ft_printf/
LIBFT_PATH			=	$(SRCS_PATH)/libft/
GNL_PATH			=	$(SRCS_PATH)/get_next_line/

SRCS				=	$(LIBFT_PATH)\
						$(FT_PRINTF_PATH)\
						$(GNL_PATH)

all: compile

compile: $(SRCS)
	@for src in $(SRCS); do \
		$(MAKE) $$src; \
	done;

clean			:
	@for src in $(SRCS); do \
		$(MAKE) $$src clean; \
	done;

fclean	:	clean
	rm -rf $(NAME)

re				:	fclean all

bonus			:	all

.PHONY			:	run compile all dev re fclean clean bonus
