#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


bool check(int m,int d){
	string s = to_string(m)+to_string(d);
	for(int i = 1;i<s.size();i++){
		if(s[i] != s[0])return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int ans =0;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		for(int j = 1;j<=k;j++){
			ans += check(i,j);
		}
	}
	cout<<ans;
}
