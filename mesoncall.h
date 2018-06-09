/****************************************************************************
**
** Copyright (C) Jayaditya Gupta <cooljay.gupta@gmail.com>
** Contact: http://www.qt.io/licensing
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#ifndef MESONCALL_H
#define MESONCALL_H

#include <QObject>

#include <QJsonDocument>
#include <QJsonArray>
#include <QVariantMap>
#include <QObject>
#include <utils/qtcprocess.h>

class MesonCall : public QObject
{
    Q_OBJECT

private:
    Utils::QtcProcess *process;

public:
    explicit MesonCall(QObject *parent = 0);
    QVariantMap projectInfoResults;
    QVariantMap introspectResults;
    QString projectPath;


    QString getMesonPath();
    QString getProjectPath();
    void getProjectInfo();
    void getBuildSystemFiles();
    void getTargetInfo();

signals:
    void mesonProcess();

public slots:
    void mesonProcessComplete();


};

#endif // MESONCALL_H
