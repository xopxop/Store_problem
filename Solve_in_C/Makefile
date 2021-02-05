CC			:= clang
# CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra -g
PROGRAM		:= my_program
INCLUDES	:= -Iincludes/
BUILD_DIR	:= ./build

SRC += main.c
SRC += init_examples.c
SRC += clean_up.c
SRC += solution.c
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

all: mkdirs $(PROGRAM)

mkdirs:
	@mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(PROGRAM): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $@

clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -rf $(PROGRAM)

re: fclean all

.Phony: all clean fclean re
