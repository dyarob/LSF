#include "liblsf.h"
#include "cabbagefarm.h"
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
int	cu[2] = {0, 0};
int	sm = 0;
Submap	map = {5, 50, 70, 20, "Main floor"};
Submap	smcfarm = {8, 60, 10, 4, "Cabbage farm"};
Submap	cabbagefarm = {5, 55, 60, 20, "Cabbage farm"};
Character	**chars = chars_init();
Art	*Lullaby = (Art *)malloc(sizeof(Art));
Art	*Melody = (Art *)malloc(sizeof(Art));
Lullaby->w = 1; Lullaby->h = 2; Lullaby->art = "cC";
Melody->w = 1; Melody->h = 2; Melody->art = "oG";
chars[0]->art = Lullaby; chars[1]->art = Melody;
Cabbage	**cabbages = cabbages_init();
Art	cabbagesprout = {4, 2, "     ff "};
Art	cabbage = {4, 2, " ff kkkk"};
Art	cabbageripe = {4, 2, "ffff kk "};
int	interactions_count = 0;
int	cabbage_count = 0;
if (ac>1) cabbage_count = atoi(av[1]);
lsf_init();

dialog("Welcome to LSF.");
char	c = 0;
while(1) {
	inventory(cabbage_count);
	display_submap(map);
	switch (sm) {
	case 0:
		display_submap(smcfarm);
		draw_characters(map, chars);
		display_cu(map, cu);
		break;
	case 1:
		display_submap(cabbagefarm);
		draw_cabbages(cabbagefarm, cabbages, cabbage, cabbageripe, interactions_count);
		display_cu(cabbagefarm, cu);
		break;
	}
	while((c=getch())==ERR);
	interactions_count++;
	if (c=='q') break;
	switch (c) {
	case 'h': --cu[1]; break;
	case 'j': ++cu[0]; break;
	case 'k': --cu[0]; break;
	case 'l': ++cu[1]; break;
	case 's':
		if (sm==0) { sm = 1; break; }
		cabbage_count = collect(cabbages, cabbage, cu, interactions_count, cabbage_count);
		break;
	case 'w': if (sm==1) sm = 0; break;
	}
}

lsf_end(); printf("save: %d\n", cabbage_count); return 0; }
