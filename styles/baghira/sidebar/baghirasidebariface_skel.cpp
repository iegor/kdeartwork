/****************************************************************************
**
** DCOP Skeleton generated by dcopidl2cpp from baghirasidebariface.kidl
**
** WARNING! All changes made in this file will be lost!
**
*****************************************************************************/

#include "./baghirasidebariface.h"

#include <kdatastream.h>


static const char* const BaghiraSidebarIface_ftable[4][3] = {
    { "void", "mediumAdded(QString)", "mediumAdded(QString name)" },
    { "void", "mediumRemoved(QString)", "mediumRemoved(QString name)" },
    { "void", "mediumChanged(QString)", "mediumChanged(QString name)" },
    { 0, 0, 0 }
};
static const int BaghiraSidebarIface_ftable_hiddens[3] = {
    0,
    0,
    0,
};

bool BaghiraSidebarIface::process(const QCString &fun, const QByteArray &data, QCString& replyType, QByteArray &replyData)
{
    if ( fun == BaghiraSidebarIface_ftable[0][1] ) { // void mediumAdded(QString)
	QString arg0;
	QDataStream arg( data, IO_ReadOnly );
	if (arg.atEnd()) return false;
	arg >> arg0;
	replyType = BaghiraSidebarIface_ftable[0][0]; 
	mediumAdded(arg0 );
    } else if ( fun == BaghiraSidebarIface_ftable[1][1] ) { // void mediumRemoved(QString)
	QString arg0;
	QDataStream arg( data, IO_ReadOnly );
	if (arg.atEnd()) return false;
	arg >> arg0;
	replyType = BaghiraSidebarIface_ftable[1][0]; 
	mediumRemoved(arg0 );
    } else if ( fun == BaghiraSidebarIface_ftable[2][1] ) { // void mediumChanged(QString)
	QString arg0;
	QDataStream arg( data, IO_ReadOnly );
	if (arg.atEnd()) return false;
	arg >> arg0;
	replyType = BaghiraSidebarIface_ftable[2][0]; 
	mediumChanged(arg0 );
    } else {
	return DCOPObject::process( fun, data, replyType, replyData );
    }
    return true;
}

QCStringList BaghiraSidebarIface::interfaces()
{
    QCStringList ifaces = DCOPObject::interfaces();
    ifaces += "BaghiraSidebarIface";
    return ifaces;
}

QCStringList BaghiraSidebarIface::functions()
{
    QCStringList funcs = DCOPObject::functions();
    for ( int i = 0; BaghiraSidebarIface_ftable[i][2]; i++ ) {
	if (BaghiraSidebarIface_ftable_hiddens[i])
	    continue;
	QCString func = BaghiraSidebarIface_ftable[i][0];
	func += ' ';
	func += BaghiraSidebarIface_ftable[i][2];
	funcs << func;
    }
    return funcs;
}


