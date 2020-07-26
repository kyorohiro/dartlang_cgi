#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int _key(char* target) {
    for(int index=0;target[index]!= '\0';index++){
        if(target[index]=='=') {
            return index;
        }
    }
    return -1;
}

int _eq(char* target) {
    if(target[0] == '=') {
        return 1;
    }
    return -1;
}

int _value(char* target) {
    int index = 0;
    for(;target[index]!= '\0'&& target[index]!= '&' ;index++){
    }
    return index;
}

int _amp(char* target) {
    if(target[0] == '&') {
        return 1;
    }
    return 0;
}

int getQueryParam(char *key, char *output, int outputLen) {
    char* queryString = getenv("QUERY_STRING");
    int querylen = strlen(queryString);
    int keyLen = strlen(key);
    for(int index=0;index<querylen;index++) {
        int keyStart = index;
        int keyEnd = index;
        int valueStart = index;
        int valueEnd = index;

        // key
        int tokenLength = _key(&queryString[index]);   
        if(tokenLength <0) {
            snprintf(output, outputLen, "%s","");
            return -1;
        }
        keyStart = index;
        keyEnd = index+tokenLength;
        index+=tokenLength;

        // =
        tokenLength = _eq(&queryString[index]);
        if(tokenLength <0) {
            snprintf(output, outputLen, "%s","");
            return -2;
        }
        index+=tokenLength;

        // value
        tokenLength = _value(&queryString[index]);

        if(tokenLength <0) {
            snprintf(output, outputLen, "%s","");
            return -3;
        }
        
        valueStart = index;
        valueEnd = index+tokenLength;
        index+=tokenLength;
        
        // &
        tokenLength = _amp(&queryString[index]);

        //
        if(0==strncmp(key, &queryString[keyStart], keyEnd-keyStart)) {
            if(outputLen < (valueEnd-valueStart+1)) {// +1 is \0
                snprintf(output, outputLen, "%s","");
                return -4;
            }
            snprintf(output,valueEnd-valueStart,"%s", &queryString[valueStart]);
            return 0;
        }

        if(tokenLength == 0) {
            snprintf(output, outputLen, "%s","");
            return 0;
        }
        index+=tokenLength;    
    }
    return 0;
}
