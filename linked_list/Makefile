
CC = cc

CFLAG1 = -c
CFLAG2 = -c -D GENERIC

.SUFFIXES: .c .o .x

OBJ1 = seq_int.o main1.o
OBJ2 = seq_generic.o main2.o
EXES = main1.x main2.x

all: $(EXES)

main1.x: $(OBJ1)
	$(CC) -s $(OBJ1) -o $@ || rm -f $@

main2.x: $(OBJ2)
	$(CC) -s $(OBJ2) -o $@ || rm -f $@

seq_int.o: seq.c
	$(CC) $(CFLAG1) $? -o $@ || rm -f $@

seq_generic.o: seq.c
	$(CC) $(CFLAG2) $? -o $@ || rm -f $@

clean:
	rm -rf $(EXES) $(OBJ1) $(OBJ2)
