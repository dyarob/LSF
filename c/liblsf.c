#include "liblsf.h"

int	Y = 4;
int	CU[2] = {0,0};
int	SM_Y = 0, SM_X = 0;

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

void	display_submap() {
	int	sm_y = 5;
	int	sm_x = 45;
	int	sm_w = 60;
	int	sm_h = 20;
	SM_Y = 5;
	SM_X = 45;

	move(sm_y, sm_x);
	for (int i=0;i<sm_w;++i) addch(95);
	for (int y=sm_y+1;y<=sm_y+sm_h;++y) {
		mvaddch(y, sm_x, 124);
		mvaddch(y, sm_x+sm_w, 124); }
	move(sm_y+sm_h, sm_x+1);
	for (int i=0;i<sm_w-1;++i) addch(95);
	refresh();
}

void	display_ch(int c, int ch[2][2]) {

	for (int i=0;i<c;++i) {
		move(6+ch[i][0], 51+ch[i][1]);
		addch('C');
		refresh(); }
}

void	display_cu(int cu[2]) {

	move(6+CU[0],51+CU[1]);
	addch(' ');
	CU[0] = cu[0];
	CU[1] = cu[1];
	move(6+CU[0],51+CU[1]);
	addch('<');
}

void	draw(int y, int x, Art a) {

	move(SM_Y+y, SM_X+x);
	for (int i=0;i<a.h;i++) {
		for (int j=0;j<a.w;j++) addch(a.art[i*a.w+j]);
		move(SM_Y+y+i+1, SM_X+x); }
}
