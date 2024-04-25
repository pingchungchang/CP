#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	io
	int n;
	cin>>n;
//	if(n == 2){
//		cout<<"5\n0 0 1 1 0";
//		return 0;
//	}
	vector<int> ans;
	for(int i = 0;i<n;i++){
		ans.push_back(i);
		for(int j = i+1;j<n;j++){
			ans.push_back(i);
			ans.push_back(j);
		}
	}
	ans.push_back(0);
	cout<<ans.size()<<'\n';
	for(auto i:ans)cout<<i<<' ';
}

