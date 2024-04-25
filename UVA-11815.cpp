#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!= EOF){
        if(n<0)return 0;
        string ans;
        while(n>0){
            ans = (char)('0'+n%3)+ans;
            n /=3;
        }
        if(ans.size()==0)ans = "0";
        cout<<ans<<'\n';
    }
}