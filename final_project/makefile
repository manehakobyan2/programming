
CC = gcc
CFLAGS = -Wall -g
LIBS = -lsqlite3

#Source files that need to be compiled
SRC = main.c auth.c slot_manage.c
# Object file derived from source files
OBJ = $(SRC:.c=.o)
#output
EXEC = bitcart
CFLAGS = -Wall -g -I/opt/homebrew/opt/openssl@3/include
LDFLAGS = -L/opt/homebrew/opt/openssl@3/lib -lcrypto -lsqlite3

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(EXEC)

