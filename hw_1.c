//Ŀ�¤����а� 20190975 ��ȿ��
//tic-tac-toe
#include <stdio.h>
int win(char b[][3], int c, int r)
{
	int i, j;
	char p = b[c][r];

	//���� ����
	for (i = 0; i < 3; i++){
		if (b[i][0] == p)
			if (b[i][0] == b[i][1] && b[i][0] == b[i][2])
				return 1;
		if (b[0][i] == p)
			if (b[0][i] == b[1][i] && b[0][i] == b[2][i])
				return 1;
	}
	//�밢��
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
			printf("Player %c<��, ��>", player);
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
}