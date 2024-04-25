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
	vector<ll> v = {1ll};
	for(int i = 0;i<35;i++){
		if(v.back() == 4096)v.push_back(8092);
		else v.push_back(v.back()<<1);
	}
	int n;
	cin>>n;
	cout<<v[n];
}
