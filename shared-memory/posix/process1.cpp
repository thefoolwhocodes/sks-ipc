#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
 
int main()
{
    /* Size of shared memory object in bytes */
    const int SIZE = 5096;
 
    /* Name of shared memory object */
    const char* name = "SMO";
 
    /* File descriptor of shared memory */
    int fd;
 
    /* Pointer of type void to shared memory object */
    void* ptr;
 
    /* Create the shared memory object */
    fd = shm_open(name, O_CREAT | O_RDWR, 0666);
 
    /* Configure the size of the shared memory object with given size */
    ftruncate(fd, SIZE);
 
    /* Map the shared memory object to the callers address space */
    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, fd, 0);
 
    /* Write to the shared memory object */
    std::cout<<"Provide data to be written: "<<std::endl;
    std::cin.getline((char*)ptr, SIZE);

    /* Unmap the page */
    munmap(ptr, SIZE);

    /* Close file descriptor */
    close(fd);
 
    return 0;
}
