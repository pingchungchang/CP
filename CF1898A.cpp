#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
int suf[mxn];
string s;

void solve(){
	int n,m;
	cin>>n>>m;
	cin>>s;
	s = "#"+s;
	suf[n+1] = 0;
	for(int i = n;i>=1;i--){
		suf[i] = suf[i+1]+(s[i] == 'B');
	}
	if(suf[1] == m){
		cout<<"0\n";
		return;
	}
	for(int i = 2;i<=n+1;i++){
		if(suf[i]==m){
			cout<<"1\n"<<i-1<<" A\n";
			return;
		}
		if(i-1+suf[i] == m){
			cout<<"1\n"<<i-1<<" B\n";
			return;
		}
	}
	assert(false);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
