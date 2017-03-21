#include "timing.h"

////////////////////////////////////////////////////////////

Float getRemainingDuration(Time startTime,
    Float currentPercentage) {
  Duration currentDuration = getDuration(startTime);
  return currentDuration *
    (100.0 / currentPercentage - 1) / 3600;

}

Duration getDuration(Time startTime) {
  Time currentTime = getTime();
  return chrono::duration_cast
    <chrono::seconds>(currentTime - startTime).count();
}

Time getTime() {
  return chrono::system_clock::now();
}

////////////////////////////////////////////////////////////

void testTiming() {
  Time startTime = getTime();
  Long period = 1000000000;
  for (Long i = 0; i < period; i++);
  cout << getRemainingDuration(startTime, 50) << "h left\n";
  for (Long i = 0; i < period; i++);
  cout << getDuration(startTime) << "s total\n";
}
