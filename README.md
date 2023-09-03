# C Data Structures and Algorithms Library 

This C library provides generic implementations of common data structures and algorithms. It includes data structures like a stack, queue, heap(priority queue), and a trie. Additionally, it offers searching algorithms suck as linear search and binary search. Sorting techniques like bubble sort, quick sort, merge sort, and insertion sort are also included. 
<br/>
<br/>

## Table Of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Data Structures](#data-structures)
  - [Stack](#stack)
  - [Queue](#queue)
  - [Priority Queue](#priority-queue)
  - [Trie](#trie)
- [Algorithms](#algorithms)
  - [Searching](#searching)
  - [Sorting](#sorting)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This library provides a collection of common data structures and algorithms implemented in C, allowing you to use them in your projects easily. Whether you need a stack, queue, or trie, or if you're looking for searching and sorting algorithms, this library has got you covered.

## Features

- ***Generic Data Structures:*** All data structures are generic, allowing you to use them with any data type.
- ***Flexible Sorting:*** Choose from various sorting algorithms like bubble sort, quicksort, merge sort, and insertion sort using function pointers.
- ***Search Algorithms:*** Includes linear search and binary search.
- ***Modular Design:*** Well-organized directory structure and modular code make it easy to understand and maintain.
- ***Detailed Documentation:*** Each data structure and algorithm is thoroughly documented for easy reference.

## Getting Started

  ### Prerequisites

  Before using this library, you'll need to have a C development environment set up on your       system.

  ### Installation

  1. **Clone the repository:**
     
     ```
     git clone https://github.com/vishnubansal001/stl-library-for-c.git
     cd stl-library-for-c
     ```
  2. **Use in Your Project:<br/>**
     
     Link the library to your project by including the header files and linking to the static        library file. Make sure to include the relevant headers for the data structures and             algorithms you want to use.


## Usage

- Include the necessary header files in your C code.
- Initialize and use the data structures and algorithms as needed.
- Refer to the documentation in the code comments for detailed usage instructions.

## Data Structures

  ### Stack
  A generic stack implementation with push, pop, and peek operations.

  ### Queue
  A generic queue implementation with enqueue, dequeue, and peek operations.

  ### Priorirty Queue 
  A generic priority queue implementation using a heap data structure

  ### Trie
  A generic trie (prefix tree) implementation for efficient string-based data storage and retrieval.

## Algorithms

  ### Searching 
  - ***Linear Search:*** Find an element in an array using a linear search algorithm
  - ***Binary Search:*** Find an element in a sorted array using a binary search algorithm

  ### Sorting
  - ***Bubble Sort:*** Sort an array using the bubble sort algorithm.
  - ***Insertion Sort:*** Sort an array using the insertion sort algorithm.
  - ***Quick Sort:*** Sort an array using the quick sort algorithm.
  - ***Merge Sort:*** Sort an array using the merge sort algorithm.

## Contibuting

  Contributions are welcome! If you'd like to contribute to this project, please follow these     guidelines:

  1. Fork the repository.
  2. Create a new branch: ```git checkout -b feature/your-feature-name```.
  3. Make your changes and commit them: ```git commit -m 'New:Add some feature'```.
  4. Push to the branch: ```git push origin feature/your-feature-name```.
  5. Open a pull request to the `main` branch of this repository.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
