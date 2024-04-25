#include <bits/stdc++.h>
using namespace std;
typedef struct Node{
    Node* front;
    Node* back;
    string value;
}Node;
int main(){
    string s;
    Node* start = new Node;
    Node* last = new Node;
    last->front = start;
    start->back = last;
    last->value = "";
    last->back = nullptr;
    start->value = "";
    start->front = nullptr;
    while(cin>>s){
        if(s == "ADD"){
            string k;
            cin>>k;
            Node* adding = new Node;
            adding->back = last;
            adding->front = last->front;
            last->front->back = adding;
            last->front = adding;
            adding->value = k;
        }
        else if(s == "INSERT"){
            string a,b;
            Node* adding = new Node;
            cin>>a>>b;
            adding->value = a;
            Node* finding = start;
            while(finding->value != b) finding = finding->back;
            Node* before = finding->front;
            before->back = adding;
            adding->front = before;
            adding->back = finding;
            finding->front = adding;
        }
        else if(s == "REMOVE"){
            string k;
            cin>>k;
            Node* finding = start;
            while(finding->value != k)finding = finding->back;
            Node* before = finding->front;
            Node* nextone = finding->back;
            before->back = nextone;
            nextone->front = before;
        }
        else{
            start = start->back;
            while(start->value != last->value){
                cout<<start->value<<' ';
                start = start->back;
            }
            return 0;
        }
    }   
}