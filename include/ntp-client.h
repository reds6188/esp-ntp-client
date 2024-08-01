#ifndef NTP_CLIENT_H_
#define NTP_CLIENT_H_

#include <Arduino.h>
#include <esp_sntp.h>
#include <console.h>

#define NTP_T			"NTP"

#define NTP_SERVER_1	"pool.ntp.org"
#define NTP_SERVER_2	"time.nist.gov"
#define NTP_SERVER_3	"time.google.com"

void timeAvailable(struct timeval *t);
void initNtpClient(void);
time_t getTimestampNtp(void);
bool isNtpSync(void);

#endif  /* NTP_CLIENT_H_ */