#include <iostream>
#include <string>

using namespace std;

struct patient {
  string fname = "";
  string lname = "";
  string age = "";
  string disease = "";
};

void AddPatient(patient *, int);
void DataEntry(string, string &);
void PatientDetail(patient *, int);
void DisplayAll(patient *, int);
void UpdatePatient(patient *, int);
void DeletePatient(patient *, int &);

int main() {
  patient Patients[10];
  int index = 0;
  int count = 0;
  int option;
  do {
    cout << "===========[ MENU ]===========\n"
         << "[ 1 ] ADD PATIENT\n"
         << "[ 2 ] PATIENT DETAILS\n"
         << "[ 3 ] DISPLAY ALL PATIENTS\n"
         << "[ 4 ] MODIFY PATIENT\n"
         << "[ 5 ] DELETE PATIENT\n"
         << "[ 6 ] EXIT\n"
         << "===============================\n"
         << "Input your choice: ";
    cin >> option;
    cin.ignore(); // To handle the newline after cin
    cout << "===============================\n";
    switch (option) {
    case 1:
      if (count < 10) {
        cout << "INPUT AN INDEX NUMBER [0 - 9]: ";
        cin >> index;
        cin.ignore();
        if (index >= 0 && index < 10) {
          AddPatient(&Patients[index], index);
          count++;
        } else {
          cout << "Invalid index. Please try again.\n";
        }
      } else {
        cout << "Patient list is full!\n";
      }
      break;
    case 2: {
      int indexToView;
      cout << "INPUT AN INDEX NUMBER [0 - 9]: ";
      cin >> indexToView;
      cin.ignore();
      PatientDetail(Patients, indexToView);
      break;
    }
    case 3:
      cout << "DISPLAYING ALL PATIENTS\n";
      DisplayAll(Patients, count);
      break;
    case 4: {
      int indexToUpdate;
      cout << "INPUT AN INDEX NUMBER [0 - 9]: ";
      cin >> indexToUpdate;
      cin.ignore();
      UpdatePatient(Patients, indexToUpdate);
      break;
    }
    case 5: {
      int indexToDelete;
      cout << "INPUT AN INDEX NUMBER [0 - 9]: ";
      cin >> indexToDelete;
      cin.ignore();
      DeletePatient(Patients, count);
      break;
    }
    case 6:
      cout << "Logging off.\n";
      break;
    default:
      cout << "Invalid Input. Try Again.\n";
    }
  } while (option != 6);
  return 0;
}

void AddPatient(patient *Patient, int index) {
  cout << "===============================\n";
  cout << "PATIENT INDEX NUMBER " << index << endl;
  DataEntry("Input First Name: ", Patient->fname);
  DataEntry("Input Last Name: ", Patient->lname);
  DataEntry("Input Age: ", Patient->age);
  DataEntry("Input Disease: ", Patient->disease);
}

void DataEntry(string instructions, string &input) {
  cout << instructions;
  getline(cin, input);
}

void PatientDetail(patient *Patients, int index) {
  if (index >= 0 && index < 10) {
    cout << "===============================\n";
    cout << "DISPLAYING PATIENT DETAILS OF INDEX NUMBER: " << index << "\n";
    cout << "First Name: " << Patients[index].fname << "\n";
    cout << "Last Name: " << Patients[index].lname << "\n";
    cout << "Age: " << Patients[index].age << "\n";
    cout << "Disease: " << Patients[index].disease << "\n";
  } else {
    cout << "Invalid index.\n";
  }
}

void DisplayAll(patient *Patients, int count) {
  cout << "\n";
  for (int i = 0; i < count; i++) {
    cout << "Index " << i << ": " << Patients[i].fname << " "
         << Patients[i].lname << "\n"
         << Patients[i].age << "\n"
         << Patients[i].disease << "\n\n";
  }
}

void UpdatePatient(patient *Patients, int index) {
  if (index >= 0 && index < 10) {
    cout << "UPDATING THE PATIENT AT INDEX NUMBER " << index << ":\n";
    cout << "New First Name: ";
    getline(cin, Patients[index].fname);
    cout << "New Last Name: ";
    getline(cin, Patients[index].lname);
    cout << "New Age: ";
    getline(cin, Patients[index].age);
    cout << "New Disease: ";
    getline(cin, Patients[index].disease);
  } else {
    cout << "Invalid index.\n";
  }
}

void DeletePatient(patient *Patients, int &count) {
  int index;
  cout << "INPUT AN INDEX NUMBER [0 - 9]: ";
  cin >> index;
  cin.ignore();
  if (index >= 0 && index < 10) {
    Patients[index] = {}; // Reset patient info
    cout << "PATIENT AT INDEX " << index << " HAS BEEN DELETED.\n";
    count--;
  } else {
    cout << "Invalid index.\n";
  }
}
