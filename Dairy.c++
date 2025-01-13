#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Person {
private:
    vector<int> id;
    vector<string> name;
    vector<string> type;
    vector<string> date;
    vector<string> time;

public:
    Person() {}

    void addPerson() {
        int personID;
        string personName, personType, personDate, personTime;
        cout << "\n--- Add New Person ---\n";
        cout << "Enter ID: ";
        while (!(cin >> personID)) {
            cout << "Invalid input. Please enter a numeric ID: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, personName);
        cout << "Enter Type (e.g., Visitor/Staff): ";
        getline(cin, personType);
        cout << "Enter Date (YYYY-MM-DD): ";
        getline(cin, personDate);
        cout << "Enter Time (HH:MM): ";
        getline(cin, personTime);

        id.push_back(personID);
        name.push_back(personName);
        type.push_back(personType);
        date.push_back(personDate);
        time.push_back(personTime);
        cout << "Person added successfully!\n";
    }

    void searchPerson() {
        if (name.empty()) {
            cout << "No records available to search.\n";
            return;
        }

        string tgt;
        cout << "Enter name to search: ";
        cin.ignore();
        getline(cin, tgt);

        bool found = false;
        for (size_t i = 0; i < name.size(); i++) {
            if (name[i] == tgt) {
                cout << "\n--- Person Found ---\n";
                cout << "ID: " << id[i] << "\n";
                cout << "Name: " << name[i] << "\n";
                cout << "Type: " << type[i] << "\n";
                cout << "Date: " << date[i] << "\n";
                cout << "Time: " << time[i] << "\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Person not found.\n";
        }
    }

    void displayAllPersons() {
        if (name.empty()) {
            cout << "No records to display.\n";
            return;
        }

        cout << "\n--- All Persons ---\n";
        for (size_t i = 0; i < name.size(); i++) {
            cout << "\nPerson " << i + 1 << ":\n";
            cout << "ID: " << id[i] << "\n";
            cout << "Name: " << name[i] << "\n";
            cout << "Type: " << type[i] << "\n";
            cout << "Date: " << date[i] << "\n";
            cout << "Time: " << time[i] << "\n";
        }
    }
};

int main() {
    Person person;
    int choice;

    do {
        cout << "\n--- Person Management System ---\n";
        cout << "1. Add Person\n";
        cout << "2. Search Person\n";
        cout << "3. Display All Persons\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                person.addPerson();
                break;
            case 2:
                person.searchPerson();
                break;
            case 3:
                person.displayAllPersons();
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}
