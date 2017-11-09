
require recipes-core/images/rpi-hwup-image.bb

IMAGE_INSTALL += "htop example netconfig dnsmasq bluez5 kernel-module-mcp251x libsocketcan canutils"
EXTRA_IMAGE_FEATURES += "ssh-server-openssh" 

