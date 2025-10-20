NAME = 	ScalarConverter
SRCS = main.cpp \
		ScalarConverter.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o  $(NAME)

clean :
	rm -r $(OBJS)


fclean : clean
	rm -r $(NAME)


re : fclean all



phony: all, clean, fclean, re