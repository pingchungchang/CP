#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n,t;
	cin>>n>>t;
	pll arr[n];
	for(auto &i:arr)cin>>i.fs;
	for(auto &i:arr)cin>>i.sc;
	int ans = -1;
	for(int i = 0;i<n;i++){
		if(arr[i].fs+i<=t){
			if(ans == -1||arr[ans].sc<arr[i].sc)ans = i;
		}
	}
	if(ans != -1)cout<<ans+1<<'\n';
	else cout<<-1<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
