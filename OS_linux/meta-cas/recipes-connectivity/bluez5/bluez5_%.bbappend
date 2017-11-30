FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
SRC_URI += "file://main.conf"
SRC_URI += "file://bluetooth.service"

FILES_${PN} += "${sysconfdir}/bluetooth/main.conf"

do_install_append() {
	install -m 0644 ${WORKDIR}/main.conf ${D}/${sysconfdir}/bluetooth/
	install -d ${D}${sysconfdir}/systemd/system/bluetooth.target.wants
	install -m 0644 ${WORKDIR}/bluetooth.service ${D}${systemd_unitdir}/system/bluetooth.service
}
