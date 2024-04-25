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
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(auto i:s){
		if(i == 'U')cout<<"D";
		else if(i == 'D')cout<<"U";
		else cout<<i;
	}
	cout<<'\n';
	return;
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
}

