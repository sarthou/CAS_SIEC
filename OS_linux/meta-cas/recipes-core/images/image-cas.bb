
require recipes-core/images/rpi-hwup-image.bb

IMAGE_INSTALL += "htop example netconfig dnsmasq bluez5 bluez5-dev kernel-module-mcp251x libsocketcan canutils udev-rules packagegroup-core-buildessential"
EXTRA_IMAGE_FEATURES += "ssh-server-openssh" 

KERNEL_MODULE_AUTOLOAD += "mcp251x"
