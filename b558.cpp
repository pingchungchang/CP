#include <stdio.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",1+(n-1)*n/2);
        scanf("\n");
    }
}