#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	string s;
	cin>>n>>s;
	for(int i = 1;i<n;i++){
		string ta = s.substr(0,i),tb = s.substr(i,n-i);
		if(tb>ta){
			cout<<"Yes\n";
			return;
		}
	}
	cout<<"No\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
