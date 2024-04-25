#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int main(){
	io
	int n,m;
	cin>>n>>m;
	set<int> st[m];
	for(int i = 0;i<m;i++){
		int k;
		cin>>k;
		while(k--){
			int x;
			cin>>x;
			st[i].insert(x);
		}
	}
	bool ans = true;
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			bool flag = false;
			for(auto &tmp:st){
				if(tmp.find(i) != tmp.end()&&tmp.find(j) != tmp.end())flag = true;
			}
			if(!flag)ans = false;
		}
	}
	if(ans)cout<<"Yes";
	else cout<<"No";
}

