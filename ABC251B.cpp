#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int ans = 0;
    int arr[n+2] = {};
    set<int> st;
    for(int i = 0;i<n;i++)cin>>arr[i];
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<=n;j++){
            for(int k = j+1;k<=n+1;k++){
                if(arr[i]+arr[j]+arr[k] <= m)st.insert(arr[i]+arr[j]+arr[k]);
            }
        }
    }
    cout<<st.size();
}
