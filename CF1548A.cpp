#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double


const int mxn= 2e5+10;
int main(){
	io
	int n,m;
	cin>>n>>m;
	bitset<mxn> now = {};
	vector<int> cnt(n+1,0);
	for(int i = 1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		if(a>b)swap(a,b);
		cnt[a]++;
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		if(cnt[i] == 0)ans++;
	}
	int q;
	cin>>q;
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int a,b;
			cin>>a>>b;
			if(a>b)swap(a,b);
			if(cnt[a] == 0){
				ans--;
			}
			cnt[a]++;
		}
		else if(t == 2){
			int a,b;
			cin>>a>>b;
			if(a>b)swap(a,b);
			if(cnt[a] == 1){
				ans++;
			}
			cnt[a]--;
		}
		else{
			cout<<ans<<'\n';
		}
	}
	return 0;
}

