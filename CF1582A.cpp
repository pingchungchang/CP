#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	ll a,b,c;
	cin>>a>>b>>c;
	cout<<(a+c)%2<<'\n';
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

