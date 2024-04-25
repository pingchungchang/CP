#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 2e5+10;
vector<tlll> paths[mxn];
bitset<mxn> done;
pll pos[mxn];

void dfs(int now){
	done[now] = true;
	for(auto nxt:paths[now]){
		if(!done[get<0>(nxt)]){
			int p = get<0>(nxt),dx = get<1>(nxt),dy = get<2>(nxt);
			pos[p] = {pos[now].fs+dx,pos[now].sc+dy};
			dfs(p);
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		paths[a].push_back(make_tuple(b,c,d));
		paths[b].push_back(make_tuple(a,-c,-d));
	}
	dfs(1);
	for(int i = 1;i<=n;i++){
		if(!done[i])cout<<"undecidable\n";
		else cout<<pos[i].fs<<' '<<pos[i].sc<<'\n';
	}
	return 0;
}
