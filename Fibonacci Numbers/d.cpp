
string isFibo(long long int m) {
    
    bool flag = false;
    long long int a =0,b=1;
    while(b<=m){
        if(b==m){
            flag = true;
            break;
        }
        tie(a,b) = make_tuple(b,a+b);
    }
    
    if(flag)
        return "IsFibo";
    else
        return "IsNotFibo";
}
