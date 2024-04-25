#include <stdio.h>
#include <unordered_map>

using namespace std;

int main(){
    // int n;
    // scanf("%d",&n);
    int n=1000000;
    unordered_map<int,int> m;
    for(int i=1;i<=n;i++){
        int now = i;
        if(m.count(i) == 0)printf("%d\n",i);
        int k = now;
        while(now!=0){
            k +=now%10;
            now /=10;
        }
        m[k] = 1;
    }
}