#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>





int randInt(){
  int fd = open("/dev/random",O_RDONLY);
  int randLum ;
  //handle errors
  read(fd,&randLum,4);
  close(fd);
  return randLum;
}

void printArray(int *arr){
  
}

int main(){
  int *array = (int*)malloc(40);
  
  //filling array up
  int ctr = *array;
  while(*array){
    *array = randInt();
    array++;
  }
  array = ctr;
  
  //writing array into file
  umask(0);
  int fd = open("randFile.txt", O_CREAT | O_APPEND, 0666);

  while(*array){
    write(fd,array,4);
    array++;
  }

  close(fd);
  
  printArray(array);
  return 0;
}
