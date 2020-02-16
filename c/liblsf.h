#ifndef LIBLSF_H
# define LIBLSF_H
#include <stdio.h>
#include <locale.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>

typedef struct {
int	y, x, w, h;
char	*name;
} Submap;
typedef struct {
int	w, h;
char	*art;
} Art;

// FUNC
void	lsf_init();
void	lsf_end();

// DIALOG
void	dialog(char *str);
void	inventory(int c);

// GAME
void	display_map();
void	display_submap(Submap sm);
void	display_ch(int chc, int chv[2][2]);
void	display_cu(Submap sm, int cursor[2]);
void	doodle(Submap sm, int y, int x, Art a);

// TOOL
void	itoa(int n, char s[]);
void	reverse(char s[]);
#endif
