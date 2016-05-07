#include <time.h>

#include <iostream>
#include "proto/message.pb.h"

using namespace std;

const int iterations = 1000;

int main(int argc, char const *argv[])
{
  // Setup sample framework Info
  message::FrameworkInfo fwkInfo;
  fwkInfo.set_name("testName");
  fwkInfo.set_user("testUser");

   // Add 10 sample labels	
  message::Labels labels;
  message::Label* label = labels.add_labels();
  label->set_key("testKey");
  label->set_value("testValue");
  label = labels.add_labels();
  label->set_key("testKey");
  label->set_value("testValue"); 
  label = labels.add_labels();
  label->set_key("testKey");
  label->set_value("testValue");  
  label = labels.add_labels();
  label->set_key("testKey");
  label->set_value("testValue");
  label = labels.add_labels();
  label->set_key("testKey");
  label->set_value("testValue");
  label = labels.add_labels();
  label->set_key("testKey");
  label->set_value("testValue");
  label = labels.add_labels();
  label->set_key("testKey");
  label->set_value("testValue"); 
  label = labels.add_labels();
  label->set_key("testKey");
  label->set_value("testValue");  
  label = labels.add_labels();
  label->set_key("testKey");
  label->set_value("testValue");
  label = labels.add_labels();
  label->set_key("testKey");
  label->set_value("testValue");

  fwkInfo.mutable_labels()->CopyFrom(labels); 

  fwkInfo.set_principal("SamplePrincipal");

  fwkInfo.set_failover_timeout(1);

  // `Serialize` fwkInfo via SerializToString and deserialize via `ParseFromString` 
  clock_t tStart = clock(); // Wallclock seems ok
  double failover_timeouts = 0;	

  string serial;
  for (int i = 0; i < iterations; ++i) {
    fwkInfo.SerializeToString(&serial);

    message::FrameworkInfo fwkInfo2;
    fwkInfo2.ParseFromString(serial);
 
    failover_timeouts += fwkInfo2.failover_timeout(); 
  }
  cout << "SerializeToString/ParseFromString: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << " : "  << failover_timeouts << endl;


  // `Serialize` fwkInfo via SerializToString only 
  tStart = clock(); // Wallclock seems ok
  long string_length = 0;	

  for (int i = 0; i < iterations; ++i) {
    fwkInfo.SerializeToString(&serial);

    string_length += serial.size(); 
  }
  cout << "SerializeToString (only): " << (double)(clock() - tStart)/CLOCKS_PER_SEC << " :  "  <<string_length << endl;

  // `Serialize` fwkInfo via CopyFrom
  tStart = clock(); // Wallclock seems ok
  failover_timeouts = 0;	

  for (int i = 0; i < iterations; ++i) {
    message::FrameworkInfo fwkInfo2;
    fwkInfo2.CopyFrom(fwkInfo);
 
    failover_timeouts += fwkInfo2.failover_timeout(); 
  }
  cout << "CopyFrom: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << " :  " << failover_timeouts << endl;


  return 0;
}
