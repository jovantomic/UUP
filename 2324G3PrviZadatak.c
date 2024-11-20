#include <stdio.h>
#include <stdlib.h>

int mx(int a, int b){
    return a > b ? a : b;
}

int mn(int a, int b){
    return a < b ? a : b;
}
int sklonibroj(int a, int b){
    int stepen = 1;
    int broj =0;
    while(a>0){

        if(a%10!=b){
            broj += (a%10)*stepen;
            stepen *=10;
        }
        a/=10;
    }
     return broj;

}

int beznajvece(int n){
    int temp = n;
    int mx_cifra =0;
    while(temp>0){
        mx_cifra = mx(mx_cifra, temp%10);
        temp/=10;
    }

    return sklonibroj(n, mx_cifra);

}

int beznajmanje(int n){
    int temp = n;
    int mn_cifra =1e9;
    while(temp>0){

        mn_cifra = mn(mn_cifra, temp%10);
        temp/=10;
    }
    return sklonibroj(n, mn_cifra);
}

int je_fibnovacijev(int n) {
    if(n == 0 || n == 1) return 1;
    int x= 1;
    int y= 1;
    while(y <= n) {
        if (y == n) return 1;
        int tr = x + y;
        x = y;
        y = tr;
    }
    return 0;
}

int pom(int arg){
    if(je_fibnovacijev(arg))
        beznajvece(arg);
    else
        beznajmanje(arg);
}

int main(){

    int x;
    while(1){
     scanf("%d", &x);
     if(x == 0){ printf('0');break;}
     else printf("%d", pom(x));

    }

}
