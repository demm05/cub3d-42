compiledb:
	@compiledb make -n all > /dev/null 2>&1

gdb g:
	@$(MAKE) all BUILD_MODE=debug
	@printf "$(PURPLE)🐛 Starting GDB...$(RESET) ARGS: $(CYAN)$(ARGS)$(RESET)\n"
	@gdb --args ./$(NAME) $(ARGS)

gdbtui gt: $(NAME)
	@$(MAKE) all BUILD_MODE=debug
	@printf "$(PURPLE)🖥️  Starting GDB TUI...$(RESET) ARGS: $(CYAN)$(ARGS)$(RESET)\n"
	@gdb -tui --args ./$(NAME) $(ARGS)

gprof:
	@$(MAKE) re BUILD_MODE=profile
	@printf "$(YELLOW)📊 Running profiler...$(RESET)\n"
	@$(MAKE) r
	@if [ -f gmon.out ]; then \
		gprof ./$(NAME) gmon.out | gprof2dot | dot -Tpdf -o prof.pdf && \
		(open prof.pdf 2>/dev/null || xdg-open prof.pdf 2>/dev/null || \
		printf "$(GREEN)Profile generated: prof.pdf$(RESET)\n"); \
	else \
		printf "$(RED)No profiling data generated$(RESET)\n"; \
	fi

n norm:
	@norminette $(SDIR) $(HDIR) $(LIBFT_DIR) \
		| grep Error | grep -v "INVALID_HEADER" | grep -v "PREPROC_BAD_INDENT" \
		| grep -v "PREPOC_ONLY_GLOBAL" | grep -v "NL_AFTER_PREPROC" | grep -v "PREPROC_CONSTANT" \
		| grep -v "WRONG_SCOPE_COMMENT" | grep -v "LINE_TOO_LONG" | grep -v "TOO_MANY_ARGS"

v: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) map1.cub

.PHONY: gprof gt gdbtui gdb g debug n norm v 
