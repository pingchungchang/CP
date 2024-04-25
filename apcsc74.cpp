#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define all(T) T.begin(),T.end()

string f(vector<string>& ops){
	int tmp = 0;
	string operation = "";
//	for(auto i:ops)cout<<i;cout<<endl;
	for(auto &i:ops){
//		cout<<tmp<<',';
		if(i == "+"||i == "-")operation = i;
		else{
//			cout<<i<<endl<<endl;
			if(operation.empty())tmp = stoi(i);
			else{
				if(operation == "+")tmp += stoi(i);
				else tmp -= stoi(i);
				operation = "";
			}
		}
	}
//	cout<<"x\n";
	return to_string(tmp);
}
int main(){
//	io
	string s;
	getline(cin,s);
	stringstream ss(s);
	stack<string> st;
	string in;
	while(ss>>in){
//		cout<<in<<endl;
		if(in == "("){
			st.push("(");
		}
		else if(in == ")"){
			vector<string> ops;
			while(st.top() != "("){
				ops.push_back(st.top());
				st.pop();
			}
			st.pop();
			reverse(all(ops));
			st.push(f(ops));
		}
		else{
			st.push(in);
		}
	}
	vector<string> v;
	while(!st.empty()){
		v.push_back(st.top());
		st.pop();
	}
	reverse(all(v));
	cout<<f(v);
}

