#include "liblsf.h"
#include <stdlib.h>
#include <string.h>

int	main(int ac, char **av) {
lsf_init();
dialog("Lullaby and Melody");
char	**names = (char **)malloc(sizeof(char *)*10);
for (int i=0;i<10;i++) names[i] = (char *)malloc(20);
strcpy(names[0], "Lullaby");
strcpy(names[1], "Melody");
Art	cabbage = {2, 4, " ff kkkk"};

display_submap();
draw(4, 7, cabbage);
draw(4, 12, cabbage);
char	c;
while(1) {
	while((c=getch())==ERR);
	if (c=='q') break;
}
lsf_end(); return 0;
}
