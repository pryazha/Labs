BUILDDIR ?= ../build
OBJS ?= main.o

main: $(OBJS)
	@mkdir -p ../build
	gcc -g -o $(BUILDDIR)/min_sp_tree $(OBJS)

main.o: main.c
	gcc -c -g main.c

clean:
	rm *.o
