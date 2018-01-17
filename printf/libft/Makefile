.PHONY: all clean fclean re

NAME=libft.a
CC=gcc
CFLAG=
CFLAG+= -Werror
CFLAG+= -Wextra
CFLAG+= -Wall
SRCNAME= ft_isprint \
		 ft_recursive_factorial \
		 ft_stradd\
		 ft_isnegative\
		 ft_memccpy \
		 ft_memcut \
		 ft_putendl \
		 ft_strcmp  \
		 ft_strlen  \
		 ft_strrchr \
		 ft_itoa    \
		 ft_itoa_base\
		 ft_memchr   \
		 ft_putendl_fd \
		 ft_strcpy   \
		 ft_strmap   \
		 ft_strsplit \
		 ft_lstadd   \
		 ft_memcmp   \
		 ft_putnbr   \
		 ft_strdel   \
		 ft_strmapi  \
		 ft_strstr   \
		 ft_atoi     \
		 ft_lstdel   \
		 ft_memcpy   \
		 ft_putnbr_fd\
		 ft_abs      \
		 ft_strdup   \
		 ft_strncat  \
		 ft_isspace  \
		 ft_strsub   \
		 ft_bzero    \
		 ft_lstdelone\
		 ft_memdel   \
		 ft_putstr   \
		 ft_strequ   \
		 ft_strncmp  \
		 ft_strtrim  \
		 ft_isalnum  \
		 ft_lstiter  \
		 ft_memmove  \
		 ft_putstr_fd\
		 ft_striter  \
		 ft_strncpy  \
		 ft_tolower  \
		 ft_isalpha  \
		 ft_lstmap   \
		 ft_memset   \
		 ft_strcat   \
		 ft_striteri \
		 ft_strnequ  \
		 ft_toupper  \
		 ft_isascii  \
		 ft_lstnew   \
		 ft_putchar  \
		 ft_strchr   \
		 ft_strjoin  \
		 ft_strnew   \
		 ft_isdigit  \
		 ft_memalloc \
		 ft_putchar_fd\
		 ft_strclr   \
		 ft_strlcat  \
		 ft_strnstr  \
		 ft_sqrt     \
		 ft_putstarstr\
		 ft_realloc\
		 v_new\
		 v_push\
		 v_push_first\
		 v_print\
		 v_append_raw\
		 v_get\
		 v_size\
		 v_split\
		 v_del\
		 v_raw\

OBJDIR=obj/
CLEANOBJDIR=OBJDIR
CLEANOBJ=OBJ
SRCDIR=src/

SRC= $(addprefix $(SRCDIR), $(addsuffix .c, $(SRCNAME)))

OBJ= $(addprefix $(OBJDIR), $(addsuffix .o, $(SRCNAME)))

INCDIR= includes/

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CFLAG) -c $< -o $@ -I $(INCDIR)
	@(echo "_ \033[032m$@\033[00m")

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	
$(NAME): $(OBJDIR) $(OBJ)
	@ar -rc  $(NAME) $(OBJ)
	@(echo "[ \033[35m$(NAME)\033[00m ]")

clean:
	@rm -rf $(OBJ) $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
