#ifndef _ADC_config_H
#define _ADC_config_H

/****************ADC voltage reference*********************
AREF					=	0
AVCC					=	1
Internal_2.56V			=	2
 */
#define VOLTAGE_REFERENCE_SELECTION	AVCC
/****************ADC prescaller selection*********************
PRESCALLER_2	0
PRESCALLER_4	1
PRESCALLER_8	2
PRESCALLER_16	3
PRESCALLER_32	4
PRESCALLER_64	5
PRESCALLER_128	6
*/
#define ADC_PRESCALLER	PRESCALLER_64
/****************ADC adjust selection*********************
RIGHT_ADJUST	0
LEFT_ADJUST		1
*/
#define ADC_ADJUST	0

#endif
