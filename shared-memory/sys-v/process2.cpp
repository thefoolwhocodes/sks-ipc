#include <iostream>
#include <sys/shm.h>
  
int main()
{
    std::cout<<"Reader process.."<<std::endl;
    {
        key_t key = 20;
      
        // shmget returns an identifier in shmid
        int shmid = shmget(key,1024,0666|IPC_CREAT);
      
        // shmat to attach to shared memory
        char *str = (char*) shmat(shmid,(void*)0,0);
      
        std::cout<<"Data read from memory: " << str << std::endl; 
          
        //detach from shared memory 
        shmdt(str);
        
        // destroy the shared memory
        shmctl(shmid,IPC_RMID,NULL);
    }

    return 0;
}
