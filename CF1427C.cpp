#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>

const int mxn = 1e5+10;

vector<tuple<int,int,int>> cnt[mxn];

inline bool check(tuple<int,int,int> &a,tuple<int,int,int> &b){
	return abs(get<0>(a)-get<0>(b))+abs(get<1>(a)-get<1>(b))<=get<2>(b)-get<2>(a);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cnt[0].push_back(make_tuple(1,1,0));
	int r,n;
	cin>>r>>n;
	int pre = 0;
	int mx = 0;
	for(int i = 0;i<n;i++){
		tuple<int,int,int> now;
		cin>>get<2>(now)>>get<0>(now)>>get<1>(now);
		bool flag = false;
		for(int j = mx;j>=0;j--){
			if(flag)break;
			for(auto &k:cnt[j]){
				if(check(k,now)){
					cnt[j+1].push_back(now);
					mx = max(mx,j+1);
					flag = true;
					break;
				}
			}
		}
	}
	cout<<mx;
}
