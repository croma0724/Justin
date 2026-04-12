

#include <iostream>
#include "Lesson1.h"
using namespace std;



int main()
{
  displayCurrentTime();
  std::cout << "\n";

  string stime = getTimeOffset(3600);
  displayTime(stime);
  std::cout << "\n";

  return 0;
}

string getTimeNow()
{
  string ret;
  char buffer[BUFSZ] = { 0 };
  time_t timestamp;

  // Retrieve current time in seconds.
  time(&timestamp);
  // Convert time<sec> to human format
  ctime_s(buffer, BUFSZ, &timestamp);

  ret = buffer;
  return ret;
}

string getTimeOffset(int offset)
{
  string ret;
  char buffer[BUFSZ] = { 0 };
  time_t timestamp;

  // Retrieve current time in seconds.
  time(&timestamp);
  timestamp += offset;
  // Convert time<sec> to human format
  ctime_s(buffer, BUFSZ, &timestamp);
  ret = buffer;
  return ret;
}

void displayCurrentTime()
{
  string ret = getTimeNow();
  cout << Msg << "now: " << ret << "\n";
}

void displayTime(const string& setime)
{
  cout << Msg << "offset: " << setime << "\n";
}