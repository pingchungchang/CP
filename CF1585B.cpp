#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
void solve(){
	int n,m;
	cin>>n>>m;
	bool used[n+1] = {};
	for(int i = 0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		used[b] = true;
	}
	int root = 0;
	for(int i = 1;i<=n;i++){
		if(used[i] == false){
			root = i;
			break;
		}
	}
	for(int i = 1;i<=n;i++){
		if(i != root)cout<<i<<' '<<root<<'\n';
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

