#include<iostream>
#include<string>
#include<vector>

class Parts
{
private:

    unsigned int m_id = 0;
    std::string m_PartName;

public:

    Parts(unsigned int id, std::string PartName)
    {
        m_id = id;
        m_PartName = PartName;
    }

    std::string GetPartName()
    {
        return m_PartName;
    }
};

class Car
{
private:

    unsigned int m_id = 0;
    std::string m_model = "";
    std::vector<Parts*> m_Parts;

public:

    Car(unsigned int id, std::string model)
    {
        m_id = id;
        m_model = model;
    }

    void AddParts(Parts* parts)
    {
        m_Parts.push_back(parts);
    }

    void PrintParts()
    {
        for (size_t i = 0; i < m_Parts.size(); i++)
        {
            std::cout << m_Parts[i]->GetPartName() << std::endl;
        }
    }
};


int main()
{
    Car* car = new Car(0, "Toyota");
    car -> PrintParts();

    Parts* parts1 = new Parts(0, "Engine");
    Parts* parts2 = new Parts(1, "Accelerator");

    car->AddParts(parts1);
    car->AddParts(parts2);

    car->PrintParts();

    delete car;
    delete parts1;
    delete parts2;

}