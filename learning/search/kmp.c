/*
 * 字符串匹配KMP算法
 * 阮一峰 http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/*
 * return target index, -1 is not found
 *
 *
 */
int str_find(const char *str, const char *target)
{
	int i, j;
	int index = -1;
	for (i = 0, j = 0; str[i] && target[j]; ++i) {
		if (str[i] == target[j]) {
			if (index == -1)
				index = i;
			++j;
			continue;
		}
		/* if not the same, re-search from start */
		/* 将搜索词整个后移一位，再从头逐个比较 */
		if (index != -1) {
			index = -1;
			j = 0;
		}
	}
	/* don't forget it */
	if (str[i] == '\0' && target[j] != '\0')
		index = -1;
	return index;
}


/******************************************************************************/


/*
 * 找出前缀和后缀集合间最长共有元素的长度
 * prefix集合 和 suffix集合的长度相等，都有count个元素，
 */
int get_match_len(char *prefix, char *suffix, int count, int len)
{
	int i, j, max_len, nums;
	char *pre, *suf;

	max_len = 0;
	for (i = 1; i <= count; ++i) {
		pre = prefix + i*len;
		for (j = 1; j <= count; ++j) {
			suf = suffix + j*len;
			if (strcmp(pre, suf) == 0) {
				nums = strlen(pre);
				max_len = nums > max_len ? nums : max_len;
			}
		}
	}
	return max_len;
}

/*
 * "部分匹配值"就是"前缀"和"后缀"的最长的共有元素的长度
 * "前缀"和"后缀"。 "前缀"指除了最后一个字符以外，一个字符串的全部头部组合；
 * "后缀"指除了第一个字符以外，一个字符串的全部尾部组合。
 */
int *create_partical_match_tb(const char *str)
{
	int len = strlen(str);
	int *match_tb = (int *) malloc(sizeof(int) * len);
	if (match_tb == NULL) {
		perror("malloc()");
		return NULL;
	}

	char *prefix = (char *) calloc(len * len, sizeof(char));
	char *suffix = (char *) calloc(len * len, sizeof(char));
	if (prefix == NULL || suffix == NULL) {
		perror("malloc()");
		return NULL;
	}

	int index, i, j, match_len;
	match_tb[0] = 0;
	for (i = 1; i < len; ++i) {
		/* create prefix and suffix */
		strncpy(prefix+(i*len), str, i);
		*(prefix+(i*len+i)) = '\0';
		//printf("prefix: %s\n", prefix+i*len);
		index = i;
		/* suffix need to re-create everytime */
		for (j = 1; j <= i; --index, ++j) {
			strncpy(suffix+(j*len), str+index, j);
			*(suffix+(j*len+j)) = '\0';
			//printf("suffix: %s\n", suffix+j*len);
		}

		match_len = get_match_len(prefix, suffix, i, len);
		match_tb[i] = match_len;
	}

	return match_tb;
}

/*
 *
 */
void delete_partical_match_tb(int *match_tb)
{
	if (match_tb != NULL)
		free(match_tb);
	match_tb = NULL;
}


/*
 *
 */
int kmp_search(const char *str, const char *target)
{
	int i, j;
	int index = -1;
	int *match_tb = NULL;
	int match_num, move_num;

	match_tb = create_partical_match_tb(target);
	if (match_tb == NULL) {
		fprintf(stderr, "create_partical_match_tb() failed\n");
		exit(EXIT_FAILURE);
	}

	/* -- for debug -- 
	printf("\nmatch_tb = [ ");
	for (i = 0; i < strlen(target); ++i)
		printf("%d ", match_tb[i]);
	printf("]\n");
	/* -- end -- */

	for (i = 0, j = 0; str[i] && target[j]; ++i) {
		if (str[i] == target[j]) {
			if (index == -1)
				index = i;
			++j;
			continue;
		}
		/* if not the same,  */
		/* 根据 部分匹配表 算出搜索词移动的位数 */
		if (index != -1) {
			/* 移动位数 = 已匹配的字符数 - 对应的部分匹配值 */
			move_num = j - match_tb[j-1];
			j = j - move_num;
			index = index + move_num;
			if (j == 0)
				index = -1;
		}
	}
	/* don't forget it */
	if (str[i] == '\0' && target[j] != '\0')
		index = -1;
	delete_partical_match_tb(match_tb);
	return index;
}




int main(int argc, char *argv[])
{
	char *s1 = "--Hello wor-hello-world--";
	char *target = "world";
	printf("index = %d\n", str_find(s1, target));
	printf("index = %d\n", kmp_search(s1, target));

	char *s2 = "--Hello wor-hello-wor";
	printf("index = %d\n", str_find(s2, target));

	char *s3 = "BBC ABCDAB ABCDABCDABDE";
	char *want = "ABCDABD";
	printf("index = %d\n", kmp_search(s3, want));

	return 0;
}
