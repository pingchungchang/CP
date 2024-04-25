#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>

pii dir[] = {{0,1},{0,-1},{1,0},{-1,0}};
const int mxn = 110;
map<string,int> mp;
char tp[mxn][mxn];
int h[mxn][mxn];
int dp[2][mxn][mxn];

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	mp["P"] = 1;
	mp["D"] = 2;
	mp["M"] = 3;
	mp["F"] = 4;
	mp["O"] = 5;
	mp["N"] = 6;
	string ans = "N";
	int m,n;
	cin>>m>>n;
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=n;j++){
			cin>>tp[i][j];
		}
	}
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=n;j++)cin>>h[i][j];
	}
	queue<pii> q;
	int x,y,nh;
	cin>>x>>y>>nh;
	bool roll = 0;
	memset(dp[roll],0,sizeof(dp[roll]));
	if(nh>h[x][y])dp[roll][x][y] = 1;
	if(nh == h[x][y])ans[0] = tp[x][y];
	for(int i = 1;i*i*5<=nh;i++){
		roll ^= 1;
		memset(dp[roll],0,sizeof(dp[roll]));
		int now = nh-i*i*5;
		for(int j = 1;j<=m;j++){
			for(int k = 1;k<=n;k++){
				if(!dp[roll^1][j][k])continue;
				//cout<<i<<j<<k<<endl;
				for(auto &kk:dir){
					pii nxt = make_pair(kk.fs+j,kk.sc+k);
					if(nxt.fs<=0||nxt.fs>m||nxt.sc<=0||nxt.sc>n)continue;
					//cout<<i<<":"<<nxt.fs<<' '<<nxt.sc<<' '<<h[nxt.fs][nxt.sc]<<' '<<now<<endl;
					if(h[nxt.fs][nxt.sc]<=now)dp[roll][nxt.fs][nxt.sc] = true;
				}
			}
		}
		for(int j  =1;j<=m;j++){
			for(int k = 1;k<=n;k++){
				if(dp[roll][j][k]&&h[j][k] == now)if(mp[ans]>mp[string(1,tp[j][k])])ans[0] = tp[j][k];
				if(dp[roll][j][k]&&h[j][k] == now)dp[roll][j][k] = 0;
			}
		}
	}
	if(ans[0] == 'N')cout<<-1;
	else if(ans[0] == 'P')cout<<"Plain";
	else if(ans[0] == 'M')cout<<"Mountain";
	else if(ans[0] == 'D')cout<<"Desert";
	else if(ans[0] == 'F')cout<<"Forest";
	else cout<<"Ocean";
}
