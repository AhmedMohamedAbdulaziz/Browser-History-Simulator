# 🌐 Browser-History-Simulator

You are asked to build a **Browser History Simulation System** that mimics how real browsers handle navigation history.  
Users can **visit new websites**, **go back to previous ones**, **move forward again**, **show the current page**, and **view complete browsing history** — all through a simple and clear **console interface**.

---

## 🎯 Project Overview

This project simulates a **web browser’s back/forward navigation system** using manually implemented **Stack** and **Dynamic Array** data structures in C++ (without STL).  
It provides a hands-on understanding of how browser history, navigation, and undo/redo logic are handled internally.

---

## ⚙️ Core Functionalities

| Feature | Description |
|----------|-------------|
| 🌐 **Visit New Site** | Input a website URL; adds it to the Back stack and history, and clears the Forward stack. |
| ⬅️ **Go Back** | Pops the current page from the Back stack and pushes it into the Forward stack. |
| ➡️ **Go Forward** | Moves from Forward stack back into the Back stack. |
| 🖥️ **Show Current Page** | Displays the current page being viewed. |
| 📜 **Show Browsing History** | Displays all visited websites stored in a dynamic array. |
| ❌ **Exit** | Exits the program safely. |

---

## 🧱 Data Structures Used

| Data Structure | Purpose |
|----------------|----------|
| **Stack (Back)** | Stores previously visited sites to allow the user to go back. |
| **Stack (Forward)** | Stores sites navigated backward from, to allow forward navigation. |
| **Dynamic Array (History)** | Permanently stores all visited websites. |

All these are implemented **manually using arrays and classes**, without STL containers like `stack` or `vector`.

---


