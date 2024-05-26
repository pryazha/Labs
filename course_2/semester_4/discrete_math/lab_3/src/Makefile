BUILDDIR ?= ../build
OBJS ?= main.o

main: $(OBJS)
	@mkdir -p $(BUILDDIR)
	gcc -Wall -g -o $(BUILDDIR)/test $(OBJS)

main.o: main.c
	gcc -Wall -c -g main.c

clean:
	rm *.o
