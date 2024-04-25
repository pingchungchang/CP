#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

ll N,L,R;

inline ll calc(ll k){
	ll high = 0;
	for(int i = 0;i<64;i++){
		if(N&(1ll<<i))high = i;
	}
	ll re = 0;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>L>>R;
	cout<<calc(R)-calc(L-1);
}
