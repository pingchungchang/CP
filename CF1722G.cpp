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
void solve(){
	int n;
	cin>>n;
	if(n == 3){
		cout<<"1 2 3\n";
		return;
	}
	vector<int> ans[2];
	for(int i = 1;i<=n/2;i++){
		ans[0].push_back(i);
		ans[1].push_back(i^(1<<28));
	}
	if(n%4 == 1)ans[0].push_back(0);
	if(n%4 == 2||n%4 == 3){
		ans[0].back() = (n/4*4+4);
		ans[1].back() = ((n/4*4+4)^(1<<27));
		ans[0][0]^= (1<<27);
	}
	if(n%4 == 3){
		ans[0].push_back(0);
	}
	int tmp[2] = {};
	for(int i = 0;i<n;i++){
		cout<<ans[i&1].back()<<' ';
		tmp[i&1]^=ans[i&1].back();
		ans[i&1].pop_back();
	}
	cout<<'\n';
//	cout<<tmp[0]<<' '<<tmp[1]<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

