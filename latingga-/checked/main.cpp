#include <iostream>
#include <string>

using namespace std;

struct Patient {
  string fName;
  string lName;
  string gender;
  string birthdate;
  int age;
  string address;
  string disease;
  string phoneNumber;
  string email;
};

void addPatient(Patient *patients, int *numPatients) {
  if (*numPatients < 10) {
    cout << "\nAdding Patient " << *numPatients + 1 << ":\n";
    cout << "First Name : ";
    getline(cin, patients[*numPatients].fName);
    cout << "Last Name : ";
    getline(cin, patients[*numPatients].lName);
    cout << "Gender : ";
    getline(cin, patients[*numPatients].gender);
    cout << "Birthdate : ";
    getline(cin, patients[*numPatients].birthdate);
    cout << "Age : ";
    cin >> patients[*numPatients].age;
    cin.ignore();
    cout << "Address : ";
    getline(cin, patients[*numPatients].address);
    cout << "Disease : ";
    getline(cin, patients[*numPatients].disease);
    cout << "Phone Number : ";
    getline(cin, patients[*numPatients].phoneNumber);
    cout << "Email : ";
    getline(cin, patients[*numPatients].email);
    (*numPatients)++;
  } else {
    cout << "Patient limit reached.\n";
  }
}

void displayPatients(Patient *patients, int numPatients) {
  cout << "\nList of Patients\n";
  for (int i = 0; i < numPatients; i++) {
    cout << "\nPatient " << i + 1 << "\n";
    cout << "First Name : " << patients[i].fName << endl;
    cout << "Last Name : " << patients[i].lName << endl;
    cout << "Gender : " << patients[i].gender << endl;
    cout << "Birthdate : " << patients[i].birthdate << endl;
    cout << "Age : " << patients[i].age << endl;
    cout << "Address : " << patients[i].address << endl;
    cout << "Disease : " << patients[i].disease << endl;
    cout << "Phone Number : " << patients[i].phoneNumber << endl;
    cout << "Email : " << patients[i].email << endl;
  }
}

void updatePatient(Patient *patients, int numPatients) {
  int index;
  cout << "\nPlease enter patient number: ";
  cin >> index;
  cin.ignore();
  if (index > 0 && index <= numPatients) {
    index--;
    cout << "\nUpdating Patient " << index + 1 << "\n";
    cout << "First Name : ";
    getline(cin, patients[index].fName);
    cout << "Last Name : ";
    getline(cin, patients[index].lName);
    cout << "Gender : ";
    getline(cin, patients[index].gender);
    cout << "Birthdate : ";
    getline(cin, patients[index].birthdate);
    cout << "Age : ";
    cin >> patients[index].age;
    cin.ignore();
    cout << "Address : ";
    getline(cin, patients[index].address);
    cout << "Disease : ";
    getline(cin, patients[index].disease);
    cout << "Phone Number : ";
    getline(cin, patients[index].phoneNumber);
    cout << "Email : ";
    getline(cin, patients[index].email);
  } else {
    cout << "Invalid patient number.\n";
  }
}

void deletePatient(Patient *patients, int *numPatients,
                   const int MAX_PATIENTS) {
  int index = -1;

  while (0 > index || MAX_PATIENTS < index) {
    cout << "\nPlease enter patient number to delete: ";
    cin >> index;
    cin.ignore();
  }

  if (index > 0 && index <= *numPatients) {
    index--;
    for (int i = index; i < MAX_PATIENTS - 1; i++) {
      patients[i] = patients[i + 1];
    }
    (*numPatients)--;
    cout << "Patient deleted successfully.\n";
  } else {
    cout << "Invalid patient number.\n";
  }
}

int main() {
  const int MAX_PATIENTS = 10;
  Patient patients[MAX_PATIENTS];
  int numPatients = 0;
  while (true) {
    int choice;
    cout << "\n---------------MENU---------------\n";
    cout << "1. Add Patient\n";
    cout << "2. Display all Patients\n";
    cout << "3. Update Patient\n";
    cout << "4. Delete Patient\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();
    switch (choice) {
    case 1:
      addPatient(patients, &numPatients);
      break;
    case 2:
      displayPatients(patients, numPatients);
      break;
    case 3:
      updatePatient(patients, numPatients);
      break;
    case 4:
      deletePatient(patients, &numPatients, MAX_PATIENTS);
      break;
    case 5:
      cout << "Exiting...\n";
      return 0;
    default:
      cout << "Invalid choice. Please select a valid option.\n";
    }
  }
  return 0;
}
