---

# 🧩 Maze Solver (C++)

A simple **maze generator** and **solver** implemented in **C++** using **Breadth-First Search (BFS)**. It generates a random maze, solves it, and displays the path from start to end.

## 🚀 Features

- **Random Maze Generation** : Creates a maze with walls and open paths.
- **BFS Solver** : Solves the maze using the Breadth-First Search algorithm.
- **Visual Output** : Displays the maze and solution path in the terminal.

---

## 🛠 Installation

1. Clone the repository :

```bash
git clone https://github.com/XanderSteyn/Maze-Solver.git
cd Maze-Solver
```

2. Compile the C++ code :

```bash
g++ -o MazeSolver MazeSolver.cpp
```

3. Run the program :

```bash
./MazeSolver.exe
```

---

## 🎮 Usage

The program generates a random maze and uses BFS to find the shortest path from the start ('S') to the end ('E'). The solution path is marked with `*`.

---

## 🛑 How It Works

1. **Maze Generation** : Randomly generates walls and open spaces, placing the start and end positions.
2. **BFS Solving** : Uses BFS to find the shortest path from start to end.
3. **Solution Display** : The solved maze is displayed with the solution path marked.

---

## 📌 Notes

- The maze is randomly generated every time the program is run.
- Press **Enter** to exit the program after solving the maze.

---
