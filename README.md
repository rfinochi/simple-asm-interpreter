# Simple Machine Language Interpreter

This is an exercise of a simple interpreter of a fictitious assember: Simple Machine Language (SML)

## Introduction

SML is writen in signed integers called _words_. Each _word_ is either data or an instruction. All instructions are assumed to be positive in value, data may either be positive or negetive. All instructions are four digit words.

In the case of an instruction, the first two digits are the _operation code_ and the last two are the location of memory for the data being operated on.

Math is done with the use of the accumulator, the _load command_ must be used to load a value into the accumulator, then an operation must be called, the result is then left in the accumulator.

The memory is a single array of 100 integers referenced as slots 0 - 99. This includes the data and text part of an SML code. 

The _operation codes_ are:

* READ (10): Read a word from the terminal into a specific location in memory.
* WRITE (11): Write a word from a specific location in memorry to the terminal.
* LOAD (20): Load a word from a specific location in memory into the _accumulator register_.
* STORE (21): Store a word from the _accumulator register_ into a specific location in memory.
* ADD (30): Add a word from a specific location in memory to the word in the _accumulator register_ (leaving the result in the accumulator). 
* SUBTRACT (31): Subtract a word from a specific location in memory from the word in the _accumulator register_ (leave result in accumulator).
* DIVIDE (32):divide a word from a specific location in memory into the word in the _accumulator register_ (leaving result in accumulator).
* MULTIPLY (33):divide a word from a specific location in memory into the word in the _accumulator register_ (leaving result in accumulator.
* BRANCH (40): Branch to a specific location in memory.
* BRANCHNEG (41): Branch to a specific location in memory if the _accumulator register_ is negative.
* BRANCHZERO (42): Branch to a specific location in memory if the _accumulator register_ is positive.
* HALT (43): Called when the program is done with its task.

## Samples

| Position | Word | Instruction | Explanation                                                       |
|----------|------|-------------|-------------------------------------------------------------------|
| 00       | 1007 | Read A      | Read a value from the terminal and put it on memory position #07  |
| 01       | 1008 | Read B      | Read a value from the terminal and put it on memory position #08  |
| 02       | 2007 | Load A      | Load the value of memory position #07 into the a accumulator      |
| 03       | 3008 | Add B       | Add the value of memory position #08 to the accumulator           |
| 04       | 2109 | Store C     | Store the value of the accumulator into memory position #09       | 
| 05       | 1109 | Write C     | Write into the terminal the value of the memory position #09      |
| 06       | 4300 | Halt        | Terminate the execution of the program                            |
| 07       | 0000 | Variable A  |                                                                   |
| 08       | 0000 | Variable B  |                                                                   |
| 09       | 0000 | Result C    |                                                                   |

This program read two values from the terminal, sum the values, and print the result.

| Position | Word | Instruction           | Explanation                                                                |
|----------|------|-----------------------|----------------------------------------------------------------------------|
| 00       | 1009 | Read A                | Read a value from the terminal and put it on memory position #09           |
| 01       | 1010 | Read B                | Read a value from the terminal and put it on memory position #10           |
| 02       | 2009 | Load A                | Load the value of memory position #09 into the a accumulator               |
| 03       | 3110 | Substract B           | Substract the value of memory position #10 to the accumulator              |
| 04       | 4107 | Branch negative to 07 | Branch to memory position #07 if the value in the accumulator are negative | 
| 05       | 1109 | Write A               | Write into the terminal the value of the memory position #09               |
| 06       | 4300 | Halt                  | Terminate the execution of the program                                     |
| 07       | 1110 | Write B               | Write into the terminal the value of the memory position #10               |
| 08       | 4300 | Halt                  | Terminate the execution of the program                                     |
| 09       | 0000 | Variable A            |                                                                            |
| 10       | 0000 | Variable B            |                                                                            |

This program read two values and determine which is greater.


## How to Run

The SMCI program can be compiled and ran localy:
```bash
make build
./smc.out
```

This project also comes has been dockerized and the container can be built by running
```bash
make docker
```
You can execute `docker run -it smli` in order to execute the docker container

#### Credits ####
This program is excersise inspired by chapter 7 of book *_C How to Program From Paul Deitel & Harvey Deitel_*.
