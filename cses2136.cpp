#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e4+10;
int arr[mxn];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        string tmp;
        cin>>tmp;
        reverse(tmp.begin(),tmp.end());
        int re = 0;
        for(int j = 0;j<m;j++){
        	if(tmp[j] == '1')re ^= (1<<j);
		}
		arr[i] = re;
    }
    int ans= m;
    for(int i = 0;i<n;i++)for(int j= i+1;j<n;j++)ans = min(ans,(int)__builtin_popcount(arr[i]^arr[j]));
    cout<<ans;
}
