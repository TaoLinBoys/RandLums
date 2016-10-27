#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>


int randInt(){
  int fd = open("/dev/random",O_RDONLY);
  int randLum;
  //handle errors
  read(fd,&randLum,4);
  close(fd);
  return randLum;
}


int main(){
  int arr[10];

  //filling array
  int ctr;
  printf("First set of random numbers:\n");
  for(ctr = 0; ctr < 10; ctr++){
    arr[ctr] = randInt();
    printf("random %d: %d\n", ctr, arr[ctr]);
  }
  printf("\n");

  
  //writing to file
  printf("Writing to file...\n");
  umask(0);
  int fd = open("randFile.txt", O_CREAT | O_RDWR, 0666);
  write(fd, arr, sizeof(arr)); 
  close(fd);

  
  //reading from file
  printf("Reading from file...\n\n");
  fd = open("randFile.txt", O_RDONLY);
  int readArr[10];
  read(fd, readArr, sizeof(readArr));
  close(fd);


  //printing again
  printf("Second set of random numbers:\n");
  for(ctr = 0; ctr < 10; ctr++){
    printf("random %d: %d\n", ctr, readArr[ctr]);
  }
  
  
  return 0;
}
