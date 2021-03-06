
   /////////////////////////////////////////////////////////////////////////
//  Reader and Writer problem
//

#include "list.h"
#include "system.h"
#include "synch.h"
#include "testcase.h"

void  read( int pagenum)
{
    Reader* creader;	// The defination can only be put in the function "read",
    			// because of this function is executing in several threads simultaneously.
    printf("%s arrives, waiting to read \n",currentThread->getName());
    creader = new Reader(currentThread->getName());
    currentThread->Yield();
    creader->read(pagenum);


}

void  write( int pagenum)
{
    Writer* cwriter;	// The defination can only be put in the function "write",
    			// because of this function is executing in several threads simultaneously.
    printf("%s arrives, waiting to write \n",currentThread->getName());
    cwriter = new Writer(currentThread->getName());
    currentThread->Yield();
    cwriter->write(pagenum);

}
void SynchTest2()
{
    scheduler->SetSchedPolicy(SCHED_RR);
    
    Thread *t_1 = new Thread("Mary");
    Thread *t_2 = new Thread("Susan");

    t_1->Fork(read,  5);
    t_2->Fork(read,  6);
}
