#include<iostream>
using namespace std;
string decrypt(string msg,int k)
{
    char ch;
    int j;
    for(j = 0; msg[j] != '\0'; j++)
    {
        ch = msg[j];
        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch - k;
            if(ch < 'a')
            {
                ch = ch + 'z' - 'a' + 1;
            }
            msg[j] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch - k;
            if(ch > 'a')
            {
                ch = ch + 'Z' - 'A' + 1;
            }
            msg[j] = ch;
        }
    }
    return msg;
}
string encrypt(string msg,int k)
{
    char ch;
    int j;
   for(j = 0; msg[j] != '\0'; j++)
   {
        ch = msg[j];
        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch + k;
            if(ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }
            msg[j] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch + k;
            if(ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }
            msg[j] = ch;
        }
    }
    return msg;
}
int main()
{
  string msg,choice;
  int k;
  cout << "Enter a message";
  cin>>msg;
  cout << "Enter key value for encrypting: ";
  cin >> k;
  string enc_ans=encrypt(msg,k);
  cout << " The Encrypted message is: " << enc_ans<<endl<<endl;
  string decr_ans=decrypt(enc_ans,k);
  cout<< "The Decrypted message is: "<<decr_ans<<endl;
  return 0;
}