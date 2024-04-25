#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;

int main(){
    string k;
    string s;
    while (getline(cin,s)){
        k += s;
    }
    int arr[26];
    int pangram = 1;
    if(k.size()>=26){
        for (int i = 0; i < k.size();i++){
            if(k[i]!=' '){
                if(k[i]-'a'>=0){
                    arr[k[i] - 'a'] = 1;
                }
                else{
                    arr[k[i] - 'A'] = 1;
                }
            }
        }
        for (int i = 0; i <= 25;i++){
            if(arr[i]!=1){
                pangram = 0;
            }
        }
        if(pangram == 1){
            cout << "pangram";
        }
        else{
            cout << "not pangram";
        }
    }
    else cout<<"not pangram";
}
// the input of the question is unusual