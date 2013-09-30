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
