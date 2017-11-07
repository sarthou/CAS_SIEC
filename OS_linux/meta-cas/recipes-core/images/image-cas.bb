
require recipes-core/images/rpi-hwup-image.bb

IMAGE_INSTALL += "htop example netconfig dnsmasq bluez5"
EXTRA_IMAGE_FEATURES += "ssh-server-openssh" 

