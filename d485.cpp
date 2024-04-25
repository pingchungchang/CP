#include <stdio.h>
using namespace std;

int main(){
    int a,b;
    scanf("%d%d",&b,&a);
    printf("%d",(a-a%2-(b+b%2))/2+1);
}