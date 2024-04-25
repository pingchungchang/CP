#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int ans =0;
	int choice[n] = {0};
	for(int i=0;i<n;i++){
		for(int j =0;j<m;j++){
			int k;
			cin>>k;
			choice[i] = max(choice[i],k);
		}
		ans+= choice[i];
	}
	cout<<ans<<'\n';
	vector<int> v;
	for(int i =0;i<n;i++){
		if(ans%choice[i] == 0){
			v.push_back(choice[i]);
		}
	}
	if(v.size()==0)v.push_back(-1);
	for(int i =0;i<v.size();i++){
		cout<<v[i];
		if(i != v.size()-1)cout<<' ';
	}
}
