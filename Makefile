NAME		=	cub3d
BUILD_MODE ?=	release
# =============================== DIRECTORIES =============================== #
HDIR		=	inc
SDIR		=	src
ODIR		=	obj
LDIR		=	lib
# =============================== COMPILATION ================================ #
CC			=	gcc
CFLAGS		=	-Wall -Wextra -I$(HDIR)
LIB_FLAGS	=	-lm
# ================================== FILES =================================== #
SRCS		:=	$(shell find $(SDIR) -name "*.c")
OBJS		:=	$(patsubst $(SDIR)/%.c,$(ODIR)/%.o, $(SRCS))
DIRS		=	$(sort $(dir $(OBJS)))

include mk/libs.mk
include mk/help.mk
include mk/tools.mk
include mk/options.mk

all: $(DIRS) $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(Q)$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIB_FLAGS)

$(OBJS): $(ODIR)/%.o: $(SDIR)/%.c
	$(Q)$(CC) $(CFLAGS) -c -o $@ $<

$(DIRS):
	$(Q)mkdir -p $@

r run: all
	@clear
	$(Q)./$(NAME) map1.cub

c clean:
	$(Q)rm -rf $(ODIR)
	$(Q)$(MAKE_LIB) $(LIBFT_DIR) clean

f fclean: clean
	$(Q)rm -rf $(NAME)
	$(Q)$(MLX_MAKE) clean > /dev/null
	$(Q)$(MAKE_LIB) $(LIBFT_DIR) fclean

rr: clean r
re: fclean all

.PHONY: all re help init rr

ifeq ($(V),1)
    Q =
else
    Q = @
endif
