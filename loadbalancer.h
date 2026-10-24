// loadbalancer.h

#ifndef LOAD_BALANCER_H
#define LOAD_BALANCER_H

#include "request.h"
#include <queue>     // STL for queue and priority_queue
#include <stack>     // STL for stack

class loadbalancer
{
   public:
      loadbalancer()
      {
         systemTime = 0;
      }
      int getTime();
      void incTime();
      void addRequest(request r);
      request getRequest();
      bool isRequestQueueEmpty();
      int getSize();
   private:
      int systemTime;
      queue<request> requestQueue;
      //priority_queue<request, vector<request>, MaxProcessTime> requestQueue;
      //priority_queue<request, vector<request>, MinProcessTime> requestQueue;
      //priority_queue<request, vector<request>, MaxPID> requestQueue;
      //stack<request> requestQueue;
};

#endif
