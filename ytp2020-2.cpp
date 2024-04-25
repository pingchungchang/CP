#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	io
	string s;
	cin>>s;
	vector<string> v(3,"");
	int now = 0;
	for(int i = 2;i<s.size();i++){
		if(s[i] == ',')now++;
		else v[now] += s[i];
	}
	if(s[0] == '1'){
		if(v[0].size() == 0||v[1].size() == 0){
			if(v[1].size() == 0)swap(v[0],v[1]);
			cout<<(int)sqrt(stoi(v.back())*stoi(v.back())-stoi(v[1])*stoi(v[1]));
		}
		else cout<<(int)(sqrt(stoi(v[0])*stoi(v[0])+pow(stoi(v[1]),2)));
	}
	else if(s[0] == '2'){
		if(v[0].size() == 0||v[1].size() == 0){
			if(v[1].size() == 0)swap(v[0],v[1]);
			cout<<(int)(stoi(v.back())/2.0+stoi(v[1]));
		}
		else{
			cout<<(int)(stoi(v[0])-stoi(v[1]))*2;
		}
	}
	else{
		if(v[0].size() == 0||v[1].size() == 0){
			if(v[1].size() == 0)swap(v[0],v[1]);
			cout<<stoi(v[2])/stoi(v[1]);
		}
		else{
			cout<<stoi(v[1])*stoi(v[0]);
		}
	}
}

