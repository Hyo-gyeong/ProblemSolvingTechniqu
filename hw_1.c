//커뮤ㅠ터학과 20190975 신효경
//tic-tac-toe
/*#include <stdio.h>
int win(char b[][3], int c, int r)
{
	int i, j;
	char p = b[c][r];

	//가로 세로
	for (i = 0; i < 3; i++){
		if (b[i][0] == p)
			if (b[i][0] == b[i][1] && b[i][0] == b[i][2])
				return 1;
		if (b[0][i] == p)
			if (b[0][i] == b[1][i] && b[0][i] == b[2][i])
				return 1;
	}
	//대각선
	if (b[1][1] == p){
		if (b[0][0] == p && b[2][2] == p)
			return 1;
		if (b[2][0] == p && b[0][2] == p)
			return 1;
	}
	return 0;
}
void display(char b[][3])
{
	int i, j;

	printf("   ");
	for (i = 0; i < 3; i++)
		printf("%2d", i);

	printf("\n   -------\n");

	for (i = 0; i < 3; i++){
		printf("%d |", i);

		for (j = 0; j < 3; j++){
			if (b[i][j] == 'X' || b[i][j] == 'O')
				printf("%2c", b[i][j]);
			else
				printf("  ");
		}
		printf("\n");
	}
}
char who(int n)
{
	if (n % 2 == 0)
		return  'X';
	return 'O';
}
int main(void)
{
	int r, c, turn;
	char player, ttt[3][3];

	turn = 0;
	while(turn < 9) {
		display(ttt);
		player = who(turn);

		do {
			printf("Player %c<행, 열>", player);
			scanf("%d %d", &c, &r);
		}while (ttt[c][r] == player);

		ttt[c][r] = player;
		turn++;

		if (win(ttt, c, r) == 1)
			break;
	}

	display(ttt);
	if (turn == 9)
		printf("Nobody wins!\n");
	else 
		printf("Player %c wins!\n", player);
}*/
//better
//컴퓨터학과 20190975 신효경
//tic-tac-toe
#include <stdio.h>
int win(char b[][3], int c, int r)
{
	int i, j;
	char p = b[c][r];

	//가로 세로
	for (i = 0; i < 3; i++){
		if (b[i][0] == p)
			if (b[i][0] == b[i][1] && b[i][0] == b[i][2])
				return 1;
		if (b[0][i] == p)
			if (b[0][i] == b[1][i] && b[0][i] == b[2][i])
				return 1;
	}
	//대각선
	if (b[1][1] == p){
		if (b[0][0] == p && b[2][2] == p)
			return 1;
		if (b[2][0] == p && b[0][2] == p)
			return 1;
	}
	return 0;
}
void display(char b[][3])
{
	int i, j;

	printf("    0 1 2\n");
	printf("   ------\n");
	for (i = 0; i < 3; i++){
		printf("%d |", i);
		for (j = 0; j < 3; j++){
			if (b[i][j] != ' ')
				printf(" %c", b[i][j]);	
			else
				printf("  ");
		}
		printf("\n");
	}
}
int main(void)
{
	int r, c, count;
	int i, j;
	char player = 'X';
	char ttt[3][3];

	//빈칸으로 초기화
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			ttt[i][j] = ' ';

	count = 1;
	display(ttt);
	do {
		printf("Player %c<행, 열>", player);
		scanf("%d %d", &c, &r);

		if (ttt[c][r] != ' ') //비어있지 않은 곳에 두면 안됨
			continue;

		ttt[c][r] = player;
		count++;
		display(ttt);

		if (win(ttt, c, r) == 1)
			break;
		player = (player == 'X'? 'O':'X');
	}while(count <= 9);

	display(ttt);
	if (count == 10 && win(ttt, c, r) != 1) //&&이후것 없으면 다채우고 이겼을 때 nobody wins로 뜸
		printf("Nobody wins!\n");
	else 
		printf("Player %c wins!\n", player);
}
