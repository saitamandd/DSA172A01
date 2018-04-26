/*
 * =========================================================================================
 * Name        : requestLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - Bach Khoa University
 * Description : library for Assignment 1 - Data structures and Algorithms - Spring 2018
 *               This library contains functions used for event management
 * =========================================================================================
 */

#ifndef A01_REQUESTLIB_H
#define A01_REQUESTLIB_H

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>

#include "listLib.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define REQUEST_CODE_SIZE     16
using namespace std;

struct VRequest {
    char        code[REQUEST_CODE_SIZE];

    VRequest() {
        code[0] = '0';
        code[1] = 0;
    }
    VRequest(char* str) {
        strncpy(code, str, REQUEST_CODE_SIZE - 1);
    }
    VRequest(string& str) {
        strncpy(code, str.data(), REQUEST_CODE_SIZE - 1);
    }
    VRequest(VRequest& a) {
        memcpy(code, a.code, REQUEST_CODE_SIZE);
    }
    VRequest(VRequest&& a) {
        memcpy(code, a.code, REQUEST_CODE_SIZE);
    }

    bool operator==(VRequest& b) {
        return strcmp(code, b.code) == 0;
    }
};

void loadRequests(char* fName, L1List<VRequest> &rList);

#endif //A01_REQUESTLIB_H
