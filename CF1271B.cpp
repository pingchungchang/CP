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
	string s;
	cin>>s;
	vector<int> v[2];
	for(int i = 0;i<n;i++){
		if(s[i] == 'W')v[0].push_back(i);
		else v[1].push_back(i);
	}
	vector<int> ans;
	if((v[0].size()&1)&&(v[1].size()&1)){
		cout<<"-1\n";
		return 0;
	}
	else if(v[1].size()&1){
		for(int i = 1;i<v[0].size();i+=2){
			for(int j = v[0][i-1];j<v[0][i];j++)ans.push_back(j);
		}
	}
	else{
		for(int i = 1;i<v[1].size();i+=2){
			for(int j = v[1][i-1];j<v[1][i];j++)ans.push_back(j);
		}
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i+1<<' ';
	return 0;
}

