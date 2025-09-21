#Makefile by Casscurs

NAME ?= app

# Цвета для оформления вывода
COLOR_TITLE = \033[1;36m
COLOR_SUCCESS = \033[1;32m
COLOR_RESET = \033[0m

SRC_FILES = $(wildcard ./*.cc)
HEADER_FILES = $(wildcard ./*.h)
OBJ_FILES = $(patsubst %.cc, %.o, $(SRC_FILES))
DEP_FILES = $(patsubst %.cc, %.d, $(SRC_FILES))

# Флаги
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -O2

all: $(NAME)

$(NAME) : $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) $(LDFLAGS) $(LIBS) -o $@
	@echo "$(COLOR_SUCCESS)=== Build complete ===$(COLOR_RESET)"

test: $(NAME)
	./app

%.o : %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@ -MMD

include $(wildcard $(DEP_FILES))

clean :
	@echo "$(COLOR_TITLE)=== Cleaning ===$(COLOR_RESET)"
	@rm -rf *.a *.o gcovr *.gcda *.gcno $(DEP_FILES) $(NAME) test
	@rm -rf *.d

format :
	@echo "$(COLOR_TITLE)=== Formatting code ===$(COLOR_RESET)"
	clang-format -i -style=Google $(SRC_FILES) $(HEADER_FILES)

.PHONY : all clean cppcheck format