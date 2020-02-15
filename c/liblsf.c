#include "liblsf.h"

int	Y = 4;

void	hello_world() {

	printf("Hello world!");
}


// FUNC
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


// DIALOGS
void	first_dialog() {

	addstr(">Welcome to the console edition !");
	move(4, 0);
	refresh();
sleep(1);
}

void	dialog(char *str) {

	addstr(str);
	move((Y+=2),0);
	refresh();
sleep(1);
}


// GAME
void	display_map() {

	move(4, 50);
	for (int i=0;i<50;++i) addch(95);
	for (int y=5;y<35;++y) {
		mvaddch(y, 50, 124);
		mvaddch(y, 100, 124); }
	move(35, 50);
	for (int i=0;i<50;++i) addch(95);
	refresh();
}

void	display_ch(int c, int ch[2][2]) {

	for (int i=0;i<c;++i) {
		move(5+ch[i][0], 50+ch[i][1]);
		addch('C');
		refresh(); }
}
