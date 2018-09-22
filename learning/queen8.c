/*
 * Quene8 - 八皇后问题
 * 国际象棋中的皇后，可以横向、纵向、斜向移动。如何在一个8*8的棋盘上
 * 放置8个皇后，使得任意两个皇后都不在同一条横线、竖线、斜线方向上。
 *
 * 递归回溯:
 * 所谓递归回溯，本质上是一种枚举法。这种方法从棋盘的第一行开始尝试
 * 摆放第一个皇后，摆放成功后，递归一层，再遵循规则在棋盘第二行来
 * 摆放第二个皇后。如果当前位置无法摆放，则向右移动一格再次尝试，
 * 如果摆放成功，则继续递归一层，摆放第三个皇后...
 * 如果某一层看遍了所有格子，都无法成功摆放，则回溯到上一个皇后，让
 * 上一个皇后右移一格，再进行递归。如果八个皇后都摆放完毕切符合规则，
 * 那么就得到了其中一种正确的解法。
 */

#include <stdio.h>
#include <string.h>

#define HAVE_CHESS	1
#define NO_CHESS	0
#define BOARD_SIZE	8
unsigned char BOARD[BOARD_SIZE][BOARD_SIZE];
unsigned char ATTACK_AREA[BOARD_SIZE+1][BOARD_SIZE+1];
unsigned char CHESS[BOARD_SIZE+1];


/*
 * 将棋盘的第i行第j列的值设为k。
 * i的取值范围: 1~8
 * j的取值范围: 1~8
 * k的取值: 0-不放棋, 1-放棋
 *
 * 成功返回0，失败返回-1
 */
int set_chess(int i, int j, int k)
{
	/* check value */
	if (!(i-1 >= 0 && i-1 <= BOARD_SIZE)) {
		fprintf(stderr, "Error: set_chess(): i[%d] "
			"over chess board size\n", i);
		return -1;
	}
	if (!(j-1 >= 0 && j-1 <= BOARD_SIZE)) {
		fprintf(stderr, "Error: set_chess(): j[%d] "
			"over chess board size\n", j);
		return -1;
	}
	if (k != 0 && k != 1) {
		fprintf(stderr, "Error: set_chess(): k[%d] "
			"value is not legal\n");
		return -1;
	}

	BOARD[i][j] = k;
	return 0;
}


/*
 * 设置攻击的区域
 * 
 */
void set_attack_area(int i, int j)
{
	int pos_i, pos_j;
	printf("CHESS[%d][%d] attack area:\n\t", i, j);

	/* - 横向 */
	for (pos_i = 1; pos_i <= BOARD_SIZE; ++pos_i) {
		ATTACK_AREA[i][pos_i] = 1;
		printf("[%d][%d]  ", i, pos_i);
	}
	printf("\n\t");
	/* | 纵向 */
	for (pos_j = 1; pos_j <= BOARD_SIZE; ++pos_j) {
		ATTACK_AREA[pos_j][j] = 1;
		printf("[%d][%d]  ", pos_j, j);
	}
	printf("\n\t");
	/* \ 斜向 */
	for (pos_i = i-1, pos_j = j-1; pos_i > 0 && pos_j > 0; 
		--pos_i, --pos_j)
	{
		ATTACK_AREA[pos_i][pos_j] = 1;
		printf("[%d][%d]  ", pos_i, pos_j);
	}
	for (pos_i = i+1, pos_j = j+1; pos_i <= BOARD_SIZE && 
		pos_j <= BOARD_SIZE; ++pos_i, ++pos_j)
	{
		ATTACK_AREA[pos_i][pos_j] = 1;
		printf("[%d][%d]  ", pos_i, pos_j);
	}
	printf("\n\t");
	/* / 斜向 */
	for (pos_i = i-1, pos_j = j+1; pos_i > 0 && pos_j <= BOARD_SIZE;
		--pos_i, ++pos_j)
	{
		ATTACK_AREA[pos_i][pos_j] = 1;
		printf("[%d][%d]  ", pos_i, pos_j);
	}
	for (pos_i = i+1, pos_j = j-1; pos_i <= BOARD_SIZE && pos_j > 0; 
		++pos_i, --pos_j)
	{
		ATTACK_AREA[pos_i][pos_j] = 1;
		printf("[%d][%d]  ", pos_i, pos_j);
	}
	printf("\n");
	ATTACK_AREA[i][j] = 1;
}

/*
 * 取消攻击的区域
 * 最简单暴力的方法就是从头根据放置的棋子重新设置攻击区域。
 */
void reset_attack_area(void)
{
	int i;

	memset(ATTACK_AREA, 0, sizeof(ATTACK_AREA));

	for (i = 1; i <= BOARD_SIZE; ++i) {
		if (CHESS[i] == 0)
			break;
		printf("reset attack area [%d][%d]\n", i, CHESS[i]);
		set_attack_area(i, CHESS[i]);
	}
}

/*
 * 检查该位置是否能放棋子
 */
int check_pos(int i, int j)
{
	if (!(i >= 1 && i <= BOARD_SIZE))
		return 0;
	if (!(j >= 1 && j <= BOARD_SIZE))
		return 0;
	if (ATTACK_AREA[i][j] == 0)
		return 1;
	else
		return 0;
}


/*
 * 
 */
int play_chess(int i, int j)
{
	/**/

	if (!check_pos(i, j)) {
		/* 先遍历某一行的所有列 */
		for (++j; j <= BOARD_SIZE; ++j) {
			if (check_pos(i, j))
				break;	
		}
		if (j > BOARD_SIZE) {
			/* 没有符合的列，要回溯 */	
			return 1;
		}
	}
	if (i <= BOARD_SIZE && j <= BOARD_SIZE) {
		/* 符合 */
		set_chess(i, j, HAVE_CHESS);
		ret = play_chess(i+1, 1); // 下一层
	}
	
}


void print_solution(void)
{
	int i;
	FILE *fp;
	static int count = 0;

	fp = fopen("./queen8_solve.txt", "a+");
	if (fp == NULL)
		return;

	fprintf(fp, "solution %d:\n", ++count);
	for (i = 1; i <= BOARD_SIZE; ++i)
		fprintf(fp, "\t[%d][%d]\n", i, CHESS[i]);
	fprintf(fp, "\n\n");
	fclose(fp);
	return;
}


/*
 * 简单暴力实现法
 */
void circle_play(void)
{
	int i, j;
	int flag;

	for (i = 1, j = 1; i <= BOARD_SIZE;) {
		flag = 0;
		for (; j <= BOARD_SIZE; ++j) {
			printf("start_i = %d, start_j = %d\n", i, j);
			if (check_pos(i, j)) {
				/* 符合规则，放棋 */
				printf("set chess [%d][%d]\n", i, j);
				flag = 1;
				CHESS[i] = j;
				set_attack_area(i, j);
				break;
			}
			/* 如果当前列不符合，则继续检查下一列 */
		}
		if (flag == 0) {
			/* 回溯，设置上一层棋子的位置 */
			--i; // 返回上一层
			if (i <= 0)
				break; // end
			j = CHESS[i] + 1; // 要向右移一格
			printf("return to level [%d], column [%d]\n", i, j);
			/* 要把上一层设置的棋子位置和攻击区域清除 */
			CHESS[i] = 0;
			reset_attack_area();
		} else {
			/* 下一层 */
			++i;

			/* 如果最后一层处理完，说明求出一个解了，
			 * 继续往下求，直到回溯时i为0 */
			if (i > BOARD_SIZE) {
				print_solution();
				--i;
				++j;
				/* 把位置和攻击区域清除 */
				CHESS[i] = 0;
				reset_attack_area();
			} else {
				/* 下一层从第一列开始 */
				j = 1;
			}
		}
	}
}




int main(int argc, char *argv[])
{



}
