#include <stdio.h>
#include "bstr.h"

#define	SCALE_MAXNOTECNT	12

typedef struct scale {
	char	*sc_name;
	int	sc_notecnt;
	int	sc_intv[SCALE_MAXNOTECNT];

} scale_t;

scale_t		scales[] = {
	{
		"min_pent",
		5,
		{ 0, 3, 5, 7, 10 }
	}
};


#define STRINGCNT	16
#define FRETCNT		25

#define SCALE_NOTE_NONE	-1

int
main(int argc, char **argv)
{

	scale_t	*sc;
	int	root;
	int	i;
	int	t;
	int	sstart;
	int	note;
	int	u;
	int	notenr;

	root = 6;
	sc = &scales[0];

	for(t = 0; t < FRETCNT; ++t) {
		if((t > 0) && ((t % 12) == 0)) {
			printf("o");
		} else printf(" ");
		printf(" ");
	}
	printf("\n");

	for(t = 0; t < FRETCNT; ++t) {
		if((t % 12) == 3 || (t % 12) == 5 || (t % 12) == 7 || 
		    (t % 12) == 9 || ((t > 0) && ((t % 12) == 0))) {
			printf("o");
		} else printf(" ");
		printf(" ");
	}
	printf("\n");


	for(i = STRINGCNT - 1; i >= 0; --i) {

		sstart = i * 5;
		note = sstart;
		for(t = 0; t < FRETCNT; ++t) {
			notenr = SCALE_NOTE_NONE;

			for(u = 0; u < sc->sc_notecnt; ++u) {
				if((note % 12) ==
				    (root + sc->sc_intv[u]) % 12 ) {
					notenr = u;
					break;
				}
			}

			if(notenr != SCALE_NOTE_NONE)
				printf("%d-", notenr + 1);
			else
				printf("|-");

			note++;
		}
		printf("\n");

		sstart += 5;
	}
	
	return 0;
}

