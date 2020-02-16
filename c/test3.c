#include "liblsf.h"
#include <stdlib.h>

int	main(int ac, char **av) {
int	cabbage_count = 0;
if (ac>1) cabbage_count = atoi(av[1]);
lsf_init();

inventory(cabbage_count);
char	c = 0;
while(1) {
	while((c=getch())==ERR);
	if (c=='q') break;
}

lsf_end(); printf("save: %d\n", cabbage_count); return 0; }
