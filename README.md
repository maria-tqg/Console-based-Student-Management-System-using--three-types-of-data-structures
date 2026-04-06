# Console-based-Student-Management-System-using--three-types-of-data-structures
This is my first-year project from BUBT, demonstrating my knowledge of C++ basics. The Student Management System is a console-based application designed to manage student records. It allows users to insert, view, search, delete, update, sort, undo and display statistics of student information.

```markdown
```mermaid
flowchart TD
    A[START] --> B[Display Menu]
    B --> C[Enter Choice]

    C --> D{Choice}

    D -->|1| E[Insert Student]
    D -->|2| F[Search Student]
    D -->|3| G[Delete Student]
    D -->|4| H[Update Student]
    D -->|5| I[Sort Student]
    D -->|6| J[Display Statistics]
    D -->|7| K[Undo Action]
    D -->|8| L[Exit]

    E --> B
    F --> B
    G --> B
    H --> B
    I --> B
    J --> B
    K --> B

    L --> M[END]
