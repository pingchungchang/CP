#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int ans = 0;
    for(int i =0;i<n;i++){
        int k;
        scanf("%d",&k);
        int s = INT_MAX;
        for(int j =0;j<k;j++){
            int x;
            scanf("%d",&x);
            s = min(s,x);
        }
        ans = max(ans,s);
    }
    printf("%d",ans);
}