#include <bits/stdc++.h>
using namespace std;

int main(){
    long long nowsmallest = 100;
    long long nowbiggest = 0;
    long long today;
    long long ans = 0;
    while(scanf("%lld",&today)){
        if(nowsmallest>today){
            ans = max(nowbiggest-nowsmallest,ans);
            nowsmallest = today;
            nowbiggest = today;
        }
        nowbiggest = max(nowbiggest,today);
        scanf(" ");
    }
    ans = max(ans,nowbiggest-nowsmallest);
    printf("%lld",ans);
}