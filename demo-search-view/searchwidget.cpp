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
#include <QEvent>
#include <QDebug>
#include <QHBoxLayout>
#include <QPushButton>

SearchWidget::SearchWidget(QWidget *parent) : QWidget(parent)
{
    setWindowFlag(Qt::FramelessWindowHint);
    move(400, 400);

    m_lineEdit = QSharedPointer<QLineEdit>(new QLineEdit);
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(m_lineEdit.data());

    QPushButton *btn = new QPushButton("测试退出", this);
    mainLayout->addStretch();
    mainLayout->addWidget(btn);
    connect(btn, &QPushButton::clicked, this, &SearchWidget::close);


    m_lineEdit->installEventFilter(this);

    connect(m_lineEdit.data(), &QLineEdit::textChanged, this, [this](const QString &text){
        qDebug()<<"current text:"<<text;
        if (this->m_timer)
            this->m_timer->start(100);
    });

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &SearchWidget::startSearch);
}

bool SearchWidget::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == m_lineEdit && event->type() == QEvent::FocusOut) {
        qDebug()<<"focus out and close.";
//        close();
        return true;
    }
    return QObject::eventFilter(obj, event);
}

void SearchWidget::startSearch()
{
    if (m_timer)
        m_timer->stop();

    QString key = m_lineEdit->text().trimmed();
    qDebug()<<"search key:"<<key;
}

