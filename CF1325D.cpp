#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll a,b;
	cin>>a>>b;
	if(!a&&!b){
		cout<<"0\n";
		return 0;
	}
	if(a == b){
		cout<<1<<'\n'<<a;
		return 0;
	}
	if(a>b||(b-a)%2 == 1){
		cout<<"-1";
		return 0;
	}
	ll ta = a,tb = 0;
	ll d = b-a;
	for(ll i = 60;i>=0;i--){
		if(a&(1LL<<i))continue;
		ll tmp = 1LL<<i;
		if(tmp*2<=d){
			ta ^= tmp,tb ^= tmp;
			d -= tmp*2;
		}
	}
	if((ta^tb) == a&&ta+tb == b){
		cout<<"2\n"<<ta<<' '<<tb;
		return 0;
	}
	cout<<"3\n"<<a<<' '<<(b-a)/2<<' '<<(b-a)/2;
}
