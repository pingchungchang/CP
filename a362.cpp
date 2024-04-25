#include <bits/stdc++.h>
using namespace std;

struct node{
    int h,w,id;
    node(){}
    bool operator<(const node& b)const{
        return h == b.h?w == b.w?id<b.id:w<b.w:h<b.h;
    }
};

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    node arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i].h>>arr[i].w;
        arr[i].id = i;
    }
    sort(arr,arr+n);
    int ans = 0;
    for(int i = 0;i<n;i++){
        ans += abs(i-arr[i].id);
    }
    cout<<ans;
}