#include <stdio.h>
#include <stdlib.h>

int mn(int a, int b){
    return a < b ? a : b;
}


int stepen(int a, int b){
 if(b == 0) return 1;
 int rez=1;
 while(b--){
    rez *=a;
 }
 return rez;

}

int najveci_prost(int x){
    int tr = 2;
    int rez =2;
    while(tr < x){
        tr++;
        if(je_prost(tr))
            rez = tr;
    }
    return rez;

}

int je_prost(int x){
    if( x < 2) return 0;
    for(int i = 2; i < sqrt(x); i++){
        if(x % i == 0)
            return 0;
    }
    return 1;

}

int manji_prost(int a, int b){
    if(je_prost(a) && je_prost(b)){
        return(mn(a, b));
    }
    else if(je_prost(a) && !je_prost(b)){
        return a;
    }
    else if(!je_prost(a) && je_prost(b)){
        return b;
    }
    else {
        return najveci_prost(mn(a,b));
    }

}


int pom(int n){
 int temp = n;
 int duzina = 0;
 while(temp){
    duzina++;
    temp/=10;
 }
 int prva_cifra = n / stepen(10, duzina -1);
 int druga_cifra = (n / stepen(10, duzina -2))%10;
 //printf("%d%d", prva_cifra, druga_cifra);
 int prvibroj = prva_cifra*10 + druga_cifra;
 int drugibroj = druga_cifra*10 + prva_cifra;
 manji_prost(prvibroj, drugibroj);

}


int main(){
   int n, x;
   scanf("%d", &n);
   while(n--){
    scanf("%d", &x);
    printf("%d", pom(x));

   }

}
