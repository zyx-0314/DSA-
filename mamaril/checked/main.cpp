#include <iostream>
#include <string>

using namespace std;

struct Patient {
  string firstName;
  string lastName;
  int age;
  string gender;
  string contactNumber;
  string address;
  string condition;
  bool isEmpty;
};

void addPatient(Patient patients[], int &count);
void displayPatients(const Patient patients[], int count);
void editPatient(Patient patients[], int count);
void deletePatient(Patient patients[], int &count);

int main() {
  const int MAX_PATIENTS = 10;
  Patient patients[MAX_PATIENTS];
  int patientCount = 0;
  int choice;

  for (int i = 0; i < MAX_PATIENTS; i++) {
    patients[i].isEmpty = true;
  }

  do {
    cout << "\nPatient Registration System\n";
    cout << "1. Add Patient\n";
    cout << "2. Display Patients\n";
    cout << "3. Edit Patient\n";
    cout << "4. Delete Patient\n";
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
      if (patientCount > 0) {
        editPatient(patients, patientCount);
      } else {
        cout << "No patients available to edit.\n";
      }
      break;
    case 4:
      if (patientCount > 0) {
        deletePatient(patients, patientCount);
      } else {
        cout << "No patients available to delete.\n";
      }
      break;
    case 5:
      cout << "Exiting the system.\n";
      break;
    default:
      cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 5);
  return 0;
}

void addPatient(Patient patients[], int &count) {
  if (count >= 10) {
    cout << "Patient limit reached. Cannot add more patients.\n";
    return;
  }
  int index;
  cout << "\nEnter the index (0-9) where you want to add the patient: ";
  cin >> index;
  if (index < 0 || index >= 10) {
    cout << "Invalid index. Please choose an index between 0 and 9.\n";
    return;
  }
  if (!patients[index].isEmpty) {
    cout << "Index " << index
         << " is already occupied. Please choose a "
            "different index.\n ";
    return;
  }
  cout << "\nAdding Patient to index " << index << ":\n";
  cout << "Enter patient first name: ";
  cin.ignore();
  getline(cin, patients[index].firstName);
  cout << "Enter patient last name: ";
  getline(cin, patients[index].lastName);
  cout << "Enter patient age: ";
  cin >> patients[index].age;
  cout << "Enter patient gender (Male/Female/Other): ";
  cin.ignore();
  getline(cin, patients[index].gender);
  cout << "Enter patient contact number: ";
  getline(cin, patients[index].contactNumber);
  cout << "Enter patient address: ";
  getline(cin, patients[index].address);
  cout << "Enter patient condition: ";
  getline(cin, patients[index].condition);
  patients[index].isEmpty = false;
  count++;
  cout << "Patient added successfully at index " << index << ".\n";
}

void displayPatients(const Patient patients[], int count) {
  if (count == 0) {
    cout << "\nNo patients to display.\n";
    return;
  }
  cout << "\nList of Patients:\n";
  for (int i = 0; i < 10; i++) {
    if (!patients[i].isEmpty) {
      cout << "Patient at index " << i << ":\n";
      cout << "First Name: " << patients[i].firstName << "\n";
      cout << "Last Name: " << patients[i].lastName << "\n";
      cout << "Age: " << patients[i].age << "\n";
      cout << "Gender: " << patients[i].gender << "\n";
      cout << "Contact Number: " << patients[i].contactNumber << "\n";
      cout << "Address: " << patients[i].address << "\n";
      cout << "Condition: " << patients[i].condition << "\n\n";
    }
  }
}

void editPatient(Patient patients[], int count) {
  int index;
  cout << "\nEnter the index number to edit (0 to 9): ";
  cin >> index;
  if (index < 0 || index >= 10 || patients[index].isEmpty) {
    cout << "Invalid index or no patient data at this index.\n";
    return;
  }
  cout << "\nEditing Patient at index " << index << ":\n";
  cout << "Enter new first name (" << patients[index].firstName << "): ";
  cin.ignore();
  getline(cin, patients[index].firstName);
  cout << "Enter new last name (" << patients[index].lastName << "): ";
  getline(cin, patients[index].lastName);
  cout << "Enter new age (" << patients[index].age << "): ";
  cin >> patients[index].age;
  cout << "Enter new gender (" << patients[index].gender << "): ";
  cin.ignore();
  getline(cin, patients[index].gender);
  cout << "Enter new contact number (" << patients[index].contactNumber
       << "): ";
  getline(cin, patients[index].contactNumber);
  cout << "Enter new address (" << patients[index].address << "): ";
  getline(cin, patients[index].address);
  cout << "Enter new condition (" << patients[index].condition << "): ";
  getline(cin, patients[index].condition);
  cout << "Patient information updated successfully.\n";
}

void deletePatient(Patient patients[], int &count) {
  int index;
  cout << "\nEnter the index number to delete (0 to 9): ";
  cin >> index;
  if (index < 0 || index >= 10 || patients[index].isEmpty) {
    cout << "Invalid index or no patient data at this index.\n";
    return;
  }
  // Mark the patient slot as empty
  patients[index].firstName = "";
  patients[index].lastName = "";
  patients[index].age = 0;
  patients[index].gender = "";
  patients[index].contactNumber = "";
  patients[index].address = "";
  patients[index].condition = "";
  patients[index].isEmpty = true;
  count--;
  cout << "Patient deleted successfully from index " << index << ".\n";
}
