
# **************************************************************************** #
# 		PROGRAM																   #
# **************************************************************************** #

NAME		=	drone_controller

# **************************************************************************** #
#		SOURCES
# **************************************************************************** #

DIRSRC		=	src
CMPTDIR     =   $(DIRSRC)/components

SRCS =	$(DIRSRC)/main.cpp \
		$(CMPTDIR)/motor/Motor.class.cpp \
		$(CMPTDIR)/MPU6050/MPU6050.class.cpp \
		$(CMPTDIR)/brain/Brain.class.cpp \
		$(CMPTDIR)/math	/PID.class.cpp

# **************************************************************************** #
#		DIRECTORIES
# **************************************************************************** #

DIRBIN		=	bin
BIN			=	$(addprefix $(DIRBIN)/, $(SRCS:.cpp=.opp))
DIRLIST		=	srcs
DIRINC		=	./includes/

# **************************************************************************** #
#		COMPILE
# **************************************************************************** #

CC			=	g++
CFLAG		=	-Wall -Wextra -Werror -std=c++11
INCS		=	-I$(DIRINC)
LIBS		=   

# **************************************************************************** #
#		RULES																   #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(DIRBIN) $(BIN)
	@printf " ------------------------------------------------------------ \n"
	@$(CC) $(CFLAG) $(BIN) $(LIBS) -o $(NAME)
	@printf "\n\t\tMAKING PROJECT\t\t\t"
	@printf "\t\e[32m[DONE]\e[0m\n\n"
	@printf " ------------------------------------------------------------ \n"

$(addprefix $(DIRBIN)/, %.opp) : %.cpp $(DIRINC)
	@mkdir -p $(@D)
	@printf "compiling \e[33m%-41s\e[0m" "$@..."
	@$(CC) $(CFLAG) $(INCS) -o $@ -c $<
	@printf "\t\e[32m[DONE]\e[0m\n"

$(DIRBIN) :
	@/bin/mkdir $(DIRBIN); \
		for DIR in $(DIRLIST); \
		do \
		/bin/mkdir $(DIRBIN)/$$DIR; \
		done

clean:
	@printf " ------------------------------------------------------------ \n"
	@printf "cleaning binaries...\t\t\t\t\t"
	@/bin/rm -rf $(DIRBIN);
	@printf "\e[32m[DONE]\e[0m\n"

fclean: clean
	@printf " ------------------------------------------------------------ \n"
	@printf "cleaning project...\t\t\t\t\t"
	@/bin/rm -rf $(NAME);
	@printf "\e[32m[DONE]\e[0m\n"
	@printf " ------------------------------------------------------------ \n"

re: fclean all

.PHONY: clean fclean re
