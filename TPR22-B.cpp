#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);




const int mxn = 1e6+10;
int id = 0,gid = 0;
stack<int>st;
int idx[mxn],gp[mxn],low[mxn];
bitset<mxn> goneto;
vector<vector<int>> v;

void tarjan(int now){
	idx[now] = ++id;
	low[now] = idx[now];
	st.push(now);
	for(auto nxt:v[now]){
		if(goneto[nxt])continue;
		if(idx[nxt] != 0)low[now] = min(low[now],idx[nxt]);
		else{
			tarjan(nxt);
			low[now] = min(low[now],low[nxt]);
		}
	}
//	cout<<now<<' '<<idx[now]<<' '<<low[now]<<endl;
	if(low[now] == idx[now]){
		gid++;
		while(st.top() != now){
			gp[st.top()] = gid;
			goneto[st.top()] = true;
			st.pop();
		}
		gp[st.top()] = gid;
		goneto[st.top()] = true;
		st.pop();
	}
	return;
}
int main(){
	int n,m;
	cin>>n>>m;
	v = vector<vector<int>>(n);
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		v[a].push_back(b);
	}
	for(int i = 0;i<n;i++){
		if(goneto[i] == false){
			tarjan(i);
		}
	}
	vector<int> deg(gid+1,0);
	vector<int> rep(n,-1);
	for(int i = 0;i<n;i++){
		rep[gp[i]] = i;
		for(auto nxt:v[i]){
			if(gp[nxt] == gp[i])continue;
			deg[gp[nxt]]++;
		}
	}
	vector<int> ans;
	for(int i = 2;i<=gid;i++){
		if(deg[i] == 0)ans.push_back(rep[i]);
	}
	cout<<ans.size()<<'\n';
	for(auto i:ans)cout<<"1 "<<i+1<<'\n';
}

