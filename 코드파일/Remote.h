#ifndef REMOTE_H_
#define REMOTE_H_
#include <iostream>
#include <string>

using namespace std;

class Clock
{
private:
    string name;
    string place;
    int hour;
    int minute;
    int alarm;
public:
    Clock();
    Clock(string name, string place);
    virtual string getName();
    virtual string getPlace();
    virtual void OnOffShow();
    virtual void ChoiceShow();
    virtual void AppInfo();
    virtual void Off();
    virtual void On();
    virtual void Now();
    virtual void Up1();
    virtual void Down1();
    virtual void Up2();
    virtual void Down2();
    virtual void Alarm();
    virtual void ShowInfo();
    virtual ~Clock();
};

class Light : public Clock
{
public:
    Light(string name, string place);
    void ChoiceShow();
    ~Light();
};

class TV : public Clock
{
private:
    int channel;
    int volume;
public:
    TV();
    TV(string name, string place);
    void ChoiceShow();
    void Now();
    void Up1();
    void Down1();
    void Up2();
    void Down2();
    ~TV();
};

class AirCon : public Clock
{
private:
    int temperature;
    int wind;
public:
    AirCon();
    AirCon(string name, string place);
    void ChoiceShow();
    void Now();
    void Up1();
    void Down1();
    void Up2();
    void Down2();
    ~AirCon();
};

class AirPurifier : public Clock
{
private:
    int w_direct;
    int w_strength;
public:
    AirPurifier();
    AirPurifier(string name, string place);
    void ChoiceShow();
    void Now();
    void Up1();
    void Down1();
    void Up2();
    void Down2();
    ~AirPurifier();
};

class RemoteControl
{
private:
    int num;
    int answer;
    int answer2;
    string appname[10] ={"L사 TV", "S사 TV", "L사 에어컨", "S사 에어컨", 
                         "L사 공기 청정기", "S사 공기 청정기", "LED등",
                          "형광등", "탁상시계" , "디지털시계"};
    string appplace[5] = {"거실", "안방", "부엌", "화장실", "현관"};
public:
    Clock* AppList[10];
    RemoteControl();
    void RegisterApp(Clock* app);
    void ChoiceRegisterApp();
    void PrintApp();
    void UnRegisterApp();
    void AllOFF();
    void AllON();
    int ChoiceControl(Clock* app);
    void OnOffControl(Clock* app);
    void AppControl();
    ~RemoteControl();
};

#endif