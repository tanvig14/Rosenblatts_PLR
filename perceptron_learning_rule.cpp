#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

float calcNet(float w[4], float ip[4])
{
    float net;
    for(int i = 0; i<4; i++)
    {
        net = net + (w[i] * ip[i]);
    }
    if(net > 0)
        return 1;
    else if(net < 0)
        return -1;
}

void display(float w1[4], float w2[4], float w3[4])
{
    cout<<"Updated weights for input vector 1:"<<endl;
    for(int a = 0; a<4; a++)
    {
        cout<<w1[a]<<"\t";
    }
    cout<<endl;
    
    cout<<"Updated weights for input vector 2:"<<endl;
    for(int b = 0; b<4; b++)
    {
        cout<<w2[b]<<"\t";
    }
    cout<<endl;
    
    cout<<"Updated weights for input vector 3:"<<endl;
    for(int c = 0; c<4; c++)
    {
        cout<<w3[c]<<"\t";
    }
    cout<<endl;
}

int main()
{
      float w[4] = {1.0, -1.0, 0, 0.5};
      float ip1[4], ip2[4], ip3[4], new_w1[4], new_w2[4], new_w3[4], temp, dw[4]; 
      float dk1, dk2, dk3, c, check;
      
      cout<<"Enter input vector 1 (4 elements)"<<endl;
      for(int j = 0; j<4; j++)
      {
          cin>>ip1[j];  
      }
      cout<<"Enter the desired output (1 or -1)"<<endl;
      cin>>dk1;
      
      cout<<"Enter input vector 2 (4 elements)"<<endl;
      for(int j = 0; j<4; j++)
      {
          cin>>ip2[j];  
      }
      cout<<"Enter the desired output (1 or -1)"<<endl;
      cin>>dk2;
      
      cout<<"Enter input vector 3 (4 elements)"<<endl;
      for(int j = 0; j<4; j++)
      {
          cin>>ip3[j];  
      }
      cout<<"Enter the desired output (1 or -1)"<<endl;
      cin>>dk3;
      
      cout<<"Enter the learning rate"<<endl;
      cin>>c;
      
      check = calcNet(w,ip1);
      //cout<<"check1 "<<check<<endl;
      if(check == dk1)
      {
          for(int x = 0; x<4; x++)
          {
              new_w1[x] = w[x];
              //cout<<"nw "<<new_w1[x]<<"\t";
          }
          check = calcNet(new_w1,ip2);
      }    
      else
      {
          //c(dk-ok).x
          temp = c * (dk1-check);
          for(int m = 0; m<4; m++)
          {
              dw[m] = temp * ip1[m];
          }
          for(int n = 0; n<4; n++)
          {
              new_w1[n] = w[n] + dw[n];
          }
          check = calcNet(new_w1,ip2);
      } 
      //cout<<"check2 "<<check<<endl;
      if(check == dk2)
      {
          for(int x = 0; x<4; x++)
          {
              new_w2[x] = new_w1[x];
          }
          check = calcNet(new_w2,ip3);
      }    
      else
      {
          temp = c * (dk2-check);
          //cout<<"temp"<<temp<<endl;
          for(int m = 0; m<4; m++)
          {
              dw[m] = temp * ip2[m];
              //cout<<"dw "<<dw[m]<<"\t";
          }
          for(int n = 0; n<4; n++)
          {
              new_w2[n] = new_w1[n] + dw[n];
              //cout<<"new weight "<<new_w2[n]<<"\t";
          }
          check = calcNet(new_w2,ip3);
      } 
      
      if(check == dk3)
      {
          for(int x = 0; x<4; x++)
          {
              new_w3[x] = new_w2[x];
          }
      }    
      else
      {
          temp = c * (dk3-check);
          for(int m = 0; m<4; m++)
          {
              dw[m] = temp * ip3[m];
          }
          for(int n = 0; n<4; n++)
          {
              new_w3[n] = new_w2[n] + dw[n];
          }
      } 
      display(new_w1,new_w2,new_w3);
}
