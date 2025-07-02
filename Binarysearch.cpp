#include<iostream>
using namespace std;

int binarysrch(int arr[],int k,int n){
  int mid;
  int l=0;
  int h=n-1;
  while(l<=h){
    mid=(l+h)/2;
    if(k==mid){
      return mid;
    }
    else if(k<mid){
      h=mid-1;
    }
    else if(k>mid){
      l=mid+1;
    }
  }
  return -1;
}

int main(){
  int n,k;
  cout<<"size of the array "<<endl;
  cin>>n;
  int arr[n];
  cout<<"Enter the numbers in array"<<endl;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<"enter the key "<<endl;
  cin>>k;
  int result = binarysrch(arr,k,n);

  if(k==-1){
    cout<<"element not found";
  }
  else{
    cout<<"element fount at "<<result;
  }
}