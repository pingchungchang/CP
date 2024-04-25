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
	cin>>n>>s;
	int flag = 0;
	for(int i = 0;i<n;i++){
		flag |= 1<<(s[i]-'A');
		if(flag == 7){
			cout<<i+1;
			return 0;
		}
	}
}
