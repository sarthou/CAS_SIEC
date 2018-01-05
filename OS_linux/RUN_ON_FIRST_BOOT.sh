hciconfig hci0 piscan

mkdir /etc/wpa_supplicant
cp /etc/wpa_supplicant.conf /etc/wpa_supplicant/wpa_supplicant-wlan0.conf

systemctl enable wpa_supplicant@wlan0
systemctl start wpa_supplicant@wlan0
