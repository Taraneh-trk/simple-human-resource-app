# HR Management System

A console-based Human Resources Management System built in C++ for managing company employee data. This project demonstrates fundamental C++ concepts including object-oriented programming, file I/O operations, inheritance, polymorphism, and template functions.

## Overview

This HR Management System is designed as a learning project to practice C++ file handling operations and object-oriented programming concepts. The system allows users to manage employee information across different teams within a company, including database teams, programming teams, testers, and security guards.

## Features

### Authentication System
- User account creation and login functionality
- Password-protected access to the system
- Account credentials stored in text files

### Employee Management
- **Add Employees**: Add new employees to different teams
- **View Employees**: Display employee information by team or all teams
- **Search Employees**: Find specific employees by name and lastname
- **Edit Employees**: Modify existing employee information
- **Delete Employees**: Remove employees from the system
- **Team Statistics**: View total number of employees per team

### Team Categories
- **Database Team**: Manage database administrators and developers
- **Programming Team**: Handle software developers and programmers
- **Testers**: Manage quality assurance and testing personnel
- **Guardians**: Handle security and facility management staff

### Employee Attributes
- Name and lastname
- Position/team assignment
- Work experience (years)
- Salary information
- Level classification (Admin/Ordinary)
- Team level (Junior/Intermediate/Senior)

## System Requirements

- C++ compiler (GCC, Visual Studio, Code::Blocks, etc.)
- Windows OS (uses `conio.h` for console operations)
- Minimum 512MB RAM
- 10MB free disk space for data files

## Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Taraneh-trk/simple-human-resource-app.git
   cd simple-human-resource-app
   ```

2. **Compile the program:**
   ```bash
   g++ -o HR1.cpp
   ```
   
   Or using your preferred IDE:
   - Open the project in Code::Blocks, Visual Studio, or Dev-C++
   - Build and compile the project

3. **Run the executable:**
   ```bash
   ./HR1
   ```

## Usage

### First Time Setup

1. **Account Creation:**
   - On first run, the system will prompt you to create an account
   - Enter a username (string) and password (integer)
   - The system will create necessary data files automatically

2. **Login:**
   - Use your created credentials to access the system
   - The system will verify your credentials against stored data

### Main Menu Options

After successful login, you'll see the following menu:

```
1- show     : Display employee information
2- add      : Add new employees
3- delete   : Remove employees
4- search   : Find specific employees
5- edit     : Modify employee information
6- total number : View team statistics
7- exit     : Close the application
```

### Adding Employees

1. Select option 2 from the main menu
2. Choose the target team (Database/Programming/Testers/Guardians)
3. Specify the number of employees to add
4. Enter employee details for each person:
   - Name and lastname
   - Level (-1 for admin, -2 for ordinary)
   - Team level (0 for junior, 1 for intermediate, 2 for senior)
   - Salary amount
   - Work experience in years

### Searching and Editing

- **Search**: Use option 4 to find employees by name and lastname
- **Edit**: Use option 5 to modify existing employee information
- **Delete**: Use option 3 to remove employees from the system

## Project Structure

```
hr-management-system/
│
├── main.cpp                    # Main source code file
├── login.txt                   # User credentials storage
├── DatabaseTeam info.txt       # Database team employee data
├── ProgrammingTeam info.txt    # Programming team employee data
├── Testers info.txt           # Testing team employee data
├── guardians info.txt         # Security team employee data
└── README.md                  # Project documentation
```

## File Structure

The system uses text files to store data:

### login.txt
Stores user authentication information:
```
username1
password1
username2
password2
```

### Team Information Files
Each team file follows this format:
```
start
employee_name
employee_lastname
level_code
team_level_code
salary
work_experience
```

## Classes and Architecture

### Core Classes

- **Login**: Handles user authentication and account management
- **Person**: Base class for all personnel with common attributes
- **Admin**: Inherited from Person, represents administrative staff
- **OrdinaryStaff**: Inherited from Person, represents regular employees
- **Menu**: Main interface controller managing all user interactions

### Team Classes (Inherited from OrdinaryStaff)

- **DatabaseTeam**: Database administrators and developers
- **ProgrammingTeam**: Software developers and programmers
- **Tester**: Quality assurance personnel
- **guardian**: Security and facility management staff

### Enumerations

- **Level**: `admin (-1)`, `ordinary (-2)`
- **TeamLevel**: `junior (0)`, `intermed (1)`, `senior (2)`

### Key Features

- **Template Functions**: Generic functions for handling different team types
- **Operator Overloading**: Custom input/output operators for employee data
- **File I/O Operations**: Persistent data storage using text files
- **Polymorphism**: Virtual functions for different employee types

## Data Management

### File Operations
- **Create**: New employee records are appended to team files
- **Read**: Employee data is loaded from text files on demand
- **Update**: Modified records overwrite existing file content
- **Delete**: Records are removed by rewriting files without deleted entries

### Data Validation
- Username and password verification during login
- Team level and employee level validation using enumerations
- File existence checking before operations

## Known Issues

1. **Platform Dependency**: Uses `conio.h` which is Windows-specific
2. **Data Types**: Some inconsistencies in integer type usage (int vs long long int)
3. **Error Handling**: Limited error handling for file operations
4. **Memory Management**: Uses variable-length arrays which may not be portable
5. **Input Validation**: Limited validation for user input data

## Contributing

This project is designed for learning purposes. If you'd like to contribute:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/improvement`)
3. Make your changes and test thoroughly
4. Commit your changes (`git commit -am 'Add new feature'`)
5. Push to the branch (`git push origin feature/improvement`)
6. Create a Pull Request

## License

This project is created for educational purposes. Feel free to use, modify, and distribute as needed for learning and educational activities.

---

**Note**: This is a learning project focused on demonstrating C++ concepts including file handling, object-oriented programming, inheritance, and polymorphism. It may not be suitable for production use without significant enhancements in security, error handling, and data validation.
