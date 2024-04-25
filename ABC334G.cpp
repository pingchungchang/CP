#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll mod = 998244353;
const int mxn = 1010;
vector<int> paths[mxn*mxn];
vector<int> tree[mxn*mxn*2];
int low[mxn*mxn],idx[mxn*mxn],cnt,gcnt;
vector<int> groups[mxn*mxn*2],st;
string arr[mxn];
int n,m;
pii dir[] = {{0,1},{0,-1},{1,0},{-1,0}};

inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
inline ll inv(ll k){
	return pw(k,mod-2);
}
inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}
inline ll mub(ll a,ll b){
	return mad(a,mod-b);
}

void tarjan(int now){
	st.push_back(now);
	idx[now] = low[now] = ++cnt;
	for(auto nxt:paths[now]){
		if(!idx[nxt]){
			tarjan(nxt);
			low[now] = min(low[now],low[nxt]);
			if(low[nxt] == idx[now]){
				gcnt++;
				while(st.back() != nxt){
					groups[st.back()].push_back(gcnt);
					st.pop_back();
				}
				groups[st.back()].push_back(gcnt);
				st.pop_back();
				groups[now].push_back(gcnt);
			}
		}
		else low[now] = min(low[now],idx[nxt]);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<n;i++)cin>>arr[i];
	ll sh = 0;
	ll C = 0;
	for(int i = 0;i<n;i++){
		for(int j =0;j<m;j++){
			if(arr[i][j] != '#')continue;
			int flag = 0;
			for(auto &d:dir){
				int nr = i+d.fs,nc = j+d.sc;
				if(nr>=n||nr<0||nc>=m||nc<0||arr[nr][nc] != '#')continue;
				flag++;
				paths[i*m+j].push_back(nr*m+nc);
				//cout<<i<<' '<<j<<":"<<nr<<' '<<nc<<endl;
			}
			if(!flag)sh = mub(sh,1);
			C++;
		}
	}
	int ans = 0;
	//cout<<sh<<endl;
	for(int i = 0;i<n;i++){
		for(int j= 0;j<m;j++){
			if(arr[i][j] != '#')continue;
			if(!idx[i*m+j]){
				ans++;
				st.clear();
				tarjan(i*m+j);
			}
			if(groups[i*m+j].size())sh = mad(sh,groups[i*m+j].size()-1);
			//cout<<i<<' '<<j<<":"<<groups[i*m+j].size()<<endl;
		}
	}
	//cout<<ans<<','<<sh<<' '<<C<<endl;
	cout<<mad(ans,sh*inv(C)%mod);
}
