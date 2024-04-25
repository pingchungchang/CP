#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

vector<int> v;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	v.resize(n);
	for(int i =0;i<n;i++)cin>>v[i];
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	if(k>v.size())cout<<"NO RESULT";
	else cout<<v[k-1];
}
