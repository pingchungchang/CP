#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	string arr[n];
	for(auto &i:arr)cin>>i;
	vector<int> x,y;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(arr[i][j] == '*'){
				x.push_back(i);
				y.push_back(j);
			}
		}
	}
	sort(x.begin(),x.end());x.erase(unique(x.begin(),x.end()),x.end());
	sort(y.begin(),y.end());y.erase(unique(y.begin(),y.end()),y.end());
	//for(auto &i:x)cout<<i<<',';for(auto &i:y)cout<<i<<',';cout<<endl;
	if(x.size()<2){
		if(x[0] != 0)x.push_back(0);
		else x.push_back(1);
	}
	if(y.size()<2){
		if(y[0] != 0)y.push_back(0);
		else{
			y.push_back(1);
		}
	}
	for(auto &i:x){
		for(auto &j:y)arr[i][j] = '*';
	}
	for(auto &i:arr)cout<<i<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
