// LINEAR SEARCH FOR MULTIPLE OCCURANCE:
#include<iostream>
using namespace std;
int main()
{
  int i;
  int input[10]={99,12,72,27,11,36,88,72,82,52};
  int target;
  bool found=false;
  cout<<"enter a number:";
  cin>>target;
  
  cout<< "value found at index: ";
  for(i=0;i<10;i++)
  {
    if(target==input[i])
    {
      cout<<i<<" ";
      found=true;
     }
  }
    if(!found){
      cout<<"value not found";
    
}
  return 0;
}
