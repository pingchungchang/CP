#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
multiset<int> box[mxn];
set<int> card[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int a,b;
			cin>>a>>b;
			box[b].insert(a);
			card[a].insert(b);
		}
		else if(t == 2){
			int a;
			cin>>a;
			for(auto &i:box[a])cout<<i<<' ';cout<<'\n';
		}
		else{
			int a;
			cin>>a;
			for(auto &i:card[a])cout<<i<<' ';cout<<'\n';
		}
	}
	return 0;
}
