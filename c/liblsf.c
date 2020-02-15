#include "liblsf.h"

int	Y = 4;
int	CU[2] = {0,0};

// FUNC
void	lsf_init() {

	setlocale(LC_ALL, "");
	initscr(); cbreak(); noecho();
	nodelay(stdscr, TRUE);

	addch('c');
	move(2, 0);
	refresh();
}

void	lsf_end() {

	endwin();
}


// DIALOGS
void	dialog(char *str) {

	move(Y,0);
	addstr(str);
	Y+=2;
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

void	display_submap(Submap sm) {

	move(sm.y, sm.x);
	for (int i=0;i<sm.w;++i) addch(95);
	for (int y=sm.y+1;y<=sm.y+sm.h;++y) {
		mvaddch(y, sm.x, 124);
		mvaddch(y, sm.x+sm.w, 124); }
	move(sm.y+sm.h, sm.x+1);
	for (int i=0;i<sm.w-1;++i) addch(95);
	refresh();
}

void	display_ch(int c, int ch[2][2]) {

	for (int i=0;i<c;++i) {
		move(6+ch[i][0], 51+ch[i][1]);
		addch('C');
		refresh(); }
}

void	display_cu(Submap sm, int cu[2]) {

	move(sm.y+1+CU[0],sm.x+1+CU[1]);
	addch(' ');
	CU[0] = cu[0];
	CU[1] = cu[1];
	move(sm.y+1+CU[0],sm.x+1+CU[1]);
	addch('<');
}

void	draw(Submap sm, int y, int x, Art a) {

	move(sm.y+y, sm.x+x);
	for (int i=0;i<a.h;i++) {
		for (int j=0;j<a.w;j++) addch(a.art[i*a.w+j]);
		move(sm.y+y+i+1, sm.x+x); }
}
