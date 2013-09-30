//Writer module


#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>


//declaration of the global variable can be used in each section of the program.

sem_t mutex,writeblock;   //mutex is binary semaphore and write block is counting semaphore
int data = 0;             //data is the data writen by the writer
int rcount = 0;           //no. of reader reading the data at a particular intance



//writers function

void *writer(void *arg)
{
  int f;
  f = ((int) arg);
  sem_wait(&writeblock);    //check whether the mutex is zero or not(busy waiting)
  data++;                   //get the access to write the data(crititcal section)
  printf("Data writen by the writer%d is %d\n",f,data);//Print data
  sleep(1);
  sem_post(&writeblock);    //release the mutex
}

main()
{
  int i,b;
  pthread_t rtid[5],wtid[5];
  sem_init(&mutex,0,1);       //initialise the mutex
  sem_init(&writeblock,0,1);  //initialize the write block semaphore
  for(i=0;i<=2;i++)
  {
    pthread_create(&wtid[i],NULL,writer,(void *)i); //creating writers thread
  }
  for(i=0;i<=2;i++)
  {
    pthread_join(wtid[i],NULL);  //making both the threads
  }
}
