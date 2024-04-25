#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string ans(26,'#');
	for(int i = 0;i<26;i++){
		int p;
		cin>>p;
		cout<<(char)(p+'a'-1);
	}
	return 0;
}
