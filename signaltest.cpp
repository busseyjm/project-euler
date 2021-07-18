#include <iostream>
#include <csignal>

using namespace std;

void signalHandler( int signum ) {
   cout << "Interrupt signal (" << signum << ") received.\n";


   exit(signum);  
}

int main () {
   // register signal SIGINT and signal handler  
   signal(SIGINT, signalHandler);  

   while(1) {

   }

   return 0;
}