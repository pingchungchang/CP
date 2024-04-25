#include <bits/stdc++.h>
using namespace std;

#define pll pair<ll,ll>
#define fs first
#define sc second
#define ll long long
const int mxn = 332;
const ll inf = 1e18;
ll ans[mxn][mxn];
vector<pll> paths[mxn];
bitset<mxn> goneto;
pll lleft[mxn];
ll n,m,tank;
class Cmp{
	public:
		bool operator()(pair<pll,ll> a,pair<pll,ll> b){
			if(a.fs.fs != b.fs.fs)return a.fs.fs>b.fs.fs;
			else return a.fs.sc<b.fs.sc;
		}
};
void dijkstra(int start){
    for(auto &i:lleft)i = {inf,-1};
    goneto.reset();
    priority_queue<pair<pll,ll>,vector<pair<pll,ll>>,Cmp> pq;
    lleft[start] = {0,tank}; 
    pq.push({{0LL,tank},start});
    while(!pq.empty()){
        auto now = pq.top();
        pq.pop();
        if(goneto[now.sc])continue;
//        cout<<start<<' '<<now.sc<<endl;
        goneto[now.sc] = true;
        for(auto nxt:paths[now.sc]){
            if(goneto[nxt.fs]||nxt.sc>tank)continue;
            pll tmp = lleft[now.sc];
            if(tmp.sc>=nxt.sc)tmp.sc -= nxt.sc;
            else{
                tmp.fs++;
                tmp.sc = tank-nxt.sc;
            } 
            if(tmp.fs<lleft[nxt.fs].fs){
                lleft[nxt.fs] = tmp;
                pq.push({lleft[nxt.fs],nxt.fs});
            }
            else if(tmp.fs == lleft[nxt.fs].fs&&tmp.sc > lleft[nxt.fs].sc){
            	lleft[nxt.fs] = tmp;
            	pq.push({lleft[nxt.fs],nxt.fs});
			}
        }
    }
    for(int i = 1;i<=n;i++){
        ans[start][i] = lleft[i].fs;
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>tank;
    for(int i = 0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        paths[a].push_back({b,c});
        paths[b].push_back({a,c});
    }
    for(int i =1;i<=n;i++){
        dijkstra(i);
    }
//    for(int i = 1;i<=n;i++){
//    	for(int j= 1;j<=n;j++)cout<<ans[i][j]<<' ';cout<<endl;
//	}
//	cout<<endl;
    int q;
    cin>>q;
    while(q--){
        int s,e;
        cin>>s>>e;
        if(ans[s][e] >= inf)cout<<"-1\n";
        else cout<<ans[s][e]<<'\n';
    }
    return 0;
}
