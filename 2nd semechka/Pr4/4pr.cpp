/*
В системе «Умный дом» используется управляющий компьютер, который взаимодействует с различными приборами.
    Приборы подразделяются на несколько категорий:
1.	Счетчики электрической энергии
    a.	Меркурий 230            //12
    b.	Нева МТ314              //10
    c.	Энергомера CE308        //16
2.	Блоки ввода дискретных сигналов:
    a.	Reallab NL-16HV         //15
    b.	Приборэлектро PRE-16    //20
    c.	Энергосервис ЭНМВ-1-24  //22
3.	Блоки управления отоплением
    a.	Ouman S203              //10
    b.	Овен ТРМ232             //11

Получить данные от каждого прибора можно через метод

void poll() {
    std::cout << “Device name” << std::endl;
// Некоторая реализация получения данных, которую вам делать
// не нужно.
}

Для реализации конкретного проекта умного дома проектировщики могут выбрать, как правило, по одному прибору каждого типа. Тем не менее, программа должна поддерживать их все.

Предложите реализацию программы, которая могла бы считывать из файла названия приборов и формировать конфигурацию с учетом конкретного проекта.
Продемонстрируйте, как вы будете вызывать метод poll.

Пишите программу с учетом того, что в будущем количество прибором может возрасти.

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Device
{
protected:

    std::string m_dev_name;

public:

    Device(const std::string& name) : m_dev_name(name) {}

    void Poll() const
    {
        std::cout << m_dev_name << std::endl;
    }

    std::string Get_Name() const
    {
        return m_dev_name;
    }

};


class Counter : public Device
{
public:
    Counter(const std::string& name) : Device(name) {}
};

class DS_Input_Unit : public Device
{
public:
    DS_Input_Unit(const std::string& name) : Device(name) {}
};

class Heating_Control_Unit : public Device
{
public:
    Heating_Control_Unit(const std::string& name) : Device(name) {}
};

//Counters

class Mercury : public Counter
{
public:
    Mercury(const std::string& name) : Counter(name) {}
};

class Neva : public Counter
{
public:
    Neva(const std::string& name) : Counter(name) {}
};

class Energy_Meter : public Counter
{
public:
    Energy_Meter(const std::string& name) : Counter(name) {}
};

//DS_Input_Units

class Reallab : public DS_Input_Unit
{
public:
    Reallab(const std::string& name) : DS_Input_Unit(name) {}
};

class Device_Electro : public DS_Input_Unit
{
public:
    Device_Electro(const std::string& name) : DS_Input_Unit(name) {}
};

class Energy_Service : public DS_Input_Unit
{
public:
    Energy_Service(const std::string& name) : DS_Input_Unit(name) {}
};

//Heating_Control_Units

class Ouman : public Heating_Control_Unit
{
public:
    Ouman(const std::string& name) : Heating_Control_Unit(name) {}
};

class Oven : public Heating_Control_Unit
{
public:
    Oven(const std::string& name) : Heating_Control_Unit(name) {}
};

std::vector<Device> counter_vec = { Device("Меркурий 230"), Device("Нева МТ314"), Device("Энергомера CE308") };
std::vector<Device> ds_input_vec = { Device("Reallab NL-16HV"), Device("Приборэлектро PRE-16"), Device("Энергосервис ЭНМВ-1-24") };
std::vector<Device> heat_control_vec = { Device("Ouman S203"), Device("Овен ТРМ232") };

Device* Factory(const std::string& name) //3 вектора с названиями приборов в каждой категории для реализации аозможности добавления их впоследствии
{
    Device* dev = nullptr;
    switch (name.length())
    {
        case(12):
            dev = new Mercury(name);
            break;
        case(10):
            if (name == "Нева МТ314") { dev = new Neva(name); }
            else if (name == "Ouman S203") { dev = new Ouman("Ouman S203"); }
            break;
        case(16):
            if (name == "Энергомера CE308") { dev = new Energy_Meter("Энергомера CE308"); }
            break;
        case(15):
            if (name == "Reallab NL-16HV") { dev = new Reallab("Reallab NL-16HV"); }
            break;
        case(20):
            if (name == "Приборэлектро PRE-16")dev = new Device_Electro("Приборэлектро PRE-16");
            break;
        case(22):
            if (name == "Энергосервис ЭНМВ-1-24")dev = new Energy_Service("Энергосервис ЭНМВ-1-24");
            break;
        case(11):
            if (name == "Овен ТРМ232")dev = new Oven("Овен ТРМ232");
            break;
        default: dev = nullptr;
    }

    return dev;


}

int main()
{
    Oven r("dwd");
    Factory(r.Get_Name());
    setlocale(LC_ALL, "ru");
    std::ifstream devicesList;
    devicesList.open("txt.txt");
    std::string currentString;
    while (getline(devicesList, currentString)) {
        Device* currentDevice = Factory(currentString);
        if (currentDevice != nullptr) {
            currentDevice->Poll();
        }
        else {
            std::cout << "[нет такого >:( ] " << currentString << std::endl;
        }
    }

    devicesList.close();
}