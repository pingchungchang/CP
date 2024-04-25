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
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	sort(_all(v));
	for(int i = 0;i<n;i++)cout<<v[i]<<' ';cout<<'\n';
	while(next_permutation(_all(v))){
		for(auto &i:v)cout<<i<<' ';cout<<'\n';
	}
	return 0;
}

