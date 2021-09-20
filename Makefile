CC			= gcc

CFLAGS		= -Wall -Werror -Wextra -g

SRCS_DIR	= srcs
OBJS_DIR	= bin
#TESTS_DIR	= tests
INCLUDES	= -I./includes

#SRCS_NAME	= src.c
#SRCS		= $(patsubst %, $(SRCS_DIR)/%, $(SRCS_NAME))
SRCS		= $(wildcard $(SRCS_DIR)/*.c)
OBJS		= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
#TESTS		= $(wildcard $(TESTS_DIR)/*.c)
NAME		= bsq

all:				$(NAME)

$(NAME):			$(OBJS)
					$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
					$(CC) $(CFLAGS) $(INCLUDES) -o $@ $< -c

#$(TESTS_DIR)/%.o:	$(OBJS)

bin:				$(OBJS)

re:					fclean $(NAME)

clean:
					$(RM) $(OBJS)

fclean:				clean
					$(RM) $(NAME)

clean_test:
					$(RM) test_parsing test_map

.PHONY:				all re clean fclean bin
