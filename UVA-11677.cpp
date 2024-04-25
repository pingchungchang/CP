#include <stdio.h>
using namespace std;

int main(){
    int h1,h2,m1,m2;
    while(scanf("%d %d %d %d",&h1,&m1,&h2,&m2)!=EOF){
        if(h1==h2&&h2==m1&&m1==m2&&m2==0)return 0;
        m1 +=h1*60;
        m2+=h2*60;
        if(m1>m2)m2+=1440;
        printf("%d\n",m2-m1);
        scanf("\n");
    }
}