#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool isdigit(char c){
	if(c>='0'&&c<='9')return true;
	return false;
}
int main(){
	string s;
	string ans;
	cin>>s;
	char now = '#';
	string tmp;
	for(auto c:s){
		if(isdigit(c)){
			tmp += c;
		}
		else{
			if(tmp.size() == 0)ans += c;
			else{
				ll times = stoll(tmp);
				for(ll j= 0;j<times;j++)ans += c;
				tmp = "";
			}
		}
	}
	cout<<ans;
}

