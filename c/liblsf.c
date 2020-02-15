#include "liblsf.h"

void	hello_world() {

	printf("Hello world!");
}

void	lsf_init() {

	setlocale(LC_ALL, "");
	initscr(); cbreak(); noecho();
addch('c');
move(2, 0);
refresh();
}

void	lsf_end() {

	endwin();
//	nocbreak();
//	echo();
}
