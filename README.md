# ⚡ Electrical Load Management System (C++)

A console-based Electrical Load Management System developed using C++. This project focuses on managing electrical loads, monitoring their operating status, calculating total power consumption, and checking power factor conditions.

It combines fundamental Electrical Engineering concepts with C++ programming techniques to demonstrate how software can be used for basic electrical load management.

##  Features

- **Add New Loads:** Add electrical loads with unique IDs, names, voltage, current, and power factor.
- **View All Loads:** Display complete information about all registered loads.
- **Search Loads:** Find loads using their names.
- **Load Status Control:** Turn individual loads ON or OFF.
- **Power Calculation:** Calculate the power consumption of individual active loads.
- **Total Power Monitoring:** Calculate the combined power consumption of all active loads.
- **Power Factor Analysis:** Identify loads with low power factors (below 0.8).
- **Input Validation:** Prevent duplicate IDs and invalid electrical parameter values.
- **Data Persistence:** Save load information in a text file and retrieve it when the program starts again.

##  Technologies & Concepts

**Programming Language**
- C++

**C++ Concepts Implemented**
- Object-Oriented Programming (OOP)
- Classes and Objects
- Constructors (Default and Parameterized)
- Encapsulation
- Private and Public Access Specifiers
- Member Functions
- Vectors (`<vector>`)
- File Handling (`<fstream>`)
- Conditional Statements
- Loops and Switch-Case
- String Manipulation
- Getters and Setters
- Functions and Data Validation

**Libraries Used**
- `<iostream>`
- `<fstream>`
- `<vector>`
- `<string>`

##  Electrical Engineering Concepts

The project incorporates basic electrical power calculations.

**Active Power Calculation:**

\[
P = \frac{V \times I \times PF}{1000}
\]

Where:
- P = Active Power (kW)
- V = Voltage (V)
- I = Current (A)
- PF = Power Factor

**Power Factor Condition:**
- PF < 0.8 → Low Power Factor
- PF ≥ 0.8 → Normal Power Factor

**Total Power:**

\[
P_{total} = \sum P_i
\]

Only active (ON) loads contribute to the total power consumption.

##  Project Structure

```text
Electrical-Load-Management/
│
├── main.cpp
├── loads.txt          (Generated automatically)
└── README.md
```

*Note: The source file may have a different filename depending on the project setup.*

##  How to Run

1. Clone or download this repository.
2. Open the project folder in VS Code.
3. Open the terminal.
4. Compile the C++ source file:

```bash
g++ main.cpp -o load_management
```

5. Run the program:

**Windows:**
```bash
.\load_management.exe
```

##  Main Menu

```text
Electrical Load Management
==============================
1. Add Load
2. Show All Loads
3. Search Load
4. Turn Load ON/OFF
5. Total Power
6. Check Power Factor
0. Exit
==============================
Enter choice:
```

## Data Storage

The system uses file handling to maintain load information.

- `loads.txt` stores the registered load information.
- Data is saved when the user exits the program.
- Previously saved data is loaded automatically when the program starts again.

##  Project Objectives

- Apply OOP principles in a practical programming project.
- Understand the implementation of vectors and file handling in C++.
- Connect programming logic with fundamental Electrical Engineering concepts.
- Develop a basic system for electrical load monitoring and management.

##  Author

**Shakhawat Hossain**  
Department of Electrical and Electronic Engineering (EEE)  
Ahsanullah University of Science and Technology (AUST)

---

*Developed as an academic programming project.*