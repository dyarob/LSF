#include <stdio.h>
#include <locale.h>
#include <ncurses.h>
#include <unistd.h>

typedef struct {
int	y, x, w, h;
} Submap;
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
void	display_submap(Submap sm);
void	inventory(int c);
void	display_ch(int chc, int chv[2][2]);
void	display_cu(Submap sm, int cursor[2]);
void	doodle(Submap sm, int y, int x, Art a);
