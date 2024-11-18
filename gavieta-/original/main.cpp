#include <iostream>
#include <string>

using namespace std;

struct Patient {
  string name;
  int age;
  string gender;
  string diagnosis;
  string contactNumber;
};

const int MAX_PATIENTS = 10;

void addPatient(Patient[], int &);
void displayPatients(const Patient[], int);
void updatePatient(Patient[], int);
void deletePatient(Patient[], int &);

int main() {
  Patient patients[MAX_PATIENTS];
  int patientCount = 0;
  int choice;
  do {
    cout << "\nPatient Management System\n";
    cout << "1. Add New Patient\n";
    cout << "2. Display Patient Records\n";
    cout << "3. Update Patient Record\n";
    cout << "4. Delete Patient Record\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
      addPatient(patients, patientCount);
      break;
    case 2:
      displayPatients(patients, patientCount);
      break;
    case 3:
      updatePatient(patients, patientCount);
      break;
    case 4:
      deletePatient(patients, patientCount);
      break;
    case 5:
      cout << "Thanks for using the System...\n";
      break;
    default:
      cout << "Invalid choice! Please try again.\n";
    }
  } while (choice != 5);
  return 0;
}

void addPatient(Patient patients[], int &count) {
  if (count >= MAX_PATIENTS) {
    cout << "Patient list is full! Maximum of 10 patients allowed.\n";
    return;
  }
  cout << "Enter Patient Name: ";
  cin.ignore();
  getline(cin, patients[count].name);
  cout << "Enter Patient Age: ";
  cin >> patients[count].age;
  cout << "Enter Patient Gender (Male/Female): ";
  cin >> patients[count].gender;
  cout << "Enter Patient Diagnosis: ";
  cin.ignore();
  getline(cin, patients[count].diagnosis);
  cout << "Enter Patient Contact Number: ";
  cin >> patients[count].contactNumber;
  count++;
  cout << "Patient added successfully!\n";
}
void displayPatients(const Patient patients[], int count) {
  if (count == 0) {
    cout << "No patient records to display.\n";
    return;
  }
  for (int i = 0; i < count; i++) {
    cout << "\nPatient " << i + 1 << " Details:\n";
    cout << "Name: " << patients[i].name << endl;
    cout << "Age: " << patients[i].age << endl;
    cout << "Gender: " << patients[i].gender << endl;
    cout << "Diagnosis: " << patients[i].diagnosis << endl;
    cout << "Contact Number: " << patients[i].contactNumber << endl;
  }
}
void updatePatient(Patient patients[], int count) {
  if (count == 0) {
    cout << "No patient records to update.\n";
    return;
  }
  int index;
  cout << "Enter patient number to update (1-" << count << "): ";
  cin >> index;
  index--;
  if (index < 0 || index >= count) {
    cout << "Invalid patient number!\n";
    return;
  }
  cout << "Updating Patient " << index + 1 << ":\n";
  cout << "Enter new Patient Name: ";
  cin.ignore();
  getline(cin, patients[index].name);
  cout << "Enter new Patient Age: ";
  cin >> patients[index].age;
  cout << "Enter new Patient Gender (Male/Female): ";
  cin >> patients[index].gender;
  cout << "Enter new Patient Diagnosis: ";
  cin.ignore();
  getline(cin, patients[index].diagnosis);
  cout << "Enter new Patient Contact Number: ";
  cin >> patients[index].contactNumber;
  cout << "Patient updated successfully!\n";
}
void deletePatient(Patient patients[], int &count) {
  if (count == 0) {
    cout << "No patient records to delete.\n";
    return;
  }
  int index;
  cout << "Enter patient number to delete (1-" << count << "): ";
  cin >> index;
  index--;
  if (index < 0 || index >= count) {
    cout << "Invalid patient number!\n";
    return;
  }
  for (int i = index; i < count - 1; i++) {
    patients[i] = patients[i + 1];
  }
  count--;
  cout << "Patient deleted successfully!\n";
}
