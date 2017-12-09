# <img src="../logo/logo.bmp" width="150"> Linux OS

Notes about the Rpi Image:
After the first boot, you should run the script RUN_ON_FIRST_BOOT.sh

Then, you should pair your device using this command :
	bluetoothctl
	scan on
	//wait to get the MAC address of your computer
	scan off
	pair <MAC_ADDRESS_COMPUTER>
	CTRL+D


WiFi connection:
	The raspberry will connect itself to the DarleneWiFi with an IP address in this range:
		192.168.0.2  -  192.168.0.5
