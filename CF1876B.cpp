#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll mod = 998244353;
const ll mxn = 1e5+10;
pll arr[mxn];
int n;
ll pw[mxn];
bitset<mxn> done;

ll f(int idx){
	int re = 0;
	for(int i = 1;i*i<=idx;i++){
		if(idx%i == 0){
			if(!done[i])re++;
			done[i] = true;
			if(!done[idx/i])re++;
			done[idx/i] = true;
		}
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i].fs;
		arr[i].sc = i;
	}
	pw[0] = 1;
	for(int i = 1;i<mxn;i++)pw[i] = pw[i-1]*2%mod;
	sort(arr+1,arr+n+1,greater<pll>());
	ll rest = n;
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		if(done[arr[i].sc])continue;
		ll cnt = f(arr[i].sc);
		//cout<<arr[i].fs<<' '<<arr[i].sc<<' '<<cnt<<' '<<rest<<endl;
		ans += (pw[cnt]-1)*arr[i].fs%mod*pw[rest-cnt]%mod;
		rest -= cnt;
		if(ans>=mod)ans -= mod;
	}
	cout<<ans;
}
