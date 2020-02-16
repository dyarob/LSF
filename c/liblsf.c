#include "liblsf.h"

int	Y = 4;
int	CU[2] = {0,0};
char	buf[50];

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

void	inventory(int cabbage_count) {
	move(2, 80);
	addstr("Cabbages ");
	itoa(cabbage_count, buf);
	addstr(buf);
}


// GAME
void	display_submap(Submap sm) {

	move(sm.y, sm.x);
	for (int i=0;i<sm.w;++i) addch(95);
	for (int y=1;y<sm.h;++y) {
		move(sm.y+y, sm.x);
		addch(124);
		for (int i=0;i<sm.w-2;++i) addch(' ');
		addch(124); }
	move(sm.y+sm.h, sm.x);
	addch(124);
	for (int i=0;i<sm.w-2;++i) addch(95);
	addch(124);
	move(sm.y+sm.h-1, sm.x+1);
	addstr(sm.name);
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

void	doodle(Submap sm, int y, int x, Art a) {

	for (int i=0;i<a.h;i++) {
		move(sm.y+y+i+1, sm.x+x+1);
		for (int j=0;j<a.w;j++) addch(a.art[i*a.w+j]);
	}
}

// TOOLS
 /* itoa:  convert n to characters in s */
 void itoa(int n, char s[])
 {
     int i, sign;
     if ((sign = n) < 0)  /* record sign */
         n = -n;          /* make n positive */
     i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0';   /* get next digit */
     } while ((n /= 10) > 0);     /* delete it */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
 }
 /* reverse:  reverse string s in place */
 void reverse(char s[])
 {
     int i, j;
     char c;
     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }
