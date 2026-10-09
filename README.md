# ⚡ Competitive Programming IDE Setup

A fast, streamlined, and production-ready Competitive Programming (CP) workflow for **Linux** and **Windows**, featuring configurations for both **Sublime Text** and **VS Code**, universal debugging headers, code snippets, and an automated stress-testing framework.

---

## 📑 Table of Contents

- [Overview & Directory Structure](#-overview--directory-structure)
- [Universal Debug Headers](#-universal-debug-headers)
  - [Full Debugger (`debug.h`)](#1-full-debugger-debugh)
  - [On-Site Minimal Debugger (`debug_onsite.h`)](#2-on-site-minimal-debugger-debug_onsiteh)
- [VS Code Setup](#-vs-code-setup)
  - [Workflow & Scripts](#workflow--scripts)
  - [3-Pane Editor Layout](#3-pane-editor-layout)
  - [Quick Start (Linux)](#quick-start-linux)
  - [Windows Notes](#windows-notes)
- [Sublime Text Setup](#-sublime-text-setup)
  - [Installation Paths](#installation-paths)
  - [Build Systems](#build-systems)
  - [Keybindings Reference](#keybindings-reference)
  - [Snippet Triggers](#snippet-triggers)
- [Stress Testing & Test Case Generator](#-stress-testing--test-case-generator)
  - [How Stress Testing Works](#how-stress-testing-works)
  - [Generators Included](#generators-included)

---

## 📂 Overview & Directory Structure

```text
IDE-cp-setup/
├── debug.h                     # Universal, container-aware C++ local debugger (dg(...))
├── debug_onsite.h              # Ultra-compact debugger for on-site / ICPC contests
├── Linux/
│   ├── Sublime Text/           # Themes, AStyle Formatter, User snippets & build systems
│   └── VS Code/                # Contest automation scripts (run, runpy, make_template.sh)
├── Windows/
│   ├── Sublime Text/           # Windows-specific Sublime Text packages and build configurations
│   └── VS Code/                # Windows VS Code setup configurations
└── Test Case Generator/        # Stress-testing scripts and random test generators
    ├── compare.sh              # Bash differential tester (solution vs brute force)
    ├── gen.cpp                 # 64-bit Mersenne Twister random number/array generator
    ├── genString.cpp           # Random string generator
    ├── gen_tree.cpp            # Random tree generator (v1)
    └── gen_tree2.cpp           # Random tree generator (v2)
```

---

## 🩺 Universal Debug Headers

Both debug headers send output exclusively to `stderr` (`cerr`) and are wrapped in `#ifdef LOCAL`, guaranteeing **zero overhead and no compilation errors** when submitting to online judges (Codeforces, AtCoder, CSES, CodeChef, etc.).

### 1. Full Debugger (`debug.h`)

Supports all C++ primitives, strings, standard pairs, tuples, and **any** nested STL containers:
- **Sequential & Associative Containers**: `vector`, `deque`, `list`, `set`, `multiset`, `unordered_set`, `map`, `unordered_map`, `array`, nested combinations (e.g., `vector<pair<int, set<int>>>`).
- **Container Adapters**: `stack`, `queue`, `priority_queue`.

#### Usage:
```cpp
#ifdef LOCAL
#include "debug.h"
#else
#define dg(...)
#endif

// In your code:
int x = 42;
vector<int> v = {1, 2, 3};
map<string, int> mp = {{"alice", 10}, {"bob", 20}};

dg(x, v, mp);
// Output on stderr:
// [Line 15] x = 42 | v = {1, 2, 3} | mp = {{"alice", 10}, {"bob", 20}} |
```

### 2. On-Site Minimal Debugger (`debug_onsite.h`)

A compact ~35-line template intended for on-site or ICPC contests where bringing or typing a 100+ line debugger is impractical.

- Prints line numbers, variable names, and values.
- Recursively prints nested pairs and any iterable container (`vector`, `set`, etc.).

---

## 💻 VS Code Setup

Located under [`Linux/VS Code/`](Linux/VS%20Code/):

### Workflow & Scripts

| Script | Purpose | Command |
|---|---|---|
| `run` | Compiles C++20 with sanitizers and runs against `input.txt` → `output.txt` | `./run <problem_name>` |
| `runpy` | Runs Python 3 with timeout against `input.txt` → `output.txt` (errors → `error.txt`) | `./runpy <problem_name>` |
| `make_template.sh` | Emits a fresh competitive programming template with author tag and timestamp | `./make_template.sh > a.cpp` |

#### The `run` Script Breakdown:
```bash
g++ "$1.cpp" -o "$1" -std=c++20 -O2 -fsanitize=address -DLOCAL -Wall -Wextra -Wshadow
timeout 5s "./$1" < input.txt > output.txt
```
- `-std=c++20`: Modern C++20 standard support.
- `-O2`: Optimization level for contest performance matching judge environments.
- `-fsanitize=address`: AddressSanitizer catches out-of-bounds array access, use-after-free, and memory leaks at runtime.
- `-DLOCAL`: Enables the `LOCAL` macro so `debug.h` is loaded only on your machine.
- `-Wall -Wextra -Wshadow`: Flags common bugs (e.g. shadowed variables, uninitialized reads).
- `timeout 5s`: Automatically kills execution after 5 seconds to prevent frozen infinite loops.
- `stderr` (`cerr`) remains unredirected: debugging information prints directly to the VS Code terminal while program answers flow into `output.txt`.

### 3-Pane Editor Layout

```text
+-----------------------------------+--------------------+
|                                   |     input.txt      |
|                                   +--------------------+
|              a.cpp                |     output.txt     |
|                                   +--------------------+
|                                   |     error.txt      |
+-----------------------------------+--------------------+
|            Integrated Terminal  (./run a)              |
+--------------------------------------------------------+
```

### Quick Start (Linux)

1. **Install Prerequisites**:
   ```bash
   sudo apt update
   sudo apt install build-essential python3
   ```
2. **Recommended VS Code Extensions**:
   - `ms-vscode.cpptools` (C/C++ by Microsoft)
   - `usernamehw.errorlens` (Error Lens - inline diagnostics)
   - `formulahendry.code-runner` (Code Runner - optional)

3. **Set Up Contest Folder**:
   ```bash
   mkdir -p ~/Contest && cd ~/Contest
   touch input.txt output.txt error.txt
   cp /path/to/IDE-cp-setup/Linux/VS\ Code/* .
   cp /path/to/IDE-cp-setup/debug.h .
   chmod +x run runpy make_template.sh
   ```

4. **Solve a Problem**:
   ```bash
   ./make_template.sh > a.cpp   # Generate boilerplate
   # Write solution in a.cpp, paste sample into input.txt
   ./run a                      # Compile and run
   ```

### Windows Notes

- Run commands via **Git Bash** or **WSL** (Windows Subsystem for Linux).
- On Windows native environments, executables use `.exe`:
  ```bash
  g++ "$1.cpp" -o "$1.exe" -std=c++20 -O2 -DLOCAL
  ./"$1.exe" < input.txt > output.txt
  ```

---

## 🎨 Sublime Text Setup

Sublime Text provides an ultra-lightweight, near-instant startup editor configured with custom themes, formatters, build systems, and algorithmic snippets.

Configurations are available for both **Linux** and **Windows** under [`Linux/Sublime Text/`](Linux/Sublime%20Text/) and [`Windows/Sublime Text/`](Windows/Sublime%20Text/).

### Installation Paths

Copy the contents of `Color Scheme - Default`, `One Dark Material - Theme`, `SublimeAStyleFormatter`, and `User` into your Sublime Text `Packages` directory:

- **Linux**:
  ```bash
  cp -r "Linux/Sublime Text/"* ~/.config/sublime-text/Packages/
  # Or for Sublime Text 3:
  # cp -r "Linux/Sublime Text/"* ~/.config/sublime-text-3/Packages/
  ```
- **Windows**:
  ```bat
  xcopy /E /I "Windows\Sublime Text\*" "%APPDATA%\Sublime Text\Packages\"
  ```

### Build Systems

Press `Ctrl+B` (or `Ctrl+R` with custom keymap) to build and execute:

- **Linux (`CP_Linux.sublime-build`)**:
  Compiles with `g++ -DLOCAL -std=c++20`, enforces a `4s` timeout, and connects `input.txt` → `output.txt`.
- **Windows (`CP.sublime-build`)**:
  Compiles with `g++.exe -std=c++17 -DLOCAL` and executes the generated binary reading from `input.txt` to `output.txt`.
- **Debug Build (`Debug.sublime-build`)**:
  Builds with local debug configuration.

### Keybindings Reference

Configured in `Default (Linux).sublime-keymap` and `Default (Windows).sublime-keymap`:

| Key Shortcut | Action | Description |
|---|---|---|
| `Ctrl + R` | `build` | Compile and run current problem |
| `Ctrl + Shift + R` | `cancel_build` | Cancel long-running / stuck build |
| `Alt + Z` | `toggle_setting (word_wrap)` | Toggle soft word wrapping |
| `Alt + Up` / `Alt + Down` | `swap_line_up` / `down` | Move lines up or down |
| `Ctrl + D` | `duplicate_line` | Duplicate current line |
| `Alt + Backspace` | `delete_line` | Delete current line |
| `F12` | `reindent` | Auto-reindent code selection |
| `Ctrl + \` | `add_line_before` | Insert newline above cursor |

### Snippet Triggers

Type the trigger text in a `.cpp` file and press <kbd>Tab</kbd>:

| Tab Trigger | Algorithm / Purpose |
|---|---|
| `CP template` | Full Competitive Programming template (fast I/O, constants, `LOCAL` debug block) |
| `regular cpp` | Standard C++ solution boilerplate |
| `simple cp` | Minimal competitive programming starter |
| `SegmentTree` | Segment Tree (point updates, range queries) |
| `Lazy Propagation` | Segment Tree with Lazy Propagation (range updates & queries) |
| `BinExpoMul` | Binary Exponentiation & Modular Multiplication |
| `KMP CP` | Knuth-Morris-Pratt (KMP) string search algorithm |
| `Rabin Karp` | Rabin-Karp rolling hash string matching |
| `Merge Sort` | Merge Sort implementation |
| `Mo's Algorithm` | Mo's Algorithm for offline range queries |

---

## 🔬 Stress Testing & Test Case Generator

The [`Test Case Generator/`](Test%20Case%20Generator/) directory provides tools to detect subtle bugs, edge cases, and Time Limit Exceeded (TLE) issues by comparing your solution against a brute-force validator using randomized tests.

### How Stress Testing Works

1. Compile your solution: `g++ sol.cpp -o sol`
2. Compile a brute-force validator (known to be correct): `g++ brute.cpp -o brute`
3. Compile the test generator: `g++ gen.cpp -o gen`
4. Run differential testing:
   ```bash
   ./compare.sh
   ```

#### Inside `compare.sh`:
```bash
for ((i = 1; ; ++i)); do
    echo "Testing iteration: $i"
    ./gen $i > input.txt
    diff -w <(./sol < input.txt) <(./brute < input.txt) || {
        echo "Mismatch found on test case $i! See input.txt"
        break
    }
done
```

The loop runs indefinitely and terminates automatically on the first test case where the outputs differ.

### Generators Included

- **[`gen.cpp`](Test%20Case%20Generator/gen.cpp)**: High-quality randomized 64-bit integers and array generator using `<random>` (`std::mt19937_64`).
- **[`genString.cpp`](Test%20Case%20Generator/genString.cpp)**: Randomized alphabet string generator for string algorithms.
- **[`gen_tree.cpp`](Test%20Case%20Generator/gen_tree.cpp)** & **[`gen_tree2.cpp`](Test%20Case%20Generator/gen_tree2.cpp)**: Generates random connected unrooted/rooted trees for tree DP and graph queries.

---

## 💡 Quick Tips for Contests

- Keep `input.txt` and `output.txt` open side-by-side with your code.
- Use `dg(...)` liberally during practice and contests—the `#ifdef LOCAL` guard ensures zero penalty when submitting to online judges.
- For interactive problems, remember to flush output (`cout << endl` or `cout << flush`) and remove `cin.tie(0)`.
