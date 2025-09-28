# 🍬 Candy Crush Saga / Bejeweled Clone

This is a simple jewel-matching puzzle game developed in **C++** using **SFML**.  
Players can swap jewels, match three or more in a row or column, and score points.  
The goal is to achieve the highest score possible before time runs out.



## ✨ Features

* **8x8 grid** with randomly generated jewels  
* **Match-3, Match-4, and Match-5 detection**  
* **Interactive Grid Interface** — jewels rendered with SFML sprites  
* **Real-time scoring system** with varying points depending on match length  
* **60-second countdown timer** (configurable)  
* **High score tracking** using file handling  
* **Colorful jewel sprites and themed background**  

---

## 🎮 Controls

* **Arrow Keys** — Navigate the cursor across the jewel grid  
* **Enter** — Select a jewel and swap with an adjacent one to form matches  

---

## 📖 How the Game Works

* Create matches of 3, 4, or 5 jewels in a row or column to score points.  
* Matched jewels vanish and are replaced by new randomly generated jewels.  
* The game continues until the timer runs out (default 1 minute).  
* Scores are based on match size: longer matches = more points.  
* Final score is compared against stored high scores.  

---

## ⚙️ Prerequisites

* A **C++ compiler** (C++11 or later recommended)  
* **SFML library** (2.5+ recommended)  
* Jewel image files and a background image (placed in `assets/`)  
* A font file (for displaying score)  

1. Ensure SFML is installed and properly linked.
2. Compile the source code. 

---
Author
Hareem Sajid
---

## 🚀 How to Build and Run

1. Make sure SFML is installed and linked correctly.  
2. Clone the repository:  
   ```bash
   git clone https://github.com/yourusername/bejeweled-clone.git
   cd bejeweled-clone
