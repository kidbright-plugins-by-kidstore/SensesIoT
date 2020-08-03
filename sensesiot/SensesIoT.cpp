#ifndef __SENSESIOT_CPP__
#define __SENSESIOT_CPP__

#include "SensesIoT.h"

SensesIoT::SensesIoT() { }

void SensesIoT::init(void) {
	esp_log_level_set("*", ESP_LOG_INFO);
	
	// clear error flag
	error = false;
	// set initialized flag
	initialized = true;
}

int SensesIoT::prop_count(void) {
	return 0;
}

bool SensesIoT::prop_name(int index, char *name) {
	// not supported
	return false;
}

bool SensesIoT::prop_unit(int index, char *unit) {
	// not supported
	return false;
}

bool SensesIoT::prop_attr(int index, char *attr) {
	// not supported
	return false;
}

bool SensesIoT::prop_read(int index, char *value) {
	// not supported
	return false;
}

bool SensesIoT::prop_write(int index, char *value) {
	// not supported
	return false;
}

void SensesIoT::process(Driver *drv) {
	
}

void SensesIoT::config(uint32_t userid, char *key) {
	this->userid = userid;
	this->key = key;
}

esp_err_t SensesIoT::send(uint32_t slot, float data) {
	char *url = (char*)malloc(500);
	memset(url, 0, 500);

	sprintf(url, "http://www.sensesiot.com:4000/send/%d/%s/%d/%f", this->userid, this->key, slot, data);
	ESP_LOGI("SensesIoT", "Url: %s", url);
	
	// Use esp http api
	esp_http_client_config_t config = {
        .url = url
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);
    esp_http_client_set_method(client, HTTP_METHOD_GET);
    esp_err_t err = esp_http_client_perform(client);

    if (err == ESP_OK) {
		uint16_t len = esp_http_client_get_content_length(client);
		uint16_t code = esp_http_client_get_status_code(client);
		
        ESP_LOGI("SensesIoT", "HTTPS Status = %d, content_length = %d", code, len);
		
		char *data = (char*)malloc(len + 1);
		esp_http_client_read(client, data, len);
		data[len] = 0;
	
		ESP_LOGI("SensesIoT", "Content: %s", data);

		free(data);
    } else {
        ESP_LOGE("SensesIoT", "Error perform http request %s", esp_err_to_name(err));
    }
    esp_http_client_cleanup(client);
	
	free(url);
	
	return err;
}

int SensesIoT::getDigitalControl(uint32_t port) {
	char *url = (char*)malloc(500);
	memset(url, 0, 500);

	sprintf(url, "http://www.sensesiot.com:4000/getdigitalstatus/%d/%s/%d", this->userid, this->key, port);
	ESP_LOGI("SensesIoT", "Url: %s", url);
	
	// Use esp http api
	esp_http_client_config_t config = {
        .url = url
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);
    esp_http_client_set_method(client, HTTP_METHOD_GET);
    esp_err_t err = esp_http_client_perform(client);

	int value = 0;

    if (err == ESP_OK) {
		uint16_t len = esp_http_client_get_content_length(client);
		uint16_t code = esp_http_client_get_status_code(client);
		
        ESP_LOGI("SensesIoT", "HTTPS Status = %d, content_length = %d", code, len);
		
		char *data = (char*)malloc(len + 1);
		esp_http_client_read(client, data, len);
		data[len] = 0;
	
		ESP_LOGI("SensesIoT", "Content: %s", data);
		
		value = strcmp(data, "on") == 0 ? 1 : 0;

		free(data);
    } else {
        ESP_LOGE("SensesIoT", "Error perform http request %s", esp_err_to_name(err));
    }
    esp_http_client_cleanup(client);
	
	free(url);
	
	return value;
}

#endif
