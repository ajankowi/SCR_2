#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(){
 
  int dis[2];                   // Zmienna uzywana przy pobieraniu file deskryptorow
  int ok = 1;                   // Zmienna do petli
  char buff[100];               // Bufor danych
  struct stat filestat;         // Struktura
  char *ptr;                    // Wskaznik



  // if(fork()==0){
  //    execlp("display","display","-update","1","-delay","2","wynik.txt", (char*) NULL);
  // }                                               // Z niewiadomego powodu nie dziala wyswietlanie :/

  while(ok == 1){

      printf("Podaj nazwe pliku ");
      scanf("%s",buff);                                 //Wczytanie nazwy plik
      
      if(buff[0]=='q'){ 
          return(0);                                    //Zamyka petle
      }
      dis[0]=open(buff, O_RDONLY,0);                    //Pobranie file deskryptorow plikow
      dis[1]=open("wynik.txt", O_WRONLY,0);             
      
      if(fstat(dis[0], &filestat)<0){                    //Pobiera rozmiar pliku
          printf("Problem z pozyskaniem danych\n");
          return(1);
      }

      ftruncate(dis[1], filestat.st_size);                              //Zmiana rozmiaru pliku   
      ptr=mmap(0,filestat.st_size,PROT_READ,MAP_SHARED, dis[0],0);      //Wskaznik na pamiec zmapowanego pliku    
      write(dis[1], ptr, filestat.st_size);                             //Zapisuje zmapowana pamiec o danym rozmairze

   
      close(dis[0]);             //Zamykanie 
      close(dis[1]);
    }
}
