#include <iostream>
#include <string>

using namespace std;
class Device
{
    int serialNumber;
    string brandName;

    public:
    Device(int s , string bn)
    {
        serialNumber = s;
        brandName = bn;
    }
    void ShowDeviceInfo()
    {
        cout << "Device Serial Number: " << serialNumber << endl;
        cout << "Device Brand Name: " << brandName << endl;
    }

};
class SmarLight:public Device
{
    int brightnessLevel;
    public:
        SmarLight(int blevel,int sn , string bn): Device(sn,bn)
        {
            brightnessLevel = blevel;
        }
        void setBrightnesslevel(int level)
        {
            brightnessLevel=level;
        }
        void display()
        {
            ShowDeviceInfo();
            cout<<"Brightness Level: "<<brightnessLevel<<endl;
        }

};
class SmartThermostat : public SmarLight
{
    float temprature;
    public:
        SmartThermostat(float temp , int bright ,int sn , string bn): SmarLight(bright , sn ,bn)
        {
            temprature = temp;
        }
        void setTemperature(float temp)
        {
            temprature = temp;
        }
        
        void displayThermostatInfo()
        {
            display();
            cout << "Thermostat Temperature: " << temprature << "  °C" << endl;
        }
};
int main() {
    SmartThermostat thermostat(22.5, 75, 123456, "SmartHome");
    thermostat.setBrightnesslevel(76);
    thermostat.setTemperature(25.0);
    // thermostat.ShowDeviceInfo();
    // thermostat.display();
    thermostat.displayThermostatInfo();
    
    return 0;
}