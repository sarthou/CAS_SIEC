# <img src="../logo/logo.bmp" width="150"> Linux OS

Notes about the Rpi Image:
After the first boot, you should run this command :
	hciconfig hci0 piscan
Then, you should pair your device using this command :
	bluetoothctl
	scan on
	//wait to get the MAC address of your computer
	scan off
	pair <MAC_ADDRESS_COMPUTER>
	CTRL+D

