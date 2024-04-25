#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	int n;
	string s;
	cin>>n>>s;
	int p1 = INT_MAX;
	for(int i = 0;i<n;i++){
		if(s[i] == '>'){
			p1 = i;
			break;
		}
	}
	int p2 = INT_MAX;
	for(int i = n-1;i>=0;i--){
		if(s[i] == '<'){
			p2 = n-1-i;
			break;
		}
	}
	cout<<min(p1,p2)<<'\n';
	return;
}
int main(){
	io
	int t;cin>>t;for(int i = 0;i<t;i++)solve();
}

