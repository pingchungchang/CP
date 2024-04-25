#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
set<int> st[mxn];
int n,q;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		st[i].insert(k);
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		if(st[a].size()>st[b].size())swap(st[a],st[b]);
		while(!st[a].empty()){
			st[b].insert(*st[a].begin());
			st[a].erase(st[a].begin());
		}
		cout<<st[b].size()<<'\n';
	}
	return 0;
}
