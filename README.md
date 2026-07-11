# 🏥 Hospital Management System

A console-based Hospital Management System built in C++ using Object-Oriented Programming (OOP) principles. Features role-based access for Admin, Doctor, Patient, and Receptionist with appointment scheduling, medical records, billing, and room management.

---

## ✨ Features

| Feature | Description |
|---------|-------------|
| 👤 **Role-Based Login** | Admin, Doctor, Patient, Receptionist — each with their own menu |
| 📅 **Appointment System** | Book, view, and manage patient appointments |
| 📝 **Medical Records** | Doctors can add and view patient diagnoses & treatments |
| 💰 **Billing System** | Generate bills, track payment status (Paid/Unpaid) |
| 🏨 **Room Management** | Assign rooms to patients, track occupancy |
| 🏗️ **Singleton Pattern** | HospitalManager ensures single instance across the system |
| 🏭 **Factory Pattern** | UserFactory creates users dynamically based on role |

---

## 🚀 Getting Started

### Prerequisites
- A C++ compiler (GCC, Clang, or MSVC)

### Compilation
```bash
g++ Hospital-Management-System.cpp -o hospital
```

### Run
```bash
./hospital
```

---

## 🎮 How to Use

1. **Run the program**
2. **Login** with your role:
   - `Admin` — Manage staff, view all appointments & billing
   - `Doctor` — View schedule, add/view medical records
   - `Patient` — Book appointments, view records & bills
   - `Receptionist` — Register patients, schedule appointments, assign rooms, handle billing
3. Enter your **Name** and **ID**
4. Use the **menu** to perform actions
5. Type `Logout` choice to switch users or exit

---

## 📸 Sample Run

```
Welcome to Hospital Management System

Login as (Admin / Doctor / Patient / Receptionist): Doctor
Enter name: Dr. Ahmed
Enter ID: DOC001

--- Doctor Menu ---
1. View Schedule
2. Add Medical Record
3. View Medical Record
4. Logout
Enter choice: 2
Patient ID: PAT001
Diagnosis: Fever
Treatment: Paracetamol 500mg
Medical record added.
```

---

## 🛠️ Tech Stack

- C++ (Object-Oriented Programming)
- Classes & Inheritance (User base class)
- Singleton Pattern (HospitalManager)
- Factory Pattern (UserFactory)
- Arrays for data storage
- Console UI

---

## 🗂️ Project Structure

```
.
├── Hospital-Management-System.cpp    # Main source code
├── README.md                         # Project overview
├── .gitignore                        # Git ignore rules
└── .gitattributes                    # Language detection rules
```

---

## 🏗️ OOP Concepts Used

| Concept | Implementation |
|---------|---------------|
| **Inheritance** | `Admin`, `Doctor`, `Patient`, `Receptionist` inherit from `User` |
| **Polymorphism** | `showMenu()` is virtual — each role has its own menu |
| **Encapsulation** | Private data members with public getter methods |
| **Singleton** | `HospitalManager` ensures only one instance exists |
| **Factory** | `UserFactory` creates appropriate user object dynamically |
| **Abstraction** | `User` is an abstract base class with pure virtual function |

---

## 👥 Roles & Permissions

| Role | Permissions |
|------|-------------|
| **Admin** | Add/remove doctors & receptionists, view all appointments & bills |
| **Doctor** | View schedule, add/view medical records |
| **Patient** | Book/view/cancel appointments, view records & bills |
| **Receptionist** | Register patients, schedule appointments, assign rooms, handle billing |

---

## 📄 License

This project is for educational purposes.
