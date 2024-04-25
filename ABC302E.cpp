#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 3e5+10;
set<int> st[mxn];

void solve(){
	int n,q;
	cin>>n>>q;
	int cnt = n;
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int a,b;
			cin>>a>>b;
			if(st[a].empty())cnt--;
			if(st[b].empty())cnt--;
			st[a].insert(b);
			st[b].insert(a);
		}
		else{
			int a;
			cin>>a;
			if(!st[a].empty())cnt++;
			for(auto &i:st[a]){
				st[i].erase(a);
				if(st[i].empty())cnt++;
			}
			st[a].clear();
		}
		cout<<cnt<<'\n';
	}
	return;

}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
