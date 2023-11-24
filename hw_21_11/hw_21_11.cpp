#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

struct Device
{
    string device_type;
    string device_name;
    string device_model;
    string brand;
    Date warranty_period;
    float price;
    Date sale_date;
};

void fillDevice(Device& device)
{
    cout << "Input device type: ";
    cin >> device.device_type;
  
    cout << "Input device name: ";
    cin.ignore();
    getline(cin, device.device_name);

    cout << "Input device model: ";
    getline(cin, device.device_model);

    cout << "Input device brand: ";
    getline(cin, device.brand);

    cout << "Input warranty period (day): ";
    cin >> device.warranty_period.day;
    if (device.warranty_period.day < 0 || device.warranty_period.day > 31)
    {
        cout << "Incorrect date value\n";
        throw "ERROR";
    }

    cout << "Input warranty period (month): ";
    cin >> device.warranty_period.month;
    if (device.warranty_period.month < 0 || device.warranty_period.month > 31)
    {
        cout << "Incorrect date value\n";
        throw "ERROR";
    }

    cout << "Input warranty period (year): ";
    cin >> device.warranty_period.year;

    cout << "Input device price: ";
    cin >> device.price;

    cout << "Input sale date (day): ";
    cin >> device.sale_date.day;

    cout << "Input sale date (month): ";
    cin >> device.sale_date.month;

    cout << "Input sale date (year): ";
    cin >> device.sale_date.year;

}

void showDevice(const Device& device)
{
    cout << "\nDevice information:\n";
    cout << "type: " << device.device_type << "\n";
    cout << "name: " << device.device_name << "\n";
    cout << "model: " << device.device_model << "\n";
    cout << "brand: " << device.brand << "\n";
    cout << "warranty period: " << device.warranty_period.day << "/" << device.warranty_period.month << "/" << device.warranty_period.year << "\n";
    cout << "price: " << device.price << "\n";
    cout << "sale date: " << device.sale_date.day << "/" << device.sale_date.month << "/" << device.sale_date.year << "\n";
}

bool checkWarranty(Device& device)
{
    cout << "Enter today's date (DD MM YYYY): ";
    Date today;
    cin >> today.day >> today.month >> today.year;

    if (today.year < device.warranty_period.year)
    {
        return true;
    }
    else if (today.year == device.warranty_period.year)
    {
        if (today.month < device.warranty_period.month)
        {
            return true;
        }
        else if (today.month == device.warranty_period.month)
        {
            if (today.day <= device.warranty_period.day)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    Device my_device;
    fillDevice(my_device);
    showDevice(my_device);

    if (checkWarranty(my_device))
    {
        cout << "Warranty is still valid\n";
    }
    else
    {
        cout << "Warranty has expired\n";
    }
}
