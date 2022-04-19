#include <stdio.h>
#include <string.h>
#define false 0
#define true 1

int isValid(char *s)
{
    //求解字符串的长度
    int len = strlen(s);
    //建立一个顺序栈
    char *stack = (char *)malloc(sizeof(char) * len);
    int top = -1;
    int i = 0;
    for (i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') //将左括号入栈
        {
            stack[++top] = s[i];
        }
        else //当遇到右括号是，则开始从栈顶中取出一个元素，进行比对
        {
            if (top == -1) //当扫描到右括号，且栈为0,即字符串中全是右括号
                return false;
            char sp = stack[top--];
            if (s[i] == ')' && sp != '(') //字符进行对比，这里是比较不同的好
                return false;
            if (s[i] == '}' && sp != '{') //字符进行对比，这里是比较不同的好
                return false;
            if (s[i] == ']' && sp != '[') //字符进行对比，这里是比较不同的好
                return false;
        }
    }
    if (top != -1) //当扫描完后，发现栈中还有元素，则表明全为空
        return false;
    return true;
}