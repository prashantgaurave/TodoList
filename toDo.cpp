#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector<string> loadTasks(const string& filename) {
    vector<string> tasks;
    ifstream file(filename);
    string task;
    while (getline(file, task)) {
        if (!task.empty())
            tasks.push_back(task);
    }
    return tasks;
}

void saveTasks(const vector<string>& tasks, const string& filename) {
    ofstream file(filename);
    for (const auto& task : tasks)
        file << task << endl;
}

void showTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks.\n";
        return;
    }
    cout << "Todo List:\n";
    for (size_t i = 0; i < tasks.size(); ++i)
        cout << i + 1 << ". " << tasks[i] << endl;
}

int main() {
    const string filename = "tasks.txt";
    vector<string> tasks = loadTasks(filename);

    int choice;
    do {
        cout << "\n1. Show tasks\n2. Add task\n3. Remove task\n4. Save & Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            showTasks(tasks);
        } else if (choice == 2) {
            cout << "Enter new task: ";
            string newTask;
            getline(cin, newTask);
            if (!newTask.empty())
                tasks.push_back(newTask);
        } else if (choice == 3) {
            showTasks(tasks);
            cout << "Enter task number to remove: ";
            size_t idx;
            cin >> idx;
            if (idx >= 1 && idx <= tasks.size())
                tasks.erase(tasks.begin() + idx - 1);
            else
                cout << "Invalid task number!\n";
        } else if (choice == 4) {
            saveTasks(tasks, filename);
            cout << "Tasks saved. Goodbye!\n";
        } else {
            cout << "Invalid option.\n";
        }
    } while (choice != 4);

    return 0;
}
