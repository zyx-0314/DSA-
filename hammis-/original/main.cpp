#include <iostream>
#include <string>

using namespace std;

struct PatientInfo {
  string firstName = "";
  string lastName = "";
  string patientAge = "";
  string arrivalDate = "";
};

void AddPatient(PatientInfo *, int);
void userInput(string, string &);
void ShowAllPatients(PatientInfo *, int);
void ModifyPatient(PatientInfo *, int);
void RemovePatient(PatientInfo *, int);

int main() {
  PatientInfo hospitalRecords[10];
  int selectedIndex;
  while (true) {
    cout << "Select an index to register a patient (0-9): ";
    cin >> selectedIndex;
    cin.ignore();
    if (selectedIndex >= 0 && selectedIndex < 10) {
      AddPatient(&hospitalRecords[selectedIndex], selectedIndex);
      break;
    } else {
      cout << "Index out of range. Please try again.\n";
    }
  }
  int userChoice;
  do {
    cout << "\nAvailable Actions:\n1. Display all records\n2. Update patient "
            "data\n3.Remove a patient\n4.Exit\nChoose an option : ";
    cin >> userChoice;
    cin.ignore();
    switch (userChoice) {
    case 1:
      ShowAllPatients(hospitalRecords, 10);
      break;
    case 2:
      while (true) {
        cout << "Enter index to modify (0-9): ";
        cin >> selectedIndex;
        cin.ignore();
        if (selectedIndex >= 0 && selectedIndex < 10) {
          ModifyPatient(&hospitalRecords[selectedIndex], selectedIndex);
          break;
        } else {
          cout << "Invalid index. Please try again.\n";
        }
      }
      break;
    case 3:
      while (true) {
        cout << "Enter index to remove patient (0-9): ";
        cin >> selectedIndex;
        cin.ignore();
        if (selectedIndex >= 0 && selectedIndex < 10) {
          RemovePatient(&hospitalRecords[selectedIndex], selectedIndex);
          break;
        } else {
          cout << "Invalid index. Please try again.\n";
        }
      }
      break;
    case 4:
      cout << "Exiting program...\n";
      break;
    default:
      cout << "Invalid choice. Please select a valid option.\n";
    }
  } while (userChoice != 4);
}

void AddPatient(PatientInfo *patientRecord, int index) {
  cout << "Adding patient at index " << index << "...\n";
  userInput("Enter First Name: ", patientRecord->firstName);
  userInput("Enter Last Name: ", patientRecord->lastName);
  userInput("Enter Age: ", patientRecord->patientAge);
  userInput("Enter Arrival Date: ", patientRecord->arrivalDate);
}

void userInput(string prompt, string &inputField) {
  cout << prompt;
  getline(cin, inputField);
}

void ShowAllPatients(PatientInfo *patientRecords, int recordCount) {
  cout << "\nDisplaying patient records:\n";
  for (int i = 0; i < recordCount; i++) {
    if (patientRecords[i].firstName != "") {
      cout << "Patient at index " << i << ":\n";
      cout << "First Name: " << patientRecords[i].firstName << "\n";
      cout << "Last Name: " << patientRecords[i].lastName << "\n";
      cout << "Age: " << patientRecords[i].patientAge << "\n";
      cout << "Arrival Date: " << patientRecords[i].arrivalDate << "\n\n";
    } else {
      cout << "No data for patient at index " << i << ".\n\n";
    }
  }
}

void ModifyPatient(PatientInfo *patientRecord, int index) {
  cout << "Modifying patient data at index " << index << "...\n";
  userInput("Update First Name: ", patientRecord->firstName);
  userInput("Update Last Name: ", patientRecord->lastName);
  userInput("Update Age: ", patientRecord->patientAge);
  userInput("Update Arrival Date: ", patientRecord->arrivalDate);
}

void RemovePatient(PatientInfo *patientRecord, int index) {
  cout << "Removing patient at index " << index << "...\n";
  patientRecord->firstName = "";
  patientRecord->lastName = "";
  patientRecord->patientAge = "";
  patientRecord->arrivalDate = "";
  cout << "Patient data at index " << index << " has been removed.\n";
}
