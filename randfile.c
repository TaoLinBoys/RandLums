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
  while (*arr){
	printf("%d, ",*arr);
	arr++;
  }
  
}

int main(){
  int *array = (int*)malloc(40);
  
  //filling array up
  int ctr = 0;
  int *temp = array;
  while(ctr<10){
    *array = randInt();
	array++;
    ctr++;
  }


  //writing array into file
  umask(0);
  int fd = open("randFile.txt", O_CREAT | O_APPEND, 0666);

  
  while(*temp){
	if (write(fd,temp,4) == -1){
		printf("what");
	}
    temp++;
  }

  close(fd);

  printArray(array);
  free(array);
  return 0;
}
