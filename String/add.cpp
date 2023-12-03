#include <bits/stdc++.h>
using namespace std;

string addStrings(string num1, string num2) 
{
        int n1=num1.length(); int n2=num2.length();
        int i=n1-1; int j=n2-1;
        string s="";
        int carry=0;
        while(i>=0 || j>=0)
        {
            int x=0, y=0;
            if (i>=0)
            {
                x=num1[i]-'0';
                // cout<<"X: "<<x<<endl;
            }
            if (j>=0)
            {
                y=num2[j]-'0';
                // cout<<"y: "<<y<<endl;
            }
            int sum=x+y+carry;
            // cout<<"sum: "<<sum<<endl;
            char c=sum%10+'0';
            s.push_back(c);
            carry=sum/10;
            // cout<<"carry: "<<carry<<endl;
            i--;
            j--;
            // carry = (x+y)%10;
        }
        if(carry) s.push_back(carry+'0');
        reverse(s.begin(),s.end());
        return s;
}


int main()
{
    string a,b;
    cin>>a>>b;
    cout<<"The sum of the numerical string is "<<addStrings(a,b);
    return 0;
}