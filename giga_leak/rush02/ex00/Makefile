SRCS_DIR = ./

SRC = checkers.c dict_navigator.c manage_threes.c parse_info.c print_handlers.c print_values.c utils.c validators.c rush_main.c main.c

SRCS = $(addprefix $(SRCS_DIR), $(SRC))

SRCS_OBJ = $(SRCS:.c=.o)

DICT_DIR = ./dictionaries/

# HEADER_DIR = ./includes/
HEADER_DIR = ./

CC = cc

CFLAGS = -Wall -Wextra -Werror

OUTPUT = rush-02

$(SRCS_DIR)%.o: $(SRCS_DIR)%.c
	${CC} ${CFLAGS} -I ${HEADER_DIR} -c $< -o $@

$(OUTPUT) : $(SRCS_OBJ)
	${CC} ${CFLAGS} -o ${OUTPUT} ${SRCS_OBJ}


clean :
	rm -f $(SRCS_OBJ)

fclean :
	rm -f $(OUTPUT)

.PHONY : all clean fclean
