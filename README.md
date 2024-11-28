<h1><img src="https://raw.githubusercontent.com/ayogun/42-project-badges/refs/heads/main/covers/cover-cpp-bonus.png"></h1>

## Description
 This project simulates a bureaucracy in C++ with classes like Bureaucrat, Form, and Intern. It explores exceptions, grade-based access control, and dynamic form creation. The goal is to blend logical rigor with advanced object-oriented programming concepts. 

# C++ Module 05 - Bureaucracy Simulation

## Description
This module introduces C++ exception handling by simulating a bureaucratic environment. Through various exercises, we will build a class structure to model **Bureaucrats**, **Forms**, and other typical entities of a complex administration.

## Structure of Exercises
Each exercise builds on the previous one to add new functionalities and complexities.

## **Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!**

- Implement a `Bureaucrat` class with:
  - A constant name.
  - A grade between **1** (highest) and **150** (lowest).
  - Exceptions:
    - `GradeTooHighException` if the grade exceeds 1.
    - `GradeTooLowException` if the grade exceeds 150.
  - Methods:
    - `getName()` and `getGrade()`.
    - `incrementGrade()` and `decrementGrade()` to modify the grade.
  - Overload the `<<` operator to display `<name>, bureaucrat grade <grade>`.

### **Exercise 01: Form up, maggots!**

- Add a `Form` class with:
  - A constant name.
  - A signed state (initially `false`).
  - Two constant grades:
    - One to sign.
    - One to execute.
  - Methods:
    - Getters for all attributes.
    - `beSigned(Bureaucrat&)`: Allows a bureaucrat to sign the form if their grade is high enough; otherwise, throws an exception.
  - Exceptions:
    - `GradeTooHighException` and `GradeTooLowException`.
  - Add `Bureaucrat::signForm()` to handle form signing.

## **Exercise 02: No, you need form 28B, not 28C...**

- Create an abstract class `AForm` and three concrete classes:
  - `ShrubberyCreationForm`: Creates an ASCII file representing trees.
  - `RobotomyRequestForm`: Simulates robotization, succeeding 50% of the time.
  - `PresidentialPardonForm`: Announces that a pardon has been granted.
- Add:
  - `AForm::execute(Bureaucrat const&)`: Verifies if the form is signed and if the grade is sufficient.
  - `Bureaucrat::executeForm(AForm const&)`: Attempts to execute a form and handles errors.

## **Exercise 03: At least this beats coffee-making**

- Implement the `Intern` class:
  - Method `makeForm()`: Dynamically creates instances of forms (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`) based on a name and a target.
  - Handles errors if the form name is invalid.

## Compilation
A `Makefile` is provided for easy compilation of the files.
```bash
make
