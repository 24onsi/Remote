#include <iostream>
#include <string>
#include "Remote.h"
#include "Remote.cpp"
using namespace std;

int main(void)
{
    int choice;
    RemoteControl remote;
    
    remote.ChoiceRegisterApp();
    while(choice != 5){
        remote.PrintApp();
        cout << "1번 : 등록 제품 제어" << endl;
        cout << "2번 : 새로운제품 등록\n";
        cout << "3번 : 등록 제품 해제" << endl;
        cout << "4번 : 등록 제품 전체 끄기" << endl;
        cout << "5번 : 등록 제품 전체 켜기" << endl;
        cout << "6번 : 종료" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            remote.AppControl();
            break;
        case 2: 
            remote.ChoiceRegisterApp();
            break;
        case 3:
            remote.UnRegisterApp();
            break;
        case 4:
            remote.AllOFF();
            break;
        case 5:
            remote.AllON();
            break;
        case 6:
            break;
            break;
        }
    }
    remote.~RemoteControl();

    return 0;
}
