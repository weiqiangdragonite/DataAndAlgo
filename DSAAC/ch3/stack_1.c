/*
 * 第三章、3.3.3
 * 平衡符号，对圆括号、方括号、花括号惊醒检验
 */


int
check(const char *str)
{
	char *c = str;
	char ch;
	stack_t *s;

	while (c && *c != '\0') {
		if (*c == '(' || *c == '[' || *c == '{')
			push(s, *c);

		else if (*c == ')' || *c == ']' || *c == '}') {
			if (isempty(s))
				return error;

			ch = pop(s);

			if (*c == ')' && ch != '(')
				return error;
			else if (*c == ']' && ch != '[')
				return error;
			else if (*c == '}' && ch != '{')
				return error;
		}

		*c++;
	}
	if (isempty(s))
		return error;

}


