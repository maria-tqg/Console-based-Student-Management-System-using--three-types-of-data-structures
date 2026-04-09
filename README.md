#  Student Management System (C++)

This is my second-year project from BUBT, demonstrating my knowledge of C++ basics and data structures.  
The system allows users to insert, view, search, delete, update, sort, undo, and display statistics of student records.


##  Features

- Add Student
- View All Students
- Search by ID & Name
- Delete Student
- Update Student
- Sort Students
- Undo Last Action (Stack)
- Display Statistics (Queue)



##  Project Type

Console-based application



##  Author

*MST. Maria Akter*


##  License

This project is for educational purposes.



##  Technologies Used

C++
Data Structures
Array
Stack (Linked List)
Queue (Linked List)

---
## FlowChart

```mermaid
flowchart TD
    A([START]) --> B[Display Menu]
    B --> C[Enter Choice]

    C --> D{Select Operation}

    D -->|1 Insert| E[Insert Student]
    D -->|2 View| F[View Students]
    D -->|3 Search| G[Search Student]
    D -->|4 Delete| H[Delete Student]
    D -->|5 Update| I[Update Student]
    D -->|6 Sort| J[Sort Students]
    D -->|7 Statistics| K[Display Statistics]
    D -->|8 Undo| L[Undo Action]
    D -->|9 Exit| M([END])

    E --> B
    F --> B
    G --> B
    H --> B
    I --> B
    J --> B
    K --> B
    L --> B
