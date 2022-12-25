NAME = printf.a

CC = gcc

CCFLAG = -Wall -Wextra -Werror -std=c99

SRC = ft_putchar_d.c ft_puthex.c ft_putchar_p.c ft_putchar_s.c ft_putchar_u.c ft_uitoa.c ft_putchar_x.c ft_printf.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

RM = rm -f

all: create_folder $(NAME)
	@echo "\033[32mprintf.a library created\033[0m"
$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)
	@echo "\033[32mObject files added to library\033[0m"

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CCFLAG) -c $< -o $@

clean:
	@$(RM) -r $(OBJ)
	@$(RM) -r $(OBJ_DIR)
	@echo "\033[31mObject files deleted\033[0m"

fclean: clean
	@$(RM) -r $(NAME)
	@echo "\033[31mLibrary deleted\033[0m"

re: fclean all

create_folder:
	@mkdir -p $(OBJ_DIR)
	@echo "\033[32mObject files created\033[0m"

.PHONY:all clean fclean re create_folder
