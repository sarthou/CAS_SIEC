
require recipes-core/images/core-image-minimal.bb

IMAGE_INSTALL += "htop example netconfig"
EXTRA_IMAGE_FEATURES += "ssh-server-openssh" 

