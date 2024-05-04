/* Author: Sabrina Jauregui
   Purpose: Final Project */
   
#include <stdio.h>
#define ROWS 23
#define COLS 16
#define SIZE 100

void loadImage(char *filename, int image[][COLS]);
void displayCurrentImage(int image[ROWS][COLS]);
void editImage();
void cropImage();
void dimImage();
void brightenImage();

int main(){
	int choice;
	int image[ROWS][COLS];
	char filename[SIZE];
	
	do{
		printf("**ERINSTAGRAM**\n");
		printf("1: Load Image\n2: Display Image\n3: Edit Image\n0: Exit\n");
		printf("Choose from one of the options above: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				loadImage(filename, image);
			break;
			case 2:
				displayCurrentImage(image);
			case 3:
				editImage();
			break;
			case 0:
				printf("Goodbye!\n");
			break;
			default:
				printf("Invalid option, please try again.\n");
		}
	}while(choice != 0);
	
	return 0;
}

void loadImage(char *filename, int image[][COLS]){
	
	printf("What is the name of the image file? ");
	scanf("%s", filename);
	
	FILE *file = fopen(filename, "r");
	
	if(file = NULL){
		printf("Could not find an image with that filename.\n");
	}
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			fscanf(file, "%d", &image[i][j]);
		}
	}
		fclose(file);
}

void displayCurrentImage(int image[][COLS]){
	
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			printf("%d", image[i][j]);
		}
	}
}

void editImage(){
	int choice;
	
	printf("**EDITING**\n");
	printf("1: Crop Image\n2: Dim Image\n3: Brighten image\n0: Return to the main menu\n");
	printf("Choose from one of the options above: ");
	scanf("%d", &choice);
}
