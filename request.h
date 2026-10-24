// request.h
#ifndef REQUEST_H
#define REQUEST_H

#include <string>

using namespace std;

// From IP source address to IP destination address and time for
// request to complete 
struct request {
   string source;
   string destination;
   int processTime;
   int pid;
};

// Comparator for max heap priority queue by process time
struct MaxProcessTime {
    bool operator()(request const& r1, request const& r2) {
        return r1.processTime < r2.processTime;
    }
};

// Comparator for min heap priority queue by process time
struct MinProcessTime {
    bool operator()(request const& r1, request const& r2) {
        return r1.processTime > r2.processTime;
    }
};

// Comparator for max heap priority queue by pid
struct MaxPID {
    bool operator()(request const& r1, request const& r2) {
        return r1.pid < r2.pid;
    }
};
#endif
