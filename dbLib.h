/*
 * =========================================================================================
 * Name        : dbLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - Bach Khoa University
 * Description : library for Assignment 1 - Data structures and Algorithms - Spring 2018
 *               This library contains functions used for database management
 * =========================================================================================
 */

#ifndef A01_DBLIB_H
#define A01_DBLIB_H

#include <string.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <functional>

#include "listLib.h"
#include "requestLib.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define VDB_HEADER_TEXT     "VRecord data"
#define VDB_HEADER_SIZE     12

#define ID_MAX_LENGTH   16

struct VRecord {
    char    id[ID_MAX_LENGTH];
    time_t  timestamp;
    double  x, y;

    VRecord() {// default constructor
        id[0] = 0;
    }
    VRecord(const char* vID) {
        strcpy(id, vID);
    }
    VRecord(VRecord& vR) : timestamp(vR.timestamp),
                           x(vR.x), y(vR.y) {
        strcpy(id, vR.id);
    }
    VRecord(VRecord&& vR): timestamp(vR.timestamp),
                           x(vR.x), y(vR.y) {
        strcpy(id, vR.id);
    }

    bool operator==(VRecord& b) {
        return  strcmp(id, b.id) == 0 &&
                timestamp == b.timestamp;
    }
};

void    printVRecord(VRecord& vR);
void    strPrintTime(char* des, time_t& t);
void    loadVDB(char* fName, L1List<VRecord> &db);

#define __deg2rad(deg) (deg * pi / 180.0)
#define __rad2deg(rad) (rad * 180.0 / pi)

double  distanceVR(double lat1d, double lon1d, double lat2d, double lon2d);


#endif //A01_DBLIB_H
