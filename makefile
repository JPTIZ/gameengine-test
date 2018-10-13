DEFAULT := "\033[0m"

GREEN := "\033[92m"
RED := "\033[91m"
YELLOW := "\033[93m"
OTHER := "\033[90m"

INFO := "[${OTHER}INFO${DEFAULT}]"
ERROR := "[${RED}ERROR${DEFAULT}]"
GOOD := "[${GREEN}GOOD${DEFAULT}]"
WARN := "[${YELLOW}WARN${DEFAULT}]"

default: all

build:
	@printf "${INFO} Generating build dir...\n"
	@mkdir -p build/
	@cp build_makefile build/makefile
	@printf "${GOOD} Done.\n"

all: build
	@printf "${INFO} Building...\n"
	@make -C build
	@printf "${GOOD} Done.\n"

run: all
	@printf "${INFO} Running...\n"
	@printf "===============================================================\n"
	@./build/persona-x
	@printf "===============================================================\n"
	@printf "${GOOD} Done.\n"

clean:
	@printf "${INFO} Cleaning...\n"
	rm -rf build/
	@printf "${GOOD} Done.\n"
