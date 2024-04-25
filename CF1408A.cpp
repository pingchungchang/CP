#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int a[n],b[n],c[n],ans[n];
	for(auto &i:a)cin>>i;
	for(auto &i:b)cin>>i;
	for(auto &i:c)cin>>i;
	ans[0] = a[0];
	for(int i = 1;i<n-1;i++){
		int tmp[] = {a[i],b[i],c[i]};
		for(auto &j:tmp){
			if(j != ans[i-1]){
				ans[i] = j;
				break;
			}
		}
	}
	int tmp[] = {a[n-1],b[n-1],c[n-1]};
	for(auto &i:tmp){
		if(i != ans[0]&&i != ans[n-2]){
			ans[n-1] = i;
			break;
		}
	}
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
