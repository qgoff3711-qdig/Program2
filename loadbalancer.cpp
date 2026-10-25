/*
 * loadbalancer.cpp
 *
 * Manage the CPU load by assigning next job to CPU with the least load
 */

#include "loadbalancer.h"

int loadbalancer::getTime()
{
   return systemTime;
}

void loadbalancer::incTime()
{
   systemTime++;
}

void loadbalancer::addRequest(request r)
{
   requestQueue.push(r);
}

request loadbalancer::getRequest()
{
   // Use front() for a queue.
   request r = requestQueue.top();

   // For a stack or priority_queue, replace the line above with:
   // request r = requestQueue.top();

   requestQueue.pop();
   return r;
}

bool loadbalancer::isRequestQueueEmpty()
{
   return requestQueue.empty();
}

int loadbalancer::getSize()
{
   return requestQueue.size();
}