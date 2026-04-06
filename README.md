# Console-based-Student-Management-System-using--three-types-of-data-structures
This is my first-year project from BUBT, demonstrating my knowledge of C++ basics. The Student Management System is a console-based application designed to manage student records. It allows users to insert, view, search, delete, update, sort, undo and display statistics of student information.

```mermaid
flowchart TD
    A([START]) --> B[Display Menu]
    B --> C[Enter Choice]

    C --> D{Select Option}

    D -->|1| E[Insert Student]
    D -->|2| F[Search Student]
    D -->|3| G[Delete Student]
    D -->|4| H[Update Student]
    D -->|5| I[Sort Student]
    D -->|6| J[Statistics]
    D -->|7| K[Undo]
    D -->|8| L[Exit]

    E --> B
    F --> B
    G --> B
    H --> B
    I --> B
    J --> B
    K --> B

    L --> M([END])

    %% Styling
    style A fill:#00ffcc,stroke:#000,color:#000
    style M fill:#ff9999,stroke:#000,color:#000
    style D fill:#ffd966,stroke:#000,color:#000
    style B fill:#cfe2ff,stroke:#000
    style C fill:#cfe2ff,stroke:#000

    style E fill:#d9ead3
    style F fill:#d9ead3
    style G fill:#f4cccc
    style H fill:#fff2cc
    style I fill:#d0e0e3
    style J fill:#ead1dc
    style K fill:#e6b8af
