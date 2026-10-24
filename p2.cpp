#include "request.h"
#include "webserver.cpp"
#include "loadbalancer.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

const int NUM_SERVERS = 5;
static int ps = 0;			// the process ID incrementer, static so one copy persists

request createRandomRequest()
{
   stringstream ips, ipd;
   request r;
   // For example, 12.243.87.112
   ips << (rand() % 256) << "." << (rand() % 256) << "." << (rand() % 256) << "." << (rand() % 256);
   ipd << (rand() % 256) << "." << (rand() % 256) << "." << (rand() % 256) << "." << (rand() % 256);
   r.source = ips.str();
   r.destination = ipd.str();
   r.processTime = (rand() % 500);
   r.pid = ++ps;
   return r;
}

int main()
{
   // random number generator


   // create a loadbalancer

   
   // start off with a "full" queue
   for (int i = 0; i < 10; i++)
   {
 
 
   }
   
   // an array of webservers, each given an initial request to process
   webserver webarray[NUM_SERVERS];
   for (int i = 0; i < NUM_SERVERS; i++)
   {




   }
   // loop
   while (lb.getTime() < 10000)
   {
      int currTime = lb.getTime();
      int size = lb.getSize();
      // check each webserver if it's done
      if(webarray[currTime % NUM_SERVERS].isRequestDone(currTime))
      {
         // get request from the server
		 
		 // print some stats
         cout << "Finished at " << currTime << " " << webarray[currTime % NUM_SERVERS].getName();
         cout << " pid " << r.pid <<"/" << size << " process time was " << r.processTime ;
         cout << " processed request from " << r.source << " to " << r.destination ;
         cout << endl;
		 
         // then give it a new request
         
      }
      // every random set of time, or get a new request







   }

}

