/*

4-1 ��������ת   (20��)
����Ҫ��ʵ��һ���������������ĵ�������ת��


����������
5
1 3 4 5 2

���������
1
2 5 4 3 1

*/


#include <stdio.h>
#include <stdlib.h>


typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;   /* �洢������� */
    PtrToNode   Next;   /* ָ����һ������ָ�� */
};
typedef PtrToNode List; /* ���嵥�������� */

List Read(); /* ϸ���ڴ˲��� */
void Print( List L ); /* ϸ���ڴ˲��� */
/* L�Ǹ�������������ReverseҪ���ر���ת������� */
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

/* ��Ĵ��뽫��Ƕ������ */


