/*


中国大学MOOC-翁恺-C语言程序设计习题集


10-2. 删除字符串中的子串(20)


输入2个字符串S1和S2，要求删除字符串S1中出现的所有子串S2，即结果字符串中不能包含S2。

输入格式：

输入在2行中分别给出不超过80个字符长度的、以回车结束的2个非空字符串，对应S1和S2。

输出格式：

在一行中输出删除字符串S1中出现的所有子串S2后的结果字符串。

输入样例：
Tomcat is a male ccatat
cat
输出样例：
Tom is a male 

*/

/*
#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[])
{
	char s1[256], s2[256];
	int s1_len, s2_len;
	int is_match, i, j;

	fgets(s1, sizeof(s1), stdin);
	fgets(s2, sizeof(s2), stdin);

	// remove the '\n'
	//s1[strlen(s1) - 1] = '\0';
	//s2[strlen(s2) - 1] = '\0';

	s1_len = strlen(s1) - 1;
	s2_len = strlen(s2) - 1;


	is_match = 0;
	for (i = 0, j = 0; i < s1_len; ++i) {
		j = 0;
		if (s1[i] != s2[j])
			continue;

		// check
		for (j = 1; j < s2_len; ++j) {
			if (s1[i+j] != s2[j])
				break;

			if (j + 1 == s2_len)
				is_match = 1;
		}

		if (!is_match)
			continue;

		// delete
		// [i] = [i + strelen(s2)]
		j = i;
		while (1) {
			s1[j] = s1[j + s2_len];

			if (s1[j] == '\0')
				break;

			++j;
		}
		s1_len = strlen(s1) - 1;
		// start check again from the beginning
		i = -1;
		is_match = 0;
	}

	printf("%s", s1);

	return 0;
}

*/


#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[])
{
	char s1[256], s2[256];
	int s2_len;
	int i;
	char *ptr;

	fgets(s1, sizeof(s1), stdin);
	fgets(s2, sizeof(s2), stdin);

	// because have '\n'
	s1[strlen(s1) - 1] = '\0';
	s2[strlen(s2) - 1] = '\0';

	//s1_len = strlen(s1);
	s2_len = strlen(s2);

	ptr = strstr(s1, s2);

	while (ptr) {
		// remove
		i = ptr - s1;
		while (1) {
			s1[i] = s1[i + s2_len];
			if (s1[i] == '\0')
				break;
			++i;
		}

		ptr = strstr(s1, s2);
	}

	printf("%s\n", s1);

	return 0;
}



/*
#include <stdio.h>
#include <string.h>
#define N 80

void del_str(char *str, char *s, char *resultstr)   //删除函数 
{
    int i, j, resultstr_len, s_len;                 //resultstr_len为resultstr字符串的长度，s_str为s字符串的长度 
    s_len = strlen(s);
    strcpy(resultstr, str);                         //将str拷贝到resultstr 
    char *p;                                         
    p = strstr(resultstr, s);                       //p指向s在resultstr中出项的首字符 
    resultstr_len = strlen(resultstr);

	for (i = 0; i < resultstr_len; ++i)
		printf("%02x ", resultstr[i]);

    while(p != NULL) {                       
        printf("p = %d\n", p - resultstr);      
        for(i = p - resultstr; i < resultstr_len - s_len + 1; i++) {   
            resultstr[i] = resultstr[i + s_len];
        } 
        resultstr_len = strlen(resultstr);
        p = strstr(resultstr, s);
    }
}

int main()
{
    char str[N+1], s[N+1], resultstr[N+1];     //str为第一个字符串，s为第二个字符串，resultstr为删除后的字符串 
    gets(str);
    gets(s);

	int i;
	for (i = 0; i < strlen(str); ++i)
		printf("%02x ", str[i]);

    del_str(str, s, resultstr);                //删除函数 
    printf("%s\n", resultstr);
    
    return 0;
}
*/




