#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans[3] = {0};
    int k;
    for(int i = 0;i<n-1;i++){
        scanf("%d\n",&k);
        ans[k%3]++;
    }
    scanf("%d",&k);
    ans[k%3]++;
    printf("%d %d %d",ans[0],ans[1],ans[2]);
}