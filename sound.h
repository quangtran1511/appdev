// in this file we difine related constants and declare functions
// for handling sounds.
//#define SDEBUG
// define sound structure (deal with .wav file)

typedef struct{
	char chunkID[4];			// should be always "RIFF"
	int chunkSize;
	char format[4];			// should ne always "WAVE"
	char subchunk1ID[4];	// should be always "fmt"
	int subchunk1Size;		// should be 16 for PCM
	short audioFormat;		// should be 1 for PCM
	short numChannels;		// could be 1 for mono, 2 for stereo
	int sampleRate;			// usually it's 44100, or 16000
	int byteRate;			// can be calculated
	short blockAlign;		// how many byte in 1 block
	short bitsPerSample;	// could be 8 or 16
	char subchunk2ID[4];	// should be always "data"
	int subchunk2Size;		// can be calculated
}WAVheader;

// function declaration
WAVheader readwavhdr(FILE *fp);
void displayWAVhdr(WAVheader h);
void wavdata(WAVheader h, FILE *fp);
