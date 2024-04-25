#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define tiii tuple<int,int,int>
#define tiiii tuple<int,int,int,int>

const int mxn = 1010;
int n,m;
string arr[mxn];
int d1[mxn][mxn];
pair<int,pii> d2[mxn][mxn][2];
pii s;
pii dir[] = {{-1,0},{1,0},{0,1},{0,-1}};

inline void BFS1(){
	queue<pii> q;
	for(int i = 0;i<n;i++)for(int j = 0;j<m;j++)d1[i][j] = -1;
	d1[s.fs][s.sc] = 0;
	q.push(s);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto &d:dir){
			pii nxt = {now.fs+d.fs,now.sc+d.sc};
			if(nxt.fs<0||nxt.fs>=n||nxt.sc<0||nxt.sc>=m)continue;
			if(arr[nxt.fs][nxt.sc] == '#'||d1[nxt.fs][nxt.sc] != -1)continue;
			q.push(nxt);
			d1[nxt.fs][nxt.sc] = d1[now.fs][now.sc]+1;
		}
	}
	return;
}

inline void BFS2(){
	queue<tiii> q;
	for(int i = 0;i<n;i++)for(int j = 0;j<m;j++)d2[i][j][0] = d2[i][j][1] = make_pair(-1,make_pair(-1,-1));
	for(int i = 0;i<n;i++){
		if(arr[i][0] != '#'){
			d2[i][0][0] = make_pair(0,make_pair(i,0));
			q.push(make_tuple(i,0,0));
		}
		if(arr[i][m-1] != '#'){
			d2[i][m-1][0] = make_pair(0,make_pair(i,m-1));
			q.push(make_tuple(i,m-1,0));
		}
	}

	for(int i = 0;i<m;i++){
		if(arr[0][i] != '#'){
			d2[0][i][0] = make_pair(0,make_pair(0,i));
			q.push(make_tuple(0,i,0));
		}
		if(arr[n-1][i] != '#'){
			d2[n-1][i][0] = make_pair(0,make_pair(n-1,i));
			q.push(make_tuple(n-1,i,0));
		}
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		auto &tmp = d2[get<0>(now)][get<1>(now)][get<2>(now)];
		for(auto &d:dir){
			pii nxt = {get<0>(now)+d.fs,get<1>(now)+d.sc};
			if(nxt.fs<0||nxt.fs>=n||nxt.sc<0||nxt.sc>=m||arr[nxt.fs][nxt.sc] == '#')continue;
			if(d2[nxt.fs][nxt.sc][0].fs == -1){
				d2[nxt.fs][nxt.sc][0] = make_pair(tmp.fs+1,tmp.sc);
				q.push(make_tuple(nxt.fs,nxt.sc,0));
			}
			else if(d2[nxt.fs][nxt.sc][1].fs == -1&&(d2[nxt.fs][nxt.sc][0].sc.fs != tmp.sc.fs||d2[nxt.fs][nxt.sc][0].sc.sc != tmp.sc.sc)){
				d2[nxt.fs][nxt.sc][1] = make_pair(tmp.fs+1,tmp.sc);
				q.push(make_tuple(nxt.fs,nxt.sc,1));
			}
		}
	}
	return;
}

void solve(){
	for(int i = 0;i<n;i++)arr[i].clear();
	cin>>n>>m;
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 0;i<n;i++){
		for(int j =0 ;j<m;j++)if(arr[i][j] == 'V')s = {i,j};
	}
	int o = 0;
	BFS1();
	BFS2();
	for(int i = 0;i<n;i++){
		o += (d1[i][0] != -1);
		o += (d1[i][m-1] != -1);
	}
	for(int i = 0;i<m;i++){
		o += (d1[0][i] != -1);
		o += (d1[n-1][i] != -1);
	}
	if(!o){
		int c = 0;
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				c += (arr[i][j] == '.');
			}
		}
		cerr<<"NO\n";
		cout<<c<<'\n';
		return;
	}
	else if(o == 1){
		int ans = 1e9;
		for(int i = 0;i<n;i++){
			if(d1[i][0] != -1)ans = min(ans,d1[i][0]);
			if(d1[i][m-1] != -1)ans = min(ans,d1[i][m-1]);
		}
		for(int i = 0;i<m;i++){
			if(d1[0][i] != -1)ans = min(ans,d1[0][i]);
			if(d1[n-1][i] != -1)ans = min(ans,d1[n-1][i]);
		}
		ans = -ans;
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				ans += (arr[i][j] == '.');
			}
		}
		cerr<<"ONE\n";
		cout<<ans<<'\n';
		return;
	}
	int ans = 1e9;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(d2[i][j][1].fs == -1||d1[i][j] == -1)continue;
			ans = min(ans,d2[i][j][0].fs+d2[i][j][1].fs+d1[i][j]);
		}
	}
	/*
	for(int i= 0;i<n;i++){
		for(int j = 0;j<m;j++)cout<<d1[i][j]<<' ';cout<<endl;
	}cout<<endl;
	for(int i= 0;i<n;i++){
		for(int j = 0;j<m;j++)cout<<d2[i][j][0].fs<<' ';cout<<endl;
	}cout<<endl;
	for(int i= 0;i<n;i++){
		for(int j = 0;j<m;j++)cout<<d2[i][j][1].fs<<' ';cout<<endl;
	}

   */
	ans = -ans;
	for(int i = 0;i<n;i++)for(int j= 0;j<m;j++)ans += (arr[i][j] == '.');
	cerr<<"MANY\n";
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
