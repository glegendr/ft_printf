NAME=libftprintf.a
CC=gcc
CFLAG=
CFLAG+= -Werror
CFLAG+= -Wextra
CFLAG+= -Wall
#CFLAG+= -fsanitize=address
SRCNAME= ft_convertissor\
		 ft_flags\
		 ft_pars\
		 ft_print_dec\
		 ft_print_flags\
		 ft_print_hex\
		 ft_printf\
		 ft_push_point\
		 ft_rawtoi\
		 ft_str_is_null\
		 wchar_t_to_str

OBJDIR=obj/
CLEANOBJDIR=OBJDIR
CLEANOBJ=OBJ
SRCDIR=./
LIBFTDIR=./libft
LIBFT=./libft/libft.a

SRC= $(addprefix $(SRCDIR), $(addsuffix .c, $(SRCNAME)))

OBJ= $(addprefix $(OBJDIR), $(addsuffix .o, $(SRCNAME)))

INCDIR= include/

all: $(NAME)

$(NAME): $(LIBFT) $(OBJDIR) $(OBJ)
	@ar -rc tmp.a $(OBJ)
	@libtool -static -o $(NAME) tmp.a $(LIBFT)
	@rm -rf tmp.a
	@(echo "[ \033[35m$(NAME)\033[00m ]")

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CFLAG) -c $< -o $@
	@(echo "\033[32m$@\033[00m")

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJ) $(OBJDIR)  
	@make -C libft/. clean
	@(echo "\033[32mit is clean")

fclean: clean
	@rm -rf $(NAME)
	@make -C libft/. fclean

re: fclean all
