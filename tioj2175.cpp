#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 333;
int n,m;
int arr[mxn][mxn];
vector<pii> v[mxn][mxn];
pii pos[mxn];
vector<int> paths[mxn*mxn];

namespace BIMATCH{
	bitset<mxn> vis;
	int mx[mxn],my[mxn];

	bool dfs(int now){
		if(vis[now])return false;
		vis[now] = true;
		for(auto nxt:paths[now]){
			if(!my[nxt]){
				my[nxt] = now;
				mx[now] = nxt;
				return true;
			}
			else if(!vis[my[nxt]]&&dfs(my[nxt])){
				my[nxt] = now;
				mx[now] = nxt;
				return true;
			}
		}
		return false;
	}

	int GO(){
		int re = 0;
		for(int i = 1;i<=mxn;i++){
			vis.reset();
			if(dfs(i))re++;
		}
		return re;
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(arr,-1,sizeof(arr));
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin>>arr[i][j];
			if(arr[i][j] >0)pos[arr[i][j]] = make_pair(i,j);
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(arr[i][j] != 0)continue;
			for(int ii = 0;ii<n;ii++){
				for(int jj = 0;jj<m;jj++){
					if(arr[ii][jj] <= 0)continue;
					v[i][j].push_back(make_pair(max(abs(i-ii),abs(j-jj)),arr[ii][jj]));
				}
			}
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			vector<int> vv;
			sort(v[i][j].begin(),v[i][j].end(),[](pii a,pii b){return a.fs == b.fs?a.sc>b.sc:a.fs<b.fs;});
			for(auto &k:v[i][j]){
				//cout<<i<<' '<<j<<":"<<k.fs<<','<<k.sc<<endl;
				if(!vv.empty()&&vv.back()>k.sc)continue;
				else vv.push_back(k.sc);
			}
			for(auto &k:vv){
				paths[i*m+j+1].push_back(pos[k].fs*m+pos[k].sc+1);
			}
		}
	}
	for(int i = 1;i<=n*m;i++){
		for(auto nxt:paths[i]){
			//cout<<(i-1)/m<<' '<<(i-1)%m<<":"<<(nxt-1)/m<<' '<<(nxt-1)%m<<endl;
		}
	}
	cout<<BIMATCH::GO();
}
