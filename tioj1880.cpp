#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


const int mxn = 1e5+10;
const int mod = 1e6+7;
vector<int> paths[mxn];
int col[mxn];

bool check(int now,int c = 1){
	if(col[now]){
		if(col[now] != c)return false;
		else return true;
	}
	col[now] = c;
	bool re = 1;
	for(auto nxt:paths[now]){
		re = re&&check(nxt,3-c);
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	int ans = 1;
	bool flag = false;
	for(int i = 1;i<=n;i++){
		if(!col[i]){
			if(check(i)){
				if(flag)ans = ans*2%mod;
				flag = true;
			}
			else ans = 0;
		}
	}
	cout<<ans;
}
