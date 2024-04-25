#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        if(n == 0) return 0;
        pair<int,double> biggest = make_pair(0,0);
        for(int i = 1;i<=n;i++){
            double a,b;
            cin>>a>>b;
            double x = max(min(a,b/4),min(a/4,b));
            x = max(x,min(a/2,b/2));
            if(x>biggest.second){
                biggest.first = i;
                biggest.second = x;
            }
        }
        printf("%d\n",biggest.first);
    }

}