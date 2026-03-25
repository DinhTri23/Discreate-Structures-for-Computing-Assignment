# Graph Algorithms Project (Bellman-Ford + TSP)

This project demonstrates:
- Bellman-Ford shortest path relaxation steps.
- Bellman-Ford path reconstruction between all vertex pairs.
- Traveling Salesman Problem (TSP) route search using backtracking.

The program uses an adjacency matrix from `inputfile.txt` and labels vertices as `A, B, C, ...`.

## Project Structure

- `main.cpp`: Program entry point, file input, and console output.
- `main.h`: Common headers.
- `bellman.h`, `bellman.cpp`: Bellman-Ford step update and path reconstruction.
- `tsp.h`, `tsp.cpp`: TSP backtracking solver.
- `inputfile.txt`: Input adjacency matrix.

## Requirements

- C++ compiler with C++11 support or newer.
  - Recommended: `g++` (MinGW on Windows, GCC on Linux/macOS).

## Build

From the project folder, compile with:

```bash
g++ -std=c++11 -O2 -o graph_app main.cpp bellman.cpp tsp.cpp
```

On Windows PowerShell with MinGW, run:

```powershell
g++ -std=c++11 -O2 -o graph_app.exe main.cpp bellman.cpp tsp.cpp
```

## Run

Make sure `inputfile.txt` is in the same directory as the executable.

- Linux/macOS:

```bash
./graph_app
```

- Windows:

```powershell
.\graph_app.exe
```

## Input Format

`inputfile.txt` should contain a weighted adjacency matrix.

Current `main.cpp` is hardcoded to read a `12 x 12` matrix (`n = 12`) even though the internal array size is `20 x 20`.

Notes:
- `0` is treated as no edge in the TSP logic.
- Positive weights are treated as valid edges.

## Output

The program prints:
- The input matrix.
- Bellman-Ford relaxation results (distance and predecessor arrays) for selected start vertices.
- Bellman-Ford path results for all pairs.
- TSP route and its cost for each start vertex from `A` to `L`.

## Quick Customization

To test another graph:
- Replace values in `inputfile.txt` with another `12 x 12` matrix.
- Run the executable again.

If you want variable graph size, update `main.cpp` to read `n` from file or command line and loop with that value.
