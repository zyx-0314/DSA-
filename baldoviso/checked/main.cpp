#include <iostream>
#include <string>

using namespace std;

// Structure representing a patient with basic information
struct patient {
  string fName = "";       // Patient's first name
  string lName = "";       // Patient's last name
  string age = "";         // Patient's age
  string arrivalDate = ""; // Date when the patient arrived
};

// Function declarations
void Registration(patient *, int); // Register a patient at a specific index
void DataEntry(string,
               string &); // Helper function to take input for patient data
void DisplayPatients(patient *, int); // Display all patients
void UpdatePatient(patient *,
                   int); // Update a patient's data at a specific index
void TerminatePatient(patient *, int); // Delete patient data

int main() {
  patient Patients[10]; // Array of 10 patients
  int index;
  char opt;

  cout << "Would you like to create a patient? y/n: "; // Run program or not
  cin >> opt;
  cin.ignore();

  if (opt == 'y') {
    // Loop until a valid index is provided for registration
    while (true) {
      cout << "Enter index to store patient data (0-9): ";
      cin >> index;
      cin.ignore(); // To ignore the newline character after input
      // Check if the index is valid
      if (index >= 0 && index < 10) {
        Registration(&Patients[index], index);
        break; // Exit loop if index is valid
      } else {
        cout << "Invalid index. Please try again.\n";
      }
    }
    // Menu for operations (display, update, delete)
    int choice;
    do {
      cout << "\nOptions:\n1. Display all patients\n2. Update a patient\n3. "
              "Delete a patient\n4.Exit\nEnter your choice : ";
      cin >> choice;
      cin.ignore(); // To ignore the newline character after input
      switch (choice) {
      case 1:
        // Display all patients
        DisplayPatients(Patients, 10);
        break;
      case 2:
        // Update patient at a specific index
        while (true) {
          cout << "Enter index to update (0-9): ";
          cin >> index;
          cin.ignore(); // To ignore the newline character after input
          // Check if the index is valid
          if (index >= 0 && index < 10) {
            UpdatePatient(&Patients[index], index);
            break; // Exit loop if index is valid
          } else {
            cout << "Invalid index. Please try again.\n";
          }
        }
        break;
      case 3: // Delete patient choice
        TerminatePatient(Patients, 10);
        break;
      case 4:
        cout << "Exiting...\n";
        break;
      default:
        cout << "Invalid choice. Try again.\n";
      }
    } while (choice != 4);
  } else if (opt == 'n') {
    cout << "Thank you for your time! ";
  } else {
    cout << "Invalid input! Please run the program again!";
  }
  return 0;
}

// Function for registering a new patient
void Registration(patient *Patient, int index) {
  cout << "Registering patient at index " << index << "...\n";
  DataEntry("First Name: ", Patient->fName);         // Collecting first name
  DataEntry("Last Name: ", Patient->lName);          // Collecting last name
  DataEntry("Age: ", Patient->age);                  // Collecting age
  DataEntry("Arrival Date: ", Patient->arrivalDate); // Collecting arrival date
}

// Function for entering patient data (modular approach)
void DataEntry(string instructions, string &input) {
  cout << instructions;
  getline(cin, input); // Reading input with spaces
}

// Function to display all patients' data
void DisplayPatients(patient *Patients, int size) {
  cout << "\nDisplaying all patients:\n";
  for (int i = 0; i < size; i++) {
    if (Patients[i].fName != "") { // Check if patient data exists
      cout << "Patient at index " << i << ":\n";
      cout << "First Name: " << Patients[i].fName << "\n";
      cout << "Last Name: " << Patients[i].lName << "\n";
      cout << "Age: " << Patients[i].age << "\n";
      cout << "Arrival Date: " << Patients[i].arrivalDate << "\n\n";
    } else {
      cout << "Patient at index " << i << " is empty.\n\n";
    }
  }
}

// Function to update a specific patient's data
void UpdatePatient(patient *Patient, int index) {
  cout << "Updating patient at index " << index << "...\n";
  DataEntry("First Name: ", Patient->fName);         // Updating first name
  DataEntry("Last Name: ", Patient->lName);          // Updating last name
  DataEntry("Age: ", Patient->age);                  // Updating age
  DataEntry("Arrival Date: ", Patient->arrivalDate); // Updating arrival date
}

// Function to remove a specific patient's data
void TerminatePatient(patient *Patients, int size) {
  int num;
  cout << "Please enter a patient index to terminate (0-9): ";
  cin >> num;
  // Check if the index is valid
  if (num >= 0 && num < size && Patients[num].fName != "") {
    // Clear patient data
    Patients[num].fName = "";
    Patients[num].lName = "";
    Patients[num].age = "";
    Patients[num].arrivalDate = "";
    cout << "Patient at index " << num << " has been deleted.\n";
  } else {
    cout << "Invalid index or no patient found at that index.\n";
  }
}
