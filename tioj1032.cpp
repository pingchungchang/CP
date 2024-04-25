#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

mt19937 seed(time(NULL));
#define rnd(l,r) uniform_int_distribution<ll>(l,r)(seed)


const ll inf = 1LL<<62;
const int mxn = 1e5+10;
unordered_map<ll,pll> mp;
int n,m;

ll val[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	while(m--){
		//cout<<m<<endl<<endl;
		int t;
		cin>>t;
		if(t == 2){
			int k;
			cin>>k;
			int re = 0;
			while(k--){
				int tmp;
				cin>>tmp;
				re ^= val[tmp];
			}
			if(!re)cout<<1<<'\n';
			else cout<<"0\n";
		}
		else if(t == 0){
			ll a,b;
			cin>>a>>b;
			if(a>b)swap(a,b);
			ll v = mp[a*mxn+b].sc;
			if(mp[a*mxn+b].sc == 0){
				v = mp[a*mxn+b].sc = rnd(1,inf);
			}
			if(mp[a*mxn+b].fs == 0){
				val[a]^=v;
				val[b]^=v;
			}
			mp[a*mxn+b].fs++;
		}
		else{
			ll a,b;
			cin>>a>>b;
			if(a>b)swap(a,b);
			mp[a*mxn+b].fs--;
			if(!mp[a*mxn+b].fs){
				val[a]^=mp[a*mxn+b].sc;
				val[b]^=mp[a*mxn+b].sc;
				mp.erase(a*mxn+b);
			}
		}
	}
	return 0;
}
