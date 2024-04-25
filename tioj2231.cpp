#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define al3 array<int,3>

const int mxn = 2e5+10;
const int mask = 20;

ll B[mxn],W[mxn],T[mxn];
int N;
ll dp[2][mxn];
deque<al3> dq[2];

struct SPARSE{
	ll spt[mask][mxn];

	void build(ll arr[]){
		for(int i = 1;i<=N;i++)spt[0][i] = arr[i];
		for(int i = 1;i<mask;i++){
			for(int j = 1;j+(1<<i)-1<=N;j++){
				spt[i][j] = max(spt[i-1][j],spt[i-1][j+(1<<(i-1))]);
			}
		}
		return;
	}
	ll getval(int l,int r){
		int d = (r-l+1);
		d = __lg(d);
		return max(spt[d][l],spt[d][r-(1<<d)+1]);
	}

};

SPARSE S[2];

ll calc(int a,int b,int dir){
	if(!dir)return dp[1][a]-B[a]+S[0].getval(a+1,b);
	else return dp[0][a]-W[a]+S[1].getval(a+1,b);
}

int intersect(int a,int b,int l,int r,int dir){
	while(l != r){
		int mid = (l+r)>>1;
		if(calc(a,mid,dir)<=calc(b,mid,dir))r = mid;
		else l = mid+1;
	}
	//cerr<<"INTERSECT:"<<a<<' '<<b<<' '<<dir<<":"<<l<<endl;
	if(calc(a,l,dir)>calc(b,l,dir))return r+1;
	else return r;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 1;i<=N;i++)cin>>B[i],B[i] += B[i-1];
	for(int i = 1;i<=N;i++)cin>>W[i],W[i] += W[i-1];
	for(int i = 1;i<=N;i++)cin>>T[i],B[i] += T[i],W[i] += T[i];
	S[0].build(B);
	S[1].build(W);
	for(int i = 1;i<=N;i++)B[i] -= T[i],W[i] -= T[i];
	dq[0].push_back(al3({0,0,N}));
	dq[1].push_back(al3({0,0,N}));
	for(int i = 1;i<=N;i++){
		for(int j = 0;j<2;j++){
			while(dq[j].back()[2]<i)dq[j].pop_back();
			dp[j][i] = calc(dq[j].back()[0],i,j);
		}
		for(int j = 0;j<2;j++){
			int pre = N;
			while(!dq[j].empty()){
				if(i == N)break;
				if(dq[j].back()[2] == i||calc(dq[j].back()[0],dq[j].back()[2],j)>=calc(i,dq[j].back()[2],j)){
					//cerr<<"KILL:"<<dq[j].back()[0]<<' '<<i<<' '<<j<<','<<dq[j].back()[2]<<":"<<calc(dq[j].back()[0],dq[j].back()[2],j)<<','<<calc(i,dq[j].back()[2],j)<<endl;
					dq[j].pop_back();
				}
				else{
					pre = intersect(dq[j].back()[0],i,i+1,N,j);
					//if(pre>dq[j].back()[2])exit(0);
					assert(pre<=dq[j].back()[2]);
					dq[j].back()[1] = pre;
					pre--;
					break;
				}
			}
			if(pre>i)dq[j].push_back(al3({i,i+1,pre}));
			//cerr<<j<<' '<<i<<":";for(auto &k:dq[j])cerr<<k[0]<<','<<k[1]<<','<<k[2]<<' ';cerr<<endl;
		}
	}

	/*
	for(int i = 1;i<=N;i++)cout<<dp[0][i]<<' ';cout<<endl;
	for(int i = 1;i<=N;i++)cout<<dp[1][i]<<' ';cout<<endl;
   */
	ll ans = min(W[N],B[N]);
	for(int i = 1;i<=N;i++){
		ans = min({ans,dp[0][i]+W[N]-W[i],dp[1][i]+B[N]-B[i]});
	}
	cout<<ans;
}
