#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,m;
	cin>>n>>m;
	pii arr[m];
	for(auto &i:arr)cin>>i.sc>>i.fs;
	sort(arr,arr+m);
	if(m&1){
		cout<<"NO\n";
		return;
	}
	for(int i = 0;i<m;i+=2){
		pii ta = arr[i],tb = arr[i+1];
		int dx = tb.fs-ta.fs;
		if(ta.sc == tb.sc){
			if(!(dx&1)){
				cout<<"NO\n";
				return;
			}
		}
		else{
			if((dx&1)){
				cout<<"NO\n";
				return;
			}
		}
		if(i != m-2&&arr[i+2].fs == tb.fs){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
