CC = cc
CFLAGS = -I. -O3 -g3 -Wall -Wextra -Werror=format-security -Werror=implicit-function-declaration \
         -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wwrite-strings -Wconversion

# Define the source files
SRCS = ArrayList.c my_string.c tokenizer.c test.c

# Define the object files
OBJS = $(SRCS:.c=.o)

# Define the output binary
BIN = test

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BIN)
