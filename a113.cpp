#include <bits/stdc++.h>
using namespace std;

struct player{
	char id;
	queue<string> cards;
	player(){
		id = 'x';
	}
};
vector<player> v(4);
int dir;
int num = 0;
bool game(int now){
	string c = v[now].cards.front();
	v[now].cards.pop();
	if(c == "A"){
		num = 0;
		return true;
	}
	else if(c == "K"){
		num = 99;
		return true;
	}
	else if(c == "4"){
		dir = -dir;
		return true;
	}
	else if(c == "5"){
		return true;
	}
	else if(c == "10"){
		if(num+10>99)num -= 10;
		else num+= 10;
		return true;
	}
	else if(c == "J"){
		return true;
	}
	else if(c == "Q"){
		if(num+20>99)num -= 20;
		else num += 20;
		return true;
	}
	else if(c == "K"){
		num = 99;
		return true;
	}
	int x = stoi(c);
	if(num+x>99){
		cout<<v[now].id<<'\n'<<v[now].cards.size();
		return false;
	}
	else{
		num += x;
		return true;
	}
}
int main(){
	dir = 1;
	for(int i = 0;i<4;i++){
		char c;
		cin>>c;
		v[i].id = c;
		for(int j = 0;j<13;j++){
			string k;
			cin>>k;
			v[i].cards.push(k);
		}
	}
	int now = 0;
	while(game(now)){
		if(v[now].cards.empty()){
			cout<<v[now].id<<'\n'<<num;
			return 0;
		}
		now = (now+dir+4)%4;
	}
} 
