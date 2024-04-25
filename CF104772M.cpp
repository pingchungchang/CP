#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


string s,t;
string v = "aeiouyAEIUOY";

inline bool vow(char c){
	for(auto &j:v){
		if(j == c)return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s>>t;
	for(auto &i:s)if(i>='a'&&i<='z')i = 'A'+(i-'a');
	for(auto &i:t)if(i>='a'&&i<='z')i = 'A'+(i-'a');
	int pt = 0;
	for(int i = 0;i<t.size();i++){
		if(pt<t.size()&&s[pt] == t[i])pt++;
		else if(vow(t[i]))continue;
		else{
			cout<<"Different";
			return 0;
		}
	}
	cout<<"Same\n";
	return 0;
}
