#ifndef MESONPROJECT_H
#define MESONPROJECT_H

#include <projectexplorer/project.h>
#include <projectexplorer/projectnodes.h>

#include <QDir>

class MesonProject : public ProjectExplorer::Project
{
    Q_OBJECT

public:
    explicit MesonProject(const Utils::FileName &fileName);
};

#endif // MESONPROJECT_H
