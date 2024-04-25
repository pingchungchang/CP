#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2020;
tlll arr[mxn];
bitset<mxn> done;
ll n,x;

bool eat(int tp,ll &h){
	pll big = {0,0};
	for(int i = 0;i<n;i++){
		if(done[i])continue;
		if(tp == get<0>(arr[i])&&h>=get<1>(arr[i]))big = max(big,make_pair(get<2>(arr[i]),i));
	}
	if(!big.fs)return false;
	h += big.fs;
	return done[big.sc] = true;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>x;
	for(int i = 0;i<n;i++){
		cin>>get<0>(arr[i])>>get<1>(arr[i])>>get<2>(arr[i]);
	}
	ll ans;
	int t = 0;
	ll tx = x;
	int tans = 0;
	while(eat(t^=1,tx))tans++;
	ans = tans;

	t = 1;
	done.reset();
	tans = 0;
	tx = x;
	while(eat(t^=1,tx))tans++;
	ans = max(ans,tans);
	cout<<ans;
}
