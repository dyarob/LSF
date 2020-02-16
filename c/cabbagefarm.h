#include "liblsf.h"
#include <stdlib.h>

typedef struct {
int	y, x;
int	tilripe;
} Cabbage;

Cabbage	**cabbages_init();
void	draw_cabbages(Submap cf, Cabbage **cb, Art c, Art cr, int ic);
int	collect(Cabbage **cb, Art c, int cu[2], int ic, int cc);
