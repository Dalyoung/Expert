// 5373.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <stdio.h>

int N;
char cube[6][3][3];
#define U 0
#define D 1
#define F 2
#define B 3
#define L 4
#define R 5

void setCube() {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[U][i][j] = 'w';
			cube[D][i][j] = 'y';
			cube[F][i][j] = 'r';
			cube[B][i][j] = 'o';
			cube[L][i][j] = 'g';
			cube[R][i][j] = 'b';
		}
	}
}

void printCube() {
	//for (int k = 0; k < 6; k++) {
		for (int i = 0; i < 3; i++) {
			printf("%c %c %c\n", cube[U][i][0], cube[U][i][1], cube[U][i][2]);
		}
	//}
}

void moveCur(char m, char d) {
	int index;
	switch (m) {
	case 'U': index = 0;
		break;
	case 'D': index = 1;
		break;
	case 'F': index = 2;
		break;
	case 'B': index = 3;
		break;
	case 'L': index = 4;
		break;
	case 'R': index = 5;
		break;
	}
	char temp[2];
	if (d == '-') {
		temp[0] = cube[index][0][0]; temp[1] = cube[index][0][1];
		cube[index][0][0] = cube[index][0][2]; cube[index][0][1] = cube[index][1][2];
		cube[index][0][2] = cube[index][2][2]; cube[index][1][2] = cube[index][2][1];
		cube[index][2][2] = cube[index][2][0]; cube[index][2][1] = cube[index][1][0];
		cube[index][2][0] = temp[0]; cube[index][1][0] = temp[1];
	}
	else {
		temp[0] = cube[index][0][0]; temp[1] = cube[index][0][1];
		cube[index][0][0] = cube[index][2][0]; cube[index][0][1] = cube[index][1][0];
		cube[index][2][0] = cube[index][2][2]; cube[index][1][0] = cube[index][2][1];
		cube[index][2][2] = cube[index][0][2]; cube[index][1][2] = cube[index][0][1];
		cube[index][0][2] = temp[0]; cube[index][0][1] = temp[1];
	}
}
void moveCube(char m, char d) {
	
	char temp[3];
	switch (m) {
	case 'U':
		for (int i = 0; i < 3; i++) {
			temp[i] = cube[F][0][i];
		}
		
		if (d == '-') {
			for (int i = 0; i < 3; i++) {
				cube[F][0][i] = cube[R][0][i];
				cube[R][0][i] = cube[B][0][i];
				cube[B][0][i] = cube[L][0][i];
				cube[L][0][i] = temp[i];
			}
			
		}
		else {
			for (int i = 0; i < 3; i++) {
				cube[F][0][i] = cube[L][0][i];
				cube[L][0][i] = cube[B][0][i];
				cube[B][0][i] = cube[R][0][i];
				cube[R][0][i] = temp[i];
			}
			
		}
		break;
	case 'D':
		for (int i = 0; i < 3; i++) {
			temp[i] = cube[F][2][i];
		}

		if (d == '-') {
			for (int i = 0; i < 3; i++) {
				cube[F][2][i] = cube[R][2][i];
				cube[R][2][i] = cube[B][2][i];
				cube[B][2][i] = cube[L][2][i];
				cube[L][2][i] = temp[i];
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				cube[F][2][i] = cube[L][2][i];
				cube[L][2][i] = cube[B][2][i];
				cube[B][2][i] = cube[R][2][i];
				cube[R][2][i] = temp[i];
			}

		}
		break;

	case 'L' :
		for (int i = 0; i < 3; i++) {
			temp[i] = cube[U][i][0];
		}

		if (d == '-') {
			for (int i = 0; i < 3; i++) {
				cube[U][i][0] = cube[F][i][0];
				cube[F][i][0] = cube[D][i][0];
				cube[D][i][0] = cube[B][i][0];
				cube[B][i][0] = temp[i]; 
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				cube[U][i][0] = cube[B][i][0];
				cube[B][i][0] = cube[D][i][0];
				cube[D][i][0] = cube[F][i][0];
				cube[F][i][0] = temp[i];
			}

		}
		break;
	case 'R':
		for (int i = 0; i < 3; i++) {
			temp[i] = cube[U][i][2];
		}

		if (d == '-') {
			for (int i = 0; i < 3; i++) {
				cube[U][i][2] = cube[F][i][2];
				cube[F][i][2] = cube[D][i][2];
				cube[D][i][2] = cube[B][i][2];
				cube[B][i][2] = temp[i];
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				cube[U][i][2] = cube[B][i][2];
				cube[B][i][2] = cube[D][i][2];
				cube[D][i][2] = cube[F][i][2];
				cube[F][i][2] = temp[i];
			}

		}
		break;
	case 'F':
		for (int i = 0; i < 3; i++) {
			temp[i] = cube[U][2][i];
		}

		if (d == '-') {
			for (int i = 0; i < 3; i++) {
				cube[U][2][i] = cube[R][2][i];
				cube[R][2][i] = cube[D][2][i];
				cube[D][2][i] = cube[L][2][i];
				cube[L][2][i] = temp[i];
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				cube[U][2][i] = cube[L][2][i];
				cube[L][2][i] = cube[D][2][i];
				cube[D][2][i] = cube[R][2][i];
				cube[R][2][i] = temp[i];
			}

		}
		break;
	case 'B':
		for (int i = 0; i < 3; i++) {
			temp[i] = cube[U][0][i];
		}

		if (d == '-') {
			for (int i = 0; i < 3; i++) {
				cube[U][0][i] = cube[R][0][i];
				cube[R][0][i] = cube[D][0][i];
				cube[D][0][i] = cube[L][0][i];
				cube[L][0][i] = temp[i];
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				cube[U][0][i] = cube[L][0][i];
				cube[L][0][i] = cube[D][0][i];
				cube[D][0][i] = cube[R][0][i];
				cube[R][0][i] = temp[i];
			}

		}
		break;
	}

	moveCur(m, d);

}
int main()
{
	setCube();

	/*
	for (int k = 0; k < 6; k++) {
		for (int i = 0; i < 3; i++) {
			printf("%c %c %c\n", cube[k][i][0], cube[k][i][1], cube[k][i][2]);
		}
	}
	*/
	int num;
	char move[3];
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d", &num);

		for (int m = 0; m < num; m++) {
			scanf("%s", move);
			//printf("%s\n", move);
			moveCube(move[0], move[1]);
		}
		printCube();

	}

    return 0;
}


