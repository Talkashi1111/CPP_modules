# C++ Module 05: Exception handeling and Abstract classes

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Exercises](#exercises)
  - [00. Bureaucrat](#00-bureaucrat)
  - [01. Form](#01-form)
  - [02. AForm](#02-aform)
  - [03. Intern](#03-intern)
- [How to Use](#how-to-use)



## Overview

This module focuses on dynamic form creation in C++ using the `Intern` class and an abstract base class `AForm`. The goal is to implement a system where forms can be created and signed dynamically based on input, using C++ concepts such as pure virtual functions, exception handling, and function pointers.

## Features of this module

- **Custom Exceptions classes:** Exception handling ensures robust behavior with specific error messages for invalid inputs or range issues. learn how to build a costume exception class based on std::exception
- **Dynamic Polymorphism:** Derived classes implement their own versions of the **execute** function, allowing customized behavior for each form type. (pure virtual class)



## Exercises

### 00. Bureaucrat
### 01. Form
### 02. Aform
### 03. Intern

**Objective:** Implement a system to dynamically create and sign forms based on the input provided.

**Key Features:**

- **Exception Handling:** Custom exception classes are implemented, inheriting from the `<exception>` library, to handle invalid arguments and range errors effectively.
- **Pure Virtual Classes:** Utilized pure virtual functions like `virtual int execute(const Bureaucrat &b) const = 0;` to enforce specific implementations of the `execute` function for derived classes of `AForm`.
- **Dynamic Form Creation:** Implemented a **typedef** `typedef AForm* (*Prototypes)(std::string const &target);` to dynamically select and call the appropriate function pointer based on the string input. This makes the use of Prototypes more easy and more rle. 
- **Intern's Role:** The `Intern` class includes the `makeForm` method:
  ```cpp
  AForm *Intern::makeForm(std::string const &name, std::string const &target);
  ```
  This method dynamically creates the requested form while ensuring exception safety with proper error handling.



## How to Use

1. Clone this repository:
   ```bash
   git clone <repository-url>
   ```
2. Navigate to the `CPP_05` directory:
   ```bash
   cd CPP_05
   ```
3. Build the project:
in each directory you can use the make command, there is a main for testing the code, you can modify it to test different cases.
   ```bash
   make
   ```

##
