# <img src="../logo/logo.bmp" width="150"> PC application

 - [x] Bluetooth connection  
 - [x] Keyboard control  
 - [x] Speed selection  
 - [ ] Add images to advise  
 - [x] Add images for sensors  
 - [x] Create protocol  
 - [x] Fix debug area resize
 - [x] Speed ramp for manual control

***Warning, after pressing to key at the same time, the first one will not respond anymore*** (like on a text editor)

***

# Protocol

## Message id - one byte

bits 7 and 6 :
 - [00] command
 - [01] debug
 - [10] warning
 - [11] error

### Command message

bits 5 and 4 :
 - [00] sensor value
 - [01] order
 - [10] camera info
 - [11] NA

***Sensor value :***  
bits 0 to 3:
 - [0x0] NA
 - [0x1] wheels position
 - [0x2] wheels speed
 - [0x3] US front and back
 - [0x4] US left
 - [0x5] US right
 - [0x6] battery
 - [0x7] steering wheel position

***Order :***  
bits 0 to 3:
 - [0x1] Turn right
 - [0x2] Turn Left
 - [0x4] Go back
 - [0x8] Go front

***Camera informations :***  
bits 0 to 3:
 - [0x0] No car detected
 - [0x1] Car at right
 - [0x2] Car at Left
 
### Error message

bits 5 and 4 :
 - [00] communication
 - [01] NA
 - [10] NA 
 - [11] NA
 
***Communication :***  
bits 0 to 3:
 - [0x0] Lost CAN

## Full frames

### Command frames

 - wheels position : [0x01] + Left[float] + Right[float]  
 - wheels speed : [0x02] + Left[float] + Right[float]  
 - US FB : [0x03] + Front[float] + Back[float]  
 - US left : [0x04] + Front[float] + Back[float]  
 - US right : [0x05] + Front[float] + Back[float]  
 - Battery : [0x06] + level[byte]  
 - Steering wheel : [0x07] + position[byte]  

 - Turn right : [0x11]  
 - Turn left : [0x12] 
 - Go back : [0x14] 
 - Go front : [0x18] 

 - Lost CAN : [0xC0]
