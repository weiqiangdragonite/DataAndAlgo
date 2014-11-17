/*
 * http://blog.csdn.net/yzl_rex/article/details/7764678
 *
 * C语言如果想做一个通用的类型比较困难，C++的话起码可以用模板
 */


#ifndef SEQ_LIST_H
#define SEQ_LIST_H


#define LISTSIZE 1024

/**/
typedef int ElemType;


/*
 *
 */
struct seq_list {
	ElemType data[LISTSIZE];	/* number of elements can store */
	unsigned int length;		/* current length of list */
};

typedef struct seq_list seq_list_t;


void init_seq_list(seq_list_t *list);
int seq_list_length(seq_list_t *list);
void free_seq_list(seq_list_t *list);
int get_seq_list(seq_list_t *list, unsigned int pos, ElemType *item);
int insert_seq_list(seq_list_t *list, unsigned int pos, ElemType item);
int delete_seq_list(seq_list_t *list, unsigned int pos, ElemType *item);
int find_seq_list(seq_list_t *list, ElemType item);

#endif	/* SEQ_LIST_H */

