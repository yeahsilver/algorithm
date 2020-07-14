#include <iostream>
using namespace std;

int main(void){
    int arr[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int month, day;
    int tmp=0, total=0;

    cin>>month>>day;

    for(int i =0;i<month;i++){
        tmp += arr[i];
    }

    total = day + tmp;
    
    switch(total%7){
        case 1 : cout<<"MON"; break;
        case 2 : cout<<"TUE"; break;
        case 3 : cout<<"WED"; break;
        case 4 : cout<<"THU"; break;
        case 5 : cout<<"FRI"; break;
        case 6 : cout<<"SAT"; break;
        case 0 : cout<<"SUN"; break;
    }
    cout<<"\n";
}
