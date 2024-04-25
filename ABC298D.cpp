#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998244353;
const ll mxn = 6e5+10;
ll pw[mxn];
deque<ll> dq;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pw[0] = 1;
	for(int i = 1;i<mxn;i++){
		pw[i] = pw[i-1]*10%mod;
	}
	ll total = 1;
	dq.push_back(1);
	ll q;
	cin>>q;
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int k;
			cin>>k;
			dq.push_back(k);
			total = total*10+k;
			total %= mod;
		}
		else if(t == 2){
			total = (total+mod-dq.front()*pw[dq.size()-1]%mod);
			total %= mod;
			dq.pop_front();
		}
		else{
			cout<<total<<'\n';
		}
	}
	return 0;
}
