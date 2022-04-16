#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdlib.h>

int main() {

  int fd[2];                             // Zmienna uzywana przy pobieranie file deskryptorow
  char obraz[100];                       // Przechowuje nazwe pliku graficzneggo
  struct stat filestat;                  // Struktura stat
  char *file_in_memory;                  // Wskaznik na ktory zostaje zmapowany plik
  FILE* plik = fopen("plik.png", "wr");  // Otwiera plik wyjsciowy
  int plik_wym;                          // Sprawdza poprawnosc otwarcia 


  if(fork() == 0){
     sleep(4);
     execlp("display", "", "-update", "1", "-delay", "2", "plik", NULL);   // Wyswietlanie obrazka
  }

  while(1) {

      printf("Podaj nazwe pliku: ");
      scanf("%s", obraz);                                               // Odczytuje nazwe pliku

      if(( fd[0] = open(obraz, O_RDWR, S_IRUSR | S_IWUSR)) < 0 ){       // Sprawdza czy plik zostal poprawnie otwarty
	printf("Nie mozna otworzyc pliku");                             // Pobiera file deskryptory plikow
      }
      fd[1] = open("plik", O_RDWR | O_CREAT);                           // Sprawdza czy pamiec wspolna zostala otwarta
      
      if(fstat(fd[0], &filestat) < 0) {                                 // Pobiera rozmiar pliku
   	 printf("Problem z pobraniem rozmiaru pliku");                  
	 return(1);
      }

      truncate("plik", filestat.st_size);                                  // Zmienia rozmiaru pliku wyjsciowego
                                                                           // Ustawienie wskaznika na zmapowany plik 
      file_in_memory = mmap(NULL, filestat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd[1], 0 );
      read(fd[0], file_in_memory,filestat.st_size);                        // Odczytanie zmapowanego pliku
      msync(file_in_memory, filestat.st_size, MS_SYNC);                    // Synchornizuje plik z zmapowana pamiecia  
      munmap(file_in_memory, filestat.st_size);                            // Usuwa zmapowana pamiec z wskaznika
      
      close(fd[0]);                                                        // Zamyka plik wejsciowy i wyjsciowy
      close(fd[1]);
      
    }
}
