#include <iostream>
#include <vector>
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

    void bubble_sortID(vector<int>& id,vector<string>& name,vector<string>& type,vector<string>& date,vector<string>& time){
        int n = id.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(id[j]>id[j+1]){
                    swap(id[j],id[j+1]);
                    swap(name[j],name[j+1]);
                    swap(type[j],type[j+1]);
                    swap(date[j],date[j+1]);
                    swap(time[j],time[j+1]);
                }
            }
        }
    }
    void Selection_Sorting(vector<int>& id,vector<string>& name,vector<string>& type,vector<string>& date,vector<string>& time){
        int n = id.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(id[i]>id[j]){
                    swap(id[i],id[j]);
                    swap(name[i],name[j]);
                    swap(type[i],type[j]);
                    swap(date[i],date[j]);
                    swap(time[i],time[j]);

                }
            }
        }
    }
    void addPerson() {
        int personID;
        string personName, personType, personDate, personTime;
        cout << "\n--- Add New Person ---\n";
        cout << "Enter ID: ";
        cin >> personID;
        cout << "Enter Name: ";
        cin >> personName;
        cout << "Enter Type (e.g., Milk/Curd): ";
        cin >>personType;
        cout << "Enter Date (YYYY-MM-DD): ";
        cin >> personDate;
        cout << "Enter Time (HH:MM): ";
        cin >> personTime;
        id.push_back(personID);
        name.push_back(personName);
        type.push_back(personType);
        date.push_back(personDate);
        time.push_back(personTime);
        bubble_sortID(id,name,type,date,time);
        // Selection_Sorting(id,name,type,date,time);
        cout << "Person added successfully!\n";
        


    }

    void searchPerson() {
        if (name.empty()) {
            cout << "No records available to search.\n";
            return;
        }

        string tgt;
        cout << "Enter name to search: ";
        cin >> tgt;

        bool found = false;
        int start = 0,end = name.size()-1 , mid ;

        while(start<=end){
        mid = (start + end)/2;
        if(tgt == name[mid]){
                cout << "\n--- Person Found ---\n";
                cout << "ID: " << id[mid] << "\n";
                cout << "Name: " << name[mid] << "\n";
                cout << "Type: " << type[mid] << "\n";
                cout << "Date: " << date[mid] << "\n";
                cout << "Time: " << time[mid] << "\n";
                found = true;
                break;
            break;
        }
        else if (tgt < name[mid])
        {
            end = mid - 1;
        }
        else if (tgt > name[mid])
        {
            start = mid + 1;
        }
        else {
            cout << "Not founded" << endl;
        }
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
