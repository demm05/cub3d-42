HDIR				=	inc
SDIR				=	src
ODIR				=	obj
NAME				=	cub3d

CC					=	gcc
CFLAGS				=	-g -Wall -Wextra -I$(HDIR)
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

ifeq ($(D), 1)
	CFLAGS+=-DDEBUG=1
endif

ifeq ($(A), 1)
	CFLAGS+=-DENABLE_MLX_PUT=1
endif

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
		| grep Error | grep -v "INVALID_HEADER" | grep -v "PREPROC_BAD_INDENT" \
		| grep -v "PREPOC_ONLY_GLOBAL" | grep -v "NL_AFTER_PREPROC"

r run: all
	@clear
	$(Q)./$(NAME)

rr: clean r

c clean:
	$(Q)rm -rf $(ODIR)
	$(Q)$(MAKE_LIB) $(LIBFT_DIR) clean
	$(Q)$(MAKE_LIB) $(MLX_DIR) clean > /dev/null

f fclean: clean
	$(Q)rm -rf $(NAME)
	$(Q)$(MAKE_LIB) $(LIBFT_DIR) fclean

re: fclean all

help:
	@echo "Usage: make [targets] [options]"
	@echo ""
	@echo "Targets:"
	@echo "  all         Builds the $(NAME) executable (default)."
	@echo "  run (r)     Clears screen and runs the $(NAME) executable."
	@echo "  re          Forces a full rebuild (fclean then all)."
	@echo "  rr          Cleans objects from project and builds game(fclean then all)."
	@echo "  norm (n)    Runs norminette checks on source and header files."
	@echo "  init (i)    Initializes and/or updates git submodules."
	@echo "  compiledb   Generates a compilation database (compile_commands.json) using bear."
	@echo "  help        Shows this help message."
	@echo ""
	@echo "Options:"
	@echo "  V=1         Enable verbose output (e.g., make V=1 all)."
	@echo "  D=1         Adds a DEBUG=1 flag"
	@echo "  A=1         Adds ENABLE_MLX_PUT=1 flag (alternative rendering)."
	@echo ""
	@echo "Examples:"
	@echo "    make D=1 A=1 rr (runs a project with optional flags)"

.PHONY: all clean fclean re test n norm v r help rr

ifeq ($(V),1)
    Q =
else
    Q = @
endif
