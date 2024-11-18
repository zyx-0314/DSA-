#include <iostream>
#include <string>

using namespace std;

struct Patient {
  int id;
  string name;
  int age;
  string disease;
};

void createRecord(Patient patients[], int &numPatients);
void readRecords(Patient patients[], int numPatients);
void updateRecord(Patient patients[], int numPatients);
void deleteRecord(Patient patients[], const int MAX_PATIENT);

int main() {
  Patient patients[10]; // Max of 10 patients
  int numPatients = 0;  // Number of patients in the system
  int choice;

  do {
    cout << "\nPatient Record System\n";
    cout << "1. Create new record\n";
    cout << "2. Read all records\n";
    cout << "3. Update a record\n";
    cout << "4. Delete a record\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
      createRecord(patients, numPatients);
      break;
    case 2:
      readRecords(patients, numPatients);
      break;
    case 3:
      updateRecord(patients, numPatients);
      break;
    case 4:
      deleteRecord(patients, numPatients);
      break;
    case 5:
      cout << "Exiting...\n";
      break;
    default:
      cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 5);
  return 0;
}

// Create
void createRecord(Patient patients[], int &numPatients) {
  if (numPatients >= 10) {
    cout << "The amount of patients has exceed the limit.\n";
    return;
  }

  Patient newPatient;
  newPatient.id = numPatients + 1;
  cout << "Enter patient name: ";
  cin >> ws;
  getline(cin, newPatient.name);
  cout << "Enter age: ";
  cin >> newPatient.age;
  cout << "Enter disease: ";
  cin >> ws;
  getline(cin, newPatient.disease);
  patients[numPatients] = newPatient;
  numPatients++;
  cout << "Patient record added successfully.\n";
}

// Read
void readRecords(Patient patients[], int numPatients) {
  if (numPatients == 0) {
    cout << "No patient records to display.\n";
    return;
  }
  cout << "\nDisplaying patient records:\n";
  for (int i = 0; i < numPatients; i++) {
    cout << "ID: " << patients[i].id << ", Name: " << patients[i].name
         << ", Age: " << patients[i].age << ", Disease: " << patients[i].disease
         << endl;
  }
}

// Update
void updateRecord(Patient patients[], int numPatients) {
  int id;
  cout << "Enter patient ID to update: ";
  cin >> id;
  bool found = false;
  for (int i = 0; i < numPatients; i++) {
    if (patients[i].id == id) {
      found = true;
      cout << "Updating record for " << patients[i].name << "\n";
      cout << "Enter new name: ";
      cin >> ws;
      getline(cin, patients[i].name);
      cout << "Enter new age: ";
      cin >> patients[i].age;
      cout << "Enter new disease: ";
      cin >> ws;
      getline(cin, patients[i].disease);
      cout << "Record updated successfully.\n";
      break;
    }
  }
  if (!found) {
    cout << "Patient with ID " << id << " not found.\n";
  }
}

// Delete
void deleteRecord(Patient patients[], const int MAX_PATIENT) {
  int id;
  cout << "Enter patient ID to delete: ";
  cin >> id;
  bool found = false;
  for (int i = 0; i < MAX_PATIENT; i++) {
    if (patients[i].id == id) {
      found = true;
      for (int j = i; j < MAX_PATIENT - 1; j++) {
        patients[j] = patients[j + 1];
      }
      cout << "Patient record deleted successfully.\n";
      break;
    }
  }
  if (!found) {
    cout << "Patient with ID " << id << " not found.\n";
  }
}
