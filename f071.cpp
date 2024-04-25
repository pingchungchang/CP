#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[3];
    for(int i =0;i<3;i++){
        scanf("%d",&arr[i]);
    }
    int nums[5];
    unordered_map<int,int> m;
    for(int i =0;i<5;i++){
        scanf("%d",&nums[i]);
    }
    for(int i =0;i<5;i++){
        int x;
        scanf("%d",&x);
        if(m.count(nums[i]) == 0)m[nums[i]] = 0;
        m[nums[i]] += x;
    }
    int ans = 0;
    for(int i =0;i<=1;i++){
        if(m.count(arr[i])!= 0)ans += m[arr[i]];
    }
    if(m.count(arr[2]) == 0) ans *=2;
    else ans -= m[arr[2]];
    if(ans<=0)printf("0");
    else printf("%d",ans);
}
