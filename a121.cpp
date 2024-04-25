#include <bits/stdc++.h>
using namespace std;

int lst = 0;
string bd(vector<string> s){
	vector<vector<string>> v;
	vector<string> tmp;
	int nm = 0;
	for(int i = 1;i<s.size();i++){
		s[i] == "("?nm++:s[i] == ")"?nm--:0;
		tmp.push_back(s[i]);
		if(nm == 0){
			v.push_back(tmp);
			tmp.clear();
		}
	}
	if(v.size()!= 3||v[2].size() != 1)return "X";
	for(auto &it:v){
		if(it.size() != 1)it = {bd(it)};
		if(it[0] == "X")return "X";
	}
	int x,y;
	for(int i = 0;i<2;i++){
		tmp = v[i];
		for(int j = 0;j<tmp[0].size();j++){
			if(tmp[0][j]>'9'||tmp[0][j]<'0'){
				if(tmp[0][j] != '-')return "X";
			}
		}
		if(i == 0)x = stoi(tmp[0]);
		else y = stoi(tmp[0]);
	}
//	for(auto it:v)cout<<it[0]<<' ';
//	cout<<endl;
	if(v[2][0] == "*"){
		return to_string(x*y);
	}
	else if(v[2][0] == "/"){
		if(y == 0)return "X";
		else return to_string(x/y);
	}
	else if(v[2][0] == "+"){
		return to_string(x+y);
	}
	else if(v[2][0] == "-")return to_string(x-y);
	else return "X";
}
void solve(){
	string s;
	getline(cin,s);
	vector<int> pos;
	for(int i = 0;i<s.size();i++){
		if(s[i] == ')'||s[i] == '('){
			pos.push_back(i);
			pos.push_back(i+1);
		}
		else if(s[i] == ','){
			s[i] = ' ';
		}
	}
	for(int i = pos.size()-1;i>=0;i--){
		s.insert(s.begin()+pos[i],' ');
	}
	stringstream ss;
	ss.clear();
	ss<<s;
	vector<string> sss;
	string k;
	while(ss>>k){
		sss.push_back(k);
	}
	string returns = bd(sss);
	if(returns == "X")cout<<-1<<'\n';
	else cout<<returns<<'\n';
	return;
}
int main(){
	string in;
	getline(cin,in);
	int t = stoi(in);
	for(int i = 0;i<t;i++)solve();
}
