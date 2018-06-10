#ifndef MESONPROJECT_H
#define MESONPROJECT_H

#include <QObject>
#include <projectexplorer/project.h>
#include <projectexplorer/projectnodes.h>

class MesonProject : public QObject
{
    Q_OBJECT
public:
    explicit MesonProject(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MESONPROJECT_H
