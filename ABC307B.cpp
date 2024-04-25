#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

bool isp(string s){
	for(int i = 0;i<s.size();i++){
		if(s[i] != s[s.size()-1-i])return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	string arr[n];
	for(auto &i:arr)cin>>i;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(i == j)continue;
			string s = arr[i]+arr[j];
			if(isp(s)){
				cout<<"Yes";
				return 0;
			}
		}
	}
	cout<<"No";
	return 0;
}
