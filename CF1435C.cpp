#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e5+10;
ll arr[mxn];
int cnt[mxn],c = 0;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int ss[6];
	for(auto &i:ss)cin>>i;
	vector<pii> v;
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		for(auto &j:ss){
			v.push_back({arr[i]-j,i});
		}
	}
	sort(v.begin(),v.end());
	int ans = 1e9;
	int p = 0;
	for(int i = 0;i<v.size();i++){
		while(p<v.size()&&c != n){
			if(!cnt[v[p].sc])c++;
			cnt[v[p].sc]++;
			p++;
		}
		if(c == n){
			ans = min(ans,v[p-1].fs-v[i].fs);
		}
		cnt[v[i].sc]--;
		if(!cnt[v[i].sc])c--;
	}
	cout<<ans;
}
