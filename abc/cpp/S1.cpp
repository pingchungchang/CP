#include "abc.h"
#include <bits/stdc++.h>
using namespace std;

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


// Alice
int // returns la
alice(
    /*  in */ const int n,
    /*  in */ const char names[][5],
    /*  in */ const unsigned short numbers[],
    /* out */ bool outputs_alice[]
) {
	for(int i = 0;i<16;i++){
		if(numbers[0]&(1<<i))outputs_alice[i] = 1;
		else outputs_alice[i] = 0;
	}
	return 16;
}


// Bob
int // returns lb
bob(
    /*  in */ const int m,
    /*  in */ const char senders[][5],
    /*  in */ const char recipients[][5],
    /* out */ bool outputs_bob[]
) {
	for(int i = 0;i<10;i++){
		if(m&(1<<i))outputs_bob[i] = 1;
		else outputs_bob[i] = 0;
	}
	return 10;
}


// Circuit

int ptr = 0;
int ZERO,ONE;
function<int(int,int,int)> ADD_OP;
function<pii(int,int)> HALF_ADDER;
function<pii(int,int,int)> FULL_ADDER;


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
	ZERO = ADD_OP(0,0,OP_ZERO);
	ONE = ADD_OP(0,0,OP_ONE);

	struct NUM{
		int pos[16];
		NUM(){memset(pos,-1,sizeof(pos));}
		NUM operator+(NUM b)const{
			NUM re;
			int cry = 0;
			for(int i = 0;i<16;i++){
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
		NUM operator*(NUM b)const{//16bit*10bit
			NUM re;
			for(int i = 0;i<16;i++)re.pos[i] = ZERO;
			for(int i = 0;i<10;i++){
				int cry = ZERO;
				for(int j = 0;j<16;j++){
					if(i+j>=16)break;
					if(i+j == 15){
						re.pos[i+j] = ADD_OP(ADD_OP(re.pos[i+j],cry,OP_XOR),ADD_OP(pos[j],b.pos[i],OP_AND),OP_XOR);
					}
					else{
						auto [ta,tb] = FULL_ADDER(re.pos[i+j],cry,ADD_OP(pos[j],b.pos[i],OP_AND));
						cry = tb;
						re.pos[i+j] = ta;
					}
				}
			}
			return re;
		}
	};


	NUM a,b;
	for(int i = 0;i<la;i++)a.pos[i] = i;
	for(int i = 0;i<lb;i++)b.pos[i] = i+la;
	NUM re = a*b;
	for(int i = 0;i<16;i++)outputs_circuit[0][i] = re.pos[i];
	return ptr;
}
