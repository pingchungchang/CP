#include <bits/stdc++.h>
using namespace std;

int turn = 0;
vector<int> points(2,0);
queue<int> bag;
int outs = 0;

void init(){
	outs = 0;
	while(!bag.empty())bag.pop();
	for(int i = 0;i<3;i++)bag.push(0);
}
void solve(string &s){
	init();
	turn =0;
	points = {0,0};
	outs = 0;
	for(int i = 0;i<s.size();i++){
		if(s[i] == 'O'||s[i] == 'K'){
			outs++;
			if(outs == 3){
				outs = 0;
				turn = (turn +1)%2;
				init();
			}
			continue;
		}
		if(s[i] == 'S'){
			points[turn]+= bag.front();
			bag.pop();
			bag.push(1);
			continue;
		}
		if(s[i] == 'W'){
			vector<int> sit;
			while(!bag.empty()){
				sit.push_back(bag.front());
				bag.pop();
			}
			if(sit[2] == 0)sit[2] = 1;
			else if(sit[2] == 1){
				if(sit[1] == 0)sit[1] = 1;
				else{
					if(sit[0] == 0)sit[0] = 1;
					else points[turn]++;
				}
			}
			for(int i = 0;i<3;i++)bag.push(sit[i]);
			continue;
		}
		if(s[i] == 'D'){
			for(int i = 0;i<2;i++){
				points[turn]+= bag.front();
				bag.pop();
			}
			bag.push(1);
		}
		else if(s[i] == 'T'){
			for(int i =0;i<3;i++){
				points[turn]+= bag.front();
				bag.pop();
			}
			bag.push(1);
		}
		else if(s[i] == 'H'){
			while(!bag.empty()){
				points[turn]+= bag.front();
				bag.pop();
			}
			points[turn]+=1;
		}
		while(bag.size()!=3)bag.push(0);
	}
	cout<<points[0]<<' '<<points[1]<<'\n';
}

//WSDTHO
int main(){
	string s;
	while(cin>>s){
		solve(s);
	}
}
