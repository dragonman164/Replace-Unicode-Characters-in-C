#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// ascii character range is 0-127 
// so take bitwise and with complement of 127 it should be 0 
int is_ascii(char ch) {
    return (ch & ~0x7f) == 0?1:-1;
}
// expected that pattern should not contain unicode characters
// steps : 
// 1. Detect series of non-ascii printable characters
// 2. For each set of series of non-ascii characters, increase required length by length of pattern. If non ascii character continue 
// 3. Now create a new string and introduce new characters accordingly
char *replaceUnicodeCharacters(char *a, char *ptr){
    int required_len = 0;
    int n = strlen(a);
    int m = strlen(ptr);
    for(int i = 0; i < n; i++ ){
        if(is_ascii(a[i]) == 1) {
            required_len ++ ;
            continue;
        }
        while(is_ascii(a[i]) == -1 && i < n) i ++ ;
        i -- ;
        required_len += m;
    }
    char *newString = malloc((required_len + 1)*sizeof(char));
    int i = 0;
    int j = 0;
    while(j < n){
        if(is_ascii(a[j]) == 1) {
            newString[i++] = a[j++];
            continue;
        }
        for(int x = 0; x < m ; x++ ){
            newString[i++] = ptr[x];
        }
        while(is_ascii(a[j]) == -1  && j < n) j ++ ;

    }
    newString[i] = '\0';
    return newString;

    

}
int main(){
    char *a = "A☹BC•def☹";
    printf("%ld\n",strlen(a));
    printf("%s",replaceUnicodeCharacters(a, "abc"));
    return 0;
}
