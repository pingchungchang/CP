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
	int p1 = 0,p2 = 0;
	for(auto &i:a)cin>>i;for(auto &i:b)cin>>i;
	int ans[m+n];
	int p = 0;
	while(p1 != n&&p2 != m){
		if(a[p1]>b[p2]){
			ans[p++] = b[p2++];
		}
		else{
			ans[p++] = a[p1++];
		}
	}
	while(p1 != n){
		ans[p++] = a[p1++];
	}
	while(p2 != m){
		ans[p++] = b[p2++];
	}
	for(int i = 0;i<n+m;i++)cout<<ans[i]<<' ';
	return 0;
}

