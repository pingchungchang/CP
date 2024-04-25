#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
int pre[mxn],arr[mxn],brr[mxn];
int n;
vector<int> ans;
int sparse[mxn][20];

void build(){
	for(int i = 1;i<=n;i++)sparse[i][0] = pre[i];
	for(int i = 1;i<20;i++){
		for(int j = 1;j+(1<<i)<=n+1;j++){
			sparse[j][i] = min(sparse[j][i-1],sparse[j+(1<<(i-1))][i-1]);
		}
	}
	return;
}

int getval(int l,int r){
	int h = 0,d = r-l+1;
	while(d)d>>=1,h++;
	h--;
	return min(sparse[l][h],sparse[r-(1<<h)+1][h]);
}

void solve(){
	for(int i = 0;i<=n;i++)pre[i] = mxn;
	cin>>n;
	ans.clear();
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++)cin>>brr[i];
	for(int i = 1;i<=n;i++)pre[arr[i]] = min(pre[arr[i]],brr[i]);
	build();
	for(int i = 1;i<=n;i++){
		bool flag = true;
		for(int l = 1;l<=n;l+=i){
			int r = min(l+i,n);
			if(getval(l,r)<l)flag = false;
		}
		if(flag)ans.push_back(i);
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(auto &i:pre)i = mxn;
	n = 1e5;
	int t;cin>>t;
	while(t--)solve();
}
