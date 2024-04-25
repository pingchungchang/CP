#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 6e5+10;
const int B = 20;

struct SPARSE{
	int st[B][mxn];
	void build(vector<int> arr){
		int n = arr.size();
		for(int i = 0;i<n;i++)st[0][i] = arr[i];
		for(int i = 1;i<B;i++){
			for(int j = 1;j+(1<<i)-1<n;j++){
				st[i][j] = min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
			}
		}
		return;
	}
	int getval(int l,int r){
		int d = r-l+1;
		d = __lg(d);
		return min(st[d][l],st[d][r-(1<<d)+1]);
	}
};

bitset<mxn> leaf;
vector<int> t1[mxn],t2[mxn];
int N;
vector<int> eul;
int dfn[mxn],dep[mxn];
SPARSE sparse;
set<int> st;
int lcnt,ans;

void dfs1(int now){
	dfn[now] = eul.size();
	eul.push_back(now);
	for(auto nxt:t2[now]){
		dep[nxt] = dep[now]+1;
		dfs1(nxt);
		eul.push_back(now);
	}
	return;
}

void upd(int now){
	lcnt -= leaf[now];
	leaf[now] = false;
	bool flag = true;
	auto it = st.upper_bound(now);
	if(it != st.end()&&sparse.getval(now,*it) == eul[now])flag = false;
	it = st.lower_bound(now);
	if(it != st.begin()){
		it--;
		if(sparse.getval(*it,now) == eul[now])flag = false;
	}
	leaf[now] = flag;
	lcnt += leaf[now];
}

void add(int now){
	now = dfn[now];
	st.insert(now);
	auto it = st.lower_bound(now);
	if(it != st.begin())it--;
	for(int i = 0;i<3&&it != st.end();it++,i++)upd(*it);
	return;
}
void del(int now){
	now = dfn[now];
	lcnt -= leaf[now];
	leaf[now] = false;
	st.erase(now);
	auto it = st.lower_bound(now);
	if(it != st.begin())it--;
	for(int i = 0;i<3&&it != st.end();it++,i++)upd(*it);
	return;
}

void dfs2(int now){
	add(now);
	for(auto nxt:t1[now])dfs2(nxt);
	ans = max(ans,lcnt);
	del(now);
	return;
}

void init(){
	st.clear();lcnt = ans = 0;
	eul.clear();
	for(int i = 1;i<=N;i++){
		t1[i].clear();t2[i].clear();
		dfn[i] = dep[i] = 0;
	}
}

void solve(){
	init();
	cin>>N;
	for(int i = 2;i<=N;i++){
		int p;
		cin>>p;
		t1[p].push_back(i);
	}
	for(int i = 2;i<=N;i++){
		int p;
		cin>>p;
		t2[p].push_back(i);
	}
	dfs1(1);
	for(auto &i:eul)i = dep[i];
	sparse.build(eul);
	dfs2(1);
	assert(!leaf.any());
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
