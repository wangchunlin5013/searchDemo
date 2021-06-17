/*

 * Copyright (C) 2019 ~ 2019 Deepin Technology Co., Ltd.

 *

 * Author:     wangcl <wangchunlin@uniontech.com>

 *

 * Maintainer: wangcl <wangchunlin@uniontech.com>

 *

 * This program is free software: you can redistribute it and/or modify

 * it under the terms of the GNU General Public License as published by

 * the Free Software Foundation, either version 3 of the License, or

 * any later version.

 *

 * This program is distributed in the hope that it will be useful,

 * but WITHOUT ANY WARRANTY; without even the implied warranty of

 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the

 * GNU General Public License for more details.

 *

 * You should have received a copy of the GNU General Public License

 * along with this program.  If not, see <http://www.gnu.org/licenses/>.

 */

#include "searchmanager.h"
#include <QCoreApplication>
#include <QtDBus/QDBusConnection>
#include <QDBusError>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDBusConnection conn = QDBusConnection::sessionBus();

    if (!conn.registerService(SearchManagerServiceName)) {
        qCritical() << "registerService Failed, maybe service exist" << conn.lastError();
        exit(0x0002);
    }

    auto registerOptions = QDBusConnection::ExportAllSlots | QDBusConnection::ExportAllSignals | QDBusConnection::ExportAllProperties;
    if (!conn.registerObject(SearchManagerServicePath, SearchManager::instance(), registerOptions)) {
        qCritical() << "registerObject Failed" << conn.lastError();
        exit(0x0003);
    }

    return a.exec();
}
