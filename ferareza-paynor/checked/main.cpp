#include <iostream>
#include <string>

using namespace std;

struct Patient {
  string name = "";
  int age = -1;
  string disease = "";
};

void CreatePatient(Patient patients[], int &numPatients,
                   const int MAX_PATIENTS) {
  if (MAX_PATIENTS <= numPatients) {
    cout << "Maximum number of patients reached." << endl;
    return;
  }
  for (int i = 0; i < MAX_PATIENTS; i++) {
    if (0 > patients[i].age) {
      cout << "Enter patient name: ";
      getline(cin, patients[i].name);
      cout << "Enter patient age: ";
      cin >> patients[i].age;
      cin.ignore();
      cout << "Enter patient disease: ";
      getline(cin, patients[i].disease);
      break;
    }
  }
  cout << "Patient added successfully!" << endl;
}

void ReadPatients(const Patient patients[], const int MAX_PATIENTS) {
  cout << "\nPatient Data: " << endl;
  for (int i = 0; i < MAX_PATIENTS; i++) {
    if (0 <= patients[i].age) {
      cout << "Patient " << (i + 1) << ":" << endl;
      cout << "Name: " << patients[i].name << endl;
      cout << "Age: " << patients[i].age << endl;
      cout << "Disease: " << patients[i].disease << endl;
      cout << "-------------------------" << endl;
    }
  }
}

void UpdatePatient(Patient patients[], const int MAX_PATIENTS) {
  int index;
  int newAge;
  string newName;
  string newDisease;

  cout << "Enter patient index to update (1 to " << MAX_PATIENTS << "): ";
  cin >> index;
  cin.ignore();

  index--;

  if (0 > index || MAX_PATIENTS <= index) {
    cout << "Invalid index." << endl;
    return;
  }

  if (0 > patients[index].age) {
    cout << "No data inside";
    return;
  }

  cout << "Updating details for " << patients[index].name << endl;
  cout << "Enter new name (leave blank to keep current): ";
  getline(cin, newName);

  if (!newName.empty()) {
    patients[index].name = newName;
  }

  cout << "Enter new age (-1 to keep current): ";
  cin >> newAge;

  if (newAge != -1) {
    patients[index].age = newAge;
  }

  cin.ignore();
  cout << "Enter new disease (leave blank to keep current): ";
  getline(cin, newDisease);

  if (!newDisease.empty()) {
    patients[index].disease = newDisease;
  }

  cout << "Patient updated successfully!" << endl;
}

void DeletePatient(Patient patients[], const int MAX_PATIENTS) {
  int index = -1;

  while (0 > index || MAX_PATIENTS < index) {
    cout << "Enter patient index to delete (1 to " << MAX_PATIENTS << "): ";
    cin >> index;

    if (0 > index || MAX_PATIENTS < index) {
      cout << "Input Error, use only 1 - " << MAX_PATIENTS;
    }
  }

  index--;

  if (0 <= patients[index].age) {
    patients[index].name = "";
    patients[index].age = -1;
    patients[index].disease = "";

    cout << "Patient deleted successfully!" << endl;
  } else
    cout << "No Data to delete" << endl;
}

int main() {
  const int MAX_PATIENTS = 10;
  Patient patients[MAX_PATIENTS];
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

    switch (choice) {
    case 1:
      cin.ignore();
      CreatePatient(patients, numPatients, MAX_PATIENTS);
      numPatients++;
      break;
    case 2:
      ReadPatients(patients, MAX_PATIENTS);
      break;
    case 3:
      UpdatePatient(patients, numPatients);
      break;
    case 4:
      DeletePatient(patients, MAX_PATIENTS);
      numPatients--;
      break;
    case 5:
      cout << "Exiting program." << endl;
      exit(0);
    default:
      cout << "Invalid option. Please try again." << endl;
      break;
    }
  } while (choice != 5);
  return 0;
}
