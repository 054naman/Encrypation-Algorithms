#include<iostream>
#include<cstdio>

using namespace std;

class DiffieHellman
{
       public:
              long long int p,g,x,a,y,b,A,B;
              DiffieHellman(long long int p1,long long int g1,long long int x1,long long int y1)
              {
                     p = p1;
                     g = g1;
                     x = x1;
                     y = y1;
                     a=power(g,x,p);      
                     b=power(g,y,p);
                     A = power(b,x,p);
                     B = power(a,y,p);
              }
              long long int power(int a,int b,int mod)
              {
                     long long int t;
                     if(b==1)
                           return a;
                     t=power(a,b/2,mod);
                     if(b%2==0)
                           return (t*t)%mod;
                     else
                           return (((t*t)%mod)*a)%mod;
              }
};

int main()
{
       long long int p,g,x,a,y,b,A,B;
      
       cout<<"Enter the values of public keys and a number for key genration : "<<endl;
       cin>>p>>g;
      
       cout<<"Enter the Secret Integer for first person : ";
       cin>>x;
       cout<<"Enter the Secret Integer for second person   : ";
       cin>>y;
       cout<<endl;
       DiffieHellman dh(p,g,x,y);
      
       cout<<"first person's private key, known only to first person : "<<dh.a<<endl;
       cout<<"second person's private key known only to second person : "<<dh.b<<endl;
       cout<<endl;
       cout<<"first person's public key, known to both : "<<dh.A<<endl;
       cout<<"second person's public key, known to both : "<<dh.B<<endl;
       return 0;
}