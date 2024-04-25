#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int main(){
	io
	int n,q;
	cin>>n>>q;
	vector<vector<int>> v;
	while(n--){
		int m;
		cin>>m;
		vector<int> tmp;
		while(m--){
			int k;
			cin>>k;
			tmp.push_back(k);
		}
		v.push_back(tmp);
	}
	while(q--){
		int r,c;
		cin>>r>>c;
		cout<<v[r-1][c-1]<<'\n';
	}
	return 0;
}

