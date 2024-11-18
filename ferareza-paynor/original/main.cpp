#include <iostream>
#include <string>

using namespace std;

struct Patient {
  string name;
  int age;
  string disease;
};

void createPatient(Patient patients[], int &numPatients) {
  if (numPatients >= 10) {
    cout << "Maximum number of patients reached." << endl;
    return;
  }
  cout << "Enter patient name: ";
  getline(cin, patients[numPatients].name);
  cout << "Enter patient age: ";
  cin >> patients[numPatients].age;
  cin.ignore();
  cout << "Enter patient disease: ";
  getline(cin, patients[numPatients].disease);
  numPatients++;
  cout << "Patient added successfully!" << endl;
}

void readPatients(const Patient patients[], int numPatients) {
  cout << "\nPatient Data: " << endl;
  for (int i = 0; i < numPatients; i++) {
    cout << "Patient " << (i + 1) << ":" << endl;
    cout << "Name: " << patients[i].name << endl;
    cout << "Age: " << patients[i].age << endl;
    cout << "Disease: " << patients[i].disease << endl;
    cout << "-------------------------" << endl;
  }
}

void updatePatient(Patient patients[], int numPatients) {
  int index;
  string newName;

  cout << "Enter patient index to update (1 to " << numPatients << "): ";
  cin >> index;
  cin.ignore();
  index--;
  if (index < 0 || index >= numPatients) {
    cout << "Invalid index." << endl;
    return;
  }
  cout << "Updating details for " << patients[index].name << endl;
  cout << "Enter new name (leave blank to keep current): ";
  getline(cin, newName);
  if (!newName.empty()) {
    patients[index].name = newName;
  }
  cout << "Enter new age (-1 to keep current): ";
  int newAge;
  cin >> newAge;
  if (newAge != -1) {
    patients[index].age = newAge;
  }
  cin.ignore();
  cout << "Enter new disease (leave blank to keep current): ";
  string newDisease;
  getline(cin, newDisease);
  if (!newDisease.empty()) {
    patients[index].disease = newDisease;
  }
  cout << "Patient updated successfully!" << endl;
}

void deletePatient(Patient patients[], int &numPatients) {
  int index;

  cout << "Enter patient index to delete (1 to " << numPatients << "): ";
  cin >> index;
  cin.ignore();
  index--;
  if (index < 0 || index >= numPatients) {
    cout << "Invalid index." << endl;
    return;
  }
  for (int i = index; i < numPatients - 1; i++) {
    patients[i] = patients[i + 1];
  }
  numPatients--;
  cout << "Patient deleted successfully!" << endl;
}

int main() {
  Patient patients[10];
  int numPatients = 0;
  int choice;

  do {
    cout << "\nPatient Management System" << endl;
    cout << "1. Add Patient" << endl;
    cout << "2. View Patients" << endl;
    cout << "3. Update Patient" << endl;
    cout << "4. Delete Patient" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
    cin >> choice;
    cin.ignore();
    switch (choice) {
    case 1:
      createPatient(patients, numPatients);
      break;
    case 2:
      readPatients(patients, numPatients);
      break;
    case 3:
      updatePatient(patients, numPatients);
      break;
    case 4:
      deletePatient(patients, numPatients);
      break;
    case 5:
      cout << "Exiting program." << endl;
      break;
    default:
      cout << "Invalid option. Please try again." << endl;
    }
  } while (choice != 5);
  return 0;
}
