# <img src="../logo/logo.bmp" width="150"> Linux OS

# Branch :

This Yocto image has been built based on the branch Jethro.

To use the Cross-Compilation SDK for Windows, we tried to developp the same image based on the branch Rocko. Using this branch, the SDK worked, but the DHCP server was not working anymore. If you decide to use the branch Rocko, you should consider fixing this issue. It might be due to the dnsmasq recipe and configuration files.



After the first boot, you should run the script RUN_ON_FIRST_BOOT.sh

It solves some issues we did not manage to solve using Yocto.

# Pairing your computer

Then, you should pair your device using this command : 

	bluetoothctl 
	scan on 
	//wait to get the MAC address of your computer 
	scan off 
	pair <MAC_ADDRESS_COMPUTER> 
	CTRL+D 


# Image Contents :


WiFi connection:  
	The raspberry will connect itself to the DarleneWiFi using wpa-supplicant.
		
DHCP Server on Ethernet port : 
	The IP Address is fixed to 192.168.1.20 . There is a DHCP server to assign a 192.168.1.0/24 address to your computer. If you are using a rocko based image, you should fix your computer's ethernet IP Address because the DHCP is not working.

OpenCV : 
	Used for image processing. 
	
Bluetooth : 
	Bluetooth server to communicate with a computer application.
	
Can support : 
	Can-utils and libsocketcan used to communicate with the STM32.
	
Camera support :
	v4l-utils and gstreamer used to grab images. 
	

	
