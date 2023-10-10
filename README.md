```
                                                                                
                                                                                
                                           @@@@@@@                              
                                         @@@@  @@@@                            
             @@@@@@@@     @@@@    @@@@   @@@                                    
            @@@@@@@@@@@   @@@@    @@@@    @@@@@@@                               
            @@@    @@@@   @@@@    @@@@        @@@@@                            
            @@@    @@@@   @@@@    @@@@   @@    @@@@  @@@                      
            @@@    @@@@   @@@@    @@@@   @@@@@@@@@@  @@@                      
            @@@    @@@@   @@@@    @@@@   @@@@@@@@@@  @@@                      
            @@@@   @@@@   @@@@@  @@@@@  @@@@    @@@@ @@@@@@@@@               
            @@@#@@@@@@     @@@@@@@@@@@          @@@@ @@@@@@@@@@               
            @@@                          @@@@@@@@@@@ @@@    @@@               
            @@@                         @@@@    @@@@ @@@    @@@               
            @@@                         @@@@    @@@@ @@@    @@@               
                            @@@@    @@@  @@@@@@@@@@@ @@@    @@@               
             @@@@@@@@@      @@@@   @@@@@   @@@@@@@   @@@    @@@               
            @@@&   @@@@    @@@@@@  @@@@@             @@@    @@@               
            @@@@          @@@@@@@ @@@ @@@    @@@@@@@@@@@                        
             @@@@@@@@@   @@@@  @@@@@@ @@@@   @@@@   @@@@                        
                   @@@@  @@@@  @@@@@   @@@@  @@@@   @@@@                        
            @@@    @@@@ @@@@    @@@@   @@@@  @@@@   @@@@                        
            @@@@@@@@@@  @@@@    @@@.    @@@@ @@@@   @@@@                        
               @@@@@                         @@@@   @@@@                        
                                             @@@@@@@@@@@                        
                                             @@@@@@@@@                         
                                             @@@@                               
                                             @@@@                               
                                             @@@@                               
                                                                                
whoAmI(campus=42barcelona, login=mporras-, mail=manuel.porras.ojeda@gmail.com)
Feel free to write!                                                     

```

# Push-Swap

## Introduction

The best way to present this project is to split it into two. On the one hand, the sorting algorithm, and on the other hand, "the game".

The algorithm used is a custom implementation, although you will surely be able to find common elements between this and any other push-swap that you can find.

On the other hand, there is the game, which is nothing more than the way I like to call a couple of implementations that I introduced only to improve the results of push-swap, but that do not actually form part of the sorting algorithm.

This implementation has the peculiarity that the larger the number of received elements, the more efficient it is in terms of the number of movements, but slower in terms of time, although the latter is due to that extra that we have already mentioned.

But before continuing, let's review the concept of stack, to have clear concepts.

Grade: 125%.

```bash
------------------------------------
Average for 5 numbers:  7
Min:        5
Max:        9
------------------------------------
------------------------------------
Average for 10 numbers:  31
Min:       26
Max:       37
------------------------------------
------------------------------------
Average for 50 numbers:  250
Min:      235
Max:      266
------------------------------------
------------------------------------
Average for 100 numbers:  606
Min:      570
Max:      637
------------------------------------
------------------------------------
Average for 500 numbers:  4827
Min:     4637
Max:     5028
------------------------------------
```
Is slow with big stacks, but is good!
I'm pretty sure that this implementation can be improved, specially around presort step.

## Stack (Data Structure in C)

A **stack** is a linear data structure that follows the Last In First Out (LIFO) principle. This means that the last element added to the stack is the first element to be removed. Conceptually, you can think of a stack as a collection of elements with two primary operations:

- **Push:** Add an element to the top of the stack.
- **Pop:** Remove the top element from the stack.

In the C programming language, a stack can be implemented using an array or a linked list. Each element in the stack typically holds a value and, in implementations using linked lists, a reference (or a pointer in C terminology) to the next element.

Stacks are used in various applications, such as:

- **Function Calls:** The call stack keeps track of function invocations in a program.
- **Expression Evaluation:** Used in algorithms to evaluate postfix or infix expressions.
- **Backtracking Algorithms:** Helps in keeping track of the previous state.

In this push-swap, stacks are implemented using linked lists, where each node (or element) of the stack holds an integer value and a pointer to the next node. I really think that implement a stack using an array can be quite tricky and overcomplicated. Using nodes and pointers means that you can manipulate the position of a particular node without need of resize, keep a track of the index, or copy all the stack.

## Overview

In many algorithmic challenges, especially those related to sorting and data manipulation, using dual stacks can be a strategic advantage.

The operations are centered around two main stacks: 'a' which initially holds all the data, and 'b' which is used for temporary storage and manipulation. Through a series of push, rotate, reverse rotate, and swap operations, the data gets organized at 'a'.

## How it Works

Imagine you're tasked with sorting a set of random numbers. The traditional approach would involve using one of the known sorting algorithms. However, with the dual-stack approach, you have an added layer of flexibility. By pushing numbers between the stacks and employing the rotate and swap operations strategically, the numbers get organized efficiently.

```
    Stack A            Stack B
    ------            ------
    |  5  |           |     |
    ------            ------
    |  2  |   ===>    |  4  |
    ------            ------
    |  4  |           |  2  |
    ------            ------
    Bottom            Bottom
```

# Push-Swap - Detailed Walk through

## Step 1: Input Collection

- The process starts with the collection of a list of integers. To begin we 'test' our input to check that if ft_atoi can handle them without problems. There is two ways to handle the input, just because I rather use fish than bash.

## Step 2: Initialization

- Once the list is obtained, the next step is to initialize the metadata for our operations using:
  ```
  t_meta_data *ft_meta_data_init(void);
  ```
  This function sets up an environment with two empty stacks (Stack A and Stack B) and other related metadata like size, min, and max values, and more.

## Step 3: Loading the Stack

- The numbers from the list are then loaded into Stack A. Stack B remains empty at this point. We use:
  ```
  int ft_load_stack(char **input, int init, t_meta_data *meta);
  ```
  This function takes the input numbers and pushes them onto Stack A while initializing necessary metadata attributes.

## Step 4: Pre-Sorting at Stack B

- To simplify the main sorting process, the push-swap first moves some numbers to Stack B in a certain order. The aim is to use Stack B as a temporary workspace to facilitate easier sorting. The pre-sorting logic is defined in:
  ```
  int ft_presort_at_b(t_meta_data *meta);
  ```

## Step 5: Determining Pivot Points

- Pivot points are essential for optimizing the sorting process. The push-swap divides the numbers in Stack A into segments, or "cuts," based on these pivots. We use:
  ```
  int ft_get_sub_stack_limits(t_meta_data *meta);
  ```
  This function determines where the cuts or segments in the stack should be to simplify the sorting process. This is the step where "the game" part is. I realized that the size of the chunks is critical to lower the movements, specially the size of the first chunck. a really big cut will give you a scattered stack that shoulb cost more to sort back on A. A small cut cost more moves to push to B. So, to deal with it I just play with the posibilities. 

## Step 6: Sorting

- With the pivots determined and some numbers pre-sorted in Stack B, the main sorting begins. If the number of elements is small, the push-swap uses the specialized functions like:
  ```
  int ft_small_cases(t_meta_data *meta, char ab);
  ```
  For more significant segments, the push-swap employs a more comprehensive logic encapsulated in:
  ```
  int ft_spin_sort_at_a(t_meta_data *meta);
  ```
  Spin sort is about how the elements on b are returned to a. The idea is calculate what is "cheaper" on moves: find the next number in b to push back to a, or move a to prepare it to recieve the closest element on b. eg:

  ```
  stack A      stack B 
    10     |     1   
    11     |     8
    12     |     15
  ```
  In this example we can push 1 to a now. Why? because it doesn't matter if between 1 and 10 some numbers are missing, 1 is lower than 10 and 12.
  ```
  stack A      stack B 
    1      |     8   
    10     |     15
    11     |     
    12     |
  ```
  So, now to push 8 we can spin A (This is just and example, you can check the code to more details about how costs are calculated):
  ```
  stack A      stack B 
    10     |     8   
    11     |     15
    12     |
    1     
  ```
  Now we can pust 8 to the hole between 1 and 10.

## Step 7: Completion

- At this point, Stack A should have all the numbers in the desired order (sorted), and Stack B should be empty. Your get a list of movements than can be checked by checker, or visualized by some tools that are quite easy to find.

# BONUS: push-swap checker

## Overview

The `push-swap checker` is a utility designed to validate the operations performed by the `push-swap` project. Given a set of numbers, the goal of `push-swap` is to sort them using a limited set of stack operations. This checker ensures that the operations provided will sort the list correctly.
Push swap bonus was quite easy. To create the checker I just used the same action functions from push-swap and with getnextline get each instruction and apply it.
At the end of the list, stack a should be sorted. That's it!

## Features

- **Load Functionality**: Efficiently load numbers into the stack, either from space-separated single arguments or directly from command line arguments.

- **Command Processing**: Reads and processes a list of commands to manipulate the stacks, keeping track of the total number of operations.

- **Input Validation**: Checks if the inputs are valid numbers and ensures no duplicates exist.
