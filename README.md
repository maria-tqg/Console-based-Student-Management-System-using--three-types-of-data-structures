# Console-based-Student-Management-System-using--three-types-of-data-structures
This is my first-year project from BUBT, demonstrating my knowledge of C++ basics. The Student Management System is a console-based application designed to manage student records. It allows users to insert, view, search, delete, update, sort, undo and display statistics of student information.

#FlowChart
```mermaid
flowchart TD
    A[START] --> B[Display Menu]
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
    L -->|Yes| M[END]
