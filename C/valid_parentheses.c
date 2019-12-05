typedef struct SeqStack
{
    int top;
    char str[10000];
}Stack;

int isMatch(char a, char b)
{
    if(a == '(' && b == ')')
        return 1;
    else if(a == '[' && b == ']')
        return 1;
    else if(a == '{' && b == '}')
        return 1;
    else 
        return 0;
}

bool isValid(char * s){    
    int len = strlen(s);
    if(!len)
        return true;
    
    Stack *stk = (Stack *)malloc(sizeof(Stack));
    stk->top = 0;
    stk->str[(stk->top)++] = s[0];
    
    for(int i = 1; i < len; i++)
    {
        if(isMatch(stk->str[(stk->top)-1], s[i]))
            stk->str[--(stk->top)] = 0;
        else
            stk->str[(stk->top)++] = s[i];
    }
    if(stk->top) return false;
    else return true;
}
