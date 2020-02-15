lib:
	gcc -c liblsf.c -o liblsf.o
	ar rc liblsf.a liblsf.o
	ranlib liblsf.a

test:
	gcc test.c -llsf -lncurses -L. -o test.out
	gcc test2.c -llsf -lncurses -L. -o test2.out

clean:
	rm -rf liblsf.o a.out
