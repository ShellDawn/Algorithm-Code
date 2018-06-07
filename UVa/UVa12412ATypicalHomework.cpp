/*
* 20171104
*/

#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 10000
#define eps 0.00001

const char fname[][20] = {"Chinese","Mathematics","English","Programming"};

struct Node{
	int id;
	char num[100];
	int cnum;
	char name[100];
	int g[10];
}p[maxn];
int cnt = 0;

void print_All()
{
	printf("Welcome to Student Performance Management System (SPMS).\n");
	printf("\n");
	printf("1 - Add\n");
	printf("2 - Remove\n");
	printf("3 - Query\n");
	printf("4 - Show ranking\n");
	printf("5 - Show Statistics\n");
	printf("0 - Exit\n");
	printf("\n");
}

bool Add()
{
	printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
	scanf("%s",p[cnt].num);
	if(strcmp(p[cnt].num,"0")==0) return false;
	scanf("%d %s %d %d %d %d",&p[cnt].cnum,p[cnt].name,&p[cnt].g[0],&p[cnt].g[1],&p[cnt].g[2],&p[cnt].g[3]);
	for(int i=0;i<cnt;i++) if(strcmp(p[cnt].num,p[i].num)==0){printf("Duplicated SID.\n");return true;}
	p[cnt].id = cnt+1;
	cnt++;
	return true;
}

bool Remove()
{
	printf("Please enter SID or name. Enter 0 to finish.\n");
	char numt[100];
	scanf("%s",numt);
	int ans = 0;
	if(strcmp(numt,"0")==0) return false;
	for(int i=0;i<cnt;i++) 
		if(strcmp(p[i].num,numt)==0||strcmp(p[i].name,numt)==0) 
		{
			p[i].id = 0;
			memset(p[i].num,0,sizeof(p[i].num));
			memset(p[i].name,0,sizeof(p[i].name));
			ans++;
		}
	printf("%d student(s) removed.\n",ans);
	return true;
}

int rank(int k)
{
	int key = 0;
	for(int j=0;j<4;j++) key+=p[k].g[j];
	int ans = 0;
	for(int i=0;i<cnt;i++)
	{
		if(p[i].id!=0)
		{
			int res = 0;
			for(int j=0;j<4;j++)
			{
				res+=p[i].g[j];
			}
			if(res>key) ans++;
		}
	}
	return ans+1;
}

bool Query()
{
	printf("Please enter SID or name. Enter 0 to finish.\n");
	char numt[100];
	scanf("%s",numt);
	if(strcmp(numt,"0")==0) return false;
	for(int i=0;i<cnt;i++) 
		if(strcmp(p[i].num,numt)==0||strcmp(p[i].name,numt)==0) 
			printf("%d %s %d %s %d %d %d %d %d %.2f\n",rank(i),p[i].num,p[i].cnum,p[i].name,p[i].g[0],p[i].g[1],p[i].g[2],p[i].g[3],p[i].g[0]+p[i].g[1]+p[i].g[2]+p[i].g[3],(p[i].g[0]+p[i].g[1]+p[i].g[2]+p[i].g[3])/4.0+eps);
	return true;
}

void ShowRanking()
{
	printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
}

void ShowStatistics()
{
	printf("Please enter class ID, 0 for the whole statistics.\n");
	int cnumt = 0;
	scanf("%d",&cnumt);
	for(int i=0;i<4;i++)
	{
		printf("%s\n",fname[i]);
		double ans = 0;
		int ansnum = 0;
		int passnum = 0;
		for(int j=0;j<cnt;j++) 
			if(p[j].id!=0&&(cnumt==0||cnumt==p[j].cnum)) 
			{	
				ans+=p[j].g[i]; 
				ansnum++;
				if(p[j].g[i]>=60) passnum++;
			}
		printf("Average Score: %.2f\n",ans/ansnum+eps);
		printf("Number of passed students: %d\n",passnum);
		printf("Number of failed students: %d\n",ansnum-passnum);
		printf("\n");
	}
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for(int i=0;i<cnt;i++)
	{
		if(p[i].id!=0&&(cnumt==0||cnumt==p[i].cnum))
		{
			int temp = 0;
			for(int j=0;j<4;j++)
			{
				if(p[i].g[j]>=60)
					temp++;
			}
			if(temp>=4) a++;
			else if(temp>=3) b++;
			else if(temp>=2) c++;
			else if(temp>=1) d++;
			else e++;
		}
	}
	printf("Overall:\n");
	printf("Number of students who passed all subjects: %d\n",a);
	printf("Number of students who passed 3 or more subjects: %d\n",a+b);
	printf("Number of students who passed 2 or more subjects: %d\n",a+b+c);
	printf("Number of students who passed 1 or more subjects: %d\n",a+b+c+d);
	printf("Number of students who failed all subjects: %d\n",e);
	printf("\n");
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("ans.txt","w",stdout);
	int a;
	print_All();
	while(scanf("%d",&a)!=EOF&&a)
	{
		if(a==1) while(Add());
		if(a==2) while(Remove());
		if(a==3) while(Query());
		if(a==4) ShowRanking();
		if(a==5) ShowStatistics();
		print_All();
	}
	return 0;
}


