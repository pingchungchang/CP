#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        string ans = "";
        while(n>0){
            if(n&1){
                ans = '1'+ans;
            }
            else ans = '0'+ans;
            n = n>>1;
        }
        cout<<ans<<"\n";
        scanf("\n");
    }
}