//-----------------------------------------------------------------------------
//
// kswarm - port of "swarm" from xlock
//

#ifndef __SWARM_H__
#define __SWARM_H__

#include <qtimer.h>

#include <kdialogbase.h>
#include "saver.h"


class kSwarmSaver : public kScreenSaver
{
	Q_OBJECT
public:
	kSwarmSaver( Drawable drawable );
	virtual ~kSwarmSaver();

	void setSpeed( int spd );
	void setLevels( int l );

protected:
	void readSettings();

protected slots:
	void slotTimeout();

protected:
	KRandomSequence rnd;
	QTimer      timer;
	int         colorContext;

	int         speed;
	int			maxLevels;
};

class kSwarmSetup : public KDialogBase
{
	Q_OBJECT
public:
	kSwarmSetup( QWidget *parent = NULL, const char *name = NULL );

protected:
	void readSettings();

private slots:
	void slotSpeed( int );
	void slotLevels( int );

	void slotOk();
	void slotHelp();

private:
	QWidget *preview;
	kSwarmSaver *saver;

	int			speed;
	int			maxLevels;
};

#endif

