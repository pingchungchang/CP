#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

bool bigger(pll a,pll b){
	if(a.sc>=b.sc+32)return 1;
	if(b.sc>=a.sc+32)return 0;
	while(a.sc>b.sc)a.fs *= 2,a.sc--;
	while(b.sc>a.sc)b.fs *= 2,b.sc--;
	return a.fs>=b.fs;//return a>=b:true else false
}

ll divide(pll a,pll b){//return __lg(a/b)
	while(a.fs<b.fs)a.fs *= 2,a.sc--;
	while(a.fs>b.fs)b.fs *= 2,b.sc--;
	return a.sc-b.sc;
}

void solve(){
	ll n;
	cin>>n;
	pll arr[n];
	for(auto &i:arr)cin>>i.fs,i.sc = 0;
	ll ans = 0;
	for(int i = 1;i<n;i++){
		if(bigger(arr[i],arr[i-1]))continue;
		ll tmp = divide(arr[i-1],arr[i]);
		ans += tmp;
		arr[i].sc += tmp;
	}
	//for(auto &i:arr)cout<<i.fs<<' '<<i.sc<<',';
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
