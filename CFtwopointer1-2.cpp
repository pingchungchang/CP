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
	int n,m;
	cin>>n>>m;
	int a[n],b[m];
	for(auto &i:a)cin>>i;
	for(auto &i:b)cin>>i;
	int p = 0;
	int ans[m] = {};
	for(int i = 0;i<m;i++){
		while(p != n&&a[p]<b[i])p++;
		ans[i] = p;
	}
	for(int i = 0;i<m;i++)cout<<ans[i]<<' ';
}

