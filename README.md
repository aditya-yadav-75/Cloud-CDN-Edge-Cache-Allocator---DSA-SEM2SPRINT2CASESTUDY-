# Cloud CDN Edge Cache Allocator

> **Developed by:** **Aditya Yadav**
> **Language:** C++
> **Project Type:** Data Structures and Algorithms (DSA) Mini Project

---

# Problem Statement

With the increasing demand for fast and reliable internet services, Content Delivery Networks (CDNs) play an important role in reducing latency and improving user experience. A CDN stores content across multiple servers and delivers it from the nearest or most efficient location. Managing URLs, downloads, cached files, server connections, and routing efficiently requires the use of suitable data structures and algorithms.

This project simulates the basic working of a CDN Edge Cache Allocator using C++. It demonstrates how various DSA concepts can be applied to solve real-world problems in a simple and interactive way.

---

# Objectives

* Build a menu-driven CDN simulation using C++.
* Understand the practical applications of Data Structures and Algorithms.
* Store and manage URL mappings efficiently.
* Simulate session history with undo functionality.
* Process download requests in the correct order.
* Maintain cached files dynamically.
* Search servers efficiently using Binary Search.
* Sort files based on popularity using Merge Sort.
* Represent server networks using graphs and perform graph traversals.
* Find the shortest latency path between servers using Dijkstra's Algorithm.

---

# System Overview / Architecture

The project is divided into multiple modules, each handling a specific task.

* **URL Manager:** Maps URLs to their respective servers using a hash map.
* **Session Manager:** Stores user actions using a stack and supports undo operations.
* **Download Queue:** Processes download requests in FIFO order using a queue.
* **Server Directory:** Maintains a sorted list of servers and performs Binary Search.
* **Popularity Manager:** Sorts files based on request count using Merge Sort.
* **Cache Manager:** Stores cached files using a singly linked list.
* **Network Graph:** Represents server connections and supports BFS, DFS, and Dijkstra's shortest path algorithm.

The application is completely menu-driven, allowing users to test each functionality individually.

---

# Data Structures and Algorithms Used

## Data Structures

* **Hash Map (`unordered_map`)** – Stores URL and server mappings.
* **Stack** – Maintains session history and undo operations.
* **Queue** – Handles download requests.
* **Vector** – Stores server names.
* **Singly Linked List** – Manages cached files.
* **Graph (Adjacency List)** – Represents the CDN network.
* **Set** – Used while implementing Dijkstra's Algorithm.

## Algorithms

* Binary Search
* Merge Sort
* Breadth First Search (BFS)
* Depth First Search (DFS)
* Dijkstra's Shortest Path Algorithm

---

# Implementation Approach

The project follows an object-oriented approach where every major feature is implemented in its own class. URLs are stored in a hash map for quick access, session actions are managed using a stack, and download requests are handled using a queue. Servers are stored in a vector and searched using Binary Search. File popularity is sorted using Merge Sort before displaying the results. Cached files are maintained through a linked list, while the network topology is represented as a graph. BFS and DFS are used for graph traversal, and Dijkstra's Algorithm calculates the minimum latency path between two servers.

This modular implementation makes the code easier to understand, maintain, and extend.

---

# Time and Space Complexity Analysis

| Operation             | Data Structure / Algorithm | Time Complexity  |
| --------------------- | -------------------------- | ---------------- |
| Add/Search/Delete URL | Hash Map                   | O(1) Average     |
| Push/Pop Session      | Stack                      | O(1)             |
| Add/Process Download  | Queue                      | O(1)             |
| Search Server         | Binary Search              | O(log n)         |
| Sort Popularity       | Merge Sort                 | O(n log n)       |
| Insert/Delete Cache   | Linked List                | O(n)             |
| BFS Traversal         | Graph                      | O(V + E)         |
| DFS Traversal         | Graph                      | O(V + E)         |
| Dijkstra's Algorithm  | Graph + Set                | O((V + E) log V) |

---

# Execution Steps

## Requirements

* C++ compiler (GCC/G++)
* Any IDE such as VS Code, Code::Blocks, CLion, or Visual Studio

## Compilation

```bash
g++ main.cpp -o cdn
```

## Execution

**Windows**

```bash
cdn.exe
```

**macOS / Linux**

```bash
./cdn
```

After running the program, choose the required option from the menu and follow the prompts displayed on the console.

---

# Sample Inputs and Outputs

### Example 1 – Add URL

**Input**

```text
Choice: 1
URL: www.google.com
Server: Mumbai_Server
```

**Output**

```text
URL added successfully!
```

---

### Example 2 – Search URL

**Input**

```text
Choice: 2
URL: www.google.com
```

**Output**

```text
Stored on Server: Mumbai_Server
```

---

### Example 3 – Download Queue

**Input**

```text
Choice: 8
File: report.pdf
```

**Output**

```text
Request added.
```

After processing:

```text
Processing: report.pdf
```

---

### Example 4 – Shortest Path

**Input**

```text
Source Server: Mumbai
Destination Server: Bangalore
```

**Output**

```text
Shortest Latency: 25 ms

Path:
Mumbai -> Pune -> Bangalore
```

---

# Screenshots

## Main Menu

![Main Menu](screenshots/01-main-menu.png)

## Add URL

![Add URL](screenshots/02-add-url.png)

## Search URL

![Search URL](screenshots/03-search-url.png)

## Display URLs

![Display URLs](screenshots/04-display-urls.png)

## Session History

![Session History](screenshots/05-session-history.png)

## Undo Action

![Undo Action](screenshots/06-undo-action.png)

## Download Queue

![Download Queue](screenshots/07-download-queue.png)

## Server Directory

![Server Directory](screenshots/08-server-directory.png)

## File Popularity

![File Popularity](screenshots/09-file-popularity.png)

## Cache Manager

![Cache Manager](screenshots/10-cache-manager.png)

## Network Graph

![Network Graph](screenshots/11-network-graph.png)

## BFS Traversal

![BFS](screenshots/12-bfs.png)

## DFS Traversal

![DFS](screenshots/13-dfs.png)

## Dijkstra's Algorithm

![Dijkstra](screenshots/14-dijkstra.png)
---

# Results and Observations

The project successfully demonstrates the practical implementation of several important data structures and algorithms. URL operations using hash maps are efficient, stack and queue operations behave as expected, Binary Search quickly locates servers, and Merge Sort correctly ranks files by popularity. Graph traversal using BFS and DFS works accurately, while Dijkstra's Algorithm computes the shortest latency path between connected servers.

The modular design also makes the program easy to understand and modify for future enhancements.

---

# Conclusion

This project gave me practical experience in applying Data Structures and Algorithms to a real-world-inspired problem. Instead of implementing each concept independently, integrating them into a CDN simulation helped me understand how different data structures work together in software systems.

Overall, the project strengthened my understanding of C++ programming, object-oriented design, searching and sorting techniques, graph algorithms, and efficient data management while providing a simple yet effective simulation of a Cloud CDN Edge Cache Allocator.

---

## Author

**Aditya Yadav**
B.Tech Computer Science Engineering Student
ITM Skills University, Kharghar

If you found this project useful or have suggestions for improvement, feel free to explore and modify the code for learning purposes.
