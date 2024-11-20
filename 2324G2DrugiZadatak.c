#include <stdio.h>
#include <stdlib.h>

char smanji_slovo(char c, int x){
    return 'a' + (c - 'a' - x + 26)%26;

}
char povecaj_slovo(char c, int x){
    return 'a' + (c - 'a' + x)%26;

}

int main(){
   char c;
   int broj_reci = 1;
   int broj_slova = 0;
   int broj_slova_predhodne = 0;
   while((c = getchar()) != '\n'){
        if(c == ' '){
            broj_reci++;
            broj_slova = 0;
            printf("%c",' ');
            }
        else if(broj_reci % 2 == 0){
            broj_slova++;
            printf("%c", povecaj_slovo(c, broj_reci));
        }
        else{
            broj_slova++;
            printf("%c", smanji_slovo(c, broj_slova));

        }
   }

}
