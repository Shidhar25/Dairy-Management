#include <iostream>
#include <vector>
using namespace std;

class Person {
private:
    vector<int> id;
    vector<string> name;
    vector<string> date;
    vector<string> time;

public:
    Person(vector<int> id, vector<string> name, vector<string> date, vector<string> time) : id(id), name(name), date(date), time(time) {}

    void searchPerson(string tgt) {
        bool found = false;
        for (size_t i = 0; i < name.size(); i++) {
            if (name[i] == tgt) {
                cout << "Found. ID is: " << id[i] << endl << " Name is: " << name[i] << endl << " Date is: " << date[i] << endl << " Time is: " << time[i];
                found = true;
            }
        }
        if (!found) {
            cout << "Result not found";
        }
    }

    void addData(vector<int>& id, vector<string>& name, vector<string>& date, vector<string>& time) {
        int newId;
        string newName, newDate, newTime;
        cout << "Enter new ID: ";
        cin >> newId;
        cout << "Enter new Name: ";
        cin >> newName;
        cout << "Enter new Date: ";
        cin >> newDate;
        cout << "Enter new Time: ";
        cin >> newTime;
        id.push_back(newId);
        name.push_back(newName);
        date.push_back(newDate);
        time.push_back(newTime);
    }

    void viewData() {
        for (size_t i = 0; i < name.size(); i++) {
            cout << "ID is: " << id[i] << endl << " Name is: " << name[i] << endl << " Date is: " << date[i] << endl << " Time is: " << time[i] << endl;
        }
    }

    void updateData(string tgt) {
        bool found = false;
        for (size_t i = 0; i < name.size(); i++) {
            if (name[i] == tgt) {
                cout << "Enter new ID: ";
                cin >> id[i];
                cout << "Enter new Name: ";
                cin >> name[i];
                cout << "Enter new Date: ";
                cin >> date[i];
                cout << "Enter new Time: ";
                cin >> time[i];
                found = true;
            }
        }
        if (!found) {
            cout << "Result not found";
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of persons: ";
    cin >> n;
    vector<int> id(n);
    vector<string> name(n);
    vector<string> date(n);
    vector<string> time(n);
    cout << "Enter IDs, names, dates, and times: " << endl;
    for (int i = 0; i < n; i++) {
        cout << endl;
        cout << "------------------------Person No :" << i + 1 << "------------------------" << endl;
        cout << endl;
        cout << "Enter ID :";
        cin >> id[i];
        cout << endl;
        cout << "Enter Name :";
        cin >> name[i];
        cout << endl;
        cout << "Enter Date :";
        cin >> date[i];
        cout << endl;
        cout << "Enter Time :";
        cin >> time[i]; 
        cout << endl;
    }
    Person person(id, name, date, time);
    int choice;
    cout << "Choose an option: \n1. Add Data\n2. View Data\n3. Update Data\n4. Search Person\n5. Exit" << endl;
    cin >> choice;
    while (choice != 5) {
        switch (choice) {
            case 1: {
                person.addData(id, name, date, time);
                cout << endl;
                break;
            }
            case 2: {
                person.viewData();
                cout << endl;
                break;
            }
            case 3: {
                string tgt;
                cout << "Enter name to update: ";
                cin >> tgt;
                person.updateData(tgt);
                cout << endl;
                break;
            }
            case 4: {
                string tgt;
                cout << "Enter name to search: ";
                cin >> tgt;
                person.searchPerson(tgt);
                cout << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please choose a valid option." << endl;
            }
        }
        cout << "Choose an option: \n1. Add Data\n2. View Data\n3. Update Data\n4. Search Person\n5. Exit" << endl;
        cin >> choice;
    }
    return 0;
}