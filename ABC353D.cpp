#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll mod = 998244353;
const int mxn = 2e5+10;
ll arr[mxn];
ll pref[11];
ll ans = 0;
int N;

ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 0;i<N;i++){
		cin>>arr[i];
		pref[to_string(arr[i]).size()]++;
	}
	for(int i = 0;i<N;i++){
		ll coef = 0;
		ll p = 1;
		pref[to_string(arr[i]).size()]--;
		for(int j = 0;j<=10;j++){
			coef = mad(coef,p*pref[j]%mod);
			p = p*10%mod;
		}
		coef = mad(coef,i);
		ans = mad(ans,coef*arr[i]%mod);
	}
	cout<<ans<<'\n';
	return 0;
}
