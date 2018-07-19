#define Time
#define FILE

#include <ctime>

using namespace std;


int main(){
#ifdef Time
    double timeS = (double)clock();
#endif

#ifdef FILE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif






#ifdef Time
    printf("\e[01;34m Program use Time: \e[01;31m%.4f ms\e[0m\n",(double)clock()-timeS);
#endif
    return 0;
}