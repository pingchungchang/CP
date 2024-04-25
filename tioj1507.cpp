#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool bigger(string a,string b){
	if(a.size()>b.size())return true;
	else if(a.size()<b.size())return false;
	else return a>=b;
}
string add(string a,string b){
	while(a.size()<b.size())a = '0'+a;
	while(b.size()<a.size()) b = '0'+b;
	int mv = 0;
	string ans;
	for(int i = a.size()-1;i>=0;i--){
		int c = a[i]-'0'+b[i]-'0';
		c += mv;
		mv = c/10;
		ans += (char)(c%10+'0');
	}
	if(!mv)ans += (char)(mv%10+'0');
	reverse(ans.begin(),ans.end());
	return ans;
}
string minus(string a,string b){
	while(b.size()<a.size())b = '0'+b;
	string ans;
	int mv = 0;
	for(int i = a.size()-1;i>=0;i--){
		if(a[i]<b[i]){
			a[i-1]--;
			ans += 10+a[i]-b[i];
		}
		else ans += a[i]-b[i];
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
string smult(string a,int b){
	int mv = 0;
	string ans;
	for(int i = a.size()-1;i>=0;i--){
		int c = mv+(a[i]-'0')*b;
		mv = c/10;
		ans += '0'c%10
	}
	if(!mv)ans += '0'+mv;
	reverse(ans.begin(),ans.end());
	return ans;
}
string mult(string a,string b){
	
	for(int i = b.size()-1;i>=0;i--){
		
	}
}
int main(){
}

