#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	pll ta = {0,-1};
	pll tb = ta;
	int n;
	string s;
	cin>>n>>s;
	for(int i = 0;i<n;i++){
		if(s[i] == 'A')ta = {ta.fs+1,i};
		else tb = {tb.fs+1,i};
	}
	//cout<<ta.fs<<' '<<tb.fs<<endl;
	if(ta.fs>tb.fs)cout<<"A";
	else if(ta.fs<tb.fs)cout<<"T";
	else if(ta.sc<tb.sc)cout<<"A";
	else cout<<"T";
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	solve();
}
