#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a,b;
	cin>>a>>b;
	map<int,pii> mp;
	int c = 0;
	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++){
			mp[++c] = {i,j};
		}
	}
	auto ta = mp[a],tb = mp[b];
	if(ta.fs==tb.fs&&abs(ta.sc-tb.sc) == 1)cout<<"Yes";
	else cout<<"No";
	return 0;
}
