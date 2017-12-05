
require recipes-core/images/rpi-hwup-image.bb

IMAGE_INSTALL += "htop example netconfig dnsmasq bluez5 bluez5-dev kernel-module-mcp251x libsocketcan canutils udev-rules packagegroup-core-buildessential gstreamer1.0 v4l-utils v4l-utils-dev libjpeg-turbo libjpeg-turbo-dev"
EXTRA_IMAGE_FEATURES += "ssh-server-openssh" 

KERNEL_MODULE_AUTOLOAD += "mcp251x bcm2835-v4l2"
