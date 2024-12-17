# OCC Grade Report System

## Overview
This program implements a **Grade Report System** for managing and displaying student information. It allows users to perform operations such as printing student details, searching by name, modifying course numbers, and exporting data to a file.

The project is designed for **CS A250, Fall 2023**, by:
- Nguyen, Daniel
- Dang, Jayson
- Nguyen, Huy

---

## Features
- **Print All Students**: Displays all students' details including tuition fees.
- **Print Student Information**: View details of a student by their ID.
- **Search Student by Last Name**: Search and display a student's information using their last name.
- **Print Students by Course**: View all students enrolled in a specific course (prefix and course number).
- **Print Students on Hold**: List students with outstanding tuition payments.
- **Export Students to File**: Save all students' information to an output file.
- **Modify Course Number**: Change the course number for a given course prefix.
- **Exit**: Close the program.

---

## File Requirements
1. **Input File**: `student_data.txt`
   - Contains student information in a specific format required by the program.

2. **Source Code Files**:
   - `StudentList.h` / `StudentList.cpp`: Manages student data and operations.
   - `InputHandler.h` / `InputHandler.cpp`: Handles input file reading and data creation.
   - `OutputHandler.h` / `OutputHandler.cpp`: Handles output functionalities, such as printing to a file.
   - `main.cpp`: The driver file containing the program logic and menu interface.
