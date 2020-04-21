#include <stdio.h>
#include "screen.h"
#include <unistd.h>
#include "comm.h"
#include "sound.h"

int main(void)
{
	FILE *fp;
	fp = fopen("test.wav", "r");
	WAVheader h = readwavhdr(fp);
	displayWAVhdr(h);
	clearscreen();
	wavdata(h, fp);		//to calculate the dB values and display them as a barchart
	fclose(fp);
	getchar();
}
