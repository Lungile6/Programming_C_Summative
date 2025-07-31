---

# 📁 C Systems Programming Projects – Portfolio

This repository contains five modular and well-documented C projects covering real-world systems programming concepts like multi-threading, file handling, dynamic memory allocation, and shell development. Each project is self-contained and designed for learning and enhancement.

---

## 📦 Project List

1. [Smart Home System](https://www.tinkercad.com/things/lJD6QBXhg3m-project-1-smart-home-system)
2. [Mini Shell with Built-in Commands](#2-mini-shell-with-built-in-commands)
3. [Student Management System using Structures](#3-student-management-system-using-structures)
4. [Dynamic Function Dispatcher](#4-dynamic-function-dispatcher-using-function-pointers-and-dynamic-memory)
5. [Multi-threaded Web Scraper](#5-multi-threaded-web-scraper)

---

## 1️⃣ Smart Home System

### ✅ Description

This project simulates a smart home system in Tinkercad using an Arduino Uno, a temperature sensor, and a PIR motion sensor.


---

## 2️⃣ Mini Shell with Built-in Commands

### ✅ Description

A simplified Unix-like shell that supports command execution, redirection, and piping.

### 🔧 Features

* Executes commands like `ls`, `cat`, `pwd`, etc.
* Supports **I/O redirection**: `<`, `>`
* Implements **piping** with `|`
* Includes built-in `exit` command

### 🚀 How to Run

```bash
cd MiniShell
make
./myshell
```

Type commands like:

```bash
ls -l | grep txt > result.txt
```

---

## 3️⃣ Student Management System using Structures

### ✅ Description

A CLI-based tool to manage student records using structures and file handling.

### 🔧 Features

* Stores name, ID, age, course, and grades using `struct`
* CRUD operations: **Add, View, Update, Delete**
* **Search** by name or ID
* **Sort** records by ID or name
* **Persistent storage** using files

### 🚀 How to Run

```bash
cd StudentManagementSystem
make
./student_mgmt
```

---

## 4️⃣ Dynamic Function Dispatcher using Function Pointers and Dynamic Memory

### ✅ Description

Dynamically dispatches file-handling functions using **function pointers** and handles memory using `malloc()`/`free()`.

### 🔧 Features

* Dynamically selects at runtime:

  * Add text to file
  * Count lines/characters
  * Convert file content to **uppercase/lowercase**
* Uses **function pointers**
* Dynamic memory usage

### 🚀 How to Run

```bash
cd FunctionDispatcher
make
./dispatcher
```

Follow on-screen prompts to select a file and action.

---

## 5️⃣ Multi-threaded Web Scraper

### ✅ Description

A parallel web scraper that fetches HTML from multiple user-provided URLs using `pthreads`.

### 🔧 Features

* Uses **POSIX threads** for concurrent downloads
* Prompts user to input list of URLs
* Saves each HTML content to `output/page_<n>.html`
* Implements basic **error handling**
* Uses **libcurl**

### 🔧 Dependencies

Install `libcurl`:

```bash
sudo apt-get install libcurl4-openssl-dev
```

### 🚀 How to Run

```bash
cd WebScraper
make
./scraper
```

Example:

```text
Enter number of URLs to scrape (max 10): 2
Enter URL 1: http://example.com
Enter URL 2: https://www.gnu.org
```

---

## 📚 Requirements

* GCC compiler
* Linux or WSL terminal
* `libcurl` (for Project 5)

---

## 🧰 Build System

All projects use `Makefile` for easy building. Inside each project folder:

```bash
make         # To compile
make clean   # To remove binaries and output files
```

---

## 📌 Author Notes

These projects are designed for C learners, systems programmers, and embedded enthusiasts. Each file is well-commented, modular, and easy to enhance.

For any bugs, improvements, or questions—feel free to raise an issue or fork the repository!

---
