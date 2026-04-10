//LINEAR SEARCH FOR SINGLE OCCURANCE:
#include<iostream>
using namespace std;
int main()
{
  int i;
  int input[10]={99,12,72,27,11,36,88,72,82,52};
  int target;
  cout<<"enter a number:";
  cin>>target;
  for(i=0;i<10;i++)
  {
    if(target==input[i])
    {
      cout<< "value found at index"<<i;
      break;
     }
  }
    if(i==10){
      cout<<"value not found";
      return 0;
}
  return 0;
}
