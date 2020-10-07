#include "../inc/header.h" 
char *mx_strcpy(char *dst, const char* src) {
    for (int i = 0; src[i] ; i++) {
        dst[i] = src[i];
    }
    return dst;
}

char *mx_strjoin(char const *s1, char const *s2) {
    if (!s1 && !s2)
        return 0;
    if (!s1 && s2)
        return mx_strdup(s2);
    if (s1 && !s2)
        return mx_strdup(s1);
    char *new_str = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    return mx_strcat(mx_strcpy(new_str, s1), s2);
}

int mx_strlen(const char *s) {
	return (*s) ? mx_strlen(++s) + 1 : 0;
}

char *mx_strnew(const int size) {
    char *newstr = (char *)malloc(size + 1);
    for (int i = 0; i <= size; i++)
        newstr[i] = '\0';
    return newstr;
}

int mx_static_abs(int num) {
    return num < 0 ? -num : num;
}

char *mx_score(int score) {
    if (score == 0) return mx_strdup("0");
    int len = 0;
    bool isNegative = score < 0;
    for (int i = score; i > 0 || i < 0; i /= 10) len++;
    char *number = mx_strnew(len);
    int counter = 0;
    for (; counter < len; counter++) {
        number[len - counter - 1] = mx_static_abs(score % 10) + '0';
        score /= 10;
    }
    return isNegative ? mx_strjoin("-", number) : number;
}

char *mx_strcat(char *s1, const char *s2) {
    int size1 = mx_strlen(s1);
    int size2 = mx_strlen(s2);
    for (int i = size1,z = 0; z < size2; i++, z++) {
        if(s1) {
            s1[i] = s2[z];
        }
        else {
            return s1;
        }      
    }
    return s1;
}

char *mx_strdup(const char *str) {
	char *buffer = mx_strnew(mx_strlen(str));
	return mx_strcpy(buffer, str);
}
