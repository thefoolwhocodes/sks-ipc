#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
 
int main()
{
    /* Size of shared memory object in bytes */
    const int SIZE = 5096;
 
    /* Name of the shared memory object */
    const char* name = "SMO";
 
    /* File descriptor of shared memory */
    int fd;
 
    /* Pointer of type void to shared memory object */
    void* ptr;
 
    /* Open the shared memory object in Read only mode*/
    fd = shm_open(name, O_RDONLY, 0666);
 
    /* Map the shared memory object to the callers address space */
    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, fd, 0);
 
    /* read from the shared memory object */
    std::cout<<"Data read from memory: " << (char*)ptr << std::endl;

    /* Unmap the page */
    munmap(ptr, SIZE);

    /* Close file descriptor */
    close(fd);
 
    /* remove the shared memory object */
    shm_unlink(name);
    return 0;
}
