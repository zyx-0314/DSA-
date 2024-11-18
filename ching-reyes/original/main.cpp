#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct Patient_Info {
  string first_name;
  string last_name;
  char Gender;
  string cont_num;
  string email;
  string address;
  int age;
  string Birthday;
  string illness;
  string Date_Checkup;
};

int Menu();
void Move(int choice);
bool INDEX(int index);
int Identify_Patient();
int Identify_Data();
void Remove(int ID, int DATA);
void Delete(int i);
void Delete_RC();
void Show(int index);
void input(int index);
void Loading_scr();
bool indexs(int ind);

int main() {
  const int MAX = 10;
  Patient_Info Patients[MAX];
  bool Exit = false;

  Move(Menu());
  do {
    Loading_scr();
    Move(Menu());
  } while (Exit == false);
}
void Loading_scr() {
  system("pause");
  system("cls");
  cout.width(65);
  cout << "==================================================================="
          "\n";
  cout.width(37);
  cout << "Loading\n";
  cout.width(65);
  cout << "==================================================================="
          "\n";
  system("pause");
  system("cls");
}
bool INDEX(int index) {
  if (index < 11) {
    if (index > 0) {
      return true;
    }
    if (index < 0) {
      return false;
    }
  } else {
    return false;
  }
}
bool indexs(int ind) {
  if (ind < 3) {
    if (ind > 0) {
      return true;
    }
    if (ind < 0) {
      return false;
    }
  } else {
    return false;
  }
}
int Identify_Patient() {
  int index, Index;
  do {
    cin.ignore();
    cout.width(65);
    cout << "=================================================================="
            "=\n";
    cout.width(52);
    cout << "Enter The ID (1-10) Of The Patient File: ";
    cin >> index;
    cout.width(65);
    cout << "=================================================================="
            "=\n";
  } while (INDEX(index) != true);
  Index = index - 1;
  Loading_scr();
  return Index;
}
int Identify_Data() {
  int Index;
  cout.width(65);
  cout << "==================================================================="
          "\n";
  cout.width(50);
  cout << "Choose Which Data To Edit:\n";
  cout.width(65);
  cout << "==================================================================="
          "\n";
  cout.width(37);
  cout << "[1] - Name\n";
  cout.width(40);
  cout << "[2] - Address\n";
  cout.width(41);
  cout << "[3] - Birthday\n";
  cout.width(36);
  cout << "[4] - Age\n";
  cout.width(39);
  cout << "[5] - Gender\n";
  cout.width(47);
  cout << "[6] - Contact Number\n";
  cout.width(38);
  cout << "[7] - Email\n";
  cout.width(40);
  cout << "[8] - Illness\n";
  cout.width(54);
  cout << "[9] - Date of Last Check Up\n";
  cout.width(65);
  cout << "==================================================================="
          "\n";
  cout << ": ";
  cin >> Index;
  Loading_scr();
  return Index;
}
void Remove(int ID, int DATA) {
  switch (DATA) {
  case 1:
    Patients[ID].first_name.clear();
    Patients[ID].last_name.clear();
    break;
  case 2:
    Patients[ID].adress.clear();
    break;
  case 3:
    Patients[ID].Birthday.clear();
    break;
  case 4:
    Patients[ID].age = '\0';
    break;
  case 5:
    Patients[ID].Gender = '\0';
    break;
  case 6:
    Patients[ID].cont_num.clear();
    break;
  case 7:
    Patients[ID].email.clear();
    break;
  case 8:
    Patients[ID].illness.clear();
    break;
  case 9:
    Patients[ID].Date_Checkup.clear();
    break;
  default:
    break;
  }
  cout.width(65);
  cout << "==================================================================="
          "\n";
  cout.width(50);
  cout << "[Successfully Deleted Data]\n";
  cout.width(65);
  cout << "==================================================================="
          "\n";
}
void Delete(int i) {
  Patients[i].first_name.clear();
  Patients[i].last_name.clear();
  Patients[i].age = '\0';
  Patients[i].Birthday.clear();
  Patients[i].cont_num.clear();
  Patients[i].email.clear();
  Patients[i].illness.clear();
  Patients[i].adress.clear();
  Patients[i].Gender = '\0';
  Patients[i].Date_Checkup.clear();
  cout.width(65);
  cout << "==================================================================="
          "\n";
  cout.width(50);
  cout << "[Successfully Deleted Data]\n";
  cout.width(65);
  cout << "==================================================================="
          "\n";
}
void Delete_RC() {
  for (int i = 0; i < 10; i++) {
    Patients[i].first_name.clear();
    Patients[i].last_name.clear();
    Patients[i].age = '\0';
    Patients[i].Birthday.clear();
    Patients[i].cont_num.clear();
    Patients[i].email.clear();
    Patients[i].illness.clear();
    Patients[i].adress.clear();
    Patients[i].Gender = '\0';
    Patients[i].Date_Checkup.clear();
  }
  cout.width(65);
  cout << "==================================================================="
          "\n";
  cout.width(50);
  cout << "[Successfully Deleted Data]\n";
  cout.width(65);
  cout << "==================================================================="
          "\n";
}
void Update(int ID, int DATA) {
  cout << "===================================================================\
n";
  cin.ignore();
  switch (DATA) {
  case 1:
    cout << "Enter Patient's Data\nFirst Name: ";
    getline(cin, Patients[ID].first_name);
    cout << "Last Name: ";
    getline(cin, Patients[ID].last_name);
    break;
  case 2:
    cout << "Address: ";
    getline(cin, Patients[ID].adress);
    break;
  case 3:
    cout << "Birthday: ";
    getline(cin, Patients[ID].Birthday);
    break;
  case 4:
    cout << "Age: ";
    cin >> Patients[ID].age;
    break;
  case 5:
    cout << "Gender[M/F]: ";
    cin >> Patients[ID].Gender;
    break;
  case 6:
    cout << "Contact Number: ";
    getline(cin, Patients[ID].cont_num);
    break;
  case 7:
    cout << "Email Address: ";
    getline(cin, Patients[ID].email);
    break;
  case 8:
    cout << "Illness: ";
    getline(cin, Patients[ID].illness);
    break;
  case 9:
    cout << "Date of Last Checkup: ";
    getline(cin, Patients[ID].Date_Checkup);
    break;
  default:
    break;
  }
  cout.width(65);
  cout << "==================================================================="
          "\n";
  cout.width(50);
  cout << "[Successfully Updated Data]\n";
  cout.width(65);
  cout << "==================================================================="
          "\n";
}
void Show(int index) {
  cin.ignore();
  cout << "=================================================================\n";
  cout << "Name: " << Patients[index].first_name << " "
       << Patients[index].last_name;
  cout << "\nBirthday: " << Patients[index].Birthday;
  cout << "\nAge: " << Patients[index].age;
  cout << "\nGender: " << Patients[index].Gender;
  cout << "\nContact Number: " << Patients[index].cont_num;
  cout << "\nEmail Address: " << Patients[index].email;
  cout << "\nAddress: " << Patients[index].adress;
  cout << "\nIllness: " << Patients[index].illness;
  cout << "\nDate of Last Check Up: " << Patients[index].Date_Checkup;
  cout << "\n=================================================================\
n";
}
void input(int index) {
  cin.ignore();
  cout << "=================================================================\n";
  cout << "Enter Patient's Data\nFirst Name: ";
  getline(cin, Patients[index].first_name);
  cout << "Last Name: ";
  getline(cin, Patients[index].last_name);
  cout << "Birthday: ";
  getline(cin, Patients[index].Birthday);
  cout << "Age: ";
  cin >> Patients[index].age;
  cout << "Gender[M/F]: ";
  cin >> Patients[index].Gender;
  cin.ignore();
  cout << "Contact Number: ";
  getline(cin, Patients[index].cont_num);
  cout << "Email Address: ";
  getline(cin, Patients[index].email);
  cout << "Address: ";
  getline(cin, Patients[index].adress);
  cout << "Illness: ";
  getline(cin, Patients[index].illness);
  cout << "Date of Last Checkup: ";
  getline(cin, Patients[index].Date_Checkup);
  cout.width(65);
  cout << "==================================================================="
          "\n";
  cout.width(50);
  cout << "[Successfully Added Data]\n";
  cout.width(65);
  cout << "==================================================================="
          "\n";
}
void Move(int choice) {
  int index;
  int ID = 0;
  int IDA = 0;
  switch (choice) {
  case 1:
    input(Identify_Patient());
    break;
  case 2:
    ID = Identify_Patient();
    IDA = Identify_Data();
    Remove(ID, IDA);
    break;
  case 3:
    do {
      cin.ignore();
      cout << "\n\
n==================================================================================
          == == == == == ==
          =\n ";
                   cout
                   << "Do You Wish To Update [1] A Part Of A Patient Record? Or [2]
                   The Entirety Of A Patient Record
               ?\n
               : ";
                     cin >>
                     index;
      cout << "==================================================================================
          == == == == == ==
          =\n\n ";
    } while (indexs(index) != true);
    if (index == 1) {
      ID = Identify_Patient();
      IDA = Identify_Data();
      Update(ID, IDA);
    } else if (index == 2) {
      input(Identify_Patient());
    }
    break;
  case 4:
    do {
      cin.ignore();
      cout << "\n\
n=================================================================================\
n";
      cout << "Do You Wish To Delete [1] A Specific Patient Record? Or [2]
              All Patient Records
          ?\n
          : ";
                cin >>
                index;
      cout
          << "=================================================================================\
n\n";
    } while (indexs(index) != true);
    if (index == 2) {
      Delete_RC();
    } else if (index == 1) {
      Delete(Identify_Patient());
    }
    break;
  case 5:
    Show(Identify_Patient());
    break;
  case 6:
    Exit = true;
    break;
  default:
    cout.width(65);
    cout << "=================================================================="
            "=\n";
    cout.width(37);
    cout << "Invalid\n";
    cout.width(65);
    cout << "=================================================================="
            "=\n";
    break;
  }
}
int Menu() {
  int choice;
  cin.ignore();
  cout << "=================================================================\n";
  cout.width(35);
  cout << "Menu\n";
  cout << "=================================================================\n";
  cout.width(39);
  cout << "[1] - Create\n";
  cout.width(39);
  cout << "[2] - Remove\n";
  cout.width(39);
  cout << "[3] - Update\n";
  cout.width(39);
  cout << "[4] - Delete\n";
  cout.width(37);
  cout << "[5] - View\n";
  cout.width(37);
  cout << "[6] - Exit\n";
  cout << "=================================================================\n";
  cout << ": ";
  cin >> choice;
  cout << "=================================================================\n\
n";
  return choice;
}
