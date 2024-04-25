#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
mt19937 seed(time(NULL));

#define rnd(l,r) uniform_int_distribution<int>(l,r)(seed)

const int mxn = 1ll<<20;
int arr[mxn<<1];
set<int> st[2][mxn];
int n;
const int inf = 1e9;

inline bool check(){
	for(int i = 0;i<n;i++)if(arr[i])return false;
	return true;
}

void whatever(){
	cin>>n;
	for(int i = 0;i<n;i++)st[0][i].insert(i);
	bool roll = 0;
	int C = 0;
	cout<<C<<":";for(auto &j:st[0][0])cout<<j<<' ';cout<<endl;
	for(int i = 1;i<=n;i++){
		roll ^= 1;
		for(int j = 0;j<n;j++)st[roll][j].clear();
		for(int j = 0;j+1<n;j++){
			st[roll][j] = st[roll^1][j];
			for(auto &k:st[roll^1][j+1]){
				if(st[roll][j].find(k) != st[roll][j].end())st[roll][j].erase(k);
				else st[roll][j].insert(k);
			}
		}
		st[roll][n-1] = st[roll^1][n-1];
		for(auto &k:st[roll^1][0]){
				if(st[roll][n-1].find(k) != st[roll][n-1].end())st[roll][n-1].erase(k);
				else st[roll][n-1].insert(k);
		}
		cout<<i<<":";for(auto &j:st[roll][0])cout<<j<<' ';cout<<endl;
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//whatever();exit(0);
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 0;i<n;i++)arr[i+n] = arr[i];
	int ans = 0;
	int h = __lg(n);
	for(int i = h-1;i>=0;i--){
		bool flag = true;
		for(int j = 0;j<n;j++){
			if(arr[j]^arr[j+(1<<i)])flag = false;
		}
		if(!flag){
			ans += 1<<i;
			for(int j = 0;j<n;j++)arr[j]^= arr[j+(1<<i)];
			for(int j = 0;j<n;j++)arr[j+n] = arr[j];
		}
	}
	bool flag = true;
	for(int i = 0;i<n;i++){
		if(arr[i])flag = false;
	}
	if(!flag)ans++;
	cout<<ans;
}
