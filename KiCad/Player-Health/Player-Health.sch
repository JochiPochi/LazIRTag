EESchema Schematic File Version 2
LIBS:LazIRTag
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:Player-Health-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "24 apr 2015"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 14SLED U3
U 1 1 55011520
P 6700 3850
F 0 "U3" H 6700 3350 60  0000 C CNN
F 1 "14SLED" H 6700 3500 60  0000 C CNN
F 2 "" H 6700 3850 60  0000 C CNN
F 3 "" H 6700 3850 60  0000 C CNN
	1    6700 3850
	0    1    1    0   
$EndComp
$Comp
L ATMEGA328-P IC1
U 1 1 550115B1
P 2200 6250
F 0 "IC1" H 1450 7500 40  0000 L BNN
F 1 "ATMEGA328-P" H 2600 4850 40  0000 L BNN
F 2 "DIL28" H 2200 6250 30  0000 C CIN
F 3 "" H 2200 6250 60  0000 C CNN
	1    2200 6250
	1    0    0    -1  
$EndComp
$Comp
L CRYSTAL X1
U 1 1 550115DF
P 4500 6050
F 0 "X1" H 4500 6150 60  0000 C CNN
F 1 "CRYSTAL" H 4500 5900 60  0000 C CNN
F 2 "~" H 4500 6050 60  0000 C CNN
F 3 "~" H 4500 6050 60  0000 C CNN
	1    4500 6050
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 550115EE
P 4200 6250
F 0 "C5" H 4200 6350 40  0000 L CNN
F 1 "22pF" H 4206 6165 40  0000 L CNN
F 2 "~" H 4238 6100 30  0000 C CNN
F 3 "~" H 4200 6250 60  0000 C CNN
	1    4200 6250
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 55011607
P 4800 6250
F 0 "C6" H 4800 6350 40  0000 L CNN
F 1 "22pF" H 4806 6165 40  0000 L CNN
F 2 "~" H 4838 6100 30  0000 C CNN
F 3 "~" H 4800 6250 60  0000 C CNN
	1    4800 6250
	1    0    0    -1  
$EndComp
$Comp
L LM1084IT-3.3/NOPB U2
U 1 1 5501240B
P 3300 3350
F 0 "U2" H 3500 3150 40  0000 C CNN
F 1 "LM1084IT-3.3/NOPB" H 3000 3550 40  0000 L CNN
F 2 "TO-220" H 3300 3450 30  0000 C CIN
F 3 "~" H 3300 3350 60  0000 C CNN
	1    3300 3350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR4
U 1 1 5501101E
P 1850 2050
F 0 "#PWR4" H 1850 2050 30  0001 C CNN
F 1 "GND" H 1850 1980 30  0001 C CNN
F 2 "" H 1850 2050 60  0000 C CNN
F 3 "" H 1850 2050 60  0000 C CNN
	1    1850 2050
	1    0    0    -1  
$EndComp
$Comp
L 2P_CGRID_M P1
U 1 1 55011546
P 3250 1050
F 0 "P1" H 3250 1350 60  0000 C CNN
F 1 "2P_CGRID_M" V 3250 1100 39  0000 C CNN
F 2 "" H 3250 1050 60  0000 C CNN
F 3 "" H 3250 1050 60  0000 C CNN
	1    3250 1050
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR9
U 1 1 55011447
P 3950 2300
F 0 "#PWR9" H 3950 2300 30  0001 C CNN
F 1 "GND" H 3950 2230 30  0001 C CNN
F 2 "" H 3950 2300 60  0000 C CNN
F 3 "" H 3950 2300 60  0000 C CNN
	1    3950 2300
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 55011420
P 3950 2000
F 0 "C4" H 3950 2100 40  0000 L CNN
F 1 "4.7uF" H 3956 1915 40  0000 L CNN
F 2 "~" H 3988 1850 30  0000 C CNN
F 3 "~" H 3950 2000 60  0000 C CNN
	1    3950 2000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR7
U 1 1 550112D9
P 3700 2300
F 0 "#PWR7" H 3700 2300 30  0001 C CNN
F 1 "GND" H 3700 2230 30  0001 C CNN
F 2 "" H 3700 2300 60  0000 C CNN
F 3 "" H 3700 2300 60  0000 C CNN
	1    3700 2300
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 550112AC
P 3700 1950
F 0 "R4" V 3780 1950 40  0000 C CNN
F 1 "2k" V 3707 1951 40  0000 C CNN
F 2 "~" V 3630 1950 30  0000 C CNN
F 3 "~" H 3700 1950 30  0000 C CNN
	1    3700 1950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR6
U 1 1 5501126E
P 3550 1800
F 0 "#PWR6" H 3550 1800 30  0001 C CNN
F 1 "GND" H 3550 1730 30  0001 C CNN
F 2 "" H 3550 1800 60  0000 C CNN
F 3 "" H 3550 1800 60  0000 C CNN
	1    3550 1800
	1    0    0    -1  
$EndComp
$Comp
L LED D2
U 1 1 550110A7
P 2350 1850
F 0 "D2" H 2350 1950 50  0000 C CNN
F 1 "RED" H 2350 1750 50  0000 C CNN
F 2 "~" H 2350 1850 60  0000 C CNN
F 3 "~" H 2350 1850 60  0000 C CNN
	1    2350 1850
	0    -1   -1   0   
$EndComp
$Comp
L R R1
U 1 1 55011089
P 2150 1800
F 0 "R1" V 2150 1700 40  0000 C CNN
F 1 "330" V 2150 1850 40  0000 C CNN
F 2 "~" V 2080 1800 30  0000 C CNN
F 3 "~" H 2150 1800 30  0000 C CNN
	1    2150 1800
	1    0    0    -1  
$EndComp
$Comp
L MCP73831 U1
U 1 1 55011069
P 2950 1600
F 0 "U1" H 2950 1800 60  0000 C CNN
F 1 "MCP73831" H 2950 1400 60  0000 C CNN
F 2 "" H 2950 1600 60  0000 C CNN
F 3 "" H 2950 1600 60  0000 C CNN
	1    2950 1600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR3
U 1 1 55011060
P 1650 1800
F 0 "#PWR3" H 1650 1800 30  0001 C CNN
F 1 "GND" H 1650 1730 30  0001 C CNN
F 2 "" H 1650 1800 60  0000 C CNN
F 3 "" H 1650 1800 60  0000 C CNN
	1    1650 1800
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 55011038
P 1850 1750
F 0 "C2" H 1850 1850 40  0000 L CNN
F 1 "4.7uF" H 1856 1665 40  0000 L CNN
F 2 "~" H 1888 1600 30  0000 C CNN
F 3 "~" H 1850 1750 60  0000 C CNN
	1    1850 1750
	1    0    0    -1  
$EndComp
$Comp
L MICRO_USB J1
U 1 1 5501100F
P 1000 1450
F 0 "J1" H 1000 1900 60  0000 C CNN
F 1 "MICRO_USB" V 900 1450 60  0000 C CNN
F 2 "" H 1000 1450 60  0000 C CNN
F 3 "" H 1000 1450 60  0000 C CNN
	1    1000 1450
	1    0    0    -1  
$EndComp
Text GLabel 2000 1350 1    60   Output ~ 0
USBV
$Comp
L SLIDESWITCH S1
U 1 1 55280BDF
P 4500 1250
F 0 "S1" H 4650 1150 60  0000 C CNN
F 1 "SLIDESWITCH" H 4650 1300 60  0000 C CNN
F 2 "~" H 4500 1250 60  0000 C CNN
F 3 "~" H 4500 1250 60  0000 C CNN
	1    4500 1250
	0    1    1    0   
$EndComp
$Comp
L GND #PWR8
U 1 1 55280CC3
P 3800 1150
F 0 "#PWR8" H 3800 1150 30  0001 C CNN
F 1 "GND" H 3800 1080 30  0001 C CNN
F 2 "" H 3800 1150 60  0000 C CNN
F 3 "" H 3800 1150 60  0000 C CNN
	1    3800 1150
	0    -1   -1   0   
$EndComp
Text GLabel 3750 1350 0    60   Output ~ 0
VBatt
Text Notes 650  700  0    118  ~ 0
USB LiPo Charger
$Comp
L R R2
U 1 1 55280D5E
P 2750 3650
F 0 "R2" V 2830 3650 40  0000 C CNN
F 1 "10k" V 2757 3651 40  0000 C CNN
F 2 "~" V 2680 3650 30  0000 C CNN
F 3 "~" H 2750 3650 30  0000 C CNN
	1    2750 3650
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 55280D64
P 3050 4000
F 0 "R3" V 3130 4000 40  0000 C CNN
F 1 "10k" V 3057 4001 40  0000 C CNN
F 2 "~" V 2980 4000 30  0000 C CNN
F 3 "~" H 3050 4000 30  0000 C CNN
	1    3050 4000
	0    -1   -1   0   
$EndComp
$Comp
L C C3
U 1 1 55280D6C
P 3700 3700
F 0 "C3" H 3700 3800 40  0000 L CNN
F 1 "100uF" H 3706 3615 40  0000 L CNN
F 2 "~" H 3738 3550 30  0000 C CNN
F 3 "~" H 3700 3700 60  0000 C CNN
	1    3700 3700
	1    0    0    -1  
$EndComp
Text GLabel 2000 3300 0    60   Input ~ 0
VBatt
Text GLabel 2750 4050 3    60   Output ~ 0
VSense
$Comp
L +3.3V #PWR11
U 1 1 55280D8C
P 4250 3300
F 0 "#PWR11" H 4250 3260 30  0001 C CNN
F 1 "+3.3V" H 4250 3410 30  0000 C CNN
F 2 "" H 4250 3300 60  0000 C CNN
F 3 "" H 4250 3300 60  0000 C CNN
	1    4250 3300
	0    1    1    0   
$EndComp
$Comp
L GND #PWR5
U 1 1 55280D9B
P 3300 4150
F 0 "#PWR5" H 3300 4150 30  0001 C CNN
F 1 "GND" H 3300 4080 30  0001 C CNN
F 2 "" H 3300 4150 60  0000 C CNN
F 3 "" H 3300 4150 60  0000 C CNN
	1    3300 4150
	1    0    0    -1  
$EndComp
Text Notes 4750 2400 0    59   ~ 0
-VBatt Source\n-USBV Source\n-Power Switch
Text Notes 650  2950 0    118  ~ 0
3.3 V Regulator
Text Notes 4750 4300 0    59   ~ 0
-3.3V Source\n-Voltage Sense\n-Status LEDs
Text GLabel 7650 3550 2    60   Input ~ 0
VBatt
$Comp
L GND #PWR13
U 1 1 55281188
P 7650 3850
F 0 "#PWR13" H 7650 3850 30  0001 C CNN
F 1 "GND" H 7650 3780 30  0001 C CNN
F 2 "" H 7650 3850 60  0000 C CNN
F 3 "" H 7650 3850 60  0000 C CNN
	1    7650 3850
	0    -1   -1   0   
$EndComp
Text GLabel 7650 4000 2    59   Input ~ 0
I2C DAT
Text GLabel 7650 4150 2    59   Input ~ 0
I2C CLK
Text Notes 7650 2800 2    118  ~ 0
AlphaNumeric Display
$Comp
L LED D3
U 1 1 552812BB
P 4050 3500
F 0 "D3" H 4050 3600 50  0000 C CNN
F 1 "LED" H 4050 3400 50  0000 C CNN
F 2 "~" H 4050 3500 60  0000 C CNN
F 3 "~" H 4050 3500 60  0000 C CNN
	1    4050 3500
	0    1    1    0   
$EndComp
Text GLabel 3650 6500 2    59   Output ~ 0
I2C CLK
Text GLabel 3250 6400 2    59   Output ~ 0
I2C DAT
$Comp
L +3.3V #PWR1
U 1 1 552816BB
P 1250 5150
F 0 "#PWR1" H 1250 5110 30  0001 C CNN
F 1 "+3.3V" H 1250 5260 30  0000 C CNN
F 2 "" H 1250 5150 60  0000 C CNN
F 3 "" H 1250 5150 60  0000 C CNN
	1    1250 5150
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 5528173B
P 1250 6250
F 0 "C1" H 1250 6350 40  0000 L CNN
F 1 "0.1uF" H 1256 6165 40  0000 L CNN
F 2 "~" H 1288 6100 30  0000 C CNN
F 3 "~" H 1250 6250 60  0000 C CNN
	1    1250 6250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR2
U 1 1 55281865
P 1250 7500
F 0 "#PWR2" H 1250 7500 30  0001 C CNN
F 1 "GND" H 1250 7430 30  0001 C CNN
F 2 "" H 1250 7500 60  0000 C CNN
F 3 "" H 1250 7500 60  0000 C CNN
	1    1250 7500
	1    0    0    -1  
$EndComp
Text GLabel 3250 5250 2    59   Output ~ 0
LED B
Text GLabel 3600 5350 2    59   Output ~ 0
LED R
Text GLabel 3550 5150 2    59   Input ~ 0
IR Sense
Text GLabel 3250 7350 2    59   Output ~ 0
LED G
Text GLabel 3250 6600 2    59   Input ~ 0
Reset
$Comp
L GND #PWR12
U 1 1 55281D1D
P 4500 6500
F 0 "#PWR12" H 4500 6500 30  0001 C CNN
F 1 "GND" H 4500 6430 30  0001 C CNN
F 2 "" H 4500 6500 60  0000 C CNN
F 3 "" H 4500 6500 60  0000 C CNN
	1    4500 6500
	1    0    0    -1  
$EndComp
Text GLabel 3250 5650 2    59   Output ~ 0
SCK
Text GLabel 3250 5450 2    59   Output ~ 0
MOSI
Text GLabel 3500 5550 2    59   Input ~ 0
MISO
Text GLabel 3800 6950 2    59   Output ~ 0
UART TX
Text GLabel 7800 6700 2    59   Output ~ 0
UART RX
Text Notes 2000 4800 2    118  ~ 0
MicroController
Text GLabel 3600 7250 2    59   Output ~ 0
Rumble
$Comp
L ESP8266 U4
U 1 1 55282516
P 6900 6350
F 0 "U4" H 6900 6800 60  0000 C CNN
F 1 "ESP8266" H 6450 6650 60  0000 C CNN
F 2 "~" H 6900 6350 60  0000 C CNN
F 3 "~" H 6900 6350 60  0000 C CNN
	1    6900 6350
	1    0    0    -1  
$EndComp
Text GLabel 7800 6000 2    59   Input ~ 0
UART TX
$Comp
L GND #PWR17
U 1 1 552825A2
P 7950 6500
F 0 "#PWR17" H 7950 6500 30  0001 C CNN
F 1 "GND" H 7950 6430 30  0001 C CNN
F 2 "" H 7950 6500 60  0000 C CNN
F 3 "" H 7950 6500 60  0000 C CNN
	1    7950 6500
	-1   0    0    1   
$EndComp
$Comp
L +3.3V #PWR15
U 1 1 552825B1
P 7650 6500
F 0 "#PWR15" H 7650 6460 30  0001 C CNN
F 1 "+3.3V" H 7650 6610 30  0000 C CNN
F 2 "" H 7650 6500 60  0000 C CNN
F 3 "" H 7650 6500 60  0000 C CNN
	1    7650 6500
	0    1    1    0   
$EndComp
$Comp
L +3.3V #PWR14
U 1 1 55282851
P 7650 6100
F 0 "#PWR14" H 7650 6060 30  0001 C CNN
F 1 "+3.3V" H 7650 6210 30  0000 C CNN
F 2 "" H 7650 6100 60  0000 C CNN
F 3 "" H 7650 6100 60  0000 C CNN
	1    7650 6100
	0    1    1    0   
$EndComp
Text Notes 5700 5300 0    118  ~ 0
Wireless Device
$Comp
L CONN_6 P3
U 1 1 55282A0B
P 9450 4050
F 0 "P3" V 9400 4050 60  0000 C CNN
F 1 "6pM Header" V 9500 4050 60  0000 C CNN
F 2 "" H 9450 4050 60  0000 C CNN
F 3 "" H 9450 4050 60  0000 C CNN
	1    9450 4050
	-1   0    0    1   
$EndComp
Text GLabel 9800 3900 2    59   Input ~ 0
UART TX
Text GLabel 10250 4000 2    59   Output ~ 0
UART RX
Text GLabel 9800 4100 2    60   Input ~ 0
USBV
Text GLabel 3200 6000 2    60   Input ~ 0
VSense
Text GLabel 3250 6750 2    59   Input ~ 0
UART RX
$Comp
L CONN_6 P2
U 1 1 55282A50
P 9400 1600
F 0 "P2" V 9350 1600 60  0000 C CNN
F 1 "6pM CGrid" V 9450 1600 60  0000 C CNN
F 2 "" H 9400 1600 60  0000 C CNN
F 3 "" H 9400 1600 60  0000 C CNN
	1    9400 1600
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR21
U 1 1 55282A83
P 9750 1850
F 0 "#PWR21" H 9750 1850 30  0001 C CNN
F 1 "GND" H 9750 1780 30  0001 C CNN
F 2 "" H 9750 1850 60  0000 C CNN
F 3 "" H 9750 1850 60  0000 C CNN
	1    9750 1850
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR20
U 1 1 55282A89
P 9750 1750
F 0 "#PWR20" H 9750 1710 30  0001 C CNN
F 1 "+3.3V" H 9750 1860 30  0000 C CNN
F 2 "" H 9750 1750 60  0000 C CNN
F 3 "" H 9750 1750 60  0000 C CNN
	1    9750 1750
	0    1    1    0   
$EndComp
Text GLabel 10100 1650 2    59   BiDi ~ 0
IR Sense
Text GLabel 10100 1450 2    59   BiDi ~ 0
LED B
Text GLabel 9750 1350 2    59   BiDi ~ 0
LED R
Text GLabel 9750 1550 2    59   BiDi ~ 0
LED G
Text Notes 8800 700  0    118  ~ 0
Connector to IR\nApparel Sensors
Text Notes 10400 2800 2    118  ~ 0
Programming Port
Text Notes 9900 5300 2    118  ~ 0
RFID Reader
Text GLabel 9900 6500 2    59   BiDi ~ 0
SCK
Text GLabel 10200 6400 2    59   BiDi ~ 0
MISO
Text GLabel 9900 6300 2    59   BiDi ~ 0
MOSI
$Comp
L GND #PWR24
U 1 1 55282C20
P 10200 6100
F 0 "#PWR24" H 10200 6100 30  0001 C CNN
F 1 "GND" H 10200 6030 30  0001 C CNN
F 2 "" H 10200 6100 60  0000 C CNN
F 3 "" H 10200 6100 60  0000 C CNN
	1    10200 6100
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR23
U 1 1 55282C26
P 10200 5900
F 0 "#PWR23" H 10200 5860 30  0001 C CNN
F 1 "+3.3V" H 10200 6010 30  0000 C CNN
F 2 "" H 10200 5900 60  0000 C CNN
F 3 "" H 10200 5900 60  0000 C CNN
	1    10200 5900
	0    1    1    0   
$EndComp
$Comp
L CONN_8 P4
U 1 1 55282C35
P 9550 6250
F 0 "P4" V 9500 6250 60  0000 C CNN
F 1 "8pF Header" V 9600 6250 60  0000 C CNN
F 2 "" H 9550 6250 60  0000 C CNN
F 3 "" H 9550 6250 60  0000 C CNN
	1    9550 6250
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR22
U 1 1 55282D84
P 10100 4300
F 0 "#PWR22" H 10100 4300 30  0001 C CNN
F 1 "GND" H 10100 4230 30  0001 C CNN
F 2 "" H 10100 4300 60  0000 C CNN
F 3 "" H 10100 4300 60  0000 C CNN
	1    10100 4300
	0    -1   -1   0   
$EndComp
Text GLabel 9600 3400 0    59   Output ~ 0
Reset
$Comp
L C C7
U 1 1 55282E4B
P 9900 3600
F 0 "C7" H 9900 3700 40  0000 L CNN
F 1 "0.1uF" H 9906 3515 40  0000 L CNN
F 2 "~" H 9938 3450 30  0000 C CNN
F 3 "~" H 9900 3600 60  0000 C CNN
	1    9900 3600
	-1   0    0    1   
$EndComp
$Comp
L R R7
U 1 1 55282E5A
P 10250 3400
F 0 "R7" V 10330 3400 40  0000 C CNN
F 1 "10k" V 10257 3401 40  0000 C CNN
F 2 "~" V 10180 3400 30  0000 C CNN
F 3 "~" H 10250 3400 30  0000 C CNN
	1    10250 3400
	0    1    1    0   
$EndComp
$Comp
L +3.3V #PWR25
U 1 1 55282FA8
P 10600 3400
F 0 "#PWR25" H 10600 3360 30  0001 C CNN
F 1 "+3.3V" H 10600 3510 30  0000 C CNN
F 2 "" H 10600 3400 60  0000 C CNN
F 3 "" H 10600 3400 60  0000 C CNN
	1    10600 3400
	0    1    1    0   
$EndComp
Text GLabel 6350 1200 0    59   Input ~ 0
Rumble
$Comp
L GND #PWR18
U 1 1 55283776
P 8050 2000
F 0 "#PWR18" H 8050 2000 30  0001 C CNN
F 1 "GND" H 8050 1930 30  0001 C CNN
F 2 "" H 8050 2000 60  0000 C CNN
F 3 "" H 8050 2000 60  0000 C CNN
	1    8050 2000
	0    -1   -1   0   
$EndComp
Text GLabel 7150 1450 2    60   Input ~ 0
VBatt
$Comp
L NPN Q1
U 1 1 5528377F
P 6900 1800
F 0 "Q1" H 6900 1650 50  0000 R CNN
F 1 "NPN" H 6900 1950 50  0000 R CNN
F 2 "~" H 6900 1800 60  0000 C CNN
F 3 "~" H 6900 1800 60  0000 C CNN
	1    6900 1800
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 5528378E
P 6500 1500
F 0 "R5" V 6580 1500 40  0000 C CNN
F 1 "560" V 6507 1501 40  0000 C CNN
F 2 "~" V 6430 1500 30  0000 C CNN
F 3 "~" H 6500 1500 30  0000 C CNN
	1    6500 1500
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 5528379B
P 6850 1200
F 0 "R6" V 6930 1200 40  0000 C CNN
F 1 "1k" V 6857 1201 40  0000 C CNN
F 2 "~" V 6780 1200 30  0000 C CNN
F 3 "~" H 6850 1200 30  0000 C CNN
	1    6850 1200
	0    -1   -1   0   
$EndComp
$Comp
L LED D4
U 1 1 552837A7
P 7450 1200
F 0 "D4" H 7450 1300 50  0000 C CNN
F 1 "LED" H 7450 1100 50  0000 C CNN
F 2 "~" H 7450 1200 60  0000 C CNN
F 3 "~" H 7450 1200 60  0000 C CNN
	1    7450 1200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR16
U 1 1 552837AD
P 7800 1200
F 0 "#PWR16" H 7800 1200 30  0001 C CNN
F 1 "GND" H 7800 1130 30  0001 C CNN
F 2 "" H 7800 1200 60  0000 C CNN
F 3 "" H 7800 1200 60  0000 C CNN
	1    7800 1200
	0    -1   -1   0   
$EndComp
Text Notes 6900 750  2    118  ~ 0
Rumble Motor
$Comp
L RUMBLE M1
U 1 1 55283EDD
P 7850 2000
F 0 "M1" H 7850 1850 60  0000 C CNN
F 1 "RUMBLE" H 7850 2150 60  0000 C CNN
F 2 "" H 7850 2000 60  0000 C CNN
F 3 "" H 7850 2000 60  0000 C CNN
	1    7850 2000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR19
U 1 1 5530A16F
P 8350 6200
F 0 "#PWR19" H 8350 6200 30  0001 C CNN
F 1 "GND" H 8350 6130 30  0001 C CNN
F 2 "" H 8350 6200 60  0000 C CNN
F 3 "" H 8350 6200 60  0000 C CNN
	1    8350 6200
	0    -1   -1   0   
$EndComp
$Comp
L JUMPER JP2
U 1 1 5530A41F
P 8050 6200
F 0 "JP2" H 8050 6100 60  0000 C CNN
F 1 "JUMPER" H 8050 6300 60  0000 C CNN
F 2 "" H 8050 6200 60  0000 C CNN
F 3 "" H 8050 6200 60  0000 C CNN
	1    8050 6200
	1    0    0    -1  
$EndComp
Connection ~ 2150 1550
Wire Wire Line
	1550 1700 1650 1700
Wire Wire Line
	1650 1700 1650 1800
Wire Wire Line
	1850 1950 1850 2050
Connection ~ 1850 1550
Wire Wire Line
	2000 1550 2000 1350
Connection ~ 2000 1550
Wire Wire Line
	1550 1550 2350 1550
Wire Wire Line
	2150 2050 2350 2050
Wire Wire Line
	3550 1700 3550 1800
Wire Wire Line
	3550 1600 3700 1600
Wire Wire Line
	3700 1600 3700 1700
Wire Wire Line
	3700 2200 3700 2300
Wire Wire Line
	3950 2200 3950 2300
Wire Wire Line
	3700 1150 3800 1150
Wire Wire Line
	3950 1250 3950 1800
Wire Wire Line
	3950 1500 3550 1500
Wire Wire Line
	3700 950  3950 950 
Connection ~ 3950 1500
Wire Wire Line
	3950 1350 3750 1350
Connection ~ 3950 1350
Wire Notes Line
	500  2700 5600 2700
Wire Notes Line
	5600 500  5600 7800
Wire Wire Line
	2000 3300 2900 3300
Wire Wire Line
	2750 3400 2750 3300
Connection ~ 2750 3300
Wire Wire Line
	2750 3900 2750 4050
Connection ~ 2750 4000
Wire Wire Line
	3300 3600 3300 4150
Connection ~ 3300 4000
Wire Wire Line
	3700 3500 3700 3300
Wire Wire Line
	3700 3300 4250 3300
Wire Wire Line
	3700 3900 3700 4000
Wire Wire Line
	3700 4000 3300 4000
Wire Wire Line
	7650 3550 7400 3550
Wire Wire Line
	7550 3550 7550 3700
Wire Wire Line
	7550 3700 7400 3700
Connection ~ 7550 3550
Wire Wire Line
	7400 3850 7650 3850
Wire Wire Line
	7650 4150 7400 4150
Wire Wire Line
	7400 4000 7650 4000
Wire Notes Line
	500  4550 5600 4550
Wire Wire Line
	3250 6400 3200 6400
Wire Wire Line
	1250 6050 1250 5150
Connection ~ 1250 5150
Wire Wire Line
	1250 6450 1250 7500
Connection ~ 1250 7350
Connection ~ 1250 7450
Wire Wire Line
	1250 5150 1300 5150
Wire Wire Line
	1300 7350 1250 7350
Wire Wire Line
	1300 7450 1250 7450
Wire Wire Line
	3250 6600 3200 6600
Wire Wire Line
	3200 7350 3250 7350
Wire Wire Line
	3250 5250 3200 5250
Wire Wire Line
	3600 5350 3200 5350
Wire Wire Line
	3650 6500 3200 6500
Wire Wire Line
	4200 6450 4800 6450
Wire Wire Line
	4500 6450 4500 6500
Connection ~ 4500 6450
Wire Wire Line
	3250 5450 3200 5450
Wire Wire Line
	3250 5650 3200 5650
Wire Wire Line
	3200 5750 4800 5750
Wire Wire Line
	4800 5750 4800 6050
Wire Wire Line
	3200 5850 4200 5850
Wire Wire Line
	4200 5850 4200 6050
Wire Wire Line
	3200 7250 3600 7250
Wire Wire Line
	3500 5550 3200 5550
Wire Wire Line
	3550 5150 3200 5150
Wire Wire Line
	7800 6700 7650 6700
Wire Wire Line
	7650 6000 7800 6000
Wire Wire Line
	7950 6500 7950 6600
Wire Wire Line
	7950 6600 7650 6600
Wire Wire Line
	7800 6200 7650 6200
Wire Wire Line
	9750 1650 10100 1650
Wire Wire Line
	10100 1450 9750 1450
Wire Wire Line
	10200 6400 9900 6400
Wire Wire Line
	10200 6100 9900 6100
Wire Wire Line
	9900 5900 10200 5900
Wire Wire Line
	10100 4300 9800 4300
Wire Wire Line
	9800 4200 9950 4200
Wire Wire Line
	9950 4200 9950 4300
Connection ~ 9950 4300
Wire Wire Line
	9900 3800 9800 3800
Connection ~ 9900 3400
Wire Wire Line
	9600 3400 10000 3400
Wire Wire Line
	10500 3400 10600 3400
Wire Notes Line
	5600 5050 11200 5050
Wire Notes Line
	5600 2550 11200 2550
Wire Notes Line
	8700 500  8700 7200
Wire Wire Line
	6350 1200 6600 1200
Connection ~ 6500 1200
Wire Wire Line
	7100 1200 7250 1200
Wire Wire Line
	7650 1200 7800 1200
Wire Wire Line
	7150 1450 7000 1450
Wire Wire Line
	7000 1450 7000 1600
Wire Wire Line
	6700 1800 6500 1800
Wire Wire Line
	6500 1800 6500 1750
Wire Wire Line
	6500 1200 6500 1250
Wire Wire Line
	7000 2000 7650 2000
Wire Wire Line
	10250 4000 9800 4000
Wire Wire Line
	8250 6200 8350 6200
Wire Wire Line
	3250 6750 3200 6750
Wire Wire Line
	3300 6950 3250 6950
Wire Wire Line
	3250 6950 3250 6850
Wire Wire Line
	3250 6850 3200 6850
Wire Wire Line
	3800 6950 3750 6950
$Comp
L JUMPER JP1
U 1 1 5530B17C
P 3550 6950
F 0 "JP1" H 3550 6850 60  0000 C CNN
F 1 "JUMPER" H 3550 7050 60  0000 C CNN
F 2 "~" H 3550 6950 60  0000 C CNN
F 3 "~" H 3550 6950 60  0000 C CNN
	1    3550 6950
	1    0    0    -1  
$EndComp
Connection ~ 4050 3300
$Comp
L R R8
U 1 1 5539BEA2
P 4050 3950
F 0 "R8" V 4130 3950 40  0000 C CNN
F 1 "220" V 4057 3951 40  0000 C CNN
F 2 "~" V 3980 3950 30  0000 C CNN
F 3 "~" H 4050 3950 30  0000 C CNN
	1    4050 3950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR10
U 1 1 5539BEBB
P 4050 4200
F 0 "#PWR10" H 4050 4200 30  0001 C CNN
F 1 "GND" H 4050 4130 30  0001 C CNN
F 2 "" H 4050 4200 60  0000 C CNN
F 3 "" H 4050 4200 60  0000 C CNN
	1    4050 4200
	1    0    0    -1  
$EndComp
$EndSCHEMATC
