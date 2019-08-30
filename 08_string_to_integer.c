#define INT_MAX 2147483647
#define INT_MIN -2147483648
            
int myAtoi(char* str) {
    if (str[0]=='\0') return 0;
    int i=0;
    int first_valid_position=-1;
    int last_valid_position=-1;
    int positive=1;
    long power=1;
    long ret=0;
    for(i=0;str[i]!='\0';i++) {
        if(str[i]=='-' || str[i]=='+' || (str[i]>='0' && str[i] <= '9')) {
            first_valid_position=i;
            break;
        } else if(str[i]==' ') {
            continue;
        } else {
            return 0;
        }
    }
    if(first_valid_position==-1) return 0;
    for(i=first_valid_position+1;str[i]!='\0';i++){
        if(str[i]<'0' || str[i]>'9'){
            last_valid_position=i-1;
            break;
        }
    }
    
    if(last_valid_position==-1) last_valid_position=i-1;
    if(last_valid_position-first_valid_position<0) return 0;
    
    if(last_valid_position==first_valid_position && \
		    (str[first_valid_position]=='-' || \
		     str[first_valid_position]=='+'))
        return 0;
    if(str[first_valid_position]=='-') {
        positive=0;
        first_valid_position+=1;
    }
    if(str[first_valid_position]=='+') {
        positive=1;
        first_valid_position+=1;
    }
    for(i=first_valid_position;i<=last_valid_position;i++){
        if(str[i]=='0'){
            first_valid_position+=1;
        }else{
            break;
        }
    }  
    if(last_valid_position-first_valid_position>11) 
	    return positive ? INT_MAX : INT_MIN;
    for(i=last_valid_position;i>=first_valid_position;i--){  
        ret=ret+power*(str[i]-'0');
        power=10*power;
    }
//    ret=ret+(str[last_valid_position]-'0');
    if(!positive) ret=-1 * ret;
    if(ret>INT_MAX) return INT_MAX;
    if(ret<INT_MIN) return INT_MIN;
    return (int)ret;
}
           

