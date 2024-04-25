#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define ld long double

const int mxn = 11;
int arr[mxn][mxn];
ld dp[2][mxn][mxn];
deque<ld> dq;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i  = 0;i<10;i++){
		for(int j = 0;j<10;j++)cin>>arr[i][j],dp[0][i][j] = dp[1][i][j] = 0;
	}
	dq.push_back(0.0);
	for(int i = 0;i<10;i++){
		int l,r,dir;
		if(!i)l = 1,r = 10,dir = 1;
		else if(i&1)l = 9,r = -1,dir = -1;
		else l = 0,r = 10,dir = 1;
		for(int j = l;j!=r;j+=dir){
			ld sum = 0;
			int sh = 0;
			//cout<<i<<' '<<j<<":"<<sum<<' '<<sh<<' '<<":";
			for(int k = 1;k<=6;k++){
				if(k>dq.size())sh++;
				else sum += dq[dq.size()-k];
			}
			//cout<<endl;
			ld tmp = (sum+6)/(6-sh);
			dp[0][i][j] = dp[1][i][j] = tmp;
			if(arr[i][j])dp[1][i][j] = min(dp[1][i][j],dp[0][i-arr[i][j]][j]);
			dq.push_back(dp[1][i][j]);
			//assert(dp[0][i][j] == dp[1][i][j]);
		}
	}
	/*
	for(int i = 0;i<10;i++){
		for(int j = 0;j<10;j++)cout<<setw(10)<<dp[1][i][j]<<' ';cout<<endl;
	}

   */
	cout<<fixed<<setprecision(10)<<dp[0][9][0];
}
/*
dp[i] = sum(dp[k]*1/6)+1;
(1-sh/6)dp[i] = sum(dp[k]*1/6)+1;
dp[i] = sum/(6-sh)+6/(6-sh);
*/
