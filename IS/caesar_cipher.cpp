#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;

int main() {

    string s;
    int shift;
    cout<<"\nEnter the text to be encrypted : ";
    getline(cin,s);
    cout<<"\nShift : ";
    cin>>shift;
    cout<<"Cipher Text : ";
    for(int i=0;i<s.size();i++) {
    if(((int)s[i] >= 48 && (int)s[i] <= 57)|| ((int)s[i]>=97 && (int)s[i]<=122)) {
        if((int)s[i] >= 48 && (int)s[i] <= 57) {
            stringstream ss;
            ss<<s[i];
            int x;
            ss>>x;
            x = (x+shift%10)%10;
            s[i]=char(x+48);
        }
        else {
            int y=((int)s[i]-97+shift)%26;
            s[i]=char(y+97);
        }
        cout<<s[i];
    }
    }
    cout<<"\nDeciphering..";
    Sleep(3000);
    cout<<"\nDecrypted text is : ";
    for(int i=0;i<s.size();i++) {
    if(((int)s[i] >= 48 && (int)s[i] <= 57)|| ((int)s[i]>=97 && (int)s[i]<=122)) {
        if((int)s[i] >= 48 && (int)s[i] <= 57) {
            stringstream ss;
            ss<<s[i];
            int x;
            ss>>x;
            x = (x-shift%10)%10;
            if(x<0)
                s[i]=char(x+58);
            else
                s[i]=char(x+48);
        }
        else {
            int y=((int)s[i]-97-shift)%26;
            if(y<0)
                s[i]=char(y+123);
            else
                s[i]=char(y+97);
        }
        cout<<s[i];
    }
    else
        cout<<s[i];
    }
}