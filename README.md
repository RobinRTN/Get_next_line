# Get_next_line

## Overview
"Get Next Line" (GNL) is a programming project from Ecole 42 where I developed a function that reads a file line by line. This project was not only about file I/O but also about efficiently managing memory and understanding static variables. I also included the bonus features to make the function more comprehensive and flexible.

## Functionality
- The core functionality of GNL is to read any valid file descriptor, one line at a time, until the end of the file.
- The main challenge is handling different scenarios like reading from a file, standard input, or even a network socket.

## Key Features
- Line-by-Line Reading: Reads an input source line by line, handling new line characters appropriately.
- Multiple File Descriptor Support: Capable of reading from multiple file descriptors without losing track of each reading stream.
- Error Handling: Includes error handling for file reading and memory allocation issues.

## Bonus Features
- Single Static Variable: Uses only one static variable for tracking the read content.
- Buffer Size Independence: The function works regardless of the buffer size defined during compilation.

## Challenges and Learnings
- Memory Management: Efficiently allocating and freeing memory to prevent leaks.
- Static Variables: Understanding and using static variables effectively in C programming.
