#include "liblsf.h"
#include <unistd.h>

int	main(int ac, char **av) {

	lsf_init();
sleep(3);
	lsf_end();
	hello_world();
	return 0;
}
