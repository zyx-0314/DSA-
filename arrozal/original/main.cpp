#include <iostream>
#include <string>
using namespace std;

struct Patient {
  string name;
  int patientNumber;
  string illness;
  int roomNumber;
  string disease;
  int age;
  static const int MAX_PATIENTS = 10;
};

void ClearScreen() { system("cls"); }

void DisplayHeader(const string &headerTitle) {
  ClearScreen();
  cout << "***** " << headerTitle << " *****" << endl;
}

void DisplayMessage(const string &message) { cout << message << endl; }

void AddPatient(Patient patients[], int &numPatients) {
  if (numPatients >= Patient::MAX_PATIENTS) {
    DisplayMessage("Only 10 patients are allowed to register.");
    return;
  }
  ClearScreen();
  Patient newPatient;
  cout << "Enter patient name: ";
  getline(cin, newPatient.name);
  cout << "Enter patient age: ";
  cin >> newPatient.age;
  cin.ignore();
  cout << "Enter patient disease: ";
  getline(cin, newPatient.disease);
  patients[numPatients++] = newPatient;
  DisplayHeader("Patient Added");
  cout << "Patient details:\n";
  cout << "Name: " << newPatient.name << endl;
  cout << "Age: " << newPatient.age << endl;
  cout << "Disease: " << newPatient.disease << endl;
  cout << "-----------------------------" << endl;
}

void DisplayPatientNames(const Patient patients[], int numPatients) {
  if (numPatients == 0) {
    DisplayMessage("No patients have been added yet.");
    return;
  }
  DisplayHeader("List of Patients");
  for (int i = 0; i < numPatients; ++i) {
    cout << i + 1 << ". " << patients[i].name << endl;
  }
  cout << "-----------------------------" << endl;
}

int FindPatientByName(const Patient patients[], int numPatients,
                      const string &name) {
  for (int i = 0; i < numPatients; ++i) {
    if (patients[i].name == name) {
      return i;
    }
  }
  return -1;
}

void UpdatePatient(Patient patients[], int numPatients) {
  if (numPatients == 0) {
    DisplayMessage("No patients available to update.");
    return;
  }
  DisplayPatientNames(patients, numPatients);
  string name;
  cout << "Enter the name of the patient you wish to update: ";
  getline(cin, name);
  int patientIndex = FindPatientByName(patients, numPatients, name);
  if (patientIndex != -1) {
    cout << "Enter new age: ";
    cin >> patients[patientIndex].age;
    cin.ignore();
    cout << "Enter new disease: ";
    getline(cin, patients[patientIndex].disease);
    DisplayMessage("Patient information updated successfully!");
  } else {
    ClearScreen();
    DisplayMessage("Patient not found.");
  }
}

void DeletePatient(Patient patients[], int &numPatients) {
  string name;
  cout << "Enter the name of the patient to delete: ";
  getline(cin, name);
  int patientIndex = FindPatientByName(patients, numPatients, name);
  if (patientIndex != -1) {
    for (int i = patientIndex; i < numPatients - 1; ++i) {
      patients[i] = patients[i + 1];
    }
    numPatients--;
    DisplayMessage("Patient deleted successfully!");
  } else {
    ClearScreen();
    DisplayMessage("Patient not found.");
  }
}

void DisplayPatients(const Patient patients[], int numPatients) {
  if (numPatients == 0) {
    DisplayMessage("No patients to display.");
    return;
  }
  for (int i = 0; i < numPatients; ++i) {
    cout << "**** Patient " << i + 1 << " **** " << endl;
    cout << "Name: " << patients[i].name << endl;
    cout << "Age: " << patients[i].age << endl;
    cout << "Disease: " << patients[i].disease << endl;
    cout << "-----------------------------" << endl;
  }
}

void DisplayMenu() {
  cout << "\n***********************\n";
  cout << "\n W E L C O M E \n";
  cout << "\n***********************\n";
  cout << "\nPatient Record System:\n";
  cout << "\n \n";
  cout << "1. Add Patient\n";
  cout << "2. Update Patient Information\n";
  cout << "3. Delete Patient\n";
  cout << "4. Display All Patients\n";
  cout << "5. Exit\n";
  cout << "\n \n";
  cout << "Enter your choice: ";
}

int main() {
  Patient patients[Patient::MAX_PATIENTS];
  int numPatients = 0;
  int choice;
  do {
    DisplayMenu();
    cin >> choice;
    cin.ignore();
    switch (choice) {
    case 1:
      AddPatient(patients, numPatients);
      break;
    case 2:
      UpdatePatient(patients, numPatients);
      break;
    case 3:
      DeletePatient(patients, numPatients);
      break;
    case 4:
      DisplayPatients(patients, numPatients);
      break;
    case 5:
      DisplayMessage("Leaving the system... Thank you!");
      break;
    default:
      DisplayMessage("Invalid choice. Please try again.");
    }
  } while (choice != 5);
  return 0;
}
