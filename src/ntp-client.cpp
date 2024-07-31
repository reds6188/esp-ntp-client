#include "ntp-client.h"

const long gmtOffset_sec = 0;
const int daylightOffset_sec = 0;

void NtpClient::NtpClient(void) {
	_ntp_started = false;
}

void NtpClient::begin(void) {
	//sntp_set_time_sync_notification_cb(timeAvailable);
	sntp_set_time_sync_notification_cb([this](struct timeval *t) {
		console.success(NTP_T, "Timestamp is available");
		_ntp_started = true;
	}]);
	configTime(gmtOffset_sec, daylightOffset_sec, NTP_SERVER_1, NTP_SERVER_2, NTP_SERVER_3);  
}

time_t NtpClient::getTimestamp(void) {
	time_t now;
	struct tm timeinfo;
	char datetime_str[20];
	time(&now);
	localtime_r(&now, &timeinfo);
	sprintf(datetime_str, "%d:%d:%d %d/%d/%d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec, timeinfo.tm_mday, timeinfo.tm_mon, timeinfo.tm_year);
	console.log(NTP_T, datetime_str);
	console.log(NTP_T, "Current timestamp = " + String(now));
	return now;
}

/*
void timeAvailable(struct timeval *t) {
    console.success(NTP_T, "Timestamp is available");
}
*/