#include <iostream>
#include <string>
#include <list>

using namespace std;

void printList(list<char> printList){
    for(auto it = printList.begin(); it != printList.end(); it++ ){
            cout << *it;
    }
    cout << '\n';
}

list<char>::iterator moveLeft(list<char> passwordList, list<char>::iterator iterator){
    if(iterator != passwordList.begin()){
         iterator--;
    }
    return iterator;
}

list<char>::iterator moveRight(list<char> passwordList, list<char>::iterator iterator){
    if(iterator != passwordList.end()){
        iterator++;
    }
    return iterator;
}

void eraseElement(){}



int main(void){
    int test_case;

    cin >> test_case;

    while(test_case--){
        string password;
        list<char> passwordList;

        cin >> password;

        list<char>::iterator iterator = passwordList.end();

        for(int i = 0; i < password.length(); i++){
            if(password[i] == '<'){
                iterator = moveLeft(passwordList, iterator);

            } else if(password[i] == '>'){
                iterator = moveRight(passwordList, iterator);

            } else if (password[i] == '-'){
                if(iterator == passwordList.begin()){
                    continue;
                }
                passwordList.erase(--iterator);

            } else {
                passwordList.insert(iterator, password[i]);
            }
        }

        printList(passwordList);

        passwordList.clear();
    }
}