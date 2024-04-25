#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 5e5+10;
const ll s1 = 1e6;
unordered_map<ll,vector<int>> mp;
int val[mxn];

int getrand(){
	return rand();
}



void solve(){
	int n,m;
	cin>>n>>m;
	while(m--){
		int t;
		cin>>t;
		if(t == 0){
			int a,b;
			cin>>a>>b;
			if(a == b)continue;
			int r = getrand();
			if(a>b)swap(a,b);
			mp[1LL*a*s1+b].push_back(r);
			val[a] ^= r;
			val[b]^= r;
		}
		else if(t == 1){
			int a,b;
			cin>>a>>b;
			if(a == b)continue;
			if(a>b)swap(a,b);
			if(mp[1LL*a*s1+b].empty())continue;
			int r = mp[a*s1+b].back();
			mp[1LL*a*s1+b].pop_back();
			if(mp[1LL*a*s1+b].empty())mp.erase(1LL*a*s1+b);
			val[a] ^= r;
			val[b] ^= r;
		}
		else{
			int k;
			cin>>k;
			int total = 0;
			while(k--){
				int x;
				cin>>x;
				total ^= val[x];
			}
			cout<<(total == 0)<<'\n';
		}
	}
	return;
}

int main(){
	srand(time(NULL));
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
