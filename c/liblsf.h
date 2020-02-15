#include <stdio.h>
#include <locale.h>
#include <ncurses.h>
#include <unistd.h>

typedef struct {
int	h, w;
char	*art;
} Art;

// FUNC
void	lsf_init();
void	lsf_end();

// DIALOG
void	dialog(char *str);

// GAME
void	display_map();
void	display_submap();
void	display_ch(int chc, int chv[2][2]);
void	display_cu(int cursor[2]);
void	draw(int y, int x, Art a);
