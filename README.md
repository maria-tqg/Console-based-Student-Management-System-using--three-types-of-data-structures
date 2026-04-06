# 📘 Student Management System (C++)

This is my first-year project from BUBT, demonstrating my knowledge of C++ basics and data structures.  
The system allows users to insert, view, search, delete, update, sort, undo, and display statistics of student records.

---

## ✨ Features

- Add Student
- View All Students
- Search by ID & Name
- Delete Student
- Update Student
- Sort Students
- Undo Last Action (Stack)
- Display Statistics (Queue)

---

##📌 Project Type

Console-based application

---

##👨‍💻 Author

*MST. Maria Akter*

---

##📄 License

This project is for educational purposes.

---

## 🔄 Flowchart

```mermaid
flowchart TD
    A([START]) --> B[Display Menu]
    B --> C[Enter Choice]

    C --> D{Select Operation}

    D -->|Insert| E[Insert Student]
    D -->|Search| F[Search Student]
    D -->|Delete| G[Delete Student]

    E --> H[Update Student]
    F --> H
    G --> H

    H --> I[Sort Student]
    I --> J[Display Statistics]
    J --> K[Undo Action]

    K --> L{Exit?}
    L -->|No| B
    L -->|Yes| M([END])

🛠️ Technologies Used
C++
Data Structures:
Array
Stack (Linked List)
Queue (Linked List)
