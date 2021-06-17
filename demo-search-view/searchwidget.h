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
#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QSharedPointer>
#include <QTimer>

#define SearchViewServiceName          "com.deepin.dde.searchview"
#define SearchViewServicePath          "/com/deepin/dde/searchview"
#define SearchViewServiceInterface     "com.deepin.dde.searchview"

class SearchWidget : public QWidget
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", SearchViewServiceInterface)
    Q_PROPERTY(bool visible READ isVisible WRITE setVisible DESIGNABLE false)
public:
    explicit SearchWidget(QWidget *parent = nullptr);

protected:
      bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
      void startSearch();
private:
    QSharedPointer<QLineEdit> m_lineEdit;
    QTimer *m_timer;
};

#endif // SEARCHWIDGET_H
