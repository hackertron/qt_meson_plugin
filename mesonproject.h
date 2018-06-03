#ifndef MESONPROJECT_H
#define MESONPROJECT_H

#include <projectexplorer/project.h>
#include <projectexplorer/projectnodes.h>

#include <QDir>

class MesonProject : public ProjectExplorer::Project
{
public:
    MesonProject();
};

#endif // MESONPROJECT_H
