#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUF_SIZE 16

int main(){


    pid_t pid;                       //Tworzy nowy proces
    int fd[2];                       //Umozliwia operacje read write
    int in_fd;                       //Wejscie
    int n;                           //Licznik
    char buf[BUF_SIZE];              //Bufor danych
    char fname[32];                  //Przechowuje nazwe pliku

    //Rodzic
    if(pipe(fd) < 0){                //Sprawdza czy poprawnie utworzyl sie potok
        fprintf(stderr,"Nieudana proba stworzenia potoku\n");
        return 1;
    }
    
    pid = fork();                          //Tworzenie dziecka                            

    //Dziecko
    if(pid == 0){                          //Sprawdza czy poprawnie stworzono dziecko


      close(fd[1]);                         //Zamyka zapis
                                            //Wyswietla tekst
      while((n = read(fd[0],&buf,BUF_SIZE)) > 0){     //Odczytuje z wejscia
            write(1," #", 2*sizeof(char));
            write(1,&buf,n);
            write(1,"# ", 2*sizeof(char));
        }
        close(fd[0]);                       //Zamyka czytanie z potoku
    }
    //Rodzic if(pid > 0)
    else{

      close(fd[0]);                         //Zamyka czytanie z potoku
                                            //Czyta nazwe pliku
        printf("Podaj nazwe pliku\n");
        scanf("%s",fname);
                                            //Sprawdza czy plik jest otwarty
        if((in_fd = open(fname,O_RDONLY)) < 0){   //Sprawdza plik
            fprintf(stderr,"Blad otwarcia pliku\n");
            return 2;
        
        }
                                             //Sprawdza czytanie z potoku
        while((n = read(in_fd,&buf,BUF_SIZE)) > 0){
            if(write(fd[1],&buf,n) < 0){
                fprintf(stderr,"Blad zapisu do potoku\n");
                return 3;

            }

    
        }
        close(in_fd);                       //Zamyka wejscie

    }
}
    










