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

int cnt = 0;
void solve(){
	cnt++;
	int n,k;
	cin>>n>>k;
	int s = 0;
	for(int i = 2;i<=n;i++){
		s = (s+k)%i;
	}
	cout<<"Case "<<cnt<<": ";
	cout<<s+1<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

