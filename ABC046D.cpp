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
	string s;
	cin>>s;
	n = s.size();
	int c = 0;
	int ans = n/2;
	for(auto &i:s)if(i == 'p')ans--;
	cout<<ans;
}
