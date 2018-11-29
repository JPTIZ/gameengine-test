DEFAULT := "\033[0m"

GREEN := "\033[92m"
RED := "\033[91m"
YELLOW := "\033[93m"
OTHER := "\033[90m"

INFO := "[${OTHER}INFO${DEFAULT}]"
ERROR := "[${RED}ERROR${DEFAULT}]"
GOOD := "[${GREEN}GOOD${DEFAULT}]"
WARN := "[${YELLOW}WARN${DEFAULT}]"

PYBIND11INCLUDES := `python3 -m pybind11 --includes`
CXXFLAGS         := -O3 -Wall -shared -std=c++17 -fPIC $(PYBIND11INCLUDES)
SUFFIX           := `python3-config --extension-suffix`
OUTPUT           := game

MAKE := make --no-print-directory

default: all

build:
	@printf "${INFO} Generating build dir...\n"
	@mkdir -p build/
	@cp build_makefile build/makefile
	@printf "${GOOD} Done.\n"

pylib: src/pywrap.cpp
	$(CXX) $(CXXFLAGS) $^ -o $(OUTPUT)$(SUFFIX) -Lbuild/libpersona-x.so

all: build
	@printf "${INFO} Building...\n"
	@$(MAKE) -C build
	@cp build/persona_x* .
	@printf "${GOOD} Done.\n"

run: all
	@printf "${INFO} Running...\n"
	@printf "===============================================================\n"
	@python game.py
	@printf "===============================================================\n"
	@printf "${GOOD} Done.\n"

clean:
	@printf "${INFO} Cleaning...\n"
	rm -rf build/
	@printf "${GOOD} Done.\n"
