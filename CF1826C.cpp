#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 1e6+10;
int lpf[mxn];

void solve(){
	int a,b;
	cin>>a>>b;
	if(a == 1){
		cout<<"YES\n";
		return;
	}
	if(b>=a){
		cout<<"NO\n";
		return;
	}
	if(lpf[a] > b){
		cout<<"YES\n";
		return;
	}
	else{
		cout<<"NO\n";
		return;
	}
}

int main(){
	lpf[1] = 1;
	for(int i = 2;i<mxn;i++){
		if(!lpf[i]){
			for(int j = i;j<mxn;j+=i)if(!lpf[j])lpf[j] = i;
		}
	}
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
