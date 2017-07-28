/*
* 20170727
*/

#include <cstdio>

int main()
{
    char c;
    bool a = true;
    while((c = getchar()) != EOF)
    {
        if(c == '"'){printf("%s",a?"``":"''");a =! a;}
        else printf("%c",c);
    }
    return 0;
}