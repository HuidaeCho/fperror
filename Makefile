CFLAGS=-Wall -Werror

all: fperror fperror_float

clean:
	$(RM) *.o

fperror: fperror.o
	$(CC) $(LDFLAGS) -o $@ $^

fperror_float: fperror_float.o
	$(CC) $(LDFLAGS) -o $@ $^
