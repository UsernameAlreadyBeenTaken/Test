///////////////////////////////
///                         ///
///   Tower of Hanoi game   ///
///                         ///
///////////////////////////////

#include <stdio.h>

int isVictory(int DISKS_NUMBER, int* ThirdRod); // checks victory conditions
void Show(int** Rods, int DISKS_NUMBER); // prints graphic part
void Gameplay(int** Rods, int DISKS_NUMBER); // handle game process

int main(){

	int DISKS_NUMBER = 4;
	int i;

	// allocating memory
	int** Rods;
	Rods = (int**)malloc(3*sizeof(int*));
	for (i = 0; i < 3; ++i){
		Rods[i] = (int*)malloc(DISKS_NUMBER*sizeof(int));
	}

	// initializing first rod before the start
	for (i = 0; i < DISKS_NUMBER; ++i){
		Rods[0][i] = i+1;
		Rods[1][i] = 0;
		Rods[2][i] = 0;
	}

	// print start condition
	Show(Rods, DISKS_NUMBER);
	// game process
	Gameplay(Rods, DISKS_NUMBER);

	printf("You win!\n");

	return 0;
}


int isVictory(int DISKS_NUMBER, int* ThirdRod){
	int i;
	for (i = DISKS_NUMBER - 1; i >= 0; --i){
		if (ThirdRod[i] == 0)
			return 0;
	}
	return 1;
}

void Show(int** Rods, int DISKS_NUMBER){
	int i, j, k;
	for (i = 0; i < DISKS_NUMBER; ++i){
		for (j = 0; j < 3; ++j){
			printf("|");
			for (k = 0; k < Rods[j][i]; ++k){
				printf("#");
			}
			for (k = 0; k < DISKS_NUMBER - Rods[j][i]; ++k){
				printf(" ");
			}
		}
		printf("\n");
	}
}

void Gameplay(int** Rods, int DISKS_NUMBER){
	while (isVictory(DISKS_NUMBER, Rods[2]) != 1){

		int i, Where, From;
		printf("From: ");
		scanf("%i", &From);
		printf("Where: ");
		scanf("%i", &Where);

		if (From < 1 || From > 3 || Where < 1 || Where > 3 || From == Where){
			printf("Wrong input\n");
			continue;
		}

		From = From - 1;
		Where = Where - 1;

		int fromSize = 0, whereSize = 0, fromPlace, wherePlace = DISKS_NUMBER - 1;

		for (i = 0; i < DISKS_NUMBER; ++i){
			if (Rods[From][i] != 0){
				fromSize = Rods[From][i];
				fromPlace = i;
				break;
			}
		}
		if (fromSize == 0){
			printf("Wrong turn\n");
			continue;
		}

		for (i = 0; i < DISKS_NUMBER; ++i){
			if (Rods[Where][i] != 0){
				whereSize = Rods[Where][i];
				wherePlace = i - 1;
				break;
			}
		}

		if (fromSize > whereSize && whereSize != 0){
			printf("Wrong turn\n");
			continue;
		}

		Rods[Where][wherePlace] = Rods[From][fromPlace];
		Rods[From][fromPlace] = 0;

		Show(Rods, DISKS_NUMBER);
	}
}