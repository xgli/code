int numDecodings(char* s) {
    
    
    int len = strlen(s);
    if(len = 0){
        return 1;
    }
    if(s[0] == '0'){
        return 0;
    }
    if(len == 1){
        return 1;
    }
 
    d[100];
    d[0] == 0;
    
    int i = 1;
    
    int r;
    while(s[i] != '\0'){
        r = (s[i-1] - '0')*10 + (s[i]-'0');
        
        if(s[i]=='0'){
            if(r == 0){
                return 0;
            }
            if(r < 26){
                d[i] = d[i-1] + 1;
            }
            if(r > 26){
                return 0;
            }
        }
        else{
            if(r < 27){
                d[i] = d[i-1] + d[i-2] + 2;
            }
            else{
                d[i] = d[i-1] + 1;
            }
            
        }
        
        i++;
        
    }
    
    
}
