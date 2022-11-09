typedef struct Pair{
    int x, y;
} Pair;

Pair new_c(int x, int y){
    Pair pair = { x, y };
    return pair;
}

int doubler(int x){
    return x * 2;
}
