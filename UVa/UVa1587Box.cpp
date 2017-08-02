/*
* 20170802
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Pallet
{
public:
	int l;
	int w;
public:
	void init(int a,int b){l=max(a,b);w=min(a,b);}
	bool operator == (const Pallet& t){if(t.l==l&&t.w==w) return true;return false;}
};

Pallet p[6];

int cmp(const void*a,const void*b)
{
	Pallet* x = (Pallet*)a;
	Pallet* y = (Pallet*)b;
	if(x->l==y->l) return y->w-x->w;
	else return y->l-x->l;
}

bool solve()
{
	qsort(p,6,sizeof(p[0]),cmp);
	for(int i=0;i<5;i+=2) if(!(p[i]==p[i+1])) return false;
	if(p[0].l==p[2].l&&p[0].w==p[4].l&&p[2].w==p[4].w) return true;
	if(p[0].l==p[2].l&&p[0].w==p[4].w&&p[2].w==p[4].l) return true;
	return false;
}

int main()
{
	int a,b;
	int cnt = 0;
	while(scanf("%d%d",&a,&b)==2)
	{
		p[cnt++].init(a,b);
		if(cnt==6){cnt=0;printf("%s\n",solve()?"POSSIBLE":"IMPOSSIBLE");}
	}
}