#include <iostream>
#include <string>
#include "Remote.h"

using namespace std;

Clock::Clock(string name, string place) 
: name(name), place(place), hour(1), minute(38), alarm(0) { }

string Clock::getName() { return name; }
string Clock::getPlace() { return place; }

void Clock::OnOffShow()
{
    cout << "----------------------------------------------" << endl;
    cout << "  | 1번 : 전원 ON     | 2번 : 전원 OFF" << endl;
    cout << "  | 0번 : 나가기      |" << endl;
    cout << "----------------------------------------------" << endl;
}    
void Clock::ChoiceShow()
{
    cout << "----------------------------------------------" << endl;
    cout << "  | 0번 : 나가기       | 1번 : 전원 OFF" << endl;        
    cout << "  | 2번 : (시) Up      | 3번 : (시) Down" << endl;
    cout << "  | 4번 : (분) Up      | 5번 : (분) Down" << endl;
    cout << "  | 6번 : 알람         |" << endl;
    cout << "----------------------------------------------" << endl;
}

void Clock::AppInfo()
{
    cout << place << "에 있는 " << name << " 을(를) 제어합니다.\n\n";
}

void Clock::Off()
{
    cout << place <<"에 있는 " << name << "이(가) 꺼졌습니다.\n";
}

void Clock::On()
{
    cout << place <<"에 있는 " << name << "이(가) 켜졌습니다.\n";
}

void Clock::Now()
{
    cout << "  ( 시간  "<< hour << " : " << minute << ")\n";
}

void Clock::Up1()
{
    if(hour <= 24){
        hour += 1;
    }
    else{
        hour = 1;
    }
    cout << place << "에 있는 " << name <<"의 ( 시 )가 변경되었습니다.\n";
}

void Clock::Down1()
{
    if(hour > 1){
        hour -= 1;
    }
    else{
        hour = 24;
    }
    cout << place << "에 있는 " << name <<"의 ( 시 )가 변경되었습니다.\n";
}

void Clock::Up2()
{
    if(minute < 60){
        minute += 1;
    }
    else{
        minute = 1;
    }
    cout << place << "에 있는 " << name <<"의 ( 분 )이 변경되었습니다.\n";
}

void Clock::Down2()
{
    if(minute > 1){
        minute -= 1;
    }
    else{
        minute = 60;
    }
    cout << place << "에 있는 " << name <<"의 ( 분 )이 변경되었습니다.\n";
}

void Clock::Alarm()
{
    cout << name <<" : 취침 알람을 설정합니다.\n";
    cout << "몇 시간 후로 설정하시겠습니까?  : ";
    cin >> alarm;
    cout << place << "에 있는 " << name << "은 " << alarm;
    cout << " 시간 후로 취침 알람 설정이 되었습니다.\n";
}

void Clock::ShowInfo()
{
    cout << "| " << name << "( " << place << " )\n\n";
}

Clock::~Clock()
{
    cout << "--delete 시계--" << endl;
}

Light::Light(string name, string place) : Clock(name, place) { }

void Light::ChoiceShow()
{
    cout << "----------------------------------------------" << endl;
    cout << "  | 0번 :  나가기      | 1번 :  전원 OFF" << endl;
    cout << "----------------------------------------------" << endl; 
}

Light::~Light()
{
    cout << "--delete 전등--" << endl;
}

TV::TV(string name, string place) 
: Clock(name, place), channel(50), volume(10) { } 

void TV::ChoiceShow()
{
    cout << "----------------------------------------------" << endl;
    cout << "  | 0번 : 나가기       | 1번 : 전원 OFF" << endl;       
    cout << "  | 2번 : 채널 Up      | 3번 : 채널 Down" << endl;
    cout << "  | 4번 : 소리 Up      | 5번 : 소리 Down" << endl;
    cout << "  | 6번 : 알람         |" << endl;
    cout << "----------------------------------------------" << endl;
} 

void TV::Now()
{
    cout << "  ( 채널 : " << channel << " | 볼륨 : " << volume << ")\n";
}

void TV::Up1()
{
    if(channel < 500){
        channel += 1;
    }
    else{
        channel = 1;
    }
    cout << " > " << getPlace() << "에 있는 " << getName() <<" :  채널 증가\n";
}

void TV::Down1()
{
    if(channel > 1){
        channel -= 1;
    }
    else{
        channel = 500;
    }
    cout << " > " << getPlace() << "에 있는 " << getName() <<" :  채널 감소\n";
}

void TV::Up2()
{
    if(volume < 50){
        volume += 1;
    }
    else{
        volume = 0;
    }
    cout << " > " << getPlace() << "에 있는 " << getName() <<" :  볼륨 증가\n";
}

void TV::Down2()
{
    if(volume > 1){
        volume -= 1;
    }
    else{
        volume = 1;
    }
    cout << " > " << getPlace() << "에 있는 " << getName() <<" :  볼륨 감소\n";
}

TV::~TV()
{
    cout << "--delete 티비--" << endl;
}

AirCon::AirCon(string name, string place) 
: Clock(name, place), temperature(26), wind(1) { }
    
void AirCon::ChoiceShow()
{
    cout << "----------------------------------------------" << endl;
    cout << "  | 0번 : 나가기       | 1번 : 전원 OFF" << endl;       
    cout << "  | 2번 : 온도 Up      | 3번 : 온도 Down" << endl;
    cout << "  | 4번 : 바람세기 Up  | 5번 : 바람세기 Down" << endl;
    cout << "  | 6번 : 알람         |" << endl;
    cout << "----------------------------------------------" << endl;
}

void AirCon::Now()
{
    cout << "  ( 온도 : " << temperature << " | 바람세기 : " << wind << ")\n";
}

void AirCon::Up1()
{
    temperature += 1;
    cout << " > " << getPlace() << "에 있는 " << getName() <<" :  희망 온도 증가\n";
}

void AirCon::Down1()
{
    if(temperature > 1){
        temperature -= 1;
        cout << " > " << getPlace() << "에 있는 " << getName() <<" :   희망 온도 감소\n";
    }
    else
        cout << " > " << getPlace() << "에 있는 " << getName() <<" :   희망 온도 변경 불가\n";
}

void AirCon::Up2()
{
    wind += 1;    
    cout << " > " << getPlace() << "에 있는 " << getName() <<" :  바람세기 증가\n";
}

void AirCon::Down2()
{
    if(wind > 1){
        wind -= 1;
        cout << " > " << getPlace() << "에 있는 " << getName() <<" :  바람세기 감소\n";
    }
    else
        cout << " > " << getPlace() << "에 있는 " << getName() <<" :  바람세기 변경불가\n";
}

AirCon::~AirCon()
{
    cout << "--delete 에어컨--" << endl;
}

AirPurifier::AirPurifier(string name, string place) 
: Clock(name, place), w_direct(1), w_strength(1) { } 

void AirPurifier::ChoiceShow()
{
    cout << "----------------------------------------------" << endl;
    cout << "  | 0번 : 나가기         | 1번 : 전원 OFF" << endl;       
    cout << "  | 2번 : 방향 고정      | 3번 : 360도 회전" << endl;
    cout << "  | 4번 : 바람세기 Up    | 5번 : 바람세기 Down" << endl;
    cout << "  | 6번 : 알람           |" << endl;
    cout << "----------------------------------------------" << endl;
}

void AirPurifier::Now()
{
    cout << "  ( 바람방향 : ";
    (w_direct== 1) ? cout << "고정" : cout << "360도 회전";
    cout << " | 바람세기 : " << w_strength << ")\n";
}

void AirPurifier::Up1()
{
    w_direct = 1;
    cout << " > " << getPlace() << "에 있는 " << getName() <<" :  바람 방향 변경\n";
}

void AirPurifier::Down1()
{
    w_direct = 2;
    cout << " > " << getPlace() << "에 있는 " << getName() <<" :  바람 방향 변경\n";
}

void AirPurifier::Up2()
{
    if(w_strength < 30){
        w_strength += 1;
    }
    else{
        w_strength = 0;
    }
    cout << " > " << getPlace() << "에 있는 " << getName() <<" :  바람세기 증가\n";
}

void AirPurifier::Down2()
{
    if(w_strength > 1){
        w_strength -= 1;
    }
    else{
        w_strength = 10;
    }
    cout << " > " << getPlace() << "에 있는 " << getName() <<" :  바람세기 감소\n";
}

AirPurifier::~AirPurifier()
{
    cout << "--delete 공기청정기--" << endl;
}
RemoteControl::RemoteControl() : num(0), answer(0) { }
    
void RemoteControl::RegisterApp(Clock* app)
{
    if (num < 10)
        AppList[num++] = app;
    else
        cout  << "등 개수가 찼습니다.\n";
}

void RemoteControl::ChoiceRegisterApp()
{
    if(num <10){
        cout << "----------------------------------------------" << endl;
        for(int i = 0; i <10 ; i++)
        {
            cout<< i+1 << ") "<<appname[i] << "    "<< endl;
        }
        cout << "----------------------------------------------" << endl;
        cout <<"등록 원하는 제품 번호를 입력하세요. : ";
        cin >> answer;
        cout << "----------------------------------------------" << endl;
        for(int i = 0; i <5 ; i++)
            cout<< i+1 << ") "<<appplace[i] << "    " << endl;;
        cout << "----------------------------------------------" << endl;
        cout <<"제품이 있는 위치를 입력하세요. : ";
        cin >> answer2;

        switch (answer-1)
        {
        case 0:
        case 1:
            RegisterApp(new TV(appname[answer-1],appplace[answer2-1]));
            break;
        case 2:
        case 3:
            RegisterApp(new AirCon(appname[answer-1],appplace[answer2-1]));
            break;
        case 4:
        case 5:
            RegisterApp(new AirPurifier(appname[answer-1],appplace[answer2-1]));
            break;
        case 6:
        case 7:
            RegisterApp(new Light(appname[answer-1],appplace[answer2-1]));
            break;
        case 8:
        case 9:
            RegisterApp(new Clock(appname[answer-1],appplace[answer2-1]));
            break;
        }
    }
    else
         cout << "더 이상 제품을 등록할 수 없습니다." << endl;
}

void RemoteControl::PrintApp()
{
    if (num){
        for(int i = 0; i < num ; i++){
            cout << "# " << i+1 << endl;
            AppList[i]->ShowInfo();
        }
    }
    else
        cout << "등록된 제품이 없습니다.\n";
}

void RemoteControl::UnRegisterApp()
{
    PrintApp();
    cout << "- 등록 해제 원하는 제품을 입력해주세요.\n";
    cin >> answer;
    cout << AppList[answer-1]->getName() << " 등록 해제 되었습니다.\n";
    AppList[answer-1] = 0;
    for(int i = answer-1 ; i < 10; i++)
        AppList[i] = AppList[i+1];
    num -= 1;
}

void RemoteControl::AllOFF()
{
    for(int i = 0; i < num ; i++)
        AppList[i]->Off();
}

void RemoteControl::AllON()
{
    for(int i = 0; i < num ; i++)
        AppList[i]->On();
}

int RemoteControl::ChoiceControl(Clock* app)
{
    app->ChoiceShow();
    app->Now();
    cin >> answer;
    while(answer != 0)
    {
        switch (answer)
        {
        case 1:
            app->Off();
            return 0;
        case 2:
            app->Up1();
            break;
        case 3:
            app->Down1();
            break;
        case 4:
            app->Up2();
            break;
        case 5:
            app->Down2();
            break;
        case 6:
            app->Alarm();
            break;   
        }
        app->Now();
        cin >> answer;
    }
    return 0;
}

void RemoteControl::OnOffControl(Clock* app)
{
    app->AppInfo();
    app->OnOffShow();
    cin >> answer;
    switch(answer)
    {
    case 0:
        break;
    case 1:
        app->On();
        ChoiceControl(app);
        break;
    case 2:
        app->Off();
        break;
    }
}

void RemoteControl::AppControl()
{
    PrintApp();
    if(num)
    {
        cout << "- 등록된 제품을 선택해주세요. (나가기 : 0)\n";
        cin >> answer;
        while(answer != 0)
        {
            cout << " # " << answer << " ";
            OnOffControl(AppList[answer-1]);
            PrintApp();
            cout << "- 등록된 제품을 선택해주세요. (나가기 : 0)\n";
            cin >> answer;
        }
    }
}

RemoteControl::~RemoteControl()
{
    for(int i = 0; i<10; i++)
        delete AppList[i];
    cout << "delete --" << endl;
}