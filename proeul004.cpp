#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

bool check(int k){
	string s = to_string(k);
	string t = s;
	reverse(s.begin(),s.end());
	return s== t;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int ans = 0;
	for(int i = 101;i<1000;i++){
		for(int j = 101;j<1000;j++){
			if(check(i*j))ans = max(ans,i*j);
		}
	}
	cout<<ans;
}
