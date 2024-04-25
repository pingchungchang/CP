#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int n;
	cin>>n;
	vector<int> v(3,0);
	for(int i = 0;i<n;i++)for(int j = 0;j<3;j++){
		int k;
		cin>>k;
		v[j] +=k;
	}
	if(v[0] == v[1]&&v[1]==v[2]&&v[0] == 0){
		cout<<"YES";
	}
	else cout<<"NO";
}

