/****************************************************
 *
 * Display current time implementation like in C++ language
 *
 ***************************************************/
#include <iostream>
#include "Lesson11.h"
using namespace std;

int main()
{
  JTime jtime;

  jtime.displayCurrentTime();

  return 0;
}


JTime::JTime(int offset) : msg("Hello World, time ") 
{
  getTimeOffset(offset);
}

void JTime::getTimeOffset(int offset)
{
  char buffer[JTime::BUFSZ] = { 0 };
  time_t timestamp;

  // Retrieve current time in seconds.
  time(&timestamp);
  timestamp += offset;
  // Convert time<sec> to human format
  ctime_s(buffer, BUFSZ, &timestamp);
  stmp = buffer;
}


void JTime::displayCurrentTime()
{
  std::cout << msg << "now: " << stmp << "\n";
}


#ifdef AAAAAAA
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
#endif // AAAAAA
