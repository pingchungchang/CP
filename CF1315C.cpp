#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n+1] = {};
    for(int i = 1;i<=n;i++)cin>>arr[i];
    int ans[n*2+2] = {};
    set<int> st;
    for(int i = 1;i<=n*2;i++)st.insert(i);
    for(int i =1;i<=n;i++){
        ans[i*2-1] = arr[i];
        st.erase(arr[i]);
    }
    for(auto &now:st){
        int small = 0;
        int sval = 0;
        for(int i = 1;i<=n;i++){
            if(ans[i*2] == 0){
                if(arr[i]>sval&&arr[i]<now){
                    sval = arr[i];
                    small = i;
                }
            }
        }
        if(small == 0){
            cout<<"-1\n";
            return;
        }
        ans[small*2] = now;
    }
    for(int i = 2;i<=n*2;i+=2){
        for(int j = i+2;j<=n*2;j+=2){
            if(ans[i]>ans[j]&&ans[i]>ans[j-1]&&ans[j]>ans[i-1]){
                swap(ans[i],ans[j]);
            }
        }
    }
    for(int i = 1;i<=n*2;i++)cout<<ans[i]<<' ';
    cout<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}