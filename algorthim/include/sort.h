#ifndef _SORT_H
#define _SORT_H

extern void swap(void *a,void *b,int size);
extern void q_sort(void *base,int start,int end,int size,int (*cmp)(const void *a,const void *b));
extern void select_sort(void *a,int start,int end,int size,int (*cmp)(const void *a,const void *b));

extern int 	cmp_int(const void *a,const void *b);
extern int 	cmp_double(const void *a,const void *b);
extern int 	cmp_char(const void *a,const void *b);
extern int  cmp_string(const void *a,const void *b);
#endif
