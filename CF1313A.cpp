#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int a,b,c;
	cin>>a>>b>>c;
	vector<int> v;
	for(int i = 1;i<8;i++)v.push_back(i);
	vector<int> vvv = {a,b,c};
	int ans = 0;
	do{
		int tans = 0;
		auto tmp = vvv;
		for(auto &i:v){
			vector<int> vv;
			bool flag = true;
			for(int j = 0;j<3;j++){
				if((1<<j)&i){
					if(tmp[j] == 0)flag = false;
				}
			}
			if(!flag)continue;
			for(int j = 0;j<3;j++){
				if((1<<j)&i)tmp[j]--;
			}
			tans++;
		}
		ans = max(ans,tans);
	}while(next_permutation(v.begin(),v.end()));
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
