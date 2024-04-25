#include <bits/stdc++.h>
using namespace std;

string encode(int n){
	string ans;
	for(int i = 2;i>=0;i--){
		if((1<<i)&n){
			ans += '1';
		}
		else ans += '0';
	}
	return ans;
}
int getint(string s){
	int returns;
	int point;
	for(int i = 0;i<s.size();i++){
		if(s[i] == '.'){
			point = i;
			break;
		}
	}
	returns = stoi(s.substr(0,point));
	if(s[point+1]>='5')returns++;
	return returns;
}
void solve(){
	string s;
	getline(cin,s);
//	cout<<s<<endl;
//	return;
	for(char c:s){
		if(c != '0'&&c != '1'){
			cout<<-1<<'\n';
			return;
		}
	}
	int now = s[0]-'0';
	deque<pair<int,int>> dq;
	dq.push_back(make_pair(now,1));
	for(int i = 1;i<s.size();i++){
		if(dq.back().first == s[i]-'0'&&dq.back().second<7)dq.back().second++;
		else{
			now = s[i]-'0';
			dq.push_back(make_pair(now,1));
		}
	}
	int ans = 0;
	while(!dq.empty()){
		ans += 4;
		cout<<dq.front().first<<encode(dq.front().second)<<' ';
		dq.pop_front();
	}
	double xx = (double)ans*100/(double)s.size();
	string sss = to_string(xx);
	cout<<getint(sss)<<"%";
	cout<<'\n';
	return;
}
int main(){
	int t;
	string b;
	getline(cin,b);
	t = stoi(b);
	for(int i = 0;i<t;i++)solve();
}
