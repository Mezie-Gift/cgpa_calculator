---

# CGPA Calculator

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Description
The CGPA Calculator is a simple C++ console application that allows students to calculate their Cumulative Grade Point Average (CGPA) and Grade Point Average (GPA) based on their grades and credit units for different courses. This tool is useful for students who want to keep track of their academic performance over various semesters or academic years.

## Features
- Calculate GPA for a specific semester.
- Calculate CGPA for a particular academic year or the entire course duration.
- Validate user input for grades and credit units.
- Support for multiple courses and semesters.

## Installation
You have two options to run the CGPA Calculator:

### Option 1: Downloading the Executable File
1. Go to the [Releases](https://github.com/yourusername/cgpa_calculator/releases) section of the repository.
2. Download the executable file for your operating system.
3. Open a terminal or command prompt in the directory where you downloaded the executable.
4. Run the executable file:
    ```bash
    ./cgpa_calculator  # On Linux or macOS
    cgpa_calculator.exe  # On Windows
    ```

### Option 2: Compiling from Source
To compile and run the CGPA Calculator from source code, ensure you have a C++ compiler installed on your machine. Follow these steps:

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/cgpa_calculator.git
    cd cgpa_calculator
    ```

2. Compile the program:
    ```bash
    g++ -o cgpa_calculator main.cpp
    ```

3. Run the program:
    ```bash
    ./cgpa_calculator
    ```

## Usage
Upon running the program, you will be prompted to choose between calculating your GPA for a specific semester or calculating your CGPA for a particular year or the entire course duration. Follow the on-screen instructions to input your grades and credit units.

### GPA Calculation
1. Select option `b` to calculate your GPA for a specific semester.
2. Enter the number of courses you offered in the semester.
3. For each course, input your grade and the corresponding credit unit.

### CGPA Calculation
1. Select option `a` to calculate your CGPA for a particular year or the entire course duration.
2. Enter your name and the number of years your course lasts.
3. For each year and each semester, input the number of courses, grades, and credit units.

## Examples
### Example 1: Calculating GPA for a Semester
```
What do you want to do?:
a. Calculate your CGPA for a particular year(level) or for your entire college/university course duration? OR
b. Calculate your CGPA for a specific semester?
Input either a or b: b

Enter your name: John Doe
How many courses did you offer this semester: 3
For the 3 courses you offered this semester, input your grade and the credit unit of each course separated by a tab:
COURSES GRADES CREDIT UNIT
Course 1: A     3
Course 2: B     2
Course 3: C     3

John Doe, Your GPA for this semester is 3.33
```

### Example 2: Calculating CGPA for a Year
```
What do you want to do?:
a. Calculate your CGPA for a particular year(level) or for your entire college/university course duration? OR
b. Calculate your CGPA for a specific semester?
Input either a or b: a

Enter your name: Jane Smith
How many years course are you studying: 2

FOR YEAR 1: 1st SEMESTER
Enter the number of courses you offered for YEAR 1, 1st SEMESTER: 3
For the 3 courses you offered, input your grade and the credit unit for each of the course separated by a tab:
COURSES GRADES CREDIT UNIT
Course 1: A     3
Course 2: B     2
Course 3: C     3

The sum of your Quality Point is = 24
The sum of your Credit Unit is = 8
Your GPA for year 1, 1st SEMESTER is 3.00

...

Jane Smith, Your CGPA is 3.25
```

## Contributing
Contributions are welcome! If you have any ideas, suggestions, or bug reports, feel free to open an issue or submit a pull request. Please ensure that your contributions align with the project's coding style and standards.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact
If you have any questions or feedback, feel free to contact me at [iammeziegift@gmail.com](mailto:iammeziegift@gmail.com).

---
