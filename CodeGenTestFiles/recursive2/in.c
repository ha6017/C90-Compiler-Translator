


int recur(int x){
    if(x!=0){
        x--;
        return recur(x);
    }else{
        return x;
    }
}
