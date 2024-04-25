#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m,p;
	cin>>n>>m>>p;
	while(m-p>1)m-= p;
	int ans = 0;
	while(m<=n)ans++,m+=p;
	cout<<ans;
}
