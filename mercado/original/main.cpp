#include <iostream>
#include <string>

using namespace std;

struct PatientRecord {
  string FirstName;
  string LastName;
  string Age;
  string Arrival;
};

void RegisterPatient(PatientRecord *, int);
void InputField(const string &, string &);
void ShowAllPatients(PatientRecord *, int);
void ModifyPatient(PatientRecord *, int);
void DeletePatient(PatientRecord *, int);

int main() {
  PatientRecord Records[10];
  int Position;
  while (true) {
    cout << "Please choose an index for storing patient data (0-9): ";
    cin >> Position;
    cin.ignore();
    if (Position >= 0 && Position < 10) {
      RegisterPatient(&Records[Position], Position);
      break;
    } else {
      cout << "Index out of range." << endl;
    }
  }
  int Action;
  do {
    cout << "\nMenu:\n1. View all patients\n2. Edit patient data\n3. Delete"
            " patient data\n4.Exit program\nYour selection : ";
    cin >> Action;
    cin.ignore();
    switch (Action) {
    case 1:
      ShowAllPatients(Records, 10);
      break;
    case 2:
      while (true) {
        cout << "Which index would you like to update (0-9)?: ";
        cin >> Position;
        cin.ignore();
        if (Position >= 0 && Position < 10) {
          ModifyPatient(&Records[Position], Position);
          break;
        } else {
          cout << "Invalid index." << endl;
        }
      }
      break;
    case 3:
      while (true) {
        cout << "Which index would you like to delete (0-9)?: ";
        cin >> Position;
        cin.ignore();
        if (Position >= 0 && Position < 10) {
          DeletePatient(&Records[Position], Position);
          break;
        } else {
          cout << "Invalid index." << endl;
        }
      }
      break;
    case 4:
      cout << "Exiting the program.\n";
      break;
    default:
      cout << "Unrecognized option" << endl;
    }
  } while (Action != 4);
}

// Function to register a patient
void RegisterPatient(PatientRecord *record, int index) {
  cout << "Registering patient at index " << index << endl;
  InputField("First Name", record->FirstName);
  InputField("Last Name", record->LastName);
  InputField("Age", record->Age);
  InputField("Arrival Date", record->Arrival);
}

// Function to input field data
void InputField(const string &prompt, string &field) {
  cout << "Enter " << prompt << ": ";
  getline(cin, field);
}

// Function to show all patients
void ShowAllPatients(PatientRecord *records, int size) {
  cout << "Patient Records:\n";
  for (int i = 0; i < size; i++) {
    if (!records[i].FirstName.empty()) { // Show only filled records
      cout << "Index " << i << ": " << records[i].FirstName << " "
           << records[i].LastName << ", Age: " << records[i].Age
           << ", Arrival: " << records[i].Arrival << endl;
    }
  }
}

// Function to modify patient data
void ModifyPatient(PatientRecord *record, int index) {
  cout << "Modifying patient at index " << index << endl;
  InputField("New First Name", record->FirstName);
  InputField("New Last Name", record->LastName);
  InputField("New Age", record->Age);
  InputField("New Arrival Date", record->Arrival);
}

// Function to delete patient data
void DeletePatient(PatientRecord *record, int index) {
  cout << "Deleting patient at index " << index << endl;
  record->FirstName.clear();
  record->LastName.clear();
  record->Age.clear();
  record->Arrival.clear();
  cout << "Patient data deleted successfully." << endl;
}
