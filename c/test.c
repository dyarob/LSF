#include "liblsf.h"
#include <unistd.h>

int	compare_cu(int cu[2], int c, int ch[2][2]) {

	for (int i=0;i<c;++i)
		if (cu[0]==ch[i][0]&&cu[1]==ch[i][1])
			return 1;
	return 0;
}

int	main(int ac, char **av) {

	int	ch[2][2]={{1, 2}, {5, 6}};

	char	c;
	int	cu[2]={0,0};

	lsf_init();
	dialog("Welcome to the console edition !");
	dialog("This tutorial will guide you !");
	dialog("First select a character (hjkl)\nq to quit");
	display_map();
	display_ch(2, ch);

	while(1) {
		while((c=getch())==ERR);
		if (c=='q') break;
		display_ch(2, ch);
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
		if (compare_cu(cu, 2, ch))
			dialog("char select");
	}

	lsf_end();
	return 0;
}
