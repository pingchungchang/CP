#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> v(m);
	for(int i = 0;i<m;i++)cin>>v[i];
	vector<vector<int>> all(n+1);
	for(int i = 0;i<m;i++){
		int k = v[i];
		all[k].push_back(i);
	}
	for(int i = 0;i<=n;i++)all[i].push_back(INT_MAX);
	int ans =0;
	for(int i = 1;i<=n;i++){
		int dif = ans;
		if(all[i].size()==1)ans++;
		int pos = all[i][0];
		if(i != n&&lower_bound(all[i+1].begin(),all[i+1].end(),pos)==all[i+1].end()-1){
			ans++;
		}
		if(i != 1&&lower_bound(all[i-1].begin(),all[i-1].end(),pos) == all[i-1].end()-1)ans++;
//		cout<<i<<' '<<ans-dif<<' '<<endl;
	}
	cout<<ans;
}
