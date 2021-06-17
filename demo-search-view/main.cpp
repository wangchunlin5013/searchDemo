/*
 * Copyright (C) 2020 ~ 2021 Uniontech Software Technology Co., Ltd.
 *
 * Author:     wangchunlin<wangchunlin@uniontech.com>
 *
 * Maintainer: wangchunlin<wangchunlin@uniontech.com>
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

#include "searchwidget.h"
#include "searchview_adaptor.h"

#include <QApplication>
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusError>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SearchWidget w;

    QDBusConnection conn = QDBusConnection::sessionBus();
    if (conn.isConnected()) {
        Q_UNUSED(new SearchviewAdaptor(&w));

        if (!conn.registerService(SearchViewServiceName)) {
            qCritical() << "registerService Failed, maybe service exist" << conn.lastError();
            exit(0x0002);
        }

        if (!conn.registerObject(SearchViewServicePath, &w)) {
            qCritical() << "registerObject Failed" << conn.lastError();
            exit(0x0003);
        }
    }

    for (const QString &arg : a.arguments()) {
        qDebug()<<"=====arg:"<<arg;
    }
    if (a.arguments().contains(QString("--dbus-start"))) {

    } else {
        w.show();
    }

    return a.exec();
}
