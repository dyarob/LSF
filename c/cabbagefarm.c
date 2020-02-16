#include "cabbagefarm.h"

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
	if (cu[0]>=cb[i]->y&&cu[0]<cb[i]->y+c.h
		&&cu[1]>=cb[i]->x&&cu[1]<cb[i]->x+c.w) {
		cb[i]->tilripe = ic + 30;
		return ++cc;
	}
return cc;
}
