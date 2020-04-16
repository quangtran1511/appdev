#include <stdio.h>
#include "sound.h"

WAVheader readwavhdr(FILE *fp){
	WAVheader myh;
	fread(&myh, sizeof(myh), 1, fp);
	return myh;
}

void displayWAVhdr(WAVheader h){
	printf("Chunk ID: ");
	for (int i=0; i<4; i++) printf("%c", h.chunkID[i]);
	printf("\n");
	printf("Chunk size: %d\n", h.chunkSize);
	printf("Num of channels: %d\n", h.numChannels);
	printf("Sample rate: %d\n", h.sampleRate);
	printf("Block align: %d\n", h.blockAlign);
	printf("Bits per sample: %d\n", h.bitsPerSample);
}
