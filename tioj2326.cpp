#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll mxn = 1e5+10;
ll n,q,A,B,K;
ll arr[mxn],ans[mxn];
int ptr[3030];
int sz[3030];
vector<int> pos[3030],able[3030];

void subtask(){
	cin>>n>>q>>A>>B>>K;
	for(int i = 0;i<2048;i++){
		for(int j = i;j<2048;j++){
			if((A^i^j)+(B^i^j)>=K){
				able[i].push_back(j);
				if(i != j)able[j].push_back(i);
			}
		}
	}
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		pos[k].push_back(i);
		arr[i]  =k;
	}
	for(int i = 0;i<2048;i++)sz[i] = pos[i].size();
	for(int i = 1;i<=n;i++){
		int now = arr[i];
		ans[i] = ans[i-1];
		for(auto nxt:able[now]){
			int &pt = ptr[nxt];
			while(pt<sz[nxt]&&pos[nxt][pt]<i)pt++;
			ans[i] += pt;
			//if(nxt<16)cout<<i<<":"<<nxt<<":"<<pt<<endl;
		}
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<ans[b]<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	subtask();exit(0);
}
