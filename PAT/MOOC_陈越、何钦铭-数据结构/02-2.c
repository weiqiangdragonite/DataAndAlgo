/*

中国大学MOOC-陈越、何钦铭-数据结构基础习题集


02-线性结构1. Reversing Linked List (25)


Given a constant K and a singly linked list L, you are supposed to reverse the
links of every K elements on L. For example, given L being 1→2→3→4→5→6, 
if K = 3, then you must output 3→2→1→6→5→4; if K = 4, you must 
output 4→3→2→1→5→6.


Input Specification:

Each input file contains one test case. For each case, the first line contains 
the address of the first node, a positive N (<= 10^5) which is the total number 
of nodes, and a positive K (<=N) which is the length of the sublist to be 
reversed. The address of a node is a 5-digit nonnegative integer, and NULL 
is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next

where Address is the position of the node, Data is an integer, and Next is the 
position of the next node.

Output Specification:

For each case, output the resulting ordered linked list. Each node occupies a 
line, and is printed in the same format as in the input.

Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218


Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1


--------------------------------------------------------------------------------

用双向链表貌似好一点
构造链表效率太低了

00100 1 12309
12309 2 33218
33218 3 00000
00000 4 99999
99999 5 68237
68237 6 -1


计数1、2、3、4找到地址为00000的结点，然后从头找下一地址为00000的结点，
即地址为33218的结点，然后从头找下一地址为33218的结点，
这样找完4个后，从00000结点下一地址即99999开始循环

00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999

99999 5 68237
68237 6 -1


--------------

http://www.cnblogs.com/kevin-lwb/p/4283456.html
用这种思路，用数组来存，再连成链表

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SIZE	100000


struct node {
	int data;
	int addr;
	int naddr;
};


int
main(int argc, char *argv[])
{
	struct node tmp[MAX_SIZE];
	struct node array[MAX_SIZE];
	int n, k;	/* n:结点数, k:子链表长度 */
	int a, b;	/* a:首地址, b:结点地址 */
	int i, j, counter;


	scanf("%d %d %d", &a, &n, &k);


	/* 初始化 */
	for (i = 0; i < n; ++i) {
		scanf("%d", &b);
		tmp[b].addr = b;
		scanf("%d %d", &tmp[b].data, &tmp[b].naddr);
	}


	/* 整理，把结点按地址顺序存到数组中，效率 O(n) */
	/* 有一个测试点，就是结点数可能多于链表的结点数，即给出的结点数有可能
	并不属于链表上的 */
	array[0].addr = a;
	array[0].data = tmp[a].data;
	array[0].naddr = tmp[a].naddr;
	counter = 1;
	for (i = 1; i < n; ++i) {
		b = array[i - 1].naddr;
		if (b == -1)
			break;
		array[i].addr = tmp[b].addr;
		array[i].data = tmp[b].data;
		array[i].naddr = tmp[b].naddr;
		++counter;
	}

	memset(tmp, 0, sizeof(tmp));

	/* 倒序，效率 O(n) */
	i = 0;
	b = -1;
	while (1) {
		if (b + k >= counter)
			break;
		b = b + k;
		for (j = 0; j < k; ++j, ++i, --b) {
			tmp[i].addr = array[b].addr;
			tmp[i].data = array[b].data;
		}
		b = b + k;
	}
	/* 把剩下不足k的元素存到数组上 */
	for (b = b + 1; b < counter; ++b, ++i) {
		tmp[i].addr = array[b].addr;
		tmp[i].data = array[b].data;
	}
	/* 把结点指向下一个的地址值填好，效率 O(n) */
	for (i = 0; i < counter - 1; ++i)
		tmp[i].naddr = tmp[i+1].addr;
	tmp[i].naddr = -1;


	/* 输出 */
/*
	i = 0;
	while (1) {
		printf("%05d %d ", array[i].addr, array[i].data);
		if (array[i].naddr == -1) {
			printf("-1\n");
			break;
		} else {
			printf("%05d\n", array[i].naddr);
		}
		++i;
	}
*/

	i = 0;
	while (1) {
		printf("%05d %d ", tmp[i].addr, tmp[i].data);
		if (tmp[i].naddr == -1) {
			printf("-1\n");
			break;
		} else {
			printf("%05d\n", tmp[i].naddr);
		}
		++i;
	}


	return 0;
}








/*******************************************************************************
* 下面是旧的，过不了最后两个测试点（超时和段错误）
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ADDR_LEN	(5+1)

struct node {
	int data;
	char addr[ADDR_LEN];
	char naddr[ADDR_LEN];
	struct node *next;
};

typedef struct node list_t;


/*
 * 头插法初始化链表
 * 效率: O(1)
 */
int
init(list_t **list, const char addr[], const char naddr[], const int data)
{
	list_t *ptr = NULL;

	ptr = (list_t *) malloc(sizeof(list_t));
	if (ptr == NULL)
		return -1;

	snprintf(ptr->addr, ADDR_LEN, "%s", addr);
	snprintf(ptr->naddr, ADDR_LEN, "%s", naddr);
	ptr->data = data;

	if (*list == NULL)
		ptr->next = NULL;
	else
		ptr->next = *list;
	*list = ptr;

	return 0;
}

/*
 * 按格式输出链表
 */
void
print(list_t *list)
{
	list_t *i;

	i = list;
	while (i) {
		printf("%s %d %s\n", i->addr, i->data, i->naddr);
		i = i->next;
	}
}

/*
 * 找出对应的结点，并返回结点的地址
 * s: 要对比的内容
 * flag: 0是对比addr，1是对比naddr
 * del: 1是找到该结点后，把该结点从链表中移除
 *
 * 效率: O(n)
 */
void *
find(list_t **list, const char s[], const int flag, const int del)
{
	list_t *ptr, *oldptr;
	int isfind = 0;

	ptr = oldptr = *list;
	while (ptr) {
		if (flag == 0 && strcmp(s, ptr->addr) == 0)
			isfind = 1;
		else if (flag == 1 && strcmp(s, ptr->naddr) == 0)
			isfind = 1;

		if (isfind) {
			if (del && oldptr != ptr)
				oldptr->next = ptr->next;
			else if (del && oldptr == ptr)
				*list = oldptr->next;
				
			return (void *) ptr;
		}

		oldptr = ptr;
		ptr = ptr->next;
	}

	return (void *) NULL;
}

/*
 * 按顺序整理链表 - s 为链表的首结点地址，n 为结点数量
 * 先生成一个能存储地址的一维数组，然后把链表按顺序找出每个结点的地址，
 * 存到数组去，然后再把数组里的结点连接起来
 */
void
order(list_t **list, const int n, const char s[])
{
	long *addr = NULL;
	list_t *ptr = NULL;
	int i;

	addr = (void *) calloc(n, sizeof(void *));

	/* store into array by order */
	/* 这里每找到一个结点，就会把该结点从链表中移除，所以这里
	的效率应为 n*(n-1)*(n-2)...*2*1，即n! (卧槽) */
	addr[0] = (long) find(&(*list), s, 0, 1);
	ptr = (list_t *) addr[0];
	/* while (ptr->naddr != "-1") */
	for (i = 1; i < n; ++i) {
		addr[i] = (long) find(&(*list), ptr->naddr, 0, 1);
		ptr = (list_t *) addr[i];
	}


	/* 可以先不连成链表 */

	/* link to list */
	for (i = 0; i < n - 1; ++i) {
		ptr = (list_t *) addr[i];
		ptr->next = (list_t *) addr[i + 1];
	}
	/* the last item */
	ptr = (list_t *) addr[i];
	ptr->next = NULL;
	/* head */
	*list = (list_t *) addr[0];
}

/*
 * 按要求倒序链表
 * n: 结点个数
 * k: 倒序子链表的个数
 */
void
reverse(list_t **list, const int n, const int k)
{
	void *addr[n];
	list_t *ptr, *newptr;
	int i, j, flag;

	memset(addr, 0, sizeof(addr));

	ptr = newptr = *list;
	j = 0;
	while (newptr != NULL) {
		flag = 0;
		ptr = newptr;

		/* 找出第k个结点 */
		for (i = 1; i < k;) {
			++i;
			if (ptr->next == NULL && i != k) {
				flag = 1;
				break;
			}
			ptr = ptr->next;
		}
		
		if (flag)
			break;
		newptr = ptr->next;

		/* 逆序存到数组 */
		addr[j++] = ptr;
		for (i = 1; i < k; ++i, ++j) {
			addr[j] = find(&(*list), ptr->addr, 1, 0);
			ptr = (list_t *) addr[j];
		}
	}

	/* 剩下不够n个的结点 */
	ptr = newptr;
	while (ptr) {
		addr[j++] = (void *) ptr;
		ptr = ptr->next;
	}

	/* 把数组里的连接起来 */
	for (i = 0; i < n - 1; ++i) {
		ptr = (list_t *) addr[i];
		ptr->next = (list_t *) addr[i + 1];
		snprintf(ptr->naddr, ADDR_LEN, "%s", ptr->next->addr);
	}

	/* the last item */
	ptr = (list_t *) addr[i];
	ptr->next = NULL;
	snprintf(ptr->naddr, ADDR_LEN, "-1");
	/* head */
	*list = (list_t *) addr[0];
}





int
main(int argc, char *argv[])
{
	char s[6], s1[6], s2[6];
	int n, k, d, i;
	list_t *list;	/* 头指针，不带头结点 */

	memset(s, 0, sizeof(s));
	memset(s1, 0, sizeof(s));
	memset(s2, 0, sizeof(s));

	scanf("%s %d %d", s, &n, &k);
	s[5] = '\0';

	//printf("s = %s, n = %d, k = %d\n", s1, n, k);

	list = NULL;
	/* 初始化链表 */
	for (i = 0; i < n; ++i) {
		scanf("%s %d %s", s1, &d, s2);
		s1[5] = s2[5] = '\0';
		init(&list, s1, s2, d);
	}

	/* 整理 */
	order(&list, n, s);

	/* 倒序 */
	reverse(&list, n, k);

	/* 输出 */
	print(list);

	return 0;
}











