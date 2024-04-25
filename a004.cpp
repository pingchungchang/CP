#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        if(n%4!=0) printf("平年");
        else if(n%400!=0&&n%100==0)printf("平年");
        else printf("閏年");
        printf("\n");
    }
}