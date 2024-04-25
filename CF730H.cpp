#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	string arr[n];
	for(auto &i:arr)cin>>i;
	vector<string> v;
	for(int i = 0;i<m;i++){
		int k;
		cin>>k;
		v.push_back(arr[k-1]);
	}
	string tar = v[0];
	for(auto &i:v){
		if(tar.size() != i.size()){
			cout<<"No";
			return 0;
		}
		for(int j = 0;j<tar.size();j++){
			if(i[j] != tar[j])tar[j] = '?';
		}
	}
	int C = 0;
	for(auto &i:arr){
		if(i.size() != tar.size())continue;
		bool flag = true;
		for(int j = 0;j<tar.size();j++){
			if(tar[j] == '?')continue;
			else if(tar[j] != i[j])flag = false;
		}
		C += flag;
	}
	if(C == m)cout<<"Yes\n"<<tar<<'\n';
	else cout<<"No";
	return 0;
}
