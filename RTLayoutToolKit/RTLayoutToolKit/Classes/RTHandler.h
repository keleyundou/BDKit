// Copyright © 2017年 LEJU.
// All rights reserved.
/**********************************************************\
 * PROJECTNAME:  RTLayoutToolKit
 * FILENAME:     RTHandler.h
 * AUTHER:       ColaBean
 * CREATE TIME:  2017/11/24
 * MODIFY TIME:
 * DES:
 \**********************************************************/
//


#ifndef RTHandler_h
#define RTHandler_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

static inline id _EXPObjectify(const char *type, ...) {
    va_list v;
    va_start(v, type);
    id obj = nil;
    if (strcmp(type, @encode(id)) == 0) {
        id actual = va_arg(v, id);
        obj = actual;
    } else if (strcmp(type, @encode(CGPoint)) == 0) {
        CGPoint actual = (CGPoint)va_arg(v, CGPoint);
        obj = [NSValue value:&actual withObjCType:type];
    } else if (strcmp(type, @encode(CGSize)) == 0) {
        CGSize actual = (CGSize)va_arg(v, CGSize);
        obj = [NSValue value:&actual withObjCType:type];
    } else if (strcmp(type, @encode(UIEdgeInsets)) == 0) {
        UIEdgeInsets actual = (UIEdgeInsets)va_arg(v, UIEdgeInsets);
        obj = [NSValue value:&actual withObjCType:type];
    } else if(strcmp(type, @encode(char)) == 0) {
        char actual = (char)va_arg(v, int);
        obj = @(actual);
    } else if(strcmp(type, @encode(_Bool)) == 0) {
        _Static_assert(sizeof(_Bool) <= sizeof(int), "Expected _Bool to be subject to vararg type promotion");
        _Bool actual = (_Bool)va_arg(v, int);
        obj = @(actual);
    } else if(strcmp(type, @encode(double)) == 0) {
        double actual = (double)va_arg(v, double);
        obj = @(actual);
    } else if(strcmp(type, @encode(float)) == 0) {
        float actual = (float)va_arg(v, double);
        obj = @(actual);
    } else if(strcmp(type, @encode(int)) == 0) {
        int actual = (int)va_arg(v, int);
        obj = @(actual);
    } else if(strcmp(type, @encode(long)) == 0) {
        long actual = (long)va_arg(v, long);
        obj = @(actual);
    } else if(strcmp(type, @encode(long long)) == 0) {
        long long actual = (long long)va_arg(v, long long);
        obj = @(actual);
    } else if(strcmp(type, @encode(short)) == 0) {
        short actual = (short)va_arg(v, int);
        obj = @(actual);
    } else if(strcmp(type, @encode(unsigned char)) == 0) {
        unsigned char actual = (unsigned char)va_arg(v, unsigned int);
        obj = @(actual);
    } else if(strcmp(type, @encode(unsigned int)) == 0) {
        unsigned int actual = (int)va_arg(v, unsigned int);
        obj = @(actual);
    } else if(strcmp(type, @encode(unsigned long)) == 0) {
        unsigned long actual = (unsigned long)va_arg(v, unsigned long);
        obj = @(actual);
    } else if(strcmp(type, @encode(unsigned long long)) == 0) {
        unsigned long long actual = (unsigned long long)va_arg(v, unsigned long long);
        obj = @(actual);
    } else if(strcmp(type, @encode(unsigned short)) == 0) {
        unsigned short actual = (unsigned short)va_arg(v, unsigned int);
        obj = @(actual);
    }
    va_end(v);
    return obj;
}

#define RTBValue(value) _EXPObjectify(@encode(__typeof__((value))), (value))

#endif /* RTHandler_h */


