CC = gcc

CFLAGS  = -Wall -g -shared -fPIC
LIB 	= -ldl -lrt 
INCLUDE = -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include/

OO	= msgverif.o
TARGETS = msgverif.so

all: $(OO) $(TARGETS)

$(TARGETS): $(00)
	rm -f $(TARGETS)
	$(CC) $(CFLAGS) $(OO) -o $@ $(LIBDIR) $(LIB)

.c.o:
	$(CC)  $(CFLAGS) -c $(INCLUDE) $<

%:%.c
	$(CC) $(CFLAGS) -o $@ $< $(OO) $(LDFLAGS)

clean:
	rm -f *.o
	rm -f $(TARGETS)
