/*
* 20170727
*/

#include <cstdio>

const char* str = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main()
{
	char c;
	while((c = getchar())!=EOF)
	{
		int i;
		for(i=0;str[i]&&str[i]!=c;i++);
		//str最后一位是ASCII码0
		if(str[i]) printf("%c",str[i-1]);
		//空格
		else printf("%c",c);
	}
	return 0;
}