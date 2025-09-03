#  Among Us (C Project)

> **Important:** Please read this README thoroughly before starting development, and pay close attention to the inline comments in the source files.

---

##  Project Specification

This project is a simulation of a game round in **Among Us**, based on the official assignment details:  
[CS-240 Project First Phase – Full Description (PDF)](https://www.csd.uoc.gr/~hy240/old_websites/hy240a-2020-2021/material/projectPhases/CS-240_Project_first_phase_typos_fixed.pdf)

---

##  Directory Structure

src/
├── main.c # Contains the default main() function for testing
├── among_us.h # Declarations and data structures required by the project
└── among_us.c # Empty function definitions to implement
Makefile # Automates compilation

### File Details

- **`main.c`**  
  - Used for testing your implementation.  
  - You may modify it during development, but **submission must work with the original version**.

- **`among_us.h`**  
  - Defines necessary structs and function declarations, including `Player`, `Task`, and associated linked-list structures.

- **`among_us.c`**  
  - Contains empty function definitions. You can implement here **or** replace it with your own `.c` files—just don’t touch `main.c` or `among_us.h`.

- **`Makefile`**  
  - Compiles all `.c` files in `src/` into an executable named `among_us`.  
  - If you prefer, you can compile manually:
    ```bash
    gcc -Wall -o among_us src/*.c
    ```

---

##  Building & Cleaning

Recommended commands (run from project root):

```bash
make         # Builds the project -> executable: among_us
./among_us testfile1  # Example usage

make clean   # Deletes intermediate files (obj/, dep/)
make distclean  # Deletes everything including the executable
