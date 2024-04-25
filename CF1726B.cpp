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
void solve(){
	int n,m;
	cin>>n>>m;
	if(m<n){
		cout<<"NO\n";
		return;
	}
	if(m%n == 0){
		cout<<"YES\n";
		for(int i = 0;i<n;i++)cout<<m/n<<' ';cout<<'\n';
		return;
	}
	ll base = m/n;
	m -= base*n;
//	cout<<m<<endl;
	if(n&1){
		cout<<"YES\n";
		for(int i = 0;i<n-1;i++)cout<<base<<' ';cout<<base+m<<'\n';
		return;
	}
	if((n-m)&1){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	for(int i = 0;i<n-m;i++)cout<<base<<' ';
	for(int i = 0;i<m;i++)cout<<base+1<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();

}

