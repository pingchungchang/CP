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
	int n;
	cin>>n;
	vector<int> v(n);
	for(auto &i:v)cin>>i;
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	cout<<v.end()[-2];
}
