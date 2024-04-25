#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
#pragma GCC optimize("O3,-unroll loops")

set<ll> primes;
ll gcd(ll a,ll b){
	if(b>a)swap(a,b);
	while(b != 0){
		a %= b;
		swap(a,b);
	}
	return a;
}

ll dec(ll now){
	ll re = 0;
	bool flag = true;
	while(flag){
		flag = false;
		for(auto it:primes){
			if(it*it>now)break;
			if(now%it == 0){
				now /=it;
				re++;
				flag = true;
				break;
			}
		}
	}
	if(now != 1){
		primes.insert(now);
		re++;
	}
	return re;
}
void solve(){
	ll a,b,k;
	cin>>a>>b>>k;
	if(a == b&&k == 1){
		cout<<"NO\n";
		return;
	}
	ll G = gcd(a,b);
	pll p = {a/G,b/G};
	p.fs = dec(p.fs),p.sc = dec(p.sc);
	ll gg = dec(G);
//	cout<<p.fs<<' '<<p.sc<<' '<<gg<<',';
	ll total = gg+gg+p.fs+p.sc;
	if(total<k){
		cout<<"NO\n";
		return;
	}
	if(G == a||G == b){
		cout<<"YES\n";
		return;
	}
	if(k == 1)cout<<"NO\n";
	else cout<<"YES\n";
	return;
}
int main(){
	bitset<50000> b;
	b.reset();
	for(int i = 2;i<50000;i++){
		if(!b[i]){
			primes.insert(i);
			for(int j = i+i;j<50000;j+= i){
				b[j] = true;
			}
		}
	}
	io
	int t;
	cin>>t;
	while(t--)solve();
}

