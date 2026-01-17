# ================================
#           BASIC CONFIG
# ================================

# Name of the final executable
NAME		=	fractol

# Compiler and flags
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

# ================================
#   OS-SPECIFIC MiniLibX SETUP
# ================================

# Determine the OS using 'uname -s'
# On Linux: link X11 and math libraries
# On macOS: link to OpenGL and AppKit frameworks
UNAME_S		:=	$(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLX_DIR	=	./minilibx-linux
	MLX_LIB	=	$(MLX_DIR)/libmlx.a
	MLX_FLAGS = -lXext -lX11 -lm
else
	MLX_DIR	=	./minilibx
	MLX_LIB	=	$(MLX_DIR)/libmlx.a
	MLX_FLAGS = -framework OpenGL -framework AppKit
endif

# ================================
#            LIBFT SETUP
# ================================

# Path to libft library
LIBFT_DIR	=	./libft
LIBFT_LIB	=	$(LIBFT_DIR)/libft.a

# ================================
#         INCLUDE DIRECTORIES
# ================================

# -I flags let the compiler find your header files
INCLUDES	=	-Iinc -I$(LIBFT_DIR) -I$(MLX_DIR)

# ================================
#          SOURCE & OBJECTS
# ================================

# Source and object directory names
SRC_DIR		=	src
OBJ_DIR		=	obj

# All your .c source files (just file names)
SRC_FILES	=	fractol.c init.c render.c events.c math_utili.c main.c colors.c

# Add the src/ prefix to each source file
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

# Convert src/*.c into obj/*.o
# This will compile into the obj/ folder
OBJS		=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))


# Shortcuts for removing files/directories
RM			=	rm -f
RMDIR		=	rm -rf

# Default target when you run just `make`
all: $(NAME)

# Final binary rule: build libft + mlx + object files
$(NAME): $(MLX_LIB) $(LIBFT_LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)

# ================================
#       COMPILING .C TO .O
# ================================

# Rule to create .o files from .c files
# $@ = output file (e.g., obj/fractol.o)
# $< = source file (e.g., src/fractol.c)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

# ================================
#     BUILD LIBRARIES RULES
# ================================

# Build libft if it doesn't exist or is outdated
$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

# Build MiniLibX if it doesn't exist or is outdated
$(MLX_LIB):
	@make -C $(MLX_DIR)

# ================================
#          CLEANING RULES
# ================================

# Remove compiled .o files and clean libraries
clean:
	@$(RMDIR) $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean

# Remove everything including executable and built libraries
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_LIB)
	@$(RM) $(MLX_LIB)

# Recompile from scratch
re: fclean all

# ================================
#     MARK PHONY (NOT FILES)
# ================================

# Prevent make from mistaking these as actual files
.PHONY: all clean fclean re
