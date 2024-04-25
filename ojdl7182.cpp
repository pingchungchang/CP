#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>

const int mxn = 2e5+10;
vector<tuple<int,int,int,int>> req;
pii op[mxn];
int bit[mxn];
const int sq = sqrt(5e4);
vector<tuple<int,int,int>> rmo[sq];
int ans[mxn];

void modify(int p,int v){
	for(;p<mxn;p+=p&-p)bit[p] = max(bit[p],v);
	return;
}
int getval(int p){
	int re = 0;
	for(;p>0;p-= p&-p)re = max(re,bit[p]);
	return re;
}

void solve(){
	int n,m,q;
	cin>>n>>m>>q;
	for(int i = 1;i<=m;i++){
		cin>>op[i].fs>>op[i].sc;
	}
	for(int i = 1;i<=q;i++){
		int l,r,p;
		cin>>l>>r>>p;
		if(r-l<=sq){
			int re = 0;
			for(int j = l;j<=r;j++){
				if(op[j].fs<=p)re = max(re,op[j].sc);
			}
			ans[i] = re;
		}
		else{
			int tl = (l+sq-1)/sq;
			int re = 0;
			for(int j = l;j<=min(tl*sq,m);j++){
				if(op[j].fs<=p)re = max(re,op[j].sc);
			}
			ans[i] = re;
			rmo[tl].push_back(make_tuple(r,p,i));
		}
	}
	int c = (m+sq-1)/sq;
	for(int i = 0;i<=c;i++)sort(rmo[i].rbegin(),rmo[i].rend());
	for(int i = 0;i<=c;i++){
		for(int j = i*sq+1;j<=m;j++){
			//cout<<op[j].fs<<' '<<op[j].sc<<endl;
			modify(op[j].fs,op[j].sc);
			//cout<<j<<endl;
			while(!rmo[i].empty()&&get<0>(rmo[i].back()) == j){
				int p = get<1>(rmo[i].back());
				int id = get<2>(rmo[i].back());
				ans[id] = max(ans[id],getval(p));
				rmo[i].pop_back();
			}
		}
		memset(bit,0,sizeof(bit));
	}
	for(int i = 1;i<=q;i++)cout<<ans[i]<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
