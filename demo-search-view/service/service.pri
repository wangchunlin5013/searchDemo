
searchview.files = $$PWD/../com.deepin.dde.searchview.xml
DBUS_ADAPTORS += searchview

searchview_xml.path = /usr/share/dbus-1/interfaces
searchview_xml.files = searchview.files

services.path = /usr/share/dbus-1/services
services.files = $$PWD/data/com.deepin.dde.searchview.service

INSTALLS += services searchview_xml

