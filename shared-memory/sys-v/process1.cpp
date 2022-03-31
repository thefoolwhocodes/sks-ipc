#include <iostream>
#include <sys/shm.h>
  
int main()
{
    std::cout<<"Writer process"<<std::endl;
    {
        key_t key = 20;
      
        // shmget returns an identifier in shmid
        int shmid = shmget(key,1024,0666|IPC_CREAT);
      
        // shmat to attach to shared memory
        char *str = (char*) shmat(shmid,(void*)0,0);
      
        std::cout<<"Provide data to be written: "<<std::endl;
        std::cin.getline(str, 1024);
      
        std::cout << "Data written in memory: " << str << std::endl;
          
        //detach from shared memory 
        shmdt(str);
    }
 
    return 0;
}
