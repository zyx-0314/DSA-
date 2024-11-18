#include <iostream>
#include <string>
using namespace std;
// Structure to store patient details
struct Patient {
  string name;
  int age;
  string gender;
  string illness;
  string contact;
};
int main() {
  const int MAX_PATIENTS = 10;    // Max number of patients
  Patient patients[MAX_PATIENTS]; // Array to store patient data
  int totalPatients = 0;          // Current number of patients
  int choice;
  bool maxLimitReached = false; // Flag to check if max limit is reached
  do {
    // Menu for CRUD operations
    cout << "\n--- Patient Management ---\n";
    cout << "1. Create Patient Record\n";
    cout << "2. Display Patient Records\n";
    cout << "3. Update Patient Record\n";
    cout << "4. Delete Patient Record\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 1) { // Create
      if (totalPatients >= MAX_PATIENTS) {
        cout << "Cannot add more patients. Max limit reached.\n";
        maxLimitReached = true; // Set flag to true
      } else {
        cin.ignore(); // Clear input buffer before getline
        cout << "Enter Name: ";
        getline(cin, patients[totalPatients].name);
        cout << "Enter Age: ";
        cin >> patients[totalPatients].age;
        cout << "Enter Gender: ";
        cin >> patients[totalPatients].gender;
        cin.ignore(); // Clear input buffer before getline
        cout << "Enter Illness: ";
        getline(cin, patients[totalPatients].illness);
        cout << "Enter Contact: ";
        getline(cin, patients[totalPatients].contact);
        totalPatients++;
        cout << "Patient record added successfully.\n";
        // Check if max limit is reached after adding a patient
        if (totalPatients >= MAX_PATIENTS) {
          maxLimitReached = true; // Set flag to true
        }
      }
    } else if (choice == 2) { // Read
      if (totalPatients == 0) {
        cout << "No patients found.\n";
      } else {
        for (int i = 0; i < totalPatients; ++i) {
          cout << "\nPatient " << i + 1 << ":\n";
          cout << "Name: " << patients[i].name << endl;
          cout << "Age: " << patients[i].age << endl;
          cout << "Gender: " << patients[i].gender << endl;
          cout << "Illness: " << patients[i].illness << endl;
          cout << "Contact: " << patients[i].contact << endl;
        }
      }
    } else if (choice == 3) { // Update
      int patientNumber;
      cout << "Enter patient number to update: ";
      cin >> patientNumber;
      if (patientNumber < 1 || patientNumber > totalPatients) {
        cout << "Invalid patient number.\n";
      } else {
        int index = patientNumber - 1;
        cin.ignore(); // Clear input buffer before getline
        cout << "Enter new Name: ";
        getline(cin, patients[index].name);
        cout << "Enter new Age: ";
        cin >> patients[index].age;
        cout << "Enter new Gender: ";
        cin >> patients[index].gender;
        cin.ignore(); // Clear input buffer before getline
        cout << "Enter new Illness: ";
        getline(cin, patients[index].illness);
        cout << "Enter new Contact: ";
        getline(cin, patients[index].contact);
        cout << "Patient record updated successfully.\n";
      }
    } else if (choice == 4) { // Delete
      int patientNumber;
      cout << "Enter patient number to delete: ";
      cin >> patientNumber;
      if (patientNumber < 1 || patientNumber > totalPatients) {
        cout << "Invalid patient number.\n";
      } else {
        int index = patientNumber - 1;
        for (int i = index; i < totalPatients - 1; ++i) {
          patients[i] = patients[i + 1];
        }
        totalPatients--;
        cout << "Patient record deleted successfully.\n";
        // Reset the maxLimitReached flag after deletion if the number of
        // patients falls below the max limit
        if (totalPatients < MAX_PATIENTS) {
          maxLimitReached = false;
        }
      }
    } else if (choice == 5) {
      cout << "Exiting...\n";
    } else {
      cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 5 &&
           !maxLimitReached); // Stop looping if max limit is reached
  return 0;
}
