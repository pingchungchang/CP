#include <cstdio>
using namespace std;

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    while(a%4!=0)a++;
    while(b%4!=0)b--;
    int ans = (b-a)/4+1;
    while(a%100!=0)a++;
    while(b%100!=0)b--;
    ans-=(b-a)/100+1;
    while(a%400)a++;
    while(b%400)b--;
    ans+=(b-a)/400;
    printf("%d",ans+1);
}