SUMMARY = "Systemd network configuration"
DESCRIPTION = "Scripts and configuration files to set up networking on server."
SECTION = "console/network"
LICENSE="CLOSED"

REQUIRED_DISTRO_FEATURES = "systemd"

SRC_URI = "file://ethernet.network"
SRC_URI += "file://wlan.network"
NET_IFACE ?= "eth0"

RDEPENDS_${PN} += "systemd"
inherit systemd allarch

do_install () {
       install -d ${D}${sysconfdir}/systemd/network
       install -m 0644 ${WORKDIR}/wlan.network ${D}${sysconfdir}/systemd/network/
       install -m 0644 ${WORKDIR}/ethernet.network ${D}${sysconfdir}/systemd/network/
       sed -i -e "s:@@interface@@:${NET_IFACE}:" ${D}${sysconfdir}/systemd/network/ethernet.network
}

FILES_${PN} = " \
       ${sysconfdir}/* \
"

