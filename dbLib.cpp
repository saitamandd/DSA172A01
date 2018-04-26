/*
 * =========================================================================================
 * Name        : dbLib.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - Bach Khoa University
 * Description : library for Assignment 1 - Data structures and Algorithms - Spring 2018
 *               This file implements functions used for database management
 * =========================================================================================
 */

#include "dbLib.h"

#include <time.h>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

using namespace std;

void    strPrintTime(char* des, time_t& t) {
    tm *pTime = gmtime(&t);
    strftime(des, 26, "%Y-%m-%d %H:%M:%S", pTime);
}

void loadVDB(char* fName, L1List<VRecord> &db) {
    ifstream inFile(fName);

    if (inFile) {
        FILE*       fd = fopen(fName, "rb");
        int         nRecords = 0;
        char        pBuf[32];
        fread(pBuf, 1, VDB_HEADER_SIZE, fd);
        if (strncmp(pBuf, VDB_HEADER_TEXT, strlen(VDB_HEADER_TEXT)) != 0) {
            clog << "Invalid VDB data file\n";
            fclose(fd);
            return;
        }
        fread(&nRecords, 4, 1, fd);

        VRecord vR;
        int i;
        db.insertHead(vR);
        for (i = 0; i < nRecords; i++) {
            fread(&db.at(0), sizeof(VRecord), 1, fd);
            db.insertHead(vR);
        }
        fclose(fd);
        db.removeHead();
        db.reverse();
        clog << "Read " << i << " records." << endl;
    }
    else {
        clog << "The file is not found!" << endl;
    }
}

void    printVRecord(VRecord& vR) {
    printf("%s: (%0.5f, %0.5f), %s\n", vR.id, vR.x, vR.y, ctime(&vR.timestamp));
}



/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double  distanceVR(double lat1d, double lon1d, double lat2d, double lon2d) {
    double lat1r, lon1r, lat2r, lon2r, u, v;
    lat1r = __deg2rad(lat1d);
    lon1r = __deg2rad(lon1d);
    lat2r = __deg2rad(lat2d);
    lon2r = __deg2rad(lon2d);
    u = sin((lat2r - lat1r)/2);
    v = sin((lon2r - lon1r)/2);
    return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}