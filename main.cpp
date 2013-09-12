#include "routine.h"
#include "defines.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setApplicationName(VER_PRODUCTNAME_STR);
    a.setApplicationVersion(VER_PRODUCTVERSION_STR);
    a.setOrganizationName(VER_COMPANYNAME_STR);
    a.setOrganizationDomain(VER_COMPANYDOMAIN_STR);

    Routine r;
    r.show();
    
    return a.exec();
}
