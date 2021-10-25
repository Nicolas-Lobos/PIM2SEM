// C program for the above approach
#include <conio.h>
#include <stdio.h>
#include <string.h>

// Driver Code
int main()
{
	// Substitute the full file path
	// for the string file_path
	FILE* fp = fopen("file.txt", "r");

	if (!fp)
		printf("Can't open file\n");

	else {
		// Here we have taken size of
		// array 1024 you can modify it
		char buffer[1024];
        char mat[2][100];
        int i = 0;
		int row = 0;
		int column = 0;
        char password[100];

		while (fgets(buffer,1024, fp)) {
			column = 0;
			row++;

			// To avoid printing of column
			// names in file can be changed
			// according to need
			if (row == 0)
				continue;

			// Splitting the data
			char* value = strtok(buffer, ",");

			while (value) {
                strcpy(mat[i],value);
				
                printf("%s\n", value);
				value = strtok(NULL, ", ");
                i=1;
                
                printf("matriz1: %s\n", mat[0]);
                printf("matriz2: %s\n", mat[1]);
                getch();
				//column++;
			}

			printf("\n");
            
		}

		// Close the file
		fclose(fp);
        getch();
	}
	return 0;
}
