HDIR				=	inc
SDIR				=	src
ODIR				=	obj
LDIR				=	lib
NAME				=	cub3d

CC					=	gcc
CFLAGS				=	-g -O3 -Wall -Wextra -I$(HDIR) -flto
LIB_FLAGS			=	-lmlx -lX11 -lXext -lm -lft

MAKE_LIB			=	@make --no-print-directory -C
DIRS				=	$(sort $(dir $(OBJS)))

MLX_DIR				=	$(LDIR)/minilibx
MLX					=	$(MLX_DIR)/libmlx.a
CFLAGS				+=	-I$(MLX_DIR)
LIBS				+=	$(MLX)
LIB_FLAGS			+=	-L$(MLX_DIR)

LIBFT_DIR			=	$(LDIR)/libft
LIBFT				=	$(LIBFT_DIR)/libft.a
CFLAGS				+=	-I$(LIBFT_DIR)/include
LIBS				+=	$(LIBFT)
LIB_FLAGS			+=	-L$(LIBFT_DIR)

SRCS				:=	$(shell find $(SDIR) -name "*.c")
OBJS				:=	$(patsubst $(SDIR)/%.c,$(ODIR)/%.o, $(SRCS))

ifeq ($(D), 1)
	CFLAGS+=-DDEBUG=1
endif

ifeq ($(A), 1)
	CFLAGS+=-DENABLE_MLX_PUT=1
endif

ifneq ($(I), 1)
	CFLAGS+=-DENABLE_CUSTOM_INLINING=1
endif

all: $(NAME) 

$(OBJS): $(ODIR)/%.o: $(SDIR)/%.c | $(DIRS) $(LIBS)
	$(Q)$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS) 
	$(Q)$(CC) $(CFLAGS) $^ -o $@ $(LIB_FLAGS)

$(DIRS):
	$(Q)mkdir -p $@

$(MLX): | $(MLX_DIR) $(MLX_DIR)/Makefile
	$(Q)$(MAKE_LIB) $(MLX_DIR) > /dev/null 2>&1

$(LIBFT): | $(LIBFT_DIR) $(MLX_DIR)/Makefile
	$(Q)$(MAKE_LIB) $(LIBFT_DIR) > /dev/null 2>&1

$(MLX_DIR) $(MLX_DIR)/Makefile $(LIBFT_DIR) $(LIBFT_DIR)/Makefile:
	$(Q)$(MAKE_LIB) ./ init

compiledb:
	@compiledb make -n all > /dev/null 2>&1

g gprof: all
	@echo "Generating profiling report (prof.pdf)..."
	@gprof ./$(NAME) gmon.out | gprof2dot | dot -Tpdf -o prof.pdf && open prof.pdf
	# @rm -f gmon.out

i init:
	@git submodule update --init --remote --recursive

n norm:
	@norminette $(SDIR) $(HDIR) $(LIBFT_DIR) \
		| grep Error | grep -v "INVALID_HEADER" | grep -v "PREPROC_BAD_INDENT" \
		| grep -v "PREPOC_ONLY_GLOBAL" | grep -v "NL_AFTER_PREPROC" | grep -v "PREPROC_CONSTANT" \
		| grep -v "WRONG_SCOPE_COMMENT" | grep -v "LINE_TOO_LONG" | grep -v "TOO_MANY_ARGS"

v: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --log-file=valgrind-out.txt ./$< map1.cub

r run: all
	@clear
	$(Q)./$(NAME) map1.cub

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
	@echo "  I=1         Disable inline optimization flag."
	@echo ""
	@echo "Examples:"
	@echo "    make D=1 A=1 rr (runs a project with optional flags)"

.PHONY: all clean fclean re test n norm v r help rr

ifeq ($(V),1)
    Q =
else
    Q = @
endif
