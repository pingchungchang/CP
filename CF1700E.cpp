#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

int n,m;
vector<vector<int>> v;
pii dir[] = {{0,1},{0,-1},{1,0},{-1,0}};

inline bool check(int r,int c){
	bool re = false;
	if(r>n||c>m||r<1||c<1)return true;
	for(auto &i:dir){
		pii nxt = make_pair(r+i.fs,c+i.sc);
		if(v[r][c]>v[nxt.fs][nxt.sc])re = true;
	}
	return re;
}

inline bool safe(int r,int c){
	bool re = true;
	re = re&&check(r,c);
	for(auto &i:dir){
		re = re&&check(r+i.fs,c+i.sc);
	}
	return re;
}

inline ll getans(pii now){
	ll re = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			swap(v[i][j],v[now.fs][now.sc]);
			bool flag = true;
			if(!safe(now.fs,now.sc))flag = false;
			if(!safe(i,j))flag = false;
			re += flag;
			swap(v[i][j],v[now.fs][now.sc]);
		}
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	v = vector<vector<int>>(n+2);
	for(int i = 0;i<=n+1;i++)v[i] = vector<int>(m+2,5000000);
	for(int i = 1;i<=n;i++)for(int j = 1;j<=m;j++)cin>>v[i][j];
	int c = 0;
	pii tar;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(v[i][j] == 1)continue;
			if(!check(i,j))tar = {i,j},c++,cout<<i<<' '<<j<<endl;
		}
	}
	if(c != 1){
		cout<<c;
		return 0;
	}
	ll ans = 0;
	ans += getans(make_pair(tar.fs,tar.sc));
	for(auto &i:dir){
		ans += getans(make_pair(tar.fs+i.fs,tar.sc+i.sc));
	}
	for(auto &i:dir){
		pii nxt = {tar.fs+i.fs,tar.sc+i.sc};
		swap(v[nxt.fs][nxt.sc],v[tar.fs][tar.sc]);
		if(safe(tar.fs,tar.sc)&&safe(nxt.fs,nxt.sc))ans--;
		swap(v[nxt.fs][nxt.sc],v[tar.fs][tar.sc]);
	}
	cout<<ans;
}
