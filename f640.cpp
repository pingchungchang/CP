#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	vector<pair<int,char>> cals;
	while(cin>>s){
		if(s == "done")break;
		if(s.size()>1){
			cals.push_back(make_pair(stoi(s),'i'));
		}
		else{
			if(s[0]>'9'){
				cals.push_back(make_pair(1001,s[0]));
			}
			else cals.push_back(make_pair(s[0]-'0','i'));
		}
	}
	stack<int> inputs;
	for(int i = cals.size()-1;i>=0;i--){
		if(cals[i].second == 'i')inputs.push(cals[i].first);
		else{
			if(cals[i].second == 'f'){
				int x= inputs.top();
				inputs.pop();
				inputs.push(2*x-3);
			}
			else if(cals[i].second == 'g'){
				int x = inputs.top();
				inputs.pop();
				int y = inputs.top();
				inputs.pop();
				inputs.push(2*x+y-7);
			}
			else{
				int x = inputs.top();
				inputs.pop();
				int y = inputs.top();
				inputs.pop();
				int z= inputs.top();
				inputs.pop();
				inputs.push(3*x-2*y+z);
			}
		}
	}
	cout<<inputs.top();
}
//f(x) = 2x – 3
//g(x, y) = 2x +y – 7
//h(x, y, z) = 3x – 2y + z


