#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


/**
 * A simple to-do list program which let you write tasks you have to do, delete tasks,
 *  read the tasks from a list (txt file), see the task list 
 * and as a bonus it saves the list into a txt file!
 * 
 * p.s - it doesn't overwrite the file, just append text to it.
*/
string file_name = "tasks.txt";  

// Read file https://cplusplus.com/doc/tutorial/files/
void readTasksFromFile(){
    string line;
    int index = 1;
    ifstream myfile ("tasks.txt"); // Name of the file.
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
        cout << index << ". " << line << '\n'; // Arrange the tasks with numbers.
        index++;
        }
        myfile.close();
    }
    else cout << "File not found"; 
}
/**
 * Shows the current tasks.
*/
void showTasks(vector<string> &tasks){
    cout << "To-Do:\n";
    for (size_t i = 0; i < tasks.size(); i++)
    {
        cout << i+1 << ". " << tasks[i] << endl;
    }
    
}
int main(int argc, char const *argv[])
{
    vector<string> tasks;
    string task;
    char choice;
    int taskNo;
    // Opens the file so it can write in it the tasks vector (list).
    ifstream inputFile("tasks.txt");
    while (getline(inputFile, task))
    {
        tasks.push_back(task);
    }
    inputFile.close();

    do
    {
        cout << "-----MENU------" << "\nA - add a task\nV - View tasks\nD - Delete a task\nL - Load Tasks from a file\nQ - Quit" << endl;
        cout << "Enter your choice\n> ";
        cin >> choice;
        switch (choice)
        {
        case 'A': // Add a task.
        case 'a':
            cout << "Enter a task:\n> ";
            cin.ignore();
            getline(cin,task);
            tasks.push_back(task);
            break;
        case 'V':   // Display the list.
        case 'v':
            if (!tasks.empty())
            {
                showTasks(tasks);
            }else{
                cout << "No tasks to show..\n";
            }
            break;
        case 'D':   // Dletes the list.
        case 'd': 
            if(tasks.empty()){
                cout << "No tasks to delete\n" << endl;
            }else{
                showTasks(tasks);
                cout << "\nEnter an index of task to delete...\n> ";
                while(true){
                    cin >> taskNo;
                    if (tasks.size() > taskNo || tasks.size() < taskNo)
                    {
                        cout << "Invalid number, try again\n";
                    }else{
                        tasks.erase(tasks.begin() + taskNo);
                        cout << "Done." << endl;
                        break;
                    }
                }
            }
            break;
        case 'L':   // Loads the tasks file and then displays the list.
        case 'l':
            readTasksFromFile();
            break;

        }
    } while (choice != 'Q' && choice != 'q'); // User decides to exit the program
    
    // If anything written in the list saves the list otherwise not.
    if (tasks.empty())
    {  
        cout << "Nothing to save.\nBye!";
        return 0;
    }else{
        cout << "Saving file..";
        std::ofstream outputFile("tasks.txt");
        for (const auto &t : tasks)
        {
            outputFile << t << std::endl;
        }
        outputFile.close();

        return 0;
    }
}
