CC=gcc
SRC=src/main.c\
	src/input.c\
	src/solver.c\
	src/solver-utils.c\
	src/solver-slicing.c\
	src/stack.c\
	src/stack-utils.c\
	src/stack-operations.c\
	src/stack-instructions.c\
	src/slice.c\
	src/utils.c\
	src/utils2.c

CHECKER=checker

CHECKER_SRC=src/input.c\
			src/stack.c\
			src/stack-utils.c\
			src/stack-operations.c\
			src/stack-instructions.c\
			src/get_next_line/get_next_line.c\
			src/get_next_line/get_next_line_utils.c\
			src/utils.c\
			src/utils2.c\
			src/checker.c
CFLAGS=-Wall -Wextra -Werror
DFLAGS=-g -fsanitize=address
NAME=push_swap

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

checker: $(CHECKER_SRC)
	$(CC) $(CFLAGS) $(CHECKER_SRC) -o $(CHECKER)

clean:
	rm -rf $(NAME)

fclean: clean checker

re: clean all

bonus: checker

test: all checker
	@./push_swap $(TEST1) | ./checker $(TEST1)

.PHONY: all clean fclean re test bonus

TEST0=781 44 853
TEST1=187 588 151 890 318 645 324 320 849 741 268 835 471 213 437 244 166 35 938 488 384 739 291 534 287 561 943 789 11 817 81 272 743 879 131 487 428 411 216 983 73 122 895 317 28 162 940 590 928 323 725 632 54 276 55 896 559 423 934 549 586 949 937 328 770 818 446 999 782 598 115 664 891 697 108 884 59 554 764 403 573 692 322 290 365 426 990 338 630 45 195 842 929 761 370 8 568 152 99 781
TEST2= 187 588 151 890 318 645 324 320 849 741 268 835 471 213 437 244 166 35 938 488 384 739 291 534 287 561 943 789 11 817 81 272 

