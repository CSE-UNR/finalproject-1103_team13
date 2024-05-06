/* Author: Sabrina Jauregui and Anthony Felix
   Purpose: Final Project */
   
#include <stdio.h>
#define ROWS 16
#define COLS 23
#define SIZE 100


void loadImage(char *filename, int image[][COLS]);
void displayCurrentImage(int image[ROWS][COLS]);
void editImage(char *filename, int image[ROWS][COLS]);
void cropImage(int image[ROWS][COLS]);
void dimImage(int image[ROWS][COLS]);
void brightenImage(int image[ROWS][COLS]);
void saveImage(int image[][COLS]);

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
			break;
			case 3:
				editImage(filename, image);
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
	
	if(file == NULL){
		printf("Could not find an image with that filename.\n");
		return;
	}
	
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			fscanf(file, "%1d", &image[i][j]);
		}
		
	}
	fclose(file);
}

void displayCurrentImage(int image[][COLS]){
 
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            switch(image[i][j]){
            	case 0:
            		printf(" ");
            		break;
            	case 1:
            		printf(".");
            		break;
            	case 2:
            		printf("o");
            		break;
            	case 3:
            		printf("O");
            		break;
            	case 4:
            		printf("0");
            		break;
            	default:
            		printf(" ");
            		break;
            }
            	
        }
        printf("\n"); 
    }
}

	


void editImage(char *filename, int image[][COLS]){
	int choice;
	
	printf("**EDITING**\n");
	printf("1: Crop Image\n2: Dim Image\n3: Brighten image\n0: Return to the main menu\n");
	printf("Choose from one of the options above: ");
	scanf("%d", &choice);
	
	switch(choice){
		case 0:
			break;
		case 1:
			cropImage(image);
			saveImage(image);
			break;
		case 2:
			dimImage(image);
			saveImage(image);
			break;
		case 3:
			brightenImage(image);
			saveImage(image);
			break;
	
	}
}

void cropImage(int image[][COLS]){
	
	int leftCol, rightCol, topRow, botRow;
	char choice, newFileName[SIZE];
	
	printf("The image you want to crop is 12 x 21.\n");
	printf("The row and column values start in the upper lefthand corner.\n");
	
	printf("Which column do you want to be the new left side? ");
	scanf("%d", &leftCol);
	printf("Which column do you want to be the new right side? ");
	scanf("%d", &rightCol);
	
	printf("Which row do you want to be the new top? ");
	scanf("%d", &topRow);
	printf("Which row fo you want to be the bottom? ");
	scanf("%d",&botRow);
	
	for(int  i = topRow; i < botRow; i++){
		for(int j = leftCol; j < rightCol; j++){
			switch(image[i][j]){
            	case 0:
            		printf(" ");
            		break;
            	case 1:
            		printf(".");
            		break;
            	case 2:
            		printf("o");
            		break;
            	case 3:
            		printf("O");
            		break;
            	case 4:
            		printf("0");
            		break;
            	default:
            		printf(" ");
            		break;
            }
       }
       printf("\n");
    }
    printf("Do you want to save this image to a file? (y/n): ");
	scanf(" %c", &choice);  
	
	switch(choice){
		case 'Y':
		case 'y':
			printf("What do you want to name the image file? (inlcude the extension) ");
			scanf("%s", newFileName);
		
			FILE *newFile = fopen(newFileName, "w");
			if(newFile == NULL){
				printf("Could not save file.\n");
			}
		
			for(int i = 0; i < ROWS; i++){
				for(int j = 0; j < COLS; j++){
					fprintf(newFile, "%d", image[i][j]);
				}
				fprintf(newFile, "\n");
			}
			
		break;
		case 'N':
		case 'n':
		break;
		default:
			printf("Invalid option.\n");
	} 



}



void dimImage(int image[][COLS]){
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			if(image[i][j] > 0){
				image[i][j] -= 1;
			}
		}	
	}
	displayCurrentImage(image);
}


void brightenImage(int image[][COLS]){
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			if(image[i][j] < 4){
				image[i][j]++;
			}
		}	
	}
	displayCurrentImage(image);
}

void saveImage(int image[][COLS]){
	char userInput;
	char newFile[100];
		
	printf("Would you like to save the file? (y/n) ");
	scanf(" %c", &userInput);
	
	if(userInput == 'y' || userInput == 'Y'){
		printf("What do you want to name the image file? (include the extension): ");
		scanf("%s", newFile);
		
		FILE *saveFile = fopen(newFile, "w");
		
		if(saveFile == NULL){
			printf("Error. Couldn't create file.\n");
			return;
		}
		for(int i = 0; i < ROWS; i++){
			for(int j = 0; j < COLS; j++){
				fprintf(saveFile, "%d", image[i][j]);
			}	
			fprintf(saveFile, "\n");
		}
		printf("Image successfully saved!\n\n");
		fclose(saveFile);
	}
	else if(userInput == 'n' || userInput == 'N'){
		return;
	}
}








