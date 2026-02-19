PROJECT = push_swap
NAME = push_swap
BNS_NAME = checker

SRC_DIR = src
INC_DIR = inc
INCLUDE = -I $(INC_DIR) -I $(INC_DIR)/libft_inc
BNS_SRC_DIR = bonus
BNS_INC_DIR = bonus_inc
BNS_INCLUDE = -I $(BNS_INC_DIR) -I $(BNS_INC_DIR)/libft_inc
OBJ_DIR = obj
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
AR = ar rcs

LIB_DIR = libft
LIB = $(LIB_DIR)/libft.a

GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
CYAN = \033[0;36m

SRCS = $(shell find $(SRC_DIR) -name "*.c")

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

BNS_SRCS = $(shell find $(BNS_SRC_DIR) -name "*.c")

BNS_OBJS = $(patsubst $(BNS_SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(BNS_SRCS))

all: $(NAME)

$(LIB):
	@make -C $(LIB_DIR)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIB) -o $(NAME)
	@echo "$(GREEN)$(PROJECT) built: $(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(CYAN)Compiling: $<"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

bonus: $(LIB) $(BNS_OBJS)
	@$(CC) $(CFLAGS) $(BNS_INCLUDE) $(BNS_OBJS) $(LIB) -o $(BNS_NAME)
	@echo "$(GREEN)$(BNS_NAME) built: $(BNS_NAME)"

$(OBJ_DIR)/%.o: $(BNS_SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(CYAN)Compiling: $<"
	@$(CC) $(CFLAGS) $(BNS_INCLUDE) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@make clean -C $(LIB_DIR)
	@echo "$(BLUE)$(PROJECT) object files removed"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(BNS_NAME)
	@make fclean -C $(LIB_DIR)
	@echo "$(BLUE)$(PROJECT) clean (library removed)"

re: fclean all
	@echo "$(GREEN)$(PROJECT) rebuilt"

pclean:
	@$(RM) $(OBJ_DIR)
	@echo "$(BLUE)$(PROJECT) non-library object files removed"

pfclean: pclean
	@$(RM) $(NAME)
	@$(RM) $(BNS_NAME)
	@echo "$(BLUE)$(PROJECT) pclean (library removed)"

pre: pfclean all

.PHONY: all clean fclean re