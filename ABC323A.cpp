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
	string s;
	cin>>s;
	for(int i = 1;i<s.size();i+=2){
		if(s[i] != '0'){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}
