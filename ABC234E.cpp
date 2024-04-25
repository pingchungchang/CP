#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int main(){
	string s;
	cin>>s;
	string ans(18,'9');
	for(int d = -9;d<10;d++){
		string tmp;
		tmp += s[0];
		for(char k = tmp[0]+d;k>='0'&&k<='9'&&stoll(tmp)<stoll(s);k+=d)tmp += k;
		if(stoll(tmp)>=stoll(s)&&stoll(tmp)<stoll(ans))ans = tmp;
		if(s[0] != '9'){
			tmp = "";
			tmp += s[0]+1;
			for(char k = tmp[0]+d;k>='0'&&k<='9'&&stoll(tmp)<stoll(s);k+=d)tmp += k;
			if(stoll(tmp)>=stoll(s)&&stoll(tmp)<stoll(ans))ans = tmp;
		}
	}
	cout<<ans;
}

