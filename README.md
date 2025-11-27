## 📌 Abstract

The **Player Profile Management System** is a console-based C application designed to store, manage, and update gaming player records efficiently. Using structured programming and file handling, the system allows users to create and manage multiple player profiles with details such as name, age, level, and score. It includes search, score update, and automatic data loading from file, making it a lightweight yet robust player database management system.
This project demonstrates the use of **structures, arrays, menu-driven programming, loops, file handling, and user interaction** — making it ideal for learners and academic submissions.

---

## 🚀 Project Features

| Feature                    | Description                                                        |
| -------------------------- | ------------------------------------------------------------------ |
| ➕ Add New Player           | Create and store a player profile with name, age, level, and score |
| 📋 Display All Players     | Shows the list of all registered players with complete details     |
| 🔍 Search Player           | Search and view player details by entering a player name           |
| ✏ Update Score             | Modify an existing player's score                                  |
| 💾 Save to File            | Saves all player profiles permanently in `players.txt`             |
| 📂 Load Data Automatically | Reads saved player data from the file when the program starts      |
| 🧾 Menu-Driven Interface   | User-friendly number-based selection system                        |
| ♾️ Multi-Player Support    | Can store up to **100 player profiles**                            |

---

### 🧠 Concepts Used

* **Structures**
* **Arrays**
* **Functions**
* **String handling**
* **Loops and conditional statements**
* **File I/O (`fopen`, `fprintf`, `fscanf`)**
* **Menu-driven programming**

---

### 🏹 Target Audience

* Beginner to intermediate C programmers
* Students doing a **C project / GitHub submission**
* Anyone learning **file handling and structure-based programming**

---

### 📄 Output Example

```
====== PLAYER PROFILE SYSTEM ======
1. Add New Player
2. Display All Players
3. Search Player by Name
4. Update Player Score
5. Save Profiles to File
6. Exit
Enter Your Choice: 1

--- Add New Player ---
Enter Name: Alex
Enter Age: 19
Enter Level: 4
Enter Score: 3000
Player added successfully!
Below is a **Technical Requirements section** that you can directly add to your GitHub `README.md` for the **Player Profile Management System in C**.

---

| Component | Minimum Requirement                              |
| --------- | ------------------------------------------------ |
| Processor | Intel / AMD 1 GHz or higher                      |
| RAM       | 1 GB or more                                     |
| Storage   | At least 10 MB (for program and saved data file) |
| Display   | Console / Terminal output supported              |

---

### ✔️ **Software Requirements**

| Software Component | Specification                                       |
| ------------------ | --------------------------------------------------- |
| Operating System   | Windows / Linux / macOS                             |
| C Compiler         | GCC / MinGW / Turbo C / Clang                       |
| Text Editor / IDE  | VS Code, CodeBlocks, Dev-C++, Notepad++, or similar |
| File Support       | Ability to read/write `.txt` files                  |

---

### ✔️ **Programming Requirements**

| Module         | Requirement                                                 |
| -------------- | ----------------------------------------------------------- |
| Language       | C programming                                               |
| Paradigm       | Procedural programming                                      |
| Data Structure | `struct` and array of structures                            |
| Input Handling | `scanf`, string handling                                    |
| Memory         | Static allocation                                           |
| File Handling  | `fopen`, `fprintf`, `fscanf`, `fclose`                      |
| Program Design | Menu-driven system using loops, switch cases, and functions |

---

### 🔌 Dependencies & Compatibility

* No external libraries required
* Works on both **32-bit and 64-bit systems**
* Portable — runs in any system with a standard C compiler

---

### ⚙️ Execution Steps

1. Compile the program using any C compiler
2. Run the generated executable
3. A file named `players.txt` will be created automatically for storing player profiles
4. The program will reload saved player profiles every time it starts

---
