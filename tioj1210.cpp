#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e4+10;
ll deg[mxn];
int n;

int cnt[mxn];

void solve(){
	if(!n)exit(0);
	ll sum = 0;
	for(int i = 1;i<=n;i++){
		cin>>deg[i];
	}
	int p = n;
	do{
		sort(deg+1,deg+p+1);
		if(deg[p]<0){
			cout<<"No\n";
			return;
		}
		if(deg[p]>=p){
			cout<<"No\n";
			return;
		}
		for(int i = 1;i<=deg[p];i++){
			deg[p-i]--;
		}
		p--;
	}while(p);
	cout<<"Yes\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n)solve();
}
