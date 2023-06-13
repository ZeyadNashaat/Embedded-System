#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_

#define SW_u8STATE_PRESSED     1
#define SW_u8STATE_NPRESSED    0

#define SW_u8CONNTYPE_PULLUP   1
#define SW_u8CONNTYPE_PULLDOWN 0

#define SW_u8LOCKTYPE_SELF     1
#define SW_u8LOCKTYPE_TEMP     0

typedef struct
{
	u8 PORT;
	u8 PIN;
	u8 LOCKTYPE;
	u8 CONNTYPE;
}SW_t;

u8 SW_u8GetState(SW_t* Copy_pu8struct);

#endif
