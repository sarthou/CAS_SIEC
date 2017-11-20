# <img src="../logo/logo.bmp" width="150"> Nucleo STM32

|Name                | Type   |Size|Profil |Source|Destination|Fiability|Delay|Priority|
|--------------------|--------|----|-------|------|-----------|---------|-----|--------|
|pos steering wheel  |char    |1   |100ms  |Nucleo|Raspi      |-        |100ms|-       |
|pose wheels L+R     |float   |8   |100ms  |Nucleo|Raspi      |-        |100ms|-       |
|US front/back       |float   |8   |50ms   |Nucleo|Raspi      |+++      |50ms |+++     |
|US Left             |float   |8   |50ms   |Nucleo|Raspi      |+++      |50ms |+++     |
|US right            |float   |8   |50ms   |Nucleo|Raspi      |+++      |50ms |+++     |
|motors order        |int16   |4   |50ms   |Raspi |Nucleo     |++       |50ms |+       |
|steering wheel order|float   |1   |50ms   |Raspi |Nucleo     |++       |50ms |+       |
|battery             |char    |1   |aper   |Nucleo|Raspi      |--       |500ms|--      |

***

|Name                |Class ID |SubClass ID|Priority |ID    |
|--------------------|---------|-----------|---------|------|
|                    |3bits    |4bits      |4bits    |11bits|
|pos steering wheel  |0x1      |0x0        |0x1      |0x101 |
|pose wheels L+R     |0x1      |0x0        |0x0      |0x100 |
|US front/back       |0x0      |0x0        |0x0      |0x000 |
|US Left             |0x0      |0x0        |0x1      |0x001 |
|US right            |0x0      |0x0        |0x2      |0x002 |
|motors order        |0x0      |0x1        |0x0      |0x010 |
|steering wheel order|0x0      |0x1        |0x1      |0x011 |

### Data format

motors order[int16 : 0] = rear motor left   
motors order[int16 : 1] = rear motor right   

***

### systick_callback
 - can_callback
 - RearMotor_Callback
 
### Manager_Init
 - canInit();
 - FrontMotor_QuickInit();
 - RearMotors_QuickInit();
 
***

- [x] Front motors
- [ ] front motor backloop
- [ ] Front motor interface
- [ ] speed feedback
- [x] RearMotors
- [x] rear motor backloop
- [ ] RearMotor interface
- [ ] dir feedback
- [ ] Battery
- [ ] Battery interface
- [ ] US
- [ ] US interface

