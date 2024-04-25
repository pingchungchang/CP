#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	ll a[3],b[3];
	for(auto &i:a)cin>>i;
	for(auto &i:b)cin>>i;
	ll big = 0;
	big = min(a[0],b[1])+min(a[1],b[2])+min(a[2],b[0]);
	ll small = 0;
	small = n-min(a[1],b[0]+b[1])-min(a[2],b[1]+b[2])-min(a[0],b[2]+b[0]);
	cout<<small<<' '<<big<<'\n';
	return 0;
}
