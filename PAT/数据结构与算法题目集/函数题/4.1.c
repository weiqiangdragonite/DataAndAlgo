/*

4-1 单链表逆转   (20分)
本题要求实现一个函数，将给定的单链表逆转。


输入样例：
5
1 3 4 5 2

输出样例：
1
2 5 4 3 1

*/


#include <stdio.h>
#include <stdlib.h>


typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;   /* 存储结点数据 */
    PtrToNode   Next;   /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */
/* L是给定单链表，函数Reverse要返回被逆转后的链表。 */
List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */


