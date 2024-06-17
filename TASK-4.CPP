#include <iostream>
#include <vector>
#include <iomanip>
#include<conio.h>
using namespace std;

struct Task {
    string Description;
    bool Completed;
    string DueDate;
    string Category;
};

class TodoList {
private:
    vector<Task> Tasks;

public:
    void Add_Task(string Description, string DueDate, string Category) {
        Task newTask = {Description, false, DueDate, Category};
        Tasks.push_back(newTask);
        cout << "TASK ADDED SUCCESSFULLY!\n";
    }

    void Mark_Task_Complete(int index) {
        if (index >= 0 && index < Tasks.size()) {
            Tasks[index].Completed = true;
            cout << "TASK MARKED AS COMPLETE!\n";
        } else {
            cout << "INVALID TASK INDEX!\n";
        }
    }

    void removeTask(int index) {
        if (index >= 0 && index < Tasks.size()) {
            Tasks.erase(Tasks.begin() + index);
            cout << "TASK REMOVED SUCCESSFULLY!\n";
        } else {
            cout << "INVALID TASK INDEX!\n";
        }
    }

    void Display_Tasks() {

        for (size_t i = 0; i < Tasks.size(); ++i) {
            cout << "[" << setw(2) << i + 1 << "] ";
            cout << (Tasks[i].Completed ? "[X] " : "[ ] ");
            cout << "DUE: " << Tasks[i].DueDate << " | ";
            cout << "CATEGORY: " << Tasks[i].Category << " | ";
            cout << Tasks[i].Description << "\n";
        }

        cout << "===========================================================================\n";
        cout << "\t\t\tPRESS ANY KEY TO CONTINUE...\n";
        getch();
        cout << "===========================================================================\n";
    }
};

int main() {
    TodoList todoList;
    int Choice;

    do {
        system("CLS");
        cout << "===========================================================================\n";
        cout << "*************************** TODO LIST *************************************\n";
        cout << "===========================================================================\n";
        cout << "1. ADD TASK\n";
        cout << "2. MARK TASK AS COMPLETE\n";
        cout << "3. REMOVE TASK\n";
        cout << "4. DISPLAY TASKS\n";
        cout << "5. EXIT\n";
        cout << "=================================\n";
        cout << "ENTER YOUR CHOICE--: ";
        cin >> Choice;
        

        switch (Choice) {
            case 1: {
                system("CLS");
                cout << "===========================================================================\n";
                cout << "*************************** TODO LIST *************************************\n";
                cout << "===========================================================================\n";
                todoList.Display_Tasks();
                string Description, DueDate, Category;
                cout << "ENTER TASK DESCRIPTION--: ";
                cin.ignore();
                getline(cin, Description);
                cout << "ENTER DUE DATE (E.G., MM/DD/YYYY)--: ";
                cin >> DueDate;
                cout << "ENTER TASK CATEGORY--: ";
                cin.ignore();
                getline(cin, Category);
                todoList.Add_Task(Description, DueDate, Category);
                break;
            }
            case 2: {
                system("CLS");
                cout << "===========================================================================\n";
                cout << "*************************** TODO LIST *************************************\n";
                cout << "===========================================================================\n";
                todoList.Display_Tasks();
                int index;
                cout << "ENTER THE TASK INDEX TO MARK AS COMPLETE--: ";
                cin >> index;
                todoList.Mark_Task_Complete(index - 1); 
                break;
            }
            case 3: {
                system("CLS");
                cout << "===========================================================================\n";
                cout << "*************************** TODO LIST *************************************\n";
                cout << "===========================================================================\n";
                todoList.Display_Tasks();
                int index;
                cout << "ENTER THE TASK INDEX TO REMOVE--: ";
                cin >> index;
                todoList.removeTask(index - 1); 
                break;
            }
            case 4: {
                system("CLS");
                cout << "===========================================================================\n";
                cout << "*************************** TODO LIST *************************************\n";
                cout << "===========================================================================\n";
                todoList.Display_Tasks();
                break;
            }
            case 5: {
                cout << "EXITING THE TODO LIST\n";
                cout << "THANK YOU FOR USING THE TODO-LIST.\n";
                break;
            }
            default:
                cout << "INVALID CHOICE. PLEASE ENTER A VALID OPTION.\n";
        }

    } while (Choice != 0);

    return 0;
}
