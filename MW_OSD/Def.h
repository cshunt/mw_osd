/*--------------------------       advanced parameters      ----------------------------------------------------*/
/*--------------------------       advanced parameters      ----------------------------------------------------*/
/*--------------------------       advanced parameters      ----------------------------------------------------*/
/*--------------------------       advanced parameters      ----------------------------------------------------*/

/*----------------------------------------------       Developer parameters      ----------------------------------------------------*/
//#define ALWAYSARMED
//#define FORCESENSORS

// Display Debug screen display options
//#define DEBUGMW            // Enable to display MSP debug values (assumes debug[x] values are not set elsewhere) 
#define DEBUGDPOSRCDATA 33   // display RCDATA values at position X
#define DEBUGDPOSANAL 84     // display sensor values at position X
#define DEBUGDPOSPWM 264     // display PWM values at position X
#define DEBUGDPOSVAL 40      // display debug values at position X
#define DEBUGDPOSLOOP 160    // display loop rate value at position X
#define DEBUGDPOSSAT 190     // display sat value at position X
#define DEBUGDPOSARMED 250   // display armed value at position X
#define DEBUGDPOSPACKET 280  // display serial packet rate rate value at position X
#define DEBUGDPOSMEMORY 310  // display free heap/stack memory at position X. Requires MEMCHECK and not valid in latest Arduino versions
#define DEBUGDPOSRX 220      // display serial data rate at position X
//#define DEBUGDPOSMSPID 33  // display MSP ID received

// Display Debug text message in standard screen text warning message area
// Enable and set debugtext=1 in code when required 
//#define ENABLEDEBUGTEXT
#define DEBUGTEXT "DEBUG"    // Set text you wish to display when debug text message required. Must be CAPSLOCK text

//#define HARDRESET                        // Enables watchdog timer reset rather than fixed memory jmp 
#define BOOTRESET                          // Enables reset from default Atmega 328 bootloader address (instead of 0) 

#ifdef DEVELOPMENT                  // Developement pre-set test paramters only 
  #define MINIMOSD                  // Uncomment this if using standard MINIMOSD hardware (default)
  #define GPSOSD_NMEA               // Uncomment this if you are using a NMEA compatible GPS module for a GPS based OSD
  //#define GPSOSD_UBLOX              // Uncomment this if you are using a UBLOX GPS module for a GPS based OSD
  #define FIXEDWING                 // Uncomment this if you are using fixed wing with MultiWii or Baseflight
  #define MASKGPSLOCATION           // MASK GPS coordinate display with major digits set to random location "XXX.DDDDDDD" 
#endif



/*--------------------------       DEPRECATED parameters for reference only      ----------------------------------------------------*/

/********************       OSD SCREEN SWITCH settings      *********************/
// This functionality enables :
// a, 2 different screen layouts to be selected using the Flight controller "OSD_SWITCH" feature or
// b, 2 or 3 different screen layouts to be selected using a specificed RC channel assigned to a TX switch
//Choose ONLY ONE option:
#define OSD_SWITCH_RC               // Enables 3 way screen switch using a TX channel via FC. Specify channel on GUI (range 0-7 AUX1=4 AUX4=7)
//#define OSD_SWITCH                // DEPRECATED Forces original 2 way screen switch using OSD Switch via Flight Controller. MUST Ensure enabled on flight controller - e.g. #define OSD_SWITCH on multiwii




/********************  HARDWARE rule definitions  **********************/

// VTX_RTC6705 Support for RTC6705 based VTX
// VTX_RC      Support for SINGULARITY-style direct RC stick command
// VTX_LED     Support for dedicated single status LED (not a LED strip support)
// MENU_VTX    Support for VTX page in MWOSD MENU

#ifdef IMPULSERC_HELIX
//  #define RUSHDUINO
  #define VTX_RTC6705
  #define VTX_RC
  #define VTX_LED
  #define USE_MENU_VTX
  #define INFO_OPTIONS1 1<<4
#endif

#ifdef FFPV_INNOVA
  #define MINIMOSD
  #define VTX_RTC6705
  //#define VTX_RC    // Can be turned on, hard to use without VTX_LED
  //#define VTX_LED   // Needs VTXLED_* definitions in RTC6705.ino
  #define USE_MENU_VTX
  #define INFO_OPTIONS1 1<<4
#endif




/********************  CONTROLLER rule definitions  **********************/

#ifdef MULTIWII       //set up latest at time of release
  #define MULTIWII_V24
#endif

#ifdef MAHOWII       //set up latest at time of release
  #define MULTIWII_V24
#endif

#ifdef BETAFLIGHT    //set up latest at time of release
  #define BETAFLIGHT31
#endif

#ifdef TAULABS    //set up latest at time of release
//  #define TAULABS
#endif

#ifdef DRONIN    //set up latest at time of release
  #define TAULABS
#endif

#ifdef LIBREPILOT
  #define TAULABS
  #define USE_MSP_PIDNAMES
#endif

#ifdef CLEANFLIGHT    //set up latest at time of release
  #define BETAFLIGHT31
#endif

#ifdef iNAV    //set up latest at time of release
//  #define iNAV
#endif

#ifdef BASEFLIGHT     //set up latest at time of release
  #define BASEFLIGHT20150627
#endif
  
#ifdef RACEFLIGHT     //set up latest at time of release
#endif

#ifdef FIXEDWING_BF     //set up latest at time of release
  // based upon these..
  // #define BASEFLIGHT20150627
  // #define FIXEDWING
#endif

#ifdef FIXEDWING_BF_SERVO //set up latest at time of release
  // based upon these..
  // #define BASEFLIGHT20150627
  // #define FIXEDWING
#endif

#ifdef HARAKIRI
  #define BOXNAMES
  #define MULTIWII_V24
#endif

#ifdef PX4   //set up latest at time of release
  #define APM
#endif

#ifdef APM       //set up latest at time of release
#endif

#ifdef KISS      //set up latest at time of release
#endif

#ifdef SKYTRACK  //set up latest at time of release
#endif

// The unit of current varies across implementations.  There are effectively three set:
// * 100mA, for which case the value is usable as it comes aross the wire. default
// * 10mA, which sends a value 10x higher than we work wth
// * 1ma, which sends a value 100x higher than normal

//CORRECT_MSP_BF1 introduced BF201506 - adds seperate Pitch/Roll/Yaw + TPA     (MSP support)
//CORRECT_MENU_RCT1 introduced CF180/BF201506 - adds seperate Pitch/Roll/Yaw + TPA     (Menu Support)
//CORRECT_MENU_RCT2 introduced CF190 - adds seperate Pitch/Roll/Yaw + TPA + Yaw expo     (Menu support)
//ENABLE_MSP_SAVE_ADVANCED - adds the code to read/write PROFILE+LOOPIME+PID CONTROLLER if supported
//CORRECTLOOPTIME show looptime option in Adavanced tuning menu

#if defined BETAFLIGHT3
  #define AMPERAGE_DIV 10
  #define CORRECT_MSP_CF2
  #define CORRECT_MENU_RCT2
  #define ENABLE_MSP_SAVE_ADVANCED
  #define ACROPLUS

  #define MENU_STAT     0       //STATISTICS
  #define MENU_PID      1       //PID CONFIG
  #define MENU_RC       2       //RC TUNING
  #define MENU_RC_2     3       //RC TUNING PAGE 2
  #define MENU_VOLTAGE  4       //VOLTAGE
  #define MENU_RSSI     5       //RSSI
  #define MENU_CURRENT  6       //CURRENT
  #define MENU_DISPLAY  7       //DISPLAY
  #define MENU_ADVANCED 8       //ADVANCED
  #define MENU_ALARMS   9       //ALARMS
  #define MENU_PROFILE  10      //PROFILE+PID CONTROLLER
  #define MENU_DEBUG    11      //DEBUG
  #define MAXPAGE       MENU_DEBUG
#endif

#if defined BETAFLIGHT31
  #define AMPERAGE_DIV 10
  #define CORRECT_MSP_CF2
  #define CORRECT_MENU_RCT2
  #define ENABLE_MSP_SAVE_ADVANCED
  #define ACROPLUS

  #define MENU_STAT     0       //STATISTICS
  #define MENU_PID      1       //PID CONFIG
  #define MENU_RC       2       //RC TUNING
  #define MENU_RC_2     3       //RC TUNING PAGE 2
  #define MENU_INFO     4       //RC TUNING FC
  #define MENU_VOLTAGE  5       //VOLTAGE
  #define MENU_RSSI     6       //RSSI
  #define MENU_CURRENT  7       //CURRENT
  #define MENU_DISPLAY  8       //DISPLAY
  #define MENU_ADVANCED 9       //ADVANCED
  #define MENU_ALARMS   10      //ALARMS
  #define MENU_PROFILE  11      //PROFILE+PID CONTROLLER
  #define MENU_DEBUG    12      //DEBUG
  #define MAXPAGE       MENU_DEBUG

  #define CANVAS_SUPPORT
#endif

#if defined CLEANFLIGHT190
  #define AMPERAGE_DIV 10
  #define CORRECT_MSP_CF2
  #define CORRECT_MENU_RCT2
  #define ENABLE_MSP_SAVE_ADVANCED
  #define CORRECTLOOPTIME

  #define MENU_STAT     0       //STATISTICS
  #define MENU_PID      1       //PID CONFIG
  #define MENU_RC       2       //RC TUNING
  #define MENU_RC_2     3       //RC TUNING PAGE 2
  #define MENU_VOLTAGE  4       //VOLTAGE
  #define MENU_RSSI     5       //RSSI
  #define MENU_CURRENT  6       //CURRENT
  #define MENU_DISPLAY  7       //DISPLAY
  #define MENU_ADVANCED 8       //ADVANCED
  #define MENU_ALARMS   9       //ALARMS
  #define MENU_PROFILE  10      //PROFILE+PID CONTROLLER
  #define MENU_DEBUG    11
  #define MAXPAGE       MENU_DEBUG
#endif

#if defined iNAV // same as CLEANFLIGHT190 + CMS
  #define AMPERAGE_DIV 10
  #define CORRECT_MSP_CF2
  #define CORRECT_MENU_RCT2
  #define ENABLE_MSP_SAVE_ADVANCED
  #define CORRECTLOOPTIME
  #define CANVAS_SUPPORT

  #define MENU_STAT     0       //STATISTICS
  #define MENU_PID      1       //PID CONFIG
  #define MENU_RC       2       //RC TUNING
  #define MENU_RC_2     3       //RC TUNING PAGE 2
  #define MENU_INFO     4       //RC TUNING FC
  #define MENU_VOLTAGE  5       //VOLTAGE
  #define MENU_RSSI     6       //RSSI
  #define MENU_CURRENT  7       //CURRENT
  #define MENU_DISPLAY  8       //DISPLAY
  #define MENU_ADVANCED 9       //ADVANCED
  #define MENU_ALARMS   10       //ALARMS
  #define MENU_PROFILE  11      //PROFILE+PID CONTROLLER
  #define MENU_DEBUG    12
  #define MAXPAGE       MENU_DEBUG
#endif

#if defined CLEANFLIGHT180
  #define AMPERAGE_DIV 10
  #define CORRECT_MSP_CF1
  #define CORRECT_MENU_RCT1

  #define MENU_STAT     0       //STATISTICS
  #define MENU_PID      1       //PID CONFIG
  #define MENU_RC       2       //RC TUNING
  #define MENU_VOLTAGE  3       //VOLTAGE
  #define MENU_RSSI     4       //RSSI
  #define MENU_CURRENT  5       //CURRENT
  #define MENU_DISPLAY  6       //DISPLAY
  #define MENU_ADVANCED 7       //ADVANCED
  #define MENU_ALARMS   8       //ALARMS
  #define MENU_DEBUG    9      //DEBUG
  #define MAXPAGE       MENU_DEBUG
#endif

#if defined CLEANFLIGHT172
  #define AMPERAGE_DIV  10
  #define MENU_STAT     0       //STATISTICS
  #define MENU_PID      1       //PID CONFIG
  #define MENU_RC       2       //RC TUNING
  #define MENU_VOLTAGE  3       //VOLTAGE
  #define MENU_RSSI     4       //RSSI
  #define MENU_CURRENT  5       //CURRENT
  #define MENU_DISPLAY  6       //DISPLAY
  #define MENU_ADVANCED 7       //ADVANCED
  #define MENU_ALARMS   8       //ALARMS
  #define MENU_DEBUG    9      //DEBUG
  #define MAXPAGE       MENU_DEBUG
#endif

#if defined FIXEDWING_BF
  #define FIXEDWING
  #define AMPERAGE_DIV 10
  #define CORRECT_MSP_BF1
  #define CORRECT_MENU_RCT1
  #define ENABLE_MSP_SAVE_ADVANCED

  #define MENU_STAT          0       //STATISTICS
  #define MENU_PID           1       //PID CONFIG
  #define MENU_RC            2       //RC TUNING
  #define MENU_FIXEDWING     3       //FIXEDWING adjustments
  #define MENU_VOLTAGE       4       //VOLTAGE
  #define MENU_RSSI          5       //RSSI
  #define MENU_CURRENT       6       //CURRENT
  #define MENU_DISPLAY       7       //DISPLAY
  #define MENU_ADVANCED      8       //ADVANCED
  #define MENU_ALARMS        9       //ALARMS
  #define MENU_PROFILE       10      //PROFILE+PID CONTROLLER
  #define MENU_DEBUG         11      //DEBUG
  #define MAXPAGE       MENU_DEBUG
#endif

#if defined FIXEDWING_BF_SERVO
  #define FIXEDWING
  #define AMPERAGE_DIV 10
  #define CORRECT_MSP_BF1
  #define CORRECT_MENU_RCT1
  #define ENABLE_MSP_SAVE_ADVANCED

  #define MENU_STAT          0       //STATISTICS
  #define MENU_PID           1       //PID CONFIG
  #define MENU_RC            2       //RC TUNING
  #define MENU_SERVO         3       //SERVO
  #define MENU_FIXEDWING     4       //FIXEDWING adjustments
  #define MENU_VOLTAGE       5       //VOLTAGE
  #define MENU_RSSI          6       //RSSI
  #define MENU_CURRENT       7       //CURRENT
  #define MENU_DISPLAY       8       //DISPLAY
  #define MENU_ADVANCED      9       //ADVANCED
  #define MENU_ALARMS        10       //ALARMS
  #define MENU_PROFILE       11      //PROFILE+PID CONTROLLER
  #define MENU_DEBUG         12      //DEBUG
  #define MAXPAGE       MENU_DEBUG
#endif

#if defined BASEFLIGHT20150627
  #define AMPERAGE_DIV 10
  #define CORRECT_MSP_BF1
  #define CORRECT_MENU_RCT1
  #define ENABLE_MSP_SAVE_ADVANCED

  #define MENU_STAT     0       //STATISTICS
  #define MENU_PID      1       //PID CONFIG
  #define MENU_RC       2       //RC TUNING
  #define MENU_VOLTAGE  3       //VOLTAGE
  #define MENU_RSSI     4       //RSSI
  #define MENU_CURRENT  5       //CURRENT
  #define MENU_DISPLAY  6       //DISPLAY
  #define MENU_ADVANCED 7       //ADVANCED
  #define MENU_ALARMS   8       //ALARMS
  #define MENU_PROFILE  9       //PROFILE+PID CONTROLLER
  #define MENU_DEBUG    10      //DEBUG
  #define MAXPAGE       MENU_DEBUG
#endif

#if defined (BASEFLIGHT20150327)
  #define AMPERAGE_DIV  10
  #define MENU_STAT     0       //STATISTICS
  #define MENU_PID      1       //PID CONFIG
  #define MENU_RC       2       //RC TUNING
  #define MENU_VOLTAGE  3       //VOLTAGE
  #define MENU_RSSI     4       //RSSI
  #define MENU_CURRENT  5       //CURRENT
  #define MENU_DISPLAY  6       //DISPLAY
  #define MENU_ADVANCED 7       //ADVANCED
  #define MENU_ALARMS   8       //ALARMS
  #define MENU_DEBUG    9      //DEBUG
  #define MAXPAGE       MENU_DEBUG
#endif

#if defined (RACEFLIGHT)
  #define AMPERAGE_DIV  10
  #define MENU_STAT     0       //STATISTICS
  #define MENU_PID      1       //PID CONFIG
  #define MENU_VOLTAGE  2       //VOLTAGE
  #define MENU_RSSI     3       //RSSI
  #define MENU_CURRENT  4       //CURRENT
  #define MENU_DISPLAY  5       //DISPLAY
  #define MENU_ADVANCED 6       //ADVANCED
  #define MENU_ALARMS   7       //ALARMS
  #define MENU_DEBUG    8      //DEBUG
  #define MAXPAGE       MENU_DEBUG
#endif

#if defined (MULTIWII_V24)
  #define AMPERAGE_DIV  1

  #define MENU_STAT     0       //STATISTICS
  #define MENU_PID      1       //PID CONFIG
  #define MENU_RC       2       //RC TUNING
  #define MENU_VOLTAGE  3       //VOLTAGE
  #define MENU_RSSI     4       //RSSI
  #define MENU_CURRENT  5       //CURRENT
  #define MENU_DISPLAY  6       //DISPLAY
  #define MENU_ADVANCED 7       //ADVANCED
  #define MENU_GPS_TIME 8       //GPS TIME
  #define MENU_ALARMS   9       //ALARMS
  #define MENU_DEBUG    10      //DEBUG
  #define MAXPAGE       MENU_DEBUG
#endif

#if defined (MULTIWII_V23)
  #define MENU_STAT     0       //STATISTICS
  #define MENU_PID      1       //PID CONFIG
  #define MENU_RC       2       //RC TUNING
  #define MENU_VOLTAGE  3       //VOLTAGE
  #define MENU_RSSI     4       //RSSI
  #define MENU_CURRENT  5       //CURRENT
  #define MENU_DISPLAY  6       //DISPLAY
  #define MENU_ADVANCED 7       //ADVANCED
  #define MENU_ALARMS   8       //ALARMS
  #define MENU_DEBUG    9      //DEBUG
  #define MAXPAGE       MENU_DEBUG
#endif

#if defined (MULTIWII_V21)
  #define BOXNAMES              // required to support legacy protocol
  #define MENU_STAT     0       //STATISTICS
  #define MENU_PID      1       //PID CONFIG
  #define MENU_RC       2       //RC TUNING
  #define MENU_VOLTAGE  3       //VOLTAGE
  #define MENU_RSSI     4       //RSSI
  #define MENU_CURRENT  5       //CURRENT
  #define MENU_DISPLAY  6       //DISPLAY
  #define MENU_ADVANCED 7       //ADVANCED
  #define MENU_ALARMS   8       //ALARMS
  #define MENU_DEBUG    9      //DEBUG
  #define MAXPAGE       MENU_DEBUG
#endif

#if defined(TAULABS)
  #define AMPERAGE_DIV  10
  #define HAS_ALARMS
  #define ACROPLUS
  #define MENU_STAT     0       //STATISTICS
  #define MENU_PID      1       //PID CONFIG
  #define MENU_RC       2       //RC TUNING
  #define MENU_VOLTAGE  3       //VOLTAGE
  #define MENU_RSSI     4       //RSSI
  #define MENU_CURRENT  5       //CURRENT
  #define MENU_DISPLAY  6       //DISPLAY
  #define MENU_ADVANCED 7       //ADVANCED
  #define MENU_ALARMS   8       //ALARMS
  #define MENU_DEBUG    9      //DEBUG
  #define MAXPAGE       MENU_DEBUG
#endif

#if defined(APM)
  #define MENU_STAT     0       //STATISTICS
  #define MENU_VOLTAGE  1       //VOLTAGE
  #define MENU_RSSI     2       //RSSI
  #define MENU_CURRENT  3       //CURRENT
  #define MENU_DISPLAY  4       //DISPLAY
  #define MENU_ADVANCED 5       //ADVANCED
  #define MENU_ALARMS   6       //ALARMS
  #define MENU_DEBUG    7      //DEBUG
  #define MAXPAGE       MENU_DEBUG
  #define PROTOCOL_MAVLINK
  #define AMPERAGE_DIV 10
#endif

#if defined(KISS)
  #define MENU_STAT     0       //STATISTICS
  #define MENU_VOLTAGE  1       //VOLTAGE
  #define MENU_RSSI     2       //RSSI
  #define MENU_CURRENT  3       //CURRENT
  #define MENU_DISPLAY  4       //DISPLAY
  #define MENU_ADVANCED 5       //ADVANCED
  #define MENU_ALARMS   6       //ALARMS
  #define MENU_DEBUG    7      //DEBUG
  #define MAXPAGE       MENU_DEBUG
  #define PROTOCOL_KISS
  #define AMPERAGE_DIV 10
#endif

#ifdef SKYTRACK
  #undef  INTRO_MENU
  #undef  ALARM_MSP
  #undef  ALARM_SATS
  #undef  ALARM_GPS
  #undef  OSD_SWITCH_RC
  #define MENU_STAT  0           //STATISTICS
  #define MAXPAGE MENU_STAT
  #define PROTOCOL_SKYTRACK
#endif

#ifdef NOCONTROLLER
  #undef  INTRO_MENU
  #undef  ALARM_MSP
  #undef  ALARM_SATS
  #undef  ALARM_GPS
  #undef  OSD_SWITCH_RC
  #define HIDEARMEDSTATUS
  #define MENU_STAT  0           //STATISTICS
  #define MAXPAGE MENU_STAT
#endif

#if defined GPSOSD_UBLOX
  #define UBLOX
#endif
#if defined GPSOSD_NMEA
  #define NMEA
#endif
#if defined GPSOSD_MTK
  #define MTK
#endif


#if defined MTK_BINARY16
  #define GPSOSD
  #define NMEA
  #define INIT_MTK_GPS
  #define MTK_BINARY16
#endif

#if defined MTK_BINARY19
  #define GPSOSD
  #define NMEA
  #define INIT_MTK_GPS
  #define MTK_BINARY19
#endif

#if defined MTK
  #define GPSOSD
  #define NMEA
  #define INIT_MTK_GPS
#endif

#if defined UBLOX
  #define GPSOSD
#endif

#if defined NMEA
  #define GPSOSD
#endif

#if defined NAZA
  #define GPSOSD
#endif

#if defined GPSOSD
  #undef  INTRO_MENU
  #ifndef NAZA
    #undef  ALARM_MSP
  #endif
  #undef  OSD_SWITCH_RC
  #undef  DISPLAY_PR
  #define NOAHI
  #define NOSUMMARYTHROTTLERESET
  
//  #define HIDEARMEDSTATUS
  #define ALARM_GPS 5

  #define MENU_STAT     0       //STATISTICS
  #define MENU_VOLTAGE  1       //VOLTAGE
  #define MENU_RSSI     2       //RSSI
  #define MENU_CURRENT  3       //CURRENT
  #define MENU_DISPLAY  4       //DISPLAY
  #define MENU_ADVANCED 5       //ADVANCED
  #define MENU_ALARMS   6       //ALARMS
  #define MAXPAGE       MENU_ALARMS
#endif

// Flight Controller Software types to be added before here...

#ifndef MAXPAGE
  #define INFO_CONTROLLER 0
  #define MENU_STAT     0       //STATISTICS
  #define MENU_VOLTAGE  1       //VOLTAGE
  #define MENU_RSSI     2       //RSSI
  #define MENU_CURRENT  3       //CURRENT
  #define MENU_DISPLAY  4       //DISPLAY
  #define MENU_ADVANCED 5       //ADVANCED
  #define MENU_ALARMS   6       //ALARMS
  #define MAXPAGE       MENU_ALARMS
#endif

#define GTMP1 MAXPAGE +1

#ifdef USE_MENU_VTX
  const uint8_t MENU_vtx_tmp = MAXPAGE+1;
  #define MENU_VTX MENU_vtx_tmp
  #undef  MAXPAGE
  #define MAXPAGE MENU_VTX 
#endif

/*
enum {
    EMENU_VTX,
}
*/


#ifdef HAS_ALARMS
  #define MAX_ALARM_LEN 30
#endif

#ifndef AMPERAGE_DIV 
  #define AMPERAGE_DIV 100
#endif

#if defined (FC_VOLTAGE_CONFIG) && (defined (CLEANFLIGHT) || defined(BASEFLIGHT) || defined(BETAFLIGHT))
  #define USE_FC_VOLTS_CONFIG
#endif

/********************  FIXEDWING definitions  *********************/
#ifdef FIXEDWING                     
  #define LONG_RANGE_DISPLAY
  #define USEGPSHEADING
  #define USEGPSALTITUDE
  #if defined USEMAGHEADING 
    #undef USEGPSHEADING
  #endif  
  #if defined USEBAROALTITUDE
    #undef USEGPSALTITUDE
  #endif
  #define FORCESENSORS
  #ifndef USEGLIDESCOPE 
    #define USEGLIDESCOPE
  #endif
#endif

/********************  HARDWARE PINS definitions  *********************/
#define AMPERAGEPIN   A1
#define TEMPPIN       A3  // also used for airspeed         
#define RSSIPIN       A3              
#define LEDPIN        7
#define INTC3       // Arduino A3 enabled for PWM/PPM interrupts)

// All aircraft / FC types defaults...
#define RESETGPSALTITUDEATARM
#define HEADINGCORRECT              // required to correct for MWheading being 0>360 vs MWII -180>+180. Leave permanently enabled

#define cfgck 7
//#define cfgActive EEPROM.write(LINE+onTime,0);

#if defined DISABLEGPSALTITUDERESET
  #undef RESETGPSALTITUDEATARM
#endif


/********************  OSD HARDWARE rule definitions  *********************/
#ifdef RUSHDUINO                    
    # define DATAOUT          11 // MOSI
    # define DATAIN           12 // MISO
    # define SPICLOCK         13 // sck
    # define VSYNC             2 // INT0
    # define MAX7456RESET      9 // RESET
    # define MAX7456SELECT    10 // CHIP SELECT 
    # define MAX7456SETHARDWAREPORTS  pinMode(MAX7456RESET,OUTPUT);pinMode(MAX7456SELECT,OUTPUT);pinMode(DATAOUT, OUTPUT);pinMode(DATAIN, INPUT);pinMode(SPICLOCK,OUTPUT);pinMode(VSYNC, INPUT);
    # define MAX7456HWRESET   digitalWrite(MAX7456RESET,LOW);delay(60);digitalWrite(MAX7456RESET,HIGH);delay(40);
    # define MAX7456ENABLE    digitalWrite(MAX7456SELECT,LOW); 
    # define MAX7456DISABLE   digitalWrite(MAX7456SELECT,HIGH); 
#elif defined ARDUINO_OSD // Example for Arduino guys                     
    # define DATAOUT          11 // MOSI
    # define DATAIN           12 // MISO
    # define SPICLOCK         13 // sck
    # define VSYNC             2 // INT0
    # define MAX7456SELECT     6 // ss
    # define MAX7456RESET     10 // RESET
    # define MAX7456SETHARDWAREPORTS  pinMode(MAX7456RESET,OUTPUT);pinMode(MAX7456SELECT,OUTPUT);pinMode(DATAOUT, OUTPUT);pinMode(DATAIN, INPUT);pinMode(SPICLOCK,OUTPUT);pinMode(VSYNC, INPUT);
    # define MAX7456HWRESET   digitalWrite(MAX7456RESET,LOW);delay(60);digitalWrite(MAX7456RESET,HIGH);delay(40);
    # define MAX7456ENABLE    digitalWrite(MAX7456SELECT,LOW); 
    # define MAX7456DISABLE   digitalWrite(MAX7456SELECT,HIGH); 
#else                                  
    # define MAX7456ENABLE    PORTD&=B10111111; 
    # define MAX7456DISABLE   PORTD|=B01000000; 
    # define MAX7456SETHARDWAREPORTS  DDRB|=B00101100;DDRB&=B11101111;DDRD|=B01000000;DDRD&=B11111011;
    # define MAX7456HWRESET   PORTB&=B11111011;delay(100);PORTB|=B00000100;
#endif

#ifdef AEROMAX
    #define TEMPPIN       A6  // also used for airspeed         
    #define INTD5     
#endif

#ifdef AIRBOTMICRO
    #define MAX_SOFTRESET
    #define SWAPVOLTAGEPINS
#endif

#if defined  AUDIOVARIO // temporary reassign RSSI / Temp to avoid issues
//  #define TEMPPIN       A1  // also used for airspeed         
//  #define RSSIPIN       A1              
#endif

#if defined  KKAUDIOVARIO 
  #undef FIXEDLOOP
//  #define TEMPPIN       A1  // also used for airspeed         
//  #define RSSIPIN       A1              
#endif

#ifdef ANDROMEDA
    #define MAX_SOFTRESET
#endif

#ifdef RTFQV1                     
    #define SWAPVOLTAGEPINS
    #define ALTERNATEDIVIDERS
#endif

#ifdef RTFQMICRO                     
    #define SWAPVOLTAGEPINS
#endif

#ifdef KYLIN250PDB
    #undef VOLTAGEPIN
    #define VOLTAGEPIN    A6
#endif

#ifdef HOLYBROPDB
    #undef VOLTAGEPIN
    #define VOLTAGEPIN    A6
#endif

#ifdef SWAPVOLTAGEPINS                     
    #define VOLTAGEPIN    A2
    #define VIDVOLTAGEPIN A0
#else                                  
    #define VOLTAGEPIN    A0
    #define VIDVOLTAGEPIN A2
#endif

#ifdef ALTERNATEDIVIDERS
    #define DIVIDER1v1      0.0002      // Voltage divider for 1.1v reference.
    #define DIVIDER5v       0.0008      // Voltage divider for 5v reference.
#else
    #define DIVIDER1v1      0.0001      // Voltage divider for 1.1v reference. Use 0.0001 default unless advised otherwise.
    #define DIVIDER5v       0.0005      // Voltage divider for 5v reference. Use 0.0005 default unless advised otherwise.
#endif

#ifdef I2C_UB_SUPPORT
    #define I2C_UB_ADDR      0x19
  //#define I2C_UB_IRQPIN    3
    #define I2C_UB_BREQUIV   115200UL   // Pretend baudrate of 115200
    #define MSP2CFG                     // Duplicate MSP request to config port
#endif

/********************  GPS OSD rule definitions  *********************/

#if defined PPM_CONTROL
  #undef OSD_SWITCH
  #undef PWM_OSD_SWITCH
  #define OSD_SWITCH_RC               // Enables 3 way screen switch using a TX channel via FC. Specify channel on GUI (range 0-7 AUX1=4 AUX4=7)
#endif

#if defined (PWM_OSD_SWITCH)
  #define OSD_SWITCH_RC
#endif


/********************  PROTOCOL rule definitions  *********************/
#define PROTOCOL_MSP // on by default

#ifdef GPSOSD
#undef  PROTOCOL_MSP
#define FORCESENSORS
#endif

#ifdef  NAZA
#undef  PROTOCOL_MSP
#define FORCESENSORS
#endif

#ifdef PROTOCOL_MAVLINK
#undef  PROTOCOL_MSP
#define FORCESENSORS
#define NOSUMMARYTHROTTLERESET
#endif

#ifdef PROTOCOL_LTM
#undef  PROTOCOL_MSP
#define FORCESENSORS
#endif

#ifdef PROTOCOL_KISS
#undef  PROTOCOL_MSP
#define FORECSENSORACC
#endif

#ifdef FORCE_MSP
#define PROTOCOL_MSP
#endif


/********************  MSP speed enhancements rule definitions  *********************/

#if defined MSP_SPEED_HIGH
  #define hi_speed_cycle  10  // updates everything approx 6.3 times per second, updates attitude 30 times per second
#elif defined MSP_SPEED_MED
  #define hi_speed_cycle  50  // same as low, but also updates attitude 10 times per second
#else
  #define hi_speed_cycle  50  // updates everything approx 1.3 times per second
#endif


/********************  RX channel rule definitions  *********************/

#if defined TX_GS            //PITCH,YAW,THROTTLE,ROLL,AUX1,AUX2,AUX3,AUX4 //For Graupner/Spektrum    
  #define ROLLSTICK        4
  #define PITCHSTICK       1
  #define YAWSTICK         2
  #define THROTTLESTICK    3
#elif defined TX_RHF         //ROLL,PITCH,THROTTLE,YAW,AUX1,AUX2,AUX3,AUX4 //For Robe/Hitec/Futaba
  #define ROLLSTICK        1
  #define PITCHSTICK       2
  #define YAWSTICK         4
  #define THROTTLESTICK    3
#elif defined TX_M           //ROLL,PITCH,YAW,THROTTLE,AUX1,AUX2,AUX3,AUX4 //For Multiplex
  #define ROLLSTICK        1
  #define PITCHSTICK       2
  #define YAWSTICK         3
  #define THROTTLESTICK    4
#elif defined TX_HS          //PITCH,ROLL,THROTTLE,YAW,AUX1,AUX2,AUX3,AUX4 //For some Hitec/Sanwa/Others
  #define ROLLSTICK        2
  #define PITCHSTICK       1
  #define YAWSTICK         4
  #define THROTTLESTICK    3
#elif defined KISS
  #define ROLLSTICK        2
  #define PITCHSTICK       3
  #define YAWSTICK         4
  #define THROTTLESTICK    1
#elif defined PX4            //ROLL,PITCH,THROTTLE,YAW,AUX1,AUX2,AUX3,AUX4 //For PX4
  #define ROLLSTICK        1
  #define PITCHSTICK       2
  #define YAWSTICK         4
  #define THROTTLESTICK    3
#elif defined APM            //ROLL,PITCH,THROTTLE,YAW,AUX1,AUX2,AUX3,AUX4 //For APM
  #define ROLLSTICK        1
  #define PITCHSTICK       2
  #define YAWSTICK         4
  #define THROTTLESTICK    3
#else
  // RX CHANEL IN MwRcData table
  #define ROLLSTICK        1
  #define PITCHSTICK       2
  #define YAWSTICK         3
  #define THROTTLESTICK    4
#endif

#ifndef TX_CHANNELS
  #define TX_CHANNELS 8 
#endif

/********************  other paramters  *********************/

#ifdef PIODEBUG // This is for travis build only
  #define DEBUG 4 // Display debug secreen at boot
#endif

#ifdef PIOAUDIOVARIO // This is for travis build only
  #define AUDIOVARIO A3 // Enable AUDIOVARIO on RSSI
#endif

#ifdef PWM_THROTTLE
  #define ALWAYSARMED  // starts OSD in armed mode
#endif

#ifdef MAV_ARMED
  #define ALWAYSARMED  // starts OSD in armed mode
#endif

#ifndef BAUDRATE 
  #ifdef PROTOCOL_MAVLINK 
    #define BAUDRATE 57600
  #else
    #define BAUDRATE 115200
  #endif // PROTOCOL_MAVLINK
#endif // BAUDRATE


/********************  BOXID compatibility  *********************/

#ifdef iNAV
  #define IDBOXAIR 29
  #define IDBOXWP 28
#else
  #define IDBOXAIR 28
  #define IDBOXWP 20
#endif

#ifdef MULTIWII
  #ifdef INFO_CONTROLLER
   #undef INFO_CONTROLLER
  #endif;  
  #undef  INTRO_MENU
  #define INFO_CONTROLLER 1
#endif
#ifdef BASEFLIGHT
  #define INFO_CONTROLLER 2
#endif
#ifdef TAULABS
  #define INFO_CONTROLLER 4
#endif
#ifdef LIBREPILOT
  #ifdef INFO_CONTROLLER
   #undef INFO_CONTROLLER
  #endif;  
  #define INFO_CONTROLLER 3
#endif
#ifdef DRONIN
  #ifdef INFO_CONTROLLER
   #undef INFO_CONTROLLER
  #endif;  
  #define INFO_CONTROLLER 5
#endif
#ifdef CLEANFLIGHT
  #define INFO_CONTROLLER 6
#endif
#ifdef BETAFLIGHT
  #define INFO_CONTROLLER 7
#endif
#ifdef FIXEDWING_BF
  #define INFO_CONTROLLER 8
#endif
#ifdef FIXEDWING_BF_SERVO
  #define INFO_CONTROLLER 9
#endif
#ifdef HARAKIRI
  #define INFO_CONTROLLER 10
#endif
#ifdef NAZA
  #define INFO_CONTROLLER 11
#endif
#ifdef iNAV
  #define INFO_CONTROLLER 12
#endif
#ifdef KISS
  #define INFO_CONTROLLER 13
#endif
#ifdef APM
  #ifdef INFO_CONTROLLER
   #undef INFO_CONTROLLER
  #endif;  
  #define INFO_CONTROLLER 14
#endif
#ifdef PX4
  #ifdef INFO_CONTROLLER
   #undef INFO_CONTROLLER
  #endif;  
  #define INFO_CONTROLLER 15
#endif
#ifdef SKYTRACK
  #define INFO_CONTROLLER 16
#endif
#ifdef GPSOSD_UBLOX
  #ifdef INFO_CONTROLLER
   #undef INFO_CONTROLLER
  #endif;  
  #define INFO_CONTROLLER 17
#endif
#ifdef GPSOSD_NMEA
  #ifdef INFO_CONTROLLER
   #undef INFO_CONTROLLER
  #endif;  
  #define INFO_CONTROLLER 18
#endif
#ifdef GPSOSD_NMEA
  #ifdef INFO_CONTROLLER
   #undef INFO_CONTROLLER
  #endif;  
  #define INFO_CONTROLLER 19
#endif
#ifdef NOCONTROLLER
  #define INFO_CONTROLLER 20
#endif
#ifdef RACEFLIGHT
  #define INFO_CONTROLLER 21
#endif


#ifdef MINIMOSD
  #define INFO_HARDWARE 1
#endif
#ifdef MICROMINIMOSD
  #define INFO_HARDWARE 2
#endif
#ifdef AEROMAX
  #define INFO_HARDWARE 3
#endif
#ifdef RTFQV1
  #define INFO_HARDWARE 4
#endif
#ifdef RTFQMICRO
  #define INFO_HARDWARE 5
#endif
#ifdef RUSHDUINO
  #define INFO_HARDWARE 6
#endif
#ifdef KYLIN250PDB
  #define INFO_HARDWARE 7
#endif
#ifdef AIRBOTMICRO
  #define INFO_HARDWARE 8
#endif
#ifdef ANDROMEDA
  #define INFO_HARDWARE 9
#endif
#ifdef ANDROMEDA
  #define HOLYBROPDB 10
#endif


#ifdef ROTORCRAFT
  #define INFO_AIRCRAFT 1
#endif
#ifdef FIXEDWING
  #define INFO_AIRCRAFT 2
#endif


/********************  info for GUI  *********************/
#ifndef INFO_CONTROLLER
  #define INFO_CONTROLLER          0            // default - unknown 
#endif

#ifndef INFO_VERSION
  #define INFO_VERSION             MWOSDVERSION // version specified 
#endif

#ifndef INFO_VENDOR
  #define INFO_VENDOR              VENDOR       // vendor specific reference 
#endif

#ifndef INFO_HARDWARE
  #define INFO_HARDWARE            0            // default - unknown 
#endif

#ifndef INFO_AIRCRAFT
  #define INFO_AIRCRAFT            0            // default - unknown 
#endif

#ifndef INFO_OPTIONS1
  #define INFO_OPTIONS1            0            // default - unknown 
#endif



