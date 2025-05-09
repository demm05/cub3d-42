HDIR				=	inc
SDIR				=	src
ODIR				=	obj
NAME				=	cub3d

CC					=	gcc
CFLAGS				=	-g -Werror -Wall -Wextra -I$(HDIR)
MAKE_LIB			=	@make --no-print-directory -C
DIRS				=	$(sort $(dir $(OBJS)))

MLX_DIR				=	$(HDIR)/minilibx
MLX_FILE			=	libmlx.a
MLX					=	$(MLX_DIR)/$(MLX_FILE)
CFLAGS				+=	-I$(MLX_DIR)

LIBFT_FILE			=	libft.a
LIBFT_DIR			=	$(HDIR)/libft
LIBFT				=	$(LIBFT_DIR)/$(LIBFT_FILE)
CFLAGS				+=	-I$(LIBFT_DIR)/include

SRCS				:=	$(shell find $(SDIR) -name "*.c")
OBJS				:=	$(patsubst $(SDIR)/%.c,$(ODIR)/%.o, $(SRCS))

all: $(NAME)

$(OBJS): $(ODIR)/%.o: $(SDIR)/%.c | $(DIRS)
	$(Q)$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(Q)$(CC) $(CFLAGS) $^ -o $@ -L$(MLX_PATH) -lmlx -lX11 -lXext -lm

$(DIRS):
	$(Q)mkdir -p $@

$(MLX): | $(MLX_DIR)
	$(Q)$(MAKE_LIB) $(MLX_DIR) > /dev/null 2>&1

$(LIBFT): | $(LIBFT_DIR)
	$(Q)$(MAKE_LIB) $(LIBFT_DIR)

$(MLX_DIR) $(LIBFT_DIR):
	$(Q)$(MAKE_LIB) ./ init

compiledb:
	@compiledb make -n all > /dev/null 2>&1

i init:
	@git submodule update --init --remote --recursive

n norm:
	@norminette $(SDIR) $(HDIR)/*.h $(LIBFT_DIR) \
		| grep Error | grep -v "INVALID_HEADER" | grep -v "PREPROC_BAD_INDENT"

r run: $(NAME)
	@clear
	$(Q)./$(NAME)

c clean:
	$(Q)rm -rf $(ODIR)
	$(Q)$(MAKE_LIB) $(LIBFT_DIR) clean
	$(Q)$(MAKE_LIB) $(MLX_DIR) clean > /dev/null

f fclean: clean
	$(Q)rm -rf $(NAME)
	$(Q)$(MAKE_LIB) $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re test n norm v r

ifeq ($(V),1)
    Q =
else
    Q = @
endif
