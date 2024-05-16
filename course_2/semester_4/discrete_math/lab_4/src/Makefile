BUILDDIR = ../build
OBJS = main.o

automats: $(OBJS)
	@mkdir -p $(BUILDDIR)
	gcc -Wall -g -o $(BUILDDIR)/automats $(OBJS)

main.o: main.c
	gcc -Wall -g -c main.c

clean:
	rm -f *.o
