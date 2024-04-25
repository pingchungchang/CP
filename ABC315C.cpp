#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	vector<int> v[n+1];
	for(int i = 0;i<n;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
	}
	vector<int> big;
	int ans = 0;
	for(auto &i:v){
		sort(i.rbegin(),i.rend());
		if(i.size()>=2){
			ans = max(ans,i[0]+i[1]/2);
		}
		if(!i.empty())big.push_back(i[0]);
	}
	sort(big.rbegin(),big.rend());
	if(big.size()>=2)ans = max(ans,big[0]+big[1]);
	cout<<ans;
}
