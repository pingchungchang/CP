#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

vector<pll> dir;
set<pii> lck;
set<pll> st;
const int mxn = 1e5+10;
int arr[2][mxn];
int n,q;

inline bool check(pii pos){
	if(!arr[pos.fs][pos.sc])return true;
	bool re = true;
	for(int i = -1;i<=1;i++){
		pii tmp = {pos.fs^1,pos.sc+i};
		if(tmp.sc<0||tmp.sc>=n)continue;
		if(arr[tmp.fs][tmp.sc])return false;
	}
	return true;
}

inline void del(pii pos){
	st.erase(pos);
	if(lck.find(pos) != lck.end())lck.erase(pos);
	for(auto &i:dir){
		pii tmp = {pos.fs+i.fs,pos.sc+i.sc};
		if(tmp.fs>=2||tmp.fs<0||tmp.sc>=n||tmp.sc<0)continue;
		//cout<<tmp.fs<<" "<<tmp.sc<<":"<<check(tmp)<<',';
		if(st.find(tmp) != st.end()&&!check(tmp))lck.insert(tmp);
		else if(lck.find(tmp) != lck.end()&&check(tmp))lck.erase(tmp);
	}
	return;
}

inline void add(pii pos){
	st.insert(pos);
	if(!check(pos))lck.insert(pos);
	for(auto &i:dir){
		pii tmp = {pos.fs+i.fs,pos.sc+i.sc};
		if(tmp.fs>=2||tmp.fs<0||tmp.sc>=n||tmp.sc<0)continue;
		if(st.find(tmp) != st.end()&&!check(tmp))lck.insert(tmp);
	}
	return;
}

void solve(){
	for(int i = 0;i<2;i++)for(int j = 0;j<n;j++)arr[i][j] = 0;
	st.clear();
	lck.clear();
	cin>>n>>q;
	while(q--){
		pii tmp;
		cin>>tmp.fs>>tmp.sc;
		tmp.fs--,tmp.sc--;
		arr[tmp.fs][tmp.sc] ^= 1;
		//cout<<lck.size()<<":"<<arr[tmp.fs][tmp.sc]<<','<<check(make_pair(0,3))<<endl;
		if(!arr[tmp.fs][tmp.sc])del(tmp);
		else add(tmp);
		//for(auto &i:lck)cout<<i.fs<<','<<i.sc<<' ';
		if(lck.empty())cout<<"Yes\n";
		else cout<<"No\n";
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = -1;i<=1;i++)for(int j = -1;j<=1;j++)dir.push_back({i,j});
	int t = 1;
	while(t--)solve();
}
