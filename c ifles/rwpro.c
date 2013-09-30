/* The software is about to explain the concept of semaphore,mutex,busy waiting,
critical section etc.. with the help of an e-learning software. This is the
source code of the executable part of the software.We have explained all this concept
with the help of READERS/WRITERS PROBLEM*/


#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>


//declaration of the global variable can be used in each section of the program.

sem_t mutex,writeblock;   //mutex is binary semaphore and write block is counting semaphore
int data = 0;             //data is the data writen by the writer
int rcount = 0;           //no. of reader reading the data at a particular intance


//reader function

void *reader(void *arg)
{
  int f;
  f = ((int)arg);
  sem_wait(&mutex);         //checking mutex before entering the critical section
                            //if the mutex is 0 then only the reader can read the data
  rcount = rcount + 1;      //increasing the no readers
  if(rcount==1)             //if there is any reader reading the data
   sem_wait(&writeblock);   //making the writer wait till the no of reader is 0
  sem_post(&mutex);         //releasing the mutex whwen there is no reader
  printf("Data read by the reader%d is %d\n",f,data);
  sleep(1);
  sem_wait(&mutex);         //if any reader has done reading
  rcount = rcount - 1;      //decrease the no of readers count
  if(rcount==0)             //if the read count is 0
   sem_post(&writeblock);   //allowing writer to write the data
  sem_post(&mutex);         //releasing the mutex
}


//writers function

void *writer(void *arg)
{
  int f;
  f = ((int) arg);
  sem_wait(&writeblock);
  data++;
  printf("Data writen by the writer%d is %d\n",f,data);
  sleep(1);
  sem_post(&writeblock);
}

main()
{
  int i,b;
  pthread_t rtid[5],wtid[5];
  sem_init(&mutex,0,1);
  sem_init(&writeblock,0,1);
  for(i=0;i<=2;i++)
  {
    pthread_create(&wtid[i],NULL,writer,(void *)i); //creating writers thread
    pthread_create(&rtid[i],NULL,reader,(void *)i); //creating readers thread
  }
  for(i=0;i<=2;i++)
  {
    pthread_join(wtid[i],NULL);  //making both the threads
    pthread_join(rtid[i],NULL);  //work continously
  }
}
