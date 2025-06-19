MAKE				=	@make --no-print-directory
MAKE_LIB			=	$(MAKE) -C
MAKE_FILE			=	$(MAKE_LIB) ./mk -f

ifeq ($(shell pkg-config --exists mlx && echo 1), 1)
	CFLAGS		+= $(shell pkg-config --cflags mlx)
	LIB_FLAGS	+=  $(shell pkg-config --libs mlx)
else
	MLX_DIR		=	$(LDIR)/minilibx
	MLX_CLEAN	=	$(MAKE_LIB) $(MLX_DIR) clean
	MLX			=	$(MLX_DIR)/libmlx.a
	LIBS		+=	$(MLX)
	CFLAGS		+=	-I$(MLX_DIR)
	LIB_FLAGS	+=	-L$(MLX_DIR) -lmlx
endif

LIBFT_DIR		=	$(LDIR)/libft
LIBFT			=	$(LIBFT_DIR)/libft.a
CFLAGS			+=	-I$(LIBFT_DIR)/include
LIB_FLAGS		+=	-L$(LIBFT_DIR) -lft
LIBS			+=	$(LIBFT)

REQUIRED_LIBS	:= freetype2 x11 xext

CFLAGS			+=	$(shell pkg-config --cflags $(REQUIRED_LIBS))
LIB_FLAGS		+=	$(shell pkg-config --libs $(REQUIRED_LIBS))

all: $(LIBS)

$(MLX): $(MLX_DIR)/Makefile
	$(Q)$(MAKE_LIB) $(MLX_DIR) > /dev/null

$(LIBFT): $(LIBFT_DIR)/Makefile
	$(Q)$(MAKE_LIB) $(LIBFT_DIR)

$(MLX_DIR)/Makefile $(LIBFT_DIR)/Makefile:
	$(Q)$(MAKE_LIB) ./ init

i init:
	@git submodule update --init --remote --recursive

.PHONY: init all

ifeq ($(shell command -v pkg-config),)
  $(error "Error: 'pkg-config' command not found. Please install it to continue.")
endif

$(foreach lib,$(REQUIRED_LIBS),\
  $(if $(filter 1,$(shell pkg-config --exists $(lib) && echo 1)),,\
    $(error "Error: Required library '$(lib)' not found. Please check its installation."))\
)
