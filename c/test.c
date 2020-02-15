#include "liblsf.h"
#include <unistd.h>

int	main(int ac, char **av) {

	int	ch[2][2]={{1, 2}, {5, 6}};

	char	c;
	int	cu[2]={0,0};

	lsf_init();
	first_dialog();
	dialog("This tutorial will guide you !");
	dialog("First select a character (hjkl)\nq to quit");
	display_map();
	display_ch(2, ch);

	while(1) {
		while((c=getch())==ERR);
		if (c=='q') break;
		switch (c) {
		case 'h':
			--cu[1];
			display_cu(cu);
			break;
		case 'j':
			++cu[0];
			display_cu(cu);
			break;
		case 'k':
			--cu[0];
			display_cu(cu);
			break;
		case 'l':
			++cu[1];
			display_cu(cu);
			break;
		}
	}

	lsf_end();
	return 0;
}
