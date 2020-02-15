#include "liblsf.h"
#include <unistd.h>

int	main(int ac, char **av) {

	int	ch[2][2]={{1, 2}, {5, 6}};

	lsf_init();
	first_dialog();
	dialog("This tutorial will guide you !");
	dialog("First select a character.");
	display_map();
	display_ch(2, ch);

sleep(5);
	lsf_end();
	hello_world();
	return 0;
}
