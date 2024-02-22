#include <iostream>
#include <iomanip>

double CelsiusToFahrenheit(double celsius){
    return (celsius * 1.8) + 32;
}
double FahrenheitToCelsius(double fahrenheit){
    return (fahrenheit - 32)/1.8000;
}
double CelsiusToKelvin(double celsius){
    return celsius + 273.15;
}
double KelvinToCelsius(double kelvin){
    return kelvin - 273.15;
}


int main(int argc, char const *argv[])
{
    char choice;
    double num;
    double ans;
    std::string st;

    std::cout << "Choose a convertor: " << std::endl;
    std::cout << "A - Celsius to Fahrenheit" << std::endl;
    std::cout << "B - Fahrenheit to Celsius" << std::endl;
    std::cout << "C - Celsius to Kelvin" << std::endl;
    std::cout << "D - Kelvin to Celsius" << std::endl;
    bool flag = true;
    do
    {
        std::cin >> choice;
        switch (choice)
        {
            case 'A':
            case 'a':
                std::cout << "Enter the temperature in Celsius\n> ";
                std::cin >> num;
                ans = CelsiusToFahrenheit(num);
                st = "Fahrenheint";
                flag = false;
                break;
            case 'B':
            case 'b':
                std::cout << "Enter the temperature in Fahrenheit\n> ";
                std::cin >> num;
                ans = FahrenheitToCelsius(num);
                st = "Calsius";
                flag = false;
                break;
            case 'C':
            case 'c':
                std::cout << "Enter the temperature in Celsius\n> ";
                std::cin >> num;
                ans = CelsiusToKelvin(num);
                st = "Kelvin";
                flag = false;
                break;
            case 'D':
            case 'd':
                std::cout << "Enter the temperature in Kelvin\n> ";
                std::cin >> num;
                ans = KelvinToCelsius(num);
                st = "Celsius";
                flag = false;
                break;
        }
    } while (flag);
    
    std::cout << std::fixed << std::setprecision(3) << ans << " " << st << std::endl; 
    return 0;
}
