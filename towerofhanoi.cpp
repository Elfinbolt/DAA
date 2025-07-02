#include<iostream>
using namespace std;

int Towerofhanoi(int n,char s,char d,char a){
  if(n>0){
  Towerofhanoi(n-1,s,a,d);
  cout<<"move dics "<<n<<" from "<<s<<" to "<<d<<endl;
  Towerofhanoi(n-1,a,d,s);
  }
}

int main(){
  int n;
  char s,d,a;
  cout<<"enter the no of discs"<<endl;
  cin>>n;
  Towerofhanoi(n,'s','d','a');
}