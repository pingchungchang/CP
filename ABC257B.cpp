#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	int n,k,q;
	cin>>n>>k>>q;
	vector<int> v(k+2,INT_MAX);
	v[0] = -1;
	for(int i = 1;i<=k;i++)cin>>v[i];
	while(q--){
		int tmp;
		cin>>tmp;
		if(v[tmp] != n&&v[tmp+1] != v[tmp]+1)v[tmp]++;
	}
	for(int i = 1;i<=k;i++)cout<<v[i]<<' ';
	return 0;
}

