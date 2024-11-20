#include <stdio.h>
#include <stdlib.h>

int mx(int a, int b){
    return a > b ? a : b;

}

int je_prost(int n){
    if(n < 2 )return 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int sledeci_prost(int n){
    n++;
    while(!je_prost(n)){
        n++;
    }
    return n;
}

int max_prosti(int a, int b){
    if(je_prost(a) && je_prost(b)){
        return mx(a,b);
    }
    else if(je_prost(a) && !je_prost(b)){
        return a;
    }
    else if(!je_prost(a) && je_prost(b)){
        return b;
    }
    else{
        return sledeci_prost(mx(a, b));
    }
}

int pom(int arg){

    int prva_cifra, druga_cifra;
    prva_cifra = arg%10;
    druga_cifra = (arg/10)%10;
    int prvi_broj = prva_cifra * 10 + druga_cifra;
    int drugi_broj = druga_cifra * 10 + prva_cifra;
    printf("%d\n", max_prosti(prvi_broj, drugi_broj));


}

int main(){
    int n, x;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &x);
        pom(x);
    }

}
