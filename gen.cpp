#include<bits/stdc++.h>
using namespace std;

int randint(int a, int b){
    return a + rand() % (b - a + 1);
}

char randchar(char a, char b){
    return (char) a + randint(0,b-a);
}

int main(int argc, char* argv[]){
    srand(stoi(argv[1]));
    int t = 1;
    int a =randint(1,20);
    int b =randint(a,a+20);
    int v = randint(1,40);
    cout<<t<<" "<<a<<" "<<b<<" "<<v <<"\n";
    return 0;
}