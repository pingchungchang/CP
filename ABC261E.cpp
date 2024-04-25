#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	io
	int n,c;
	cin>>n>>c;
	ll ones[32],zero[32];
	fill(ones,ones+32,1LL);
	memset(zero,0LL,sizeof(zero));
	ll now = c;
	for(ll i = 0;i<n;i++){
		ll o,k;
		cin>>o>>k;
		for(ll j = 0;j<32;j++){
			if(o == 1){
				ones[j] = (((ones[j]<<j)&(k&(1LL<<j))) == 0?0:1);
				zero[j] = (((zero[j]<<j)&(k&(1LL<<j))) == 0?0:1);
			}
			else if(o == 2){
				ones[j] = (((ones[j]<<j)|(k&(1LL<<j))) == 0?0:1);
				zero[j] = (((zero[j]<<j)|(k&(1LL<<j))) == 0?0:1);
			}
			else{
//				cout<<j<<' '<<ones[j]<<'\n'<<(k&(1LL<<j))<<'\n';
				ones[j] = (((ones[j]<<j)^(k&(1LL<<j))) == 0?0LL:1LL);
				zero[j] = (((zero[j]<<j)^(k&(1LL<<j))) == 0?0LL:1LL);
			}
		}
		ll tmp = 0;
		for(ll j = 0;j<32;j++){
			if(now&1)tmp += (ones[j]<<j);
			else tmp += (zero[j]<<j);
			now>>=1;
		}
		now = tmp;
		cout<<now<<'\n';
//		for(int j = 0;j<32;j++)cout<<ones[j]<<' ';cout<<'\n';
//		for(int j = 0;j<32;j++)cout<<zero[j]<<' ';cout<<"\n\n";
	}
}

