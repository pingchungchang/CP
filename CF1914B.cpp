#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n,k;
	cin>>n>>k;
	int d = n-k-1;
	for(int i = 0;i<d;i++){
		cout<<n-i<<' ';
	}
	for(int i = 1;i<=k+1;i++)cout<<i<<' ';
	cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
