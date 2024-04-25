#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
void rec(int val,int t,vector<int> v,int now){
//	cout<<val<<' '<<t<<' '<<now<<';';
//	for(auto i:v)cout<<i<<' ';
//	cout<<endl;
	if(t == 1){
		int k = sqrt(val);
		if(k*k == val&&k<=now){
			v.push_back(k);
			ans.push_back(v);
			return;
		}
	}
	for(int i = min(now,(int)sqrt(val));i*i*t>=val;i--){
		vector<int> tmp = v;
		tmp.push_back(i);
		if(val-i*i>0)rec(val-i*i,t-1,tmp,i);
	}
}
int main(){
	int k;
	cin>>k;
	int now = (1<<k);
	rec(now,4,{},sqrt(now));
	for(int i = 0;i<ans.size();i++)sort(ans[i].begin(),ans[i].end());
	sort(ans.begin(),ans.end());
	if(ans.size()==0)cout<<0;
	for(int i = 0;i<ans.size();i++){
		for(int j= 0;j<4;j++)cout<<ans[i][j]<<' ';
		cout<<'\n';
	}
	return 0;
}
