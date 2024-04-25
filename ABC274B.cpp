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
const int mxn = 1e3+10;
int main(){
	io
	int n,m;
	cin>>n>>m;
	int ans[m] = {};
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			char c;
			cin>>c;
			if(c == '#')ans[j]++;
		}
	}
	for(auto &i:ans)cout<<i<<' ';
}

