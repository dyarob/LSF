#include "liblsf.h"
#include <stdlib.h>
#include <string.h>

void	draw_cabbages(Submap cf, Art c) {
draw(cf, 4, 7, c);
draw(cf, 4, 12, c);
draw(cf, 4, 17, c);
draw(cf, 7, 7, c);
draw(cf, 7, 12, c);
draw(cf, 7, 17, c);
}

int	main(int ac, char **av) {
lsf_init();
dialog("Lullaby and Melody");
char	**names = (char **)malloc(sizeof(char *)*10);
for (int i=0;i<10;i++) names[i] = (char *)malloc(20);
strcpy(names[0], "Lullaby");
strcpy(names[1], "Melody");
Submap	cabbagefarm = {5, 45, 60, 20};
Art	cabbage = {2, 4, " ff kkkk"};

display_submap(cabbagefarm);
draw_cabbages(cabbagefarm, cabbage);
dialog("It's taking some time to grow.");
dialog("Select one.");
char	c;
while(1) {
	while((c=getch())==ERR);
	if (c=='q') break;
}
lsf_end(); return 0;
}
