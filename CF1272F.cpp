#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 202;
const int inf = mxn*mxn;
int dp[mxn][mxn][mxn];
tuple<int,int,int> pre[mxn][mxn][mxn];
char preval[mxn][mxn][mxn];
string a,b;
int n,m;

int dfs(int ca,int cb,int sh){
	//cout<<ca<<' '<<cb<<' '<<sh<<endl;
	if(sh<0||sh>=mxn)return inf;
	if(dp[ca][cb][sh] != -1)return dp[ca][cb][sh];
	dp[ca][cb][sh] = inf;

	int pa=ca,pb = cb;

	//added (
	pa = ca,pb = cb;
	if(a[ca] == '(')pa = max(0,ca-1);
	if(b[cb] == '(')pb = max(0,cb-1);
	//cout<<ca<<' '<<cb<<' '<<sh<<":"<<pa<<' '<<pb<<endl;
	int val = dfs(pa,pb,sh-1);
	if(val+1<dp[ca][cb][sh]){
		dp[ca][cb][sh] = val+1;
		pre[ca][cb][sh] = make_tuple(pa,pb,sh-1);
		preval[ca][cb][sh] = '(';
	}

	pa = ca,pb = cb;
	if(a[ca] == ')')pa = max(0,ca-1);
	if(b[cb] == ')')pb = max(0,cb-1);
	//cout<<ca<<','<<cb<<' '<<sh<<":"<<pa<<' '<<pb<<endl;
	val = dfs(pa,pb,sh+1);
	if(val+1<dp[ca][cb][sh]){
		dp[ca][cb][sh] = val+1;
		pre[ca][cb][sh] = make_tuple(pa,pb,sh+1);
		preval[ca][cb][sh] = ')';
	}
	return dp[ca][cb][sh];
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>a>>b;
	n = a.size(),m = b.size();
	a = "#"+a;
	b = "#"+b;
	memset(dp,-1,sizeof(dp));
	dp[0][0][0] = 0;
	dfs(n,m,0);
	//cout<<dp[n][m][0]<<endl;
	tuple<int,int,int> now = make_tuple(n,m,0);
	string ans;
	while(get<0>(now)||get<1>(now)||get<2>(now)){
		//cout<<get<0>(now)<<' '<<get<1>(now)<<' '<<get<2>(now)<<endl;
		ans += preval[get<0>(now)][get<1>(now)][get<2>(now)];
		now = pre[get<0>(now)][get<1>(now)][get<2>(now)];
	}
	reverse(ans.begin(),ans.end());
	cout<<ans;
}
