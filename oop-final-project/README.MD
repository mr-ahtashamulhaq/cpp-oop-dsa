# ICC Management System (OOP Project – Phase 3)

## Overview
This project is a console-based ICC Management System built in C++ using Object-Oriented Programming concepts.  
It integrates all phases into a single system managed by the **ICC** class.

The system models:
- Cricket Boards
- Teams
- Players
- Matches
- Tournaments
- Rankings

Data persistence is handled using **CSV file handling**.

---

## Core OOP Concepts Used
- **Encapsulation**: Data members are private, accessed via methods.
- **Inheritance & Polymorphism**:  
  - `Person` (abstract class)  
  - `Player`, `Coach`, `Umpire` inherit from `Person`
- **Aggregation**:
  - ICC → CricketBoards
  - CricketBoard → Teams
  - Team → Players
- **Templates**:
  - Generic `List<T>` class (used where needed)
- **Abstraction**:
  - `Person` has pure virtual `displayInfo()`

No STL containers, no vectors, no dynamic memory allocation.

---

## Data Storage Design (Important)
- All data is stored in **one file**:  
  `icc_data.csv`
- The ICC class acts as the **central authority**.
- Data is written and read in a **fixed order**, so the system knows which data belongs to what.

### Why one CSV file?
- Simpler integration
- Centralized save/load
- Matches the role of ICC as top-level controller

---

## Current Preloaded Data (for demo)

### Cricket Board
- **PCB**
- Board ID: `70173927`

### Teams under PCB
1. **Karachi Kings**
2. **Lahore Qalandars**

### Karachi Kings Players
- Ahtasham — Batsman  
- Abu Bakar — Batsman  
- Khanghar — Batsman  
- Moeed — Batsman  
- Plus system-added players

### Lahore Qalandars Players
- All players added by system (realistic data)

This data is already present in `icc_data.csv` for demo and viva.

---

## Menu Structure (Final)

```

1. Register Cricket Board
2. Add Team to Board
3. Register Player
4. Add Player to Team
5. Organize Tournament
6. Add Match to Tournament
7. View All Details
8. View Boards
9. View Teams of a Board
10. View Players of a Team
11. Display Global Rankings
12. Save Data
13. Exit

````