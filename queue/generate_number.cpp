#include<bits/stdc++.h>
using namespace std;

void generatenum(int a,int b,int count){
  queue<string>q;
  q.push(to_string(a));
  q.push(to_string(b));
  for(int i=0;i<count;i++){
    string curr = q.front();
    q.pop();
    cout<<curr<<" ";
    string t = curr;
    t += (a +'0');
    q.push(t);
    string u = curr;
    u += (b+'0');
    q.push(u);
  }
}

int main(){
  int a,b;
  cin>>a>>b;
  int count;
  cin>>count;
  generatenum(a,b,count);
  return 0;
}