#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int sh = 1e5;

void solve(){
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		cout<<sh+i<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
