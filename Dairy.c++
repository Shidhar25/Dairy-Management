#include <iostream>
#include <vector>
using namespace std;

class Person {
private:
    vector<int> id;
    vector<string> name;
    vector<string> Type;
    vector<string> date;
    vector<string> time;

public:
    Person(vector<int> id, vector<string> name,vector<string> date,vector<string> time) : id(id), name(name),date(date),time(time) {}

    void searchPerson(string tgt) {
        bool found = false;
        int n = name.size();
        for (int i = 0; i < n; i++) {
            if (name[i] == tgt) {
                cout << "Found. ID is: " << id[i] << endl << " Name is: " << name[i] << endl << " Name is: " << date[i]<< endl << " Name is: " << time[i];
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
    cout << "Enter IDs and names: " << endl;
    for (int i = 0; i < n; i++) {
        cout << endl;
        cout << "------------------------Person No :" <<i+1 <<"------------------------"<< endl;
        cout << endl;
        cout << endl;
        cout << "Enter ID :";
        cin >> id[i];
        cout << "Enter Name :";
        cin >> name[i];
        cout << "Enter Date :";
        cin >> date[i];
        cout << "Enter ID :";
        cin >> time[i];
        
    }
    Person person(id, name,date,time);
    string tgt;
    cout << "Enter name to search: ";
    cin >> tgt;
    person.searchPerson(tgt);
    return 0;
}