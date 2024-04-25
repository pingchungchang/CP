#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int n;
void solve(){
	int arr[n];
	for(auto &i:arr)cin>>i;
	int ans = 0;
	for(int i = 0;i<n;i++){
		for(int j = i;j<n;j++){
			int s = 0;
			for(int k = i;k<=j;k++)s += arr[k];
			ans = max(ans,s);
		}
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n)solve();
}
