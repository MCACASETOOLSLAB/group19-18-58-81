group19-18-58-81
================


E-LEARNING SOFTWARE FOR PROCESS SYNCHRONIZATION

Here we have tried to develop a software where we will explain you the various cocepts of process synchronization like
critical section, semaphore, mutex, busy waiting etc by taking an example of READERS/WRITERS PROBLEM in two parts.

1. C code implementation.
2. Graphical explaination using HTML.



Readers/Writers Problem

1. There can be 'n' no of readers and a writer for a shared data.
2. At a time only one action can be performed.
3. Any no of reader can read at a time but no one can write at the same time.


Solution

1. Only one process can go  in critical secton.
2. When reader reads mutex is increased which blocks the writer to write at the same time.
3. Untill reader count is 0 the writer waits outside the critical section.
4. After read count is 0 writer writes the data.


=================================================================================================================================



C executable code implementation
================================

# In this the main file is the "rwpro.c" file.

# Compile the file and you will get the executable file.

# Before compiling the file copy the "semaphore.h" header file and paste it in the include directory

# The program wil execute in the form of switch statement.

# where you have to enter the choice that for which you want to see the running example.

# after entering ht choice you can see the running example.




=====================================================================================================================================



Graphical Explaination through HTML
===================================

# First of all run the "main.html" file 

# This will open the home page

# Here we have put the reader/writer problem and its solution.

# In the left-below section there are 5 buttons.

# The buttons are named as 
	
	1.critical section

	2.Semaphore

	3.Busy Waiting

	4.Mutex

	5.Monitor

# Here we have have explain the above topics taking reader/writer problem as a refrence.

# Click on the button on the topic u want to learn 

# on the left there are steps click on next to see the graphical representation of the process.


===========================================================================================================================================
