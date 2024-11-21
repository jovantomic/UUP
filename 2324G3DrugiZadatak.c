#include <stdio.h>
#include <stdlib.h>


int je_prost(int a){
 if(a < 2)return 0;
 for(int i = 2; i <= sqrt(a); i++){
    if( a % i ==0)return 0;
 }
 return 1;

}

int obrni_broj(int n){
  int broj = 0;
  while(n){
   broj = broj * 10 + n%10;
    n/=10;
  }
return broj;
}

int najblizi_prost(int n){
    int l = n-1;
    int r = n+1;
    while(1){
        if(je_prost(r))return r;
        if(je_prost(l))return l;
        r++;
        l--;
    }




}

int main() {
    char c;
    int broj = 0;
    int prvacifra = 0;
    int poslednjacifra = 0;
    int je_broj = 0;

    while ((c = getchar()) != '\n') {
        if (c >= '0' && c <= '9') {
            broj = broj * 10 + (c - '0');
            if (broj < 10) prvacifra = (c - '0');
            poslednjacifra = (c - '0');
            je_broj = 1;
        } else {
            if (je_broj == 1) {
                je_broj = 0;
                if (je_prost(prvacifra) && je_prost(poslednjacifra)) {
                    printf("%d", obrni_broj(broj));
                } else {
                    printf("%d", najblizi_prost(broj));
                }
            }
            broj = 0;
            prvacifra = 0;
            poslednjacifra = 0;
            putchar(c);
        }
    }
    if (je_broj == 1) {
        if (je_prost(prvacifra) && je_prost(poslednjacifra)) {
            printf("%d", obrni_broj(broj));
        } else {
            printf("%d", najblizi_prost(broj));
        }
    }

    return 0;
}
