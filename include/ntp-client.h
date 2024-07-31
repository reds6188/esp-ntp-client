#ifndef NTP_CLIENT_H_
#define NTP_CLIENT_H_

#include <Arduino.h>
#include <esp_sntp.h>
#include <console.h>

#define NTP_T			"NTP"

#define NTP_SERVER_1	"pool.ntp.org"
#define NTP_SERVER_2	"time.nist.gov"
#define NTP_SERVER_3	"time.google.com"

Class NtpClient {
	private:
		_ntp_started;
	public:
		NtpClient(void);
		void begin(void);
		time_t getTimestamp(void);
		bool isSync(void):
};

#endif  /* NTP_CLIENT_H_ */