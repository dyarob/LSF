lib:
	gcc -c liblsf.c -o liblsf.o
	ar rc liblsf.a liblsf.o
	ranlib liblsf.a

test:
	gcc test.c -llsf -lncurses -L.

clean:
	rm -rf liblsf.o a.out
