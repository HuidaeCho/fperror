CFLAGS=-Wall -Werror

all: fperror

clean:
	$(RM) *.o

fperror: fperror.o
	$(CC) $(LDFLAGS) -o $@ $^
