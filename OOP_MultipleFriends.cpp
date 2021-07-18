#include <bits/stdc++.h>
using namespace std;
class Humidity;

class Temperature
{
private:
    int m_temp;

public:
    Temperature(int temp = 0)
    {
        m_temp = temp;
    }
    friend void printWeather(const Temperature &temp,
                             const Humidity &humd);
};

class Humidity
{
private:
    int m_humidity;

public:
    Humidity(int humidity = 0)
    {
        m_humidity = humidity;
    }
    friend void printWeather(const Temperature &temp, const Humidity &humd);
};

void printWeather(const Temperature &temp, const Humidity &humd)
{
    cout << "The temperature is " << temp.m_temp << "\n";
    cout << "The Humidity is " << humd.m_humidity << "\n";
}

int main()
{
    Humidity hum(10);
    Temperature temp(12);
    printWeather(temp, hum);
    return 0;
}