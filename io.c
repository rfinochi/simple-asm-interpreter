#include <stdio.h>

#include <io.h>

int read_program(int *mem) {
   int last = 0;
   
   char filename[50];
   FILE *filePtr;

   printf("\nEnter program filename: ");
   scanf("%s", filename);
   printf("\n*** Program file load begin ***\n");

   if ((filePtr = fopen(filename, "r")) == NULL) {
      printf("\nAn error occurred opening file\n");
   } else {
      while (!feof(filePtr)) {
		fscanf(filePtr, "%d", &mem[last]);
		printf("\n%d => %d", last, mem[last]);
		last++;
      }

      fclose(filePtr);
      printf("\n\n*** Program loaded in memory ***\n");
   }

   return last;
}

void write_program(int last, int *mem) {
	int cont = 0;
	int temp;
	char filename[50];
	FILE *savePtr;

	printf("\nEnter program filename: ");
	scanf("%s", filename);
   	printf("\n*** Program writing to disk begin ***\n\n");

	if ((savePtr = fopen(filename, "w")) == NULL) {
		printf("An error occurred writing file\n");
	} else {
		for(cont = 0; cont <= last; cont++) {
			fprintf(savePtr, "%d\n", mem[cont]);
			printf("%d => %d\n",cont, mem[cont]);
		}

		printf("\n*** Program writed to disk ***\n");
	}

	fclose(savePtr);
}
