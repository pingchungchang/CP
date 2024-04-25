#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define int ll
const ll inf = 1e18;
const ll mod = 1e9+7;

struct edge{
	int w,col,from,to;
	edge(){}
	edge(int a,int b,int c,int d){
		from = a,to = b;
		w = c;
		col = d;
	}
};

inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<edge> paths[n+1];
	for(int i = 1;i<=m;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		paths[a].push_back(edge(a,b,c,d));
		paths[b].push_back(edge(b,a,c,d));
	}
	ll ans = 0;
	for(int s = 1;s<=n;s++){
		pll d1[n+1],d2[n+1];
		bool done1[n+1] = {},done2[n+1] = {};
		for(int i = 0;i<=n;i++)d1[i] = d2[i] = {inf,inf};
		queue<int> q;
		d1[s] = d2[s] = {0,0};
		for(int i = 0;i<n*2;i++){
			tuple<int,int,int> small = make_tuple(inf+1,inf,inf);
			for(int j = 1;j<=n;j++){
				if(!done1[j]&&d1[j].fs<get<0>(small))small = make_tuple(d1[j].fs,0,j);
				if(!done2[j]&&d2[j].fs<get<0>(small))small = make_tuple(d2[j].fs,1,j);
			}
			int now = get<2>(small);
			if(done1[now])done2[now] = true;
			else done1[now] = true;
			for(auto &tmp:paths[now]){
				ll d = 0;
				if(tmp.col == d1[tmp.from].sc)d = d2[tmp.from].fs;
				else d = d1[tmp.from].fs;
				if(d1[tmp.to].sc == tmp.col){
					if(d+tmp.w<d1[tmp.to].fs){
						d1[tmp.to].fs = d+tmp.w;
					}
				}
				else if(d2[tmp.to].sc == tmp.col){
					if(d+tmp.w<d2[tmp.to].fs){
						d2[tmp.to].fs = d+tmp.w;
						if(d1[tmp.to].fs>d2[tmp.to].fs)swap(d1[tmp.to],d2[tmp.to]);
					}
				}
				else{
					if(d+tmp.w<d1[tmp.to].fs){
						swap(d1[tmp.to],d2[tmp.to]);
						d1[tmp.to] = {d+tmp.w,tmp.col};
					}
					else if(d+tmp.w<d2[tmp.to].fs)d2[tmp.to] = {d+tmp.w,tmp.col};
				}
			}
		}
		//for(int i = 1;i<=n;i++)cout<<(d1[i].fs==inf?-1:d1[i].fs)<<' ';cout<<'\n';
		for(int i = s+1;i<=n;i++){
			/*
			if(d1[i].fs>d2[i].fs){
				cout<<s<<":"<<i<<endl;
				exit(0);
			}

		   */
			assert(d1[i].fs<=d2[i].fs);
			if(d1[i].fs >= inf)d1[i].fs = 0;
			ans = mad(ans,d1[i].fs*(s+i)%mod);
		}
	}
	cout<<ans<<'\n';
	return;
}
main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
