#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "pressure_Sensor.h"
#include "Mointor_Alarm.h"


int main (){
	GPIO_INITIALIZATION();
	pressure_State_ptr = state(Reading);
	Set_Alarm_actuator(1);
	
	while (1)
	{
		//Implement your Design
		pressure_State_ptr();	
	}

}
