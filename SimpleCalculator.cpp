#include <iostream>

using namespace std;

int main(){
    int num_a;
    int num_b;
    char operation;

    cout << "Choose a number: ";
    cin >> num_a;

    cout << "Choose another number: ";
    cin >> num_b;
    
    cout << "The numbers are: " << num_a << " " << num_b << endl;
    cout << "Choose a legal operations: " << endl;
    cout << "+, -, *, /\n";
    cin >> operation;    
    switch (operation)
    {
        case '+':
            cout << num_a + num_b;
            break;
        case '-':
            cout << num_a - num_b;
            break;
        case '*':
            cout << num_a * num_b;
            break;
        case '/':
            try
            {
                cout << num_a/num_b;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            break;
        default:
            cout << "Invalid operation" << std::endl;
    }
    
    return 0;
}
