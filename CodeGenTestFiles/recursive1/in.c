int makeFive(int a){
    if(a<5){
        a++;
        return makeFive(a);
    }else{
        return a;
    }
}


