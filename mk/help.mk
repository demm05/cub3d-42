RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN	= \033[0;36m
WHITE	= \033[0;37m
RESET	= \033[0m

HELP_STAMP	:=	.help_shown.stamp

first-run-help:
	@$(MAKE) --no-print-directory help
	@touch $(HELP_STAMP)

ifeq ($(shell test -f $(HELP_STAMP) || echo 1), 1)
  .DEFAULT_GOAL := first-run-help
endif

help:
	@printf "$(PURPLE)╔══════════════════════════════════════════════════════════════╗$(RESET)\n"
	@printf "$(PURPLE)║                   $(CYAN)C U B 3 D   M A K E F I L E                $(PURPLE)║$(RESET)\n"
	@printf "$(PURPLE)╚══════════════════════════════════════════════════════════════╝$(RESET)\n\n"
	@printf "$(CYAN)USAGE: make [TARGET] [OPTIONS]$(RESET)\n\n"
	@printf "$(YELLOW)📋 Build Targets:$(RESET)\n"
	@printf "  $(GREEN)all$(RESET) Build the project (default)\n"
	@printf "  $(GREEN)re$(RESET) Clean and rebuild the project\n"
	@printf "  $(GREEN)debug$(RESET) Build with debug flags (-O0, -g3, ASan)\n"
	@printf "  $(GREEN)clean$(RESET) Remove object files\n" 
	@printf "  $(GREEN)fclean$(RESET) Remove all generated files (incl. executable)\n\n"
	@printf "$(YELLOW)🚀 Run & Test Targets:$(RESET)\n"
	@printf "  $(GREEN)run, r$(RESET) Build and run the program\n"
	@printf "  $(GREEN)rr$(RESET) Rebuild and run the program\n"
	@printf "  $(GREEN)valgrind, v$(RESET) Run with Valgrind memory checker\n\n"
	@printf "$(YELLOW)🔧 Development Tools:$(RESET)\n"
	@printf "  $(GREEN)gdb, g$(RESET) Debug with GDB\n"
	@printf "  $(GREEN)gdbtui, gt$(RESET) Debug with GDB's Text User Interface\n" 
	@printf "  $(GREEN)norm, n$(RESET) Check code style with Norminette\n"
	@printf "  $(GREEN)gprof$(RESET) Generate performance profile (PDF)\n"
	@printf "  $(GREEN)compiledb$(RESET) Generate compile_commands.json for LSP\n"
	@printf "  $(GREEN)init, i$(RESET) Initialize/update git submodules\n\n"
	@printf "$(YELLOW)⚙️  Build Options:$(RESET)\n"
	@printf "  $(GREEN)BUILD_MODE$(RESET) Force a specific build mode"
