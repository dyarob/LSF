#include <stdio.h>
#include <locale.h>
#include <ncurses.h>
#include <unistd.h>

void	hello_world();

// FUNC
void	lsf_init();
void	lsf_end();

// DIALOG
void	first_dialog();
void	dialog(char *str);

// GAME
void	display_map();
void	display_ch(int chc, int chv[2][2]);
