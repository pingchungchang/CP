#include "abc.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> OUT;

#define pii pair<int,int>
#define fs first
#define sc second
// you may find the definitions useful
const int OP_ZERO    = 0;  // f(OP_ZERO,    x0, x1) = 0
const int OP_NOR     = 1;  // f(OP_NOR,     x0, x1) = !(x0 || x1)
const int OP_GREATER = 2;  // f(OP_GREATER, x0, x1) = (x0 > x1)
const int OP_NOT_X1  = 3;  // f(OP_NOT_X1,  x0, x1) = !x1
const int OP_LESS    = 4;  // f(OP_LESS,    x0, x1) = (x0 < x1)
const int OP_NOT_X0  = 5;  // f(OP_NOT_X0,  x0, x1) = !x0
const int OP_XOR     = 6;  // f(OP_XOR,     x0, x1) = (x0 ^ x1)
const int OP_NAND    = 7;  // f(OP_NAND,    x0, x1) = !(x0 && x1)
const int OP_AND     = 8;  // f(OP_AND,     x0, x1) = (x0 && x1)
const int OP_EQUAL   = 9;  // f(OP_EQUAL,   x0, x1) = (x0 == x1)
const int OP_X0      = 10; // f(OP_X0,      x0, x1) = x0
const int OP_GEQ     = 11; // f(OP_GEQ,     x0, x1) = (x0 >= x1)
const int OP_X1      = 12; // f(OP_X1,      x0, x1) = x1
const int OP_LEQ     = 13; // f(OP_LEQ,     x0, x1) = (x0 <= x1)
const int OP_OR      = 14; // f(OP_OR,      x0, x1) = (x0 || x1)
const int OP_ONE     = 15; // f(OP_ONE,     x0, x1) = 1


int HASH(const char name[]){
	int sz = 0;
	while(name[sz] != '\0')sz++;
	//cout<<sz<<":";for(int i = 0;i<sz;i++)cout<<name[i];cout<<endl;
	if(sz == 1)return name[0]-'a';
	else if(sz == 2)return 26+(name[0]-'a')+26*(name[1]-'a');
	else if(sz == 3)return 26+26*26+(name[0]-'a')+26*(name[1]-'a')+26*26*(name[2]-'a');
	else return 26+26*26+26*26*26+(name[0]-'a')+26*(name[1]-'a')+26*26*(name[2]-'a')+26*26*26*(name[3]-'a');
}


// Alice
int // returns la
alice(
    /*  in */ const int n,
    /*  in */ const char names[][5],
    /*  in */ const unsigned short numbers[],
    /* out */ bool outputs_alice[]
) {
	int la = 0;
	for(int i = 0;i<n;i++){
		int namae = HASH(names[i]);
		int num = 0;
		for(int j = 0;j<19;j++){
			if(namae&(1<<j))outputs_alice[la++] = 1;
			else outputs_alice[la++] = 0;
		}
		for(int j = 0;j<16;j++){
			if(numbers[i]&(1<<j))outputs_alice[la++] = 1;
			else outputs_alice[la++] = 0;
		}
	}
	return la;
}


// Bob
int // returns lb
bob(
    /*  in */ const int m,
    /*  in */ const char senders[][5],
    /*  in */ const char recipients[][5],
    /* out */ bool outputs_bob[]
) {
	int lb = 0;
	vector<pair<int,int>> edges;
	vector<int> v;
	for(int i = 0;i<m;i++){
		int a = HASH(senders[i]),b = HASH(recipients[i]);
		v.push_back(a);v.push_back(b);
		edges.push_back({a,b});
	}
	sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
	for(int i = 0;i<v.size();i++){
		for(int j = 0;j<19;j++){
			if(v[i]&(1<<j))outputs_bob[lb++] = 1;
			else outputs_bob[lb++] = 0;
		}
	}
	vector<vector<int>> grid(v.size(),vector<int>(v.size(),0));
	for(auto &i:edges){
		i.fs = lower_bound(v.begin(),v.end(),i.fs)-v.begin();
		i.sc = lower_bound(v.begin(),v.end(),i.sc)-v.begin();
		grid[i.fs][i.sc]++;
	}
	for(int i = 0;i<v.size();i++){
		for(int j = 0;j<v.size();j++){
			if(grid[i][j])outputs_bob[lb++] = 1;
			else outputs_bob[lb++] = 0;
		}
	}
	return lb;
}


// Circuit

int N;
int ptr = 0;
int ZERO,ONE;
function<int(int,int,int)> ADD_OP;
function<pii(int,int)> HALF_ADDER;
function<pii(int,int,int)> FULL_ADDER;
function<int(vector<int>,vector<int>)> EQUAL;
function<void(int,int,int)> ADDANS;


int // returns l
circuit(
    /*  in */ const int la,
    /*  in */ const int lb,
    /* out */ int operations[],
    /* out */ int operands[][2],
    /* out */ int outputs_circuit[][16]
) {

	ptr = la+lb;
	ADD_OP = [&](int a,int b,int op){
		operands[ptr][0] = a,operands[ptr][1] = b,operations[ptr] = op;
		return ptr++;
	};
	HALF_ADDER = [&](int a,int b){//{val,carry}
		return pii(ADD_OP(a,b,OP_XOR),ADD_OP(a,b,OP_AND));
	};
	FULL_ADDER = [&](int a,int b,int c){//{val,carry}
		auto [ta,tb] = HALF_ADDER(a,b);
		auto [tc,td] = HALF_ADDER(ta,c);
		return pii(tc,ADD_OP(td,tb,OP_OR));
	};
	EQUAL = [&](vector<int> a,vector<int> b){
		assert(a.size() == b.size()&&a.size() == 19);
		int re = ONE;
		for(int i = 0;i<a.size();i++){
			re = ADD_OP(re,ADD_OP(a[i],b[i],OP_EQUAL),OP_AND);
		}
		return re;
	};
	ZERO = ADD_OP(0,0,OP_ZERO);
	ONE = ADD_OP(0,0,OP_ONE);

	struct NUM{
		int pos[16];
		NUM(){
			for(int i = 0;i<16;i++)pos[i] = ZERO;
			return;
		}
		NUM operator+(NUM b)const{
			NUM re;
			int cry = 0;
			for(int i = 0;i<15;i++){
				auto [ta,tb] = HALF_ADDER(pos[i],b.pos[i]);
				if(!cry){
					cry = tb;
					re.pos[i] = ta;
				}
				else{
					auto [tc,td] = HALF_ADDER(cry,ta);
					re.pos[i] = tc;
					cry = ADD_OP(tb,td,OP_OR);
				}
			}
			re.pos[15] = ADD_OP(ADD_OP(pos[15],b.pos[15],OP_XOR),cry,OP_XOR);
			return re;
		}
	};

	vector<NUM> ans;

	ADDANS = [&](int from,int to,int c){
		NUM val = NUM();
		vector<int> tar;
		for(int i = 0;i<19;i++)tar.push_back(la+from*19+i);
		for(int i = 0;i<N;i++){
			vector<int> tmp;
			for(int j = 0;j<19;j++)tmp.push_back(i*35+j);
			int b = EQUAL(tar,tmp);
			b = ADD_OP(c,b,OP_AND);
			for(int j = 0;j<16;j++){
				int t = ADD_OP(b,i*35+19+j,OP_AND);
				val.pos[j] = ADD_OP(val.pos[j],t,OP_OR);
			}
		}
		tar.clear();
		for(int i = 0;i<19;i++)tar.push_back(la+to*19+i);
		for(int i = 0;i<N;i++){
			vector<int> tmp;
			for(int j = 0;j<19;j++)tmp.push_back(i*35+j);
			int b = EQUAL(tar,tmp);
			b = ADD_OP(c,b,OP_AND);
			NUM s = val;
			for(int j = 0;j<16;j++){
				s.pos[j] = ADD_OP(s.pos[j],b,OP_AND);
			}
			ans[i] = ans[i]+s;
		}
		return;
	};

	assert(la%35 == 0);
	N = la/35;
	for(int i = 0;i<N;i++){
		ans.push_back(NUM());
	}
	int shift = la+N*19;
	for(int i = 0;i<N;i++){
		for(int j = 0;j<N;j++){
			ADDANS(i,j,shift+i*N+j);
		}
	}
	for(int i = 0;i<N;i++){
		for(int j = 0;j<16;j++)outputs_circuit[i][j] = ans[i].pos[j];
	}
	return ptr;
}
