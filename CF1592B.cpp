#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int asd=0;asd<t;asd++){
        int n,k;
        cin>>n>>k;
        int arr[n];
        int ans[n];
        for(int i =0;i<n;i++){
            cin>>arr[i];
            ans[i] = arr[i];
        }
        sort(ans,ans+n);
        int re = 1;
        for(int i =0;i<n;i++){
            if(ans[i]!= arr[i]){
                int moves = max(abs(i),abs(n-i-1));
                if(moves<k)re = 0;
            }
        }
        if(re == 0)cout<<"NO\n";
        else cout<<"YES\n";
    }
}
