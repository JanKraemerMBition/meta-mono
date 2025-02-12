SUMMARY = "Mono Hello World"
DESCRIPTION = "Test applications for Mono console and windows forms"
AUTHOR = "Alex J Lennon <ajlennon@dynamicdevices.co.uk>"
HOMEPAGE = "http://www.dynamicdevices.co.uk"
SECTION = "mono/applications"
PRIORITY = "optional"
LICENSE = "GPLv3"
LIC_FILES_CHKSUM = "file://LICENSE;md5=783b7e40cdfb4a1344d15b1f7081af66"

SRC_URI = "https://github.com/DynamicDevices/mono-helloworld/releases/download/v${PV}/mono-helloworld-${PV}.tar.gz"

inherit autotools
inherit mono
inherit pkgconfig

DEPENDS += "mono-native"
RDEPENDS:${PN} += "mono"

EDEPENDS_X11 = "libgdiplus"
ERDEPENDS_X11 = "libgdiplus"
EDEPENDS_GTK = "gtk-sharp"
ERDEPENDS_GTK = "gtk-sharp"
EDEPENDS_WAYLAND = "wayland"
ERDEPENDS_WAYLAND = "wayland"

PACKAGECONFIG[x11] = "--enable-winformdemo=yes,,${EDEPENDS_X11},${ERDEPENDS_X11}"
PACKAGECONFIG[wayland] = ",,${EDEPENDS_WAYLAND},${ERDEPENDS_WAYLAND}"
PACKAGECONFIG[gtk] = "--enable-gtkdemo=yes,,${EDEPENDS_GTK},${ERDEPENDS_GTK}"

# Default configuration, distros might want to override
PACKAGECONFIG ??= "${@bb.utils.contains('DISTRO_FEATURES', 'x11', 'x11 gtk', '', d)} \
		   ${@bb.utils.contains('DISTRO_FEATURES', 'wayland', 'wayland gtk', '', d)} \
"

FILES:${PN} = "${libdir}/helloworld/helloworld.exe \
		${bindir}/helloworld \
		${libdir}/helloworld/helloworldform.exe \
		${bindir}/helloworldform \
		${libdir}/helloworld/helloworldgtk.exe \
		${bindir}/helloworldgtk \
"
