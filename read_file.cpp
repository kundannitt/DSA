#include <stdio.h>
#define filename "sampletext.txt"
int main(){
	FILE *fp;
	int count = 0;
	char c; 

	fp = fopen(filename, "r");

	if (fp == NULL){
		printf("Could not open file %s", filename);
		return 0;
	}

	for (c = getc(fp); c != EOF; c = getc(fp)){
		if (c == '\n'){
			count = count + 1;
    }
  }

	fclose(fp);
	printf("%d",count);
	return 0;
}
