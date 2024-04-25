#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


string parse(string s){
	string re;
	for(int i = 0;i<s.size();i+=2){
		re += (s[i] == '8'?'S':s[i] == '['?'P':'R');
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string in;
	cin>>in;
	string a = parse(in);
	cin>>in;
	string b = parse(in);
	int c = 0;
	for(int i = 0;i<a.size();i++){
		if(a[i] == b[i])continue;
		else if(a[i] == 'P'&&b[i] == 'R')c++;
		else if(a[i] == 'R'&&b[i] == 'S')c++;
		else if(a[i] == 'S'&&b[i] == 'P')c++;
		else c--;
	}
	cout<<(!c?"TIE":c>0?"TEAM 1 WINS":"TEAM 2 WINS");
}
