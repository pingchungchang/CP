#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1010;
const ll mod = 998244353;

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

pii dir[] = {{-1,0},{0,-1},{1,0},{0,1}};
string arr[mxn];
int col[mxn][mxn];
int n,m;

void dfs(int r,int c,int tag){
	col[r][c] = tag;
	for(auto &i:dir){
		int nr = i.fs+r,nc = i.sc+c;
		if(nr>=n||nr<0||nc>=m||nc<0)continue;
		if(!col[nr][nc]&&arr[nr][nc] == '#')dfs(nr,nc,tag);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<n;i++)cin>>arr[i];
	int sh = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(arr[i][j] == '#'&&!col[i][j])dfs(i,j,++sh);
		}
	}
	ll sum = 0;
	ll cnt = 0;
	/*
	cout<<sh<<":"<<endl;for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++)cout<<col[i][j];cout<<endl;
	}cout<<endl;

   */
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(arr[i][j] == '#')continue;
			int tans = sh;
			set<int> st;
			for(auto &d:dir){
				int nr = i+d.fs,nc = j+d.sc;
				if(nr>=n||nr<0||nc>=m||nc<0||arr[nr][nc] != '#')continue;
				st.insert(col[nr][nc]);
			}
			st.insert(mxn*mxn);
			tans = tans+1-(st.size()-1);
			sum = mad(sum,tans);
			cnt++;
			//cout<<i<<' '<<j<<":"<<tans<<endl;
		}
	}
	cout<<sum*inv(cnt)%mod<<'\n';
	return 0;
}
