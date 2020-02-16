#include "liblsf.h"
#include <stdlib.h>

typedef struct {
int	y, x;
Art	*art;
} Character;
Character	**chars_init() {
Character	**chars = (Character **)malloc(sizeof(Character*)*2+1);
for (int i=0;i<2;i++) chars[i] = (Character *)malloc(sizeof(Character));
chars[0]->y = 12; chars[0]->x = 32; chars[0]->art = NULL;
chars[1]->y = 3; chars[1]->x = 17; chars[1]->art = NULL;
chars[2] = NULL;
return chars;
}
void	draw_characters(Submap map, Character **chars) {
for (int i=0;chars[i];i++)
	doodle(map, chars[i]->y, chars[i]->x, *chars[i]->art);
}

int	main(int ac, char **av) {
Submap	map	= {5, 50, 70, 20};
Character	**chars = chars_init();
Art	*Lullaby = (Art *)malloc(sizeof(Art));
Art	*Melody = (Art *)malloc(sizeof(Art));
Lullaby->w = 1; Lullaby->h = 2; Lullaby->art = "cC";
Melody->w = 1; Melody->h = 2; Melody->art = "oG";
chars[0]->art = Lullaby; chars[1]->art = Melody;
int	cabbage_count = 0;
if (ac>1) cabbage_count = atoi(av[1]);
lsf_init();

inventory(cabbage_count);
display_submap(map);
//display_ch(2, chars);
draw_characters(map, chars);

dialog("Welcome to LSF.");
char	c = 0;
while(1) {
	while((c=getch())==ERR);
	if (c=='q') break;
}

lsf_end(); printf("save: %d\n", cabbage_count); return 0; }
