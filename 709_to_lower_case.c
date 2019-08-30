char* toLowerCase(char* str) {
    if(str==NULL) return NULL;
    for (int i=0;str[i]!='\0';i++){
        if(str[i]>='A'&&str[i]<='Z'){
            str[i]=str[i]-'A'+'a';
        }
    }
    return str;
}
