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
	string ans;
	for(auto it = s.rbegin();it != s.rend();it++){
		if(*it == '.')break;
		ans += *it;
	}
	for(auto it = ans.rbegin();it != ans.rend();it++)cout<<*it;
}
