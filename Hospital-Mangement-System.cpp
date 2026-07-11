#include <iostream>
#include <cstring>
using namespace std;

#define MAX_APPOINTMENTS 100
#define MAX_RECORDS 100
#define MAX_BILLS 100
#define MAX_ROOMS 50

// ========== USER BASE CLASS ==========
class User {
protected:
    char name[50];
    char id[20];
public:
    User(const char* name, const char* id) {
        strcpy(this->name, name);
        strcpy(this->id, id);
    }

    virtual void showMenu() = 0;
    const char* getName() { return name; }
    const char* getId() { return id; }
};

// ========== ADMIN ==========
class Admin : public User {
public:
    Admin(const char* name, const char* id) : User(name, id) {}
    void showMenu() {
        cout << "--- Admin Menu ---" << endl;
        cout << "1. Add Doctor" << endl;
        cout << "2. Remove Doctor" << endl;
        cout << "3. Add Receptionist" << endl;
        cout << "4. Remove Receptionist" << endl;
        cout << "5. View All Appointments" << endl;
        cout << "6. View Billing Summary" << endl;
        cout << "7. Logout" << endl;
    }
};

// ========== DOCTOR ==========
class Doctor : public User {
public:
    Doctor(const char* name, const char* id) : User(name, id) {}
    void showMenu() {
        cout << "--- Doctor Menu ---" << endl;
        cout << "1. View Schedule" << endl;
        cout << "2. Add Medical Record" << endl;
        cout << "3. View Medical Record" << endl;
        cout << "4. Logout" << endl;
    }
};

// ========== PATIENT ==========
class Patient : public User {
public:
    Patient(const char* name, const char* id) : User(name, id) {}
    void showMenu() {
        cout << "--- Patient Menu ---" << endl;
        cout << "1. Register/Update Profile" << endl;
        cout << "2. Book Appointment" << endl;
        cout << "3. View Appointment" << endl;
        cout << "4. Cancel Appointment" << endl;
        cout << "5. View Medical Record" << endl;
        cout << "6. View Bills" << endl;
        cout << "7. Logout" << endl;
    }
};

// ========== RECEPTIONIST ==========
class Receptionist : public User {
public:
    Receptionist(const char* name, const char* id) : User(name, id) {}
    void showMenu() {
        cout << "--- Receptionist Menu ---" << endl;
        cout << "1. Register New Patient" << endl;
        cout << "2. Schedule Appointment" << endl;
        cout << "3. Assign Room" << endl;
        cout << "4. Handle Billing" << endl;
        cout << "5. Logout" << endl;
    }
};

// ========== USER FACTORY ==========
class UserFactory {
    public:
        static User* createUser(const char* role, const char* name, const char* id) {
            User* user = nullptr;
    
            if (strcmp(role, "Admin") == 0) {
                user = new Admin(name, id);
            }
            else if (strcmp(role, "Doctor") == 0) {
                user = new Doctor(name, id);
            }
            else if (strcmp(role, "Patient") == 0) {
                user = new Patient(name, id);
            }
            else if (strcmp(role, "Receptionist") == 0) {
                user = new Receptionist(name, id);
            }
    
            return user;
        }
    };    

// ========== APPOINTMENT ==========
class Appointment {
public:
    char doctorId[20];
    char patientId[20];
    char date[20];
    char status[20];

    Appointment() {
        strcpy(doctorId, "");
        strcpy(patientId, "");
        strcpy(date, "");
        strcpy(status, "");
    }

    void setAppointment(const char* docId, const char* patId, const char* dt, const char* st) {
        strcpy(doctorId, docId);
        strcpy(patientId, patId);
        strcpy(date, dt);
        strcpy(status, st);
    }

    void viewAppointment() {
        cout << "Doctor ID: " << doctorId << ", Patient ID: " << patientId;
        cout << ", Date: " << date << ", Status: " << status << endl;
    }
};

// ========== MEDICAL RECORD ==========
class MedicalRecord {
public:
    char patientId[20];
    char doctorId[20];
    char diagnosis[100];
    char treatment[100];

    MedicalRecord() {
        strcpy(patientId, "");
        strcpy(doctorId, "");
        strcpy(diagnosis, "");
        strcpy(treatment, "");
    }

    void setRecord(const char* pId, const char* dId, const char* diag, const char* treat) {
        strcpy(patientId, pId);
        strcpy(doctorId, dId);
        strcpy(diagnosis, diag);
        strcpy(treatment, treat);
    }

    void viewRecord() {
        cout << "Patient ID: " << patientId << ", Doctor ID: " << doctorId << endl;
        cout << "Diagnosis: " << diagnosis << ", Treatment: " << treatment << endl;
    }
};

// ========== BILLING ==========
class Billing {
public:
    char patientId[20];
    float amount;
    char status[10]; // Paid or Unpaid

    Billing() {
        strcpy(patientId, "");
        amount = 0.0;
        strcpy(status, "Unpaid");
    }

    void generateBill(const char* pId, float amt) {
        strcpy(patientId, pId);
        amount = amt;
        strcpy(status, "Unpaid");
    }

    void markAsPaid() {
        strcpy(status, "Paid");
    }

    void viewBill() {
        cout << "Patient ID: " << patientId << ", Amount: Rs. " << amount;
        cout << ", Status: " << status << endl;
    }
};

// ========== ROOM ==========
class Room {
public:
    int roomNumber;
    bool isOccupied;
    char patientId[20];

    Room() {
        roomNumber = 0;
        isOccupied = false;
        strcpy(patientId, "");
    }

    void assignRoom(int number, const char* pId) {
        roomNumber = number;
        isOccupied = true;
        strcpy(patientId, pId);
    }

    void vacateRoom() {
        isOccupied = false;
        strcpy(patientId, "");
    }

    void viewRoom() {
        cout << "Room Number: " << roomNumber << ", Occupied: "
             << (isOccupied ? "Yes" : "No");
        if (isOccupied)
            cout << ", Patient ID: " << patientId;
        cout << endl;
    }
};

// ========== HOSPITAL MANAGER ==========
class HospitalManager {
private:
    static HospitalManager* instance;

    Appointment appointments[MAX_APPOINTMENTS];
    MedicalRecord records[MAX_RECORDS];
    Billing bills[MAX_BILLS];
    Room rooms[MAX_ROOMS];

    int appointmentCount = 0;
    int recordCount = 0;
    int billCount = 0;
    int roomCount = 0;

    HospitalManager() {
        for (int i = 0; i < MAX_ROOMS; i++) {
            rooms[i].roomNumber = i + 1;
        }
    }

public:
    static HospitalManager* getInstance() {
        if (!instance)
            instance = new HospitalManager();
        return instance;
    }

    // Appointment
    void bookAppointment(const char* docId, const char* patId, const char* date) {
        if (appointmentCount < MAX_APPOINTMENTS) {
            appointments[appointmentCount++].setAppointment(docId, patId, date, "Booked");
            cout << "Appointment booked." << endl;
        }
    }

    void viewAppointments() {
        for (int i = 0; i < appointmentCount; i++)
            appointments[i].viewAppointment();
    }

    // Medical Records
    void addMedicalRecord(const char* patId, const char* docId, const char* diag, const char* treat) {
        if (recordCount < MAX_RECORDS) {
            records[recordCount++].setRecord(patId, docId, diag, treat);
            cout << "Medical record added." << endl;
        }
    }

    void viewMedicalRecords(const char* patId) {
        for (int i = 0; i < recordCount; i++)
            if (strcmp(records[i].patientId, patId) == 0)
                records[i].viewRecord();
    }

    // Billing
    void createBill(const char* patId, float amount) {
        if (billCount < MAX_BILLS) {
            bills[billCount++].generateBill(patId, amount);
            cout << "Bill created." << endl;
        }
    }

    void viewBills() {
        for (int i = 0; i < billCount; i++)
            bills[i].viewBill();
    }

    // Room
    void assignRoom(const char* patId) {
        for (int i = 0; i < MAX_ROOMS; i++) {
            if (!rooms[i].isOccupied) {
                rooms[i].assignRoom(i + 1, patId);
                cout << "Room " << (i + 1) << " assigned." << endl;
                return;
            }
        }
        cout << "No available rooms." << endl;
    }

    void viewRooms() {
        for (int i = 0; i < MAX_ROOMS; i++)
            rooms[i].viewRoom();
    }
};

HospitalManager* HospitalManager::instance = nullptr;

// ========== MAIN FUNCTION ==========
int main() {
    HospitalManager* hm = HospitalManager::getInstance();

    char role[20], name[50], id[20];
    User* currentUser = nullptr;

    cout << "Welcome to Hospital Management System" << endl;

    while (true) {
        cout << endl;
        cout << "Login as (Admin / Doctor / Patient / Receptionist): ";
        cin >> role;

        cout << "Enter name: ";
        cin.ignore();
        cin.getline(name, 50);

        cout << "Enter ID: ";
        cin >> id;

        currentUser = UserFactory::createUser(role, name, id);
        if (!currentUser) {
            cout << "Invalid role. Try again." << endl;
            continue;
        }

        int choice;
        while (true) {
            currentUser->showMenu();
            cout << "Enter choice: ";
            cin >> choice;

            if (strcmp(role, "Admin") == 0) {
                if (choice == 5) hm->viewAppointments();
                else if (choice == 6) hm->viewBills();
                else if (choice == 7) break;
                else cout << "Simulated action done." << endl;
            }
            else if (strcmp(role, "Doctor") == 0) {
                if (choice == 1) hm->viewAppointments();
                else if (choice == 2) {
                    char pid[20], diag[100], treat[100];
                    cout << "Patient ID: ";
                    cin >> pid;
                    cin.ignore();
                    cout << "Diagnosis: ";
                    cin.getline(diag, 100);
                    cout << "Treatment: ";
                    cin.getline(treat, 100);
                    hm->addMedicalRecord(pid, id, diag, treat);
                }
                else if (choice == 3) {
                    char pid[20];
                    cout << "Patient ID: ";
                    cin >> pid;
                    hm->viewMedicalRecords(pid);
                }
                else if (choice == 4) break;
            }
            else if (strcmp(role, "Patient") == 0) {
                if (choice == 2) {
                    char docId[20], date[20];
                    cout << "Doctor ID: ";
                    cin >> docId;
                    cout << "Date: ";
                    cin >> date;
                    hm->bookAppointment(docId, id, date);
                }
                else if (choice == 3) hm->viewAppointments();
                else if (choice == 5) hm->viewMedicalRecords(id);
                else if (choice == 6) hm->viewBills();
                else if (choice == 7) break;
                else cout << "Simulated." << endl;
            }
            else if (strcmp(role, "Receptionist") == 0) {
                if (choice == 2) {
                    char docId[20], patId[20], date[20];
                    cout << "Doctor ID: ";
                    cin >> docId;
                    cout << "Patient ID: ";
                    cin >> patId;
                    cout << "Date: ";
                    cin >> date;
                    hm->bookAppointment(docId, patId, date);
                }
                else if (choice == 3) {
                    char patId[20];
                    cout << "Patient ID: ";
                    cin >> patId;
                    hm->assignRoom(patId);
                }
                else if (choice == 4) {
                    char patId[20]; 
                    float amt;
                    cout << "Patient ID: ";
                    cin >> patId;
                    cout << "Amount: ";
                    cin >> amt;
                    hm->createBill(patId, amt);
                }
                else if (choice == 5) break;
                else cout << "Simulated." << endl;
            }
        }

        delete currentUser;
        currentUser = nullptr;

        char again;
        cout << "Login again? (y/n): ";
        cin >> again;
        if (again == 'n' || again == 'N') break;
    }

    cout << "Thank you for using the Hospital Management System!" << endl;
    return 0;
}
