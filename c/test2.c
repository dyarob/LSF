#include "liblsf.h"
#include <stdlib.h>
#include <string.h>

typedef struct {
int	y, x;
int	tilripe;
} Cabbage;
Cabbage	**cabbages_init() {
Cabbage	**Cabbages = (Cabbage **)malloc(sizeof(Cabbage*)*6+1);
for (int i=0;i<6;i++)
	Cabbages[i] = (Cabbage *)malloc(sizeof(Cabbage));
Cabbages[6] = NULL;
Cabbages[0]->y = 4; Cabbages[0]->x = 7; Cabbages[0]->tilripe = 10;
Cabbages[1]->y = 4; Cabbages[1]->x = 12; Cabbages[1]->tilripe = 8;
Cabbages[2]->y = 4; Cabbages[2]->x = 17; Cabbages[2]->tilripe = 15;
Cabbages[3]->y = 7; Cabbages[3]->x = 7; Cabbages[3]->tilripe = 18;
Cabbages[4]->y = 7; Cabbages[4]->x = 12; Cabbages[4]->tilripe = 20;
Cabbages[5]->y = 7; Cabbages[5]->x = 17; Cabbages[5]->tilripe = 30;
return Cabbages;
}

void	draw_cabbages(Submap cf, Cabbage **cb, Art c, Art cr, int ic) {
for (int i=0;cb[i];i++)
	if (cb[i]->tilripe > ic)
		doodle(cf, cb[i]->y, cb[i]->x, c);
	else doodle(cf, cb[i]->y, cb[i]->x, cr);
}

int	collect(Cabbage **cb, Art c, int cu[2], int ic, int cc) {
for (int i=0;cb[i];i++)
	if (cu[0]>cb[i]->y&&cu[0]<=cb[i]->y+c.h
		&&cu[1]>cb[i]->x&&cu[1]<=cb[i]->x+c.w) {
		cb[i]->tilripe = ic + 30;
		return ++cc;
	}
return cc;
}

int	main(int ac, char **av) {
lsf_init();
dialog("Lullaby and Melody");
char	**names = (char **)malloc(sizeof(char *)*10);
for (int i=0;i<10;i++) names[i] = (char *)malloc(20);
strcpy(names[0], "Lullaby");
strcpy(names[1], "Melody");
Submap	cabbagefarm = {5, 45, 60, 20};
Cabbage	**cabbages = cabbages_init();
Art	cabbagesprout = {4, 2, "     ff "};
Art	cabbage = {4, 2, " ff kkkk"};
Art	cabbageripe = {4, 2, "ffff kk "};
int	cabbage_count = 0;
int	cu[2] = {0,0};
int	interactions_count = 0;

display_submap(cabbagefarm);
draw_cabbages(cabbagefarm, cabbages, cabbage, cabbageripe, interactions_count);
dialog("It's taking some time to grow.");
dialog("Select a ripe one. (s)\n(w to exit submap)");
display_cu(cabbagefarm, cu);
char	c;
while(1) {
	while((c=getch())==ERR);
	interactions_count++;
	if (c=='q') break;
	switch (c) {
	case 'h': --cu[1]; break;
	case 'j': ++cu[0]; break;
	case 'k': --cu[0]; break;
	case 'l': ++cu[1]; break;
	case 's':
		cabbage_count = collect(cabbages, cabbage, cu, interactions_count, cabbage_count);
		break;
	}
	draw_cabbages(cabbagefarm, cabbages, cabbage, cabbageripe, interactions_count);
	display_cu(cabbagefarm, cu);
	inventory(cabbage_count);
}
lsf_end(); return 0;
}
