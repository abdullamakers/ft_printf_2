NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
CORE_DIR = $(SRC_DIR)/core
PROC_DIR = $(SRC_DIR)/process
PRINT_DIR = $(SRC_DIR)/print
UTILS_DIR = $(SRC_DIR)/utils
INC_DIR = include

SRC = $(SRC_DIR)/ft_printf.c \
      $(CORE_DIR)/core_loop.c \
      $(CORE_DIR)/parse_format.c \
      $(CORE_DIR)/dispatcher.c \
      $(PROC_DIR)/process_char.c \
      $(PROC_DIR)/process_str.c \
      $(PROC_DIR)/process_ptr.c \
      $(PROC_DIR)/process_int.c \
      $(PROC_DIR)/process_uint.c \
      $(PROC_DIR)/process_hex.c \
      $(PROC_DIR)/process_percent.c \
      $(PRINT_DIR)/print_char.c \
      $(PRINT_DIR)/print_str.c \
      $(PRINT_DIR)/print_number.c \
      $(PRINT_DIR)/print_hex.c \
      $(PRINT_DIR)/print_ptr.c \
      $(PRINT_DIR)/print_padding.c \
      $(UTILS_DIR)/ft_strlen.c \
      $(UTILS_DIR)/ft_isdigit.c \
      $(UTILS_DIR)/ft_putchar.c \
      $(UTILS_DIR)/ft_putnchar.c \
      $(UTILS_DIR)/ft_putstrn.c \
      $(UTILS_DIR)/ft_itoa.c \
      $(UTILS_DIR)/ft_utoa.c \
      $(UTILS_DIR)/ft_xtoa.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(INC_DIR)/ft_printf.h
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
