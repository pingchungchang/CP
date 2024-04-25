#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int k,a,b;
	cin>>k>>a>>b;
	vector<int> va(a),vb(b);
	for(int i = 0;i<a;i++)cin>>va[i];
	for(int i = 0;i<b;i++)cin>>vb[i];
	int p1 = 0,p2 = 0;
	vector<int> ans;
	int tmp = k;
	while(p1 != a||p2 != b){
		bool flag = false;
		while(p1 != a&&va[p1]<=k){
			if(va[p1] == 0)k++;
			ans.push_back(va[p1++]);
			flag = true;
		}
		while(p2 != b&&vb[p2]<=k){
			if(vb[p2] == 0)k++;
			ans.push_back(vb[p2++]);
			flag = true;
		}
		if(!flag)break;
	}
//	for(auto &i:ans){
//		if(i == 0)tmp++;
//		if(tmp<i)flag = false;
//	}
	if(ans.size() != a+b){
		cout<<"-1\n";
		return;
	}
	for(auto i:ans)cout<<i<<' ';cout<<'\n';
//	cout<<ans.size()<<'\n'<<'\n';
	return;
}

int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

