#ifndef __SENSESIOT_H__
#define __SENSESIOT_H__

#include "driver.h"
#include "device.h"
#include "esp_log.h"

#include "esp_http_client.h"

#include <stdio.h>
#include <string.h>
#include "esp_system.h"
#include "kidbright32.h"

class SensesIoT : public Device {
	private:
		uint32_t userid = 0;
		char *key = NULL;

	public:
		// constructor
		SensesIoT();
		// override
		void init(void);
		void process(Driver *drv);
		int prop_count(void);
		bool prop_name(int index, char *name);
		bool prop_unit(int index, char *unit);
		bool prop_attr(int index, char *attr);
		bool prop_read(int index, char *value);
		bool prop_write(int index, char *value);
		
		// method
		void config(uint32_t userid, char *key) ;	
		esp_err_t send(uint32_t slot, float data) ;
		int getDigitalControl(uint32_t port) ;
		
};

#endif
