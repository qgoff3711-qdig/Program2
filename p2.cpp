#include "request.h"
#include "webserver.cpp"
#include "loadbalancer.h"

#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

const int NUM_SERVERS = 5;
static int ps = 0;

request createRandomRequest()
{
   stringstream ips, ipd;
   request r;

   ips << (rand() % 256) << "."
       << (rand() % 256) << "."
       << (rand() % 256) << "."
       << (rand() % 256);

   ipd << (rand() % 256) << "."
       << (rand() % 256) << "."
       << (rand() % 256) << "."
       << (rand() % 256);

   r.source = ips.str();
   r.destination = ipd.str();
   r.processTime = rand() % 500;
   r.pid = ++ps;

   return r;
}

int main()
{
   // Fixed seed makes the program deterministic.
   srand(1);

   loadbalancer lb;

   // Start with a full queue containing 10 requests.
   for (int i = 0; i < 10; i++)
   {
      lb.addRequest(createRandomRequest());
   }

   // Create the webservers and give each one a starting request.
   webserver webarray[NUM_SERVERS];

   for (int i = 0; i < NUM_SERVERS; i++)
   {
      webarray[i] = webserver('A' + i);

      request r = lb.getRequest();
      webarray[i].addRequest(r, lb.getTime());
   }

   // Run the simulation.
   while (lb.getTime() < 10000)
   {
      int currTime = lb.getTime();
      int size = lb.getSize();

      int serverIndex = currTime % NUM_SERVERS;

      // Check whether the selected server has finished its request.
      if (webarray[serverIndex].isRequestDone(currTime))
      {
         request finishedRequest = webarray[serverIndex].getRequest();

         cout << "Finished at " << currTime << " "
              << webarray[serverIndex].getName()
              << " pid " << finishedRequest.pid
              << "/" << size
              << " process time was " << finishedRequest.processTime
              << " processed request from "
              << finishedRequest.source
              << " to "
              << finishedRequest.destination
              << endl;

         // Give the server another request if one is waiting.
         if (!lb.isRequestQueueEmpty())
         {
            request nextRequest = lb.getRequest();
            webarray[serverIndex].addRequest(nextRequest, currTime);
         }
      }

      // Randomly add new requests to the load balancer.
      if (rand() % 100 < 10)
      {
         lb.addRequest(createRandomRequest());
      }

      lb.incTime();
   }

   return 0;
}