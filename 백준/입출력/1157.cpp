#include <iostream>
using namespace std;

int main(void){
    string s;
    int arr[26]={0,};
    int max=0;
    char result;
    cin>>s;

    for(int i =0; i<s.size();i++){
        if ((char)s[i]>=65 && (char)s[i]<=90) arr[s[i]-65]++;
        else if((char)s[i]>=97&&(char)s[i]<=122) arr[s[i]-97]++;
    }

    for(int i =0 ; i<26;i++){
       if(max<arr[i]) {
            max = arr[i];
            result = i+65;
       }
       else if(arr[i]==max) result='?'; 
    }
    cout<<result<<"\n";
}