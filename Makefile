## BillyScene, Julien Tauran 2019

#GREY	=	'\x1b[30m'
#RED	=	'\x1b[31m'
#GREEN	=	'\x1b[32m'
#YELLOW	=	'\x1b[33m'
#BLUE	=	'\x1b[34m'
#PURPLE	=	'\x1b[35m'
#CYAN	=	'\x1b[36m'
#WHITE	=	'\x1b[37m'

# BINARIES' NAME
LIBRARY_NAME		=	libbs_scenes.so

BINARY_TEST_NAME	=	unit_tests

# PATH CONFIG
DIR_SRC				=	./src/

DIR_UT				=	./tests/

DIR_LIB				=	./libs/sfml/include/

# PATH SRC

SRC_SCENES			=	scenes/Scene.cpp

SRC_WINDOW			=	window/Window.cpp

SRC_COMPONENTS_BUTTON	=	components/button/Button.cpp

# PATH UT
SRC_UT_IPC			=	ipc/SendReceiveMessage.cpp

# GROUP OF SRCS

SRCS				=	$(addprefix $(DIR_SRC), $(SRC_SCENES)) \
						$(addprefix $(DIR_SRC), $(SRC_WINDOW)) \
						$(addprefix $(DIR_SRC), $(SRC_COMPONENTS_BUTTON))

SRCS_UT				=

# Compilation flags
PARAMS				=	-W -Werror -I$(DIR_SRC) -I$(DIR_LIB) -L./libs/sfml/lib/ -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -g3 #-fsanitize=address -lasan

# OBJ
OBJ_SRC 			=	$(SRCS:.cpp=.o)
OBJ_UT 				=	$(SRCS_UT:.cpp=.o)

%.o:    %.cpp
	g++ $(PARAMS) -fPIC -o $@ -c $<

# Rules
all: $(LIBRARY_NAME)

$(LIBRARY_NAME):	$(SRCS) #$(OBJ_SRC)  # $(OBJ_SRC)
			# g++ -c $(SRCS) -fPIC $(PARAMS)
			# g++ -shared -o $(LIBRARY_NAME) *.o
			g++ -c $(SRCS) $(PARAMS)
			ar -rc $(LIBRARY_NAME) *.o

clean:
	rm -f $(OBJ_MAIN)
	rm -f $(OBJ_SRC)
	rm -f $(OBJ_UT)
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.o

fclean: clean
	@rm -f $(LIBRARY_NAME)
	@rm -f $(BINARY_TEST_NAME)
	@rm -f html
	@rm -f latex

$(PARAMS) +=  -coverage -lcriterion

tests_run:
	@printf "[\x1b[36mLib: Unit Tests all PROJECT\x1b[37m]\n"
	@g++ $(SRCS) $(SRCS_UT) -o $(BINARY_TEST_NAME) $(PARAMS) -coverage -lcriterion
	./$(BINARY_TEST_NAME)

coverage:
	gcovr --exclude tests/ .

debug: $(OBJ_SRC) $(OBJ_MAIN)
	@printf "[\x1b[36mLib Graphical: make\x1b[37m]\n"
	g++ $(OBJ_SRC) $(OBJ_MAIN) -o $(BINARY_NAME) $(PARAMS) -g3

documentation:
	doxygen

re: fclean $(BINARY_NAME)

example:
	g++ -L./libs/sfml/lib/ -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lpthread ./example/main.cpp -L. -lbs_scenes -I./src/ -g3 # -fsanitize=address -lasan

.PHONY : all fclean re tests_run debug doxygen example