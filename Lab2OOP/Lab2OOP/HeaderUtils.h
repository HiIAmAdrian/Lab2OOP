#pragma once

int compareSuprafata(const void* a, const void* b);
int comparePret(const void* a, const void* b);
int compareTip(const void* a, const void* b);
int compareSuprafata2(const void* a, const void* b);
int comparePret2(const void* a, const void* b);
int compareTip2(const void* a, const void* b);
char* ft_strdup(const char* s1);
void qsor(VectorDinamic* v, int left, int right, int (*comp)(void*, void*));