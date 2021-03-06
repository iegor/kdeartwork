//////////////////////////////////////////////////////////////////////////////
// baghiraconfig.cc
// -------------------
// Config module for Baghira window decoration
// -------------------
// Copyright (c) 2004 Thomas L�bking
// Please see the header file for copyright and license information.
//////////////////////////////////////////////////////////////////////////////

#include <kconfig.h>
#include <klocale.h>
#include <kglobal.h>
#include <kcolorbutton.h>
#include <qbutton.h>
#include <qbuttongroup.h>
#include <qcombobox.h>
#include <qcheckbox.h>
#include <qlayout.h>
#include <qlabel.h>
#include <qfont.h>
#include <qgroupbox.h>
#include <qpushbutton.h>
#include <qradiobutton.h>
#include <qsettings.h>
#include <qspinbox.h>
#include <qwhatsthis.h>

#include "baghiraconfig.h"
#include "configdialog.h"
#include "pixmaps.h"

//////////////////////////////////////////////////////////////////////////////
// BaghiraConfig Class                                                        //
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// BaghiraConfig()
// -------------
// Constructor

BaghiraConfig::BaghiraConfig(KConfig*, QWidget* parent)
    : QObject(parent), /*config_(0),*/ dialog_(0)
{
//     config_ = new KConfig("baghirarc");
//     config_ = new QSettings;
//     config_->beginGroup("/baghira/Deco");
    KGlobal::locale()->insertCatalogue("kwin_baghira_config");

    dialog_ = new ConfigDialog(parent);
    buttonDialog_ = new ButtonColors(parent, "Button Colors");
    load(0L);
    
    dialog_->show();
    
    connect(dialog_->ButtonColorConfig, SIGNAL(clicked()), buttonDialog_, SLOT(exec()));
    connect(buttonDialog_->ok, SIGNAL(clicked()), SIGNAL(changed()));
            
    // connections
    connect(dialog_->titlealign, SIGNAL(clicked(int)), SIGNAL(changed()));
    connect(dialog_->drawComicFrame, SIGNAL(toggled(bool)), SIGNAL(changed()));
    connect(dialog_->addAutoSpacing, SIGNAL(toggled(bool)), SIGNAL(changed()));
    connect(dialog_->allowEasyClosing, SIGNAL(toggled(bool)), SIGNAL(changed()));
    connect(dialog_->ResizeGrip, SIGNAL(toggled(bool)), SIGNAL(changed()));
    connect(dialog_->maxResizable, SIGNAL(toggled(bool)), SIGNAL(changed()));
    connect(dialog_->fullSpec, SIGNAL(toggled(bool)), SIGNAL(changed()));
    connect(dialog_->noModalDeco, SIGNAL(toggled(bool)), SIGNAL(changed()));
    connect(dialog_->delAppname, SIGNAL(toggled(bool)), SIGNAL(changed()));
    connect(dialog_->defaultMode, SIGNAL(activated(int)),  SIGNAL(changed()));
    connect(dialog_->minTH, SIGNAL(valueChanged(int)), SIGNAL(changed()));
    
    connect(dialog_->activeColor1_J, SIGNAL(clicked()), SIGNAL(changed()));
    connect(dialog_->activeColor2_J, SIGNAL(clicked()), SIGNAL(changed()));
    connect(dialog_->inactiveColor1_J, SIGNAL(clicked()), SIGNAL(changed()));
    connect(dialog_->inactiveColor2_J, SIGNAL(clicked()), SIGNAL(changed()));
    connect(dialog_->buttonStyle_J, SIGNAL(activated(int)), SIGNAL(changed()));
    connect(dialog_->shapeUL_J, SIGNAL(toggled(bool)), SIGNAL(changed()));
    connect(dialog_->shapeUR_J, SIGNAL(toggled(bool)), SIGNAL(changed()));
    connect(dialog_->shapeLL_J, SIGNAL(toggled(bool)), SIGNAL(changed()));
    connect(dialog_->shapeLR_J, SIGNAL(toggled(bool)), SIGNAL(changed()));
    connect(dialog_->drawIcon_J, SIGNAL(toggled(bool)), SIGNAL(changed()));
    connect(dialog_->titleeffect_J, SIGNAL(activated(int)),  SIGNAL(changed()));
    connect(dialog_->i_titleeffect_J, SIGNAL(activated(int)), SIGNAL(changed()));
    connect(dialog_->_3DImpact_J, SIGNAL(valueChanged(int)), SIGNAL(changed()));
    connect(dialog_->LineImpact_J, SIGNAL(valueChanged(int)), SIGNAL(changed()));
   connect(dialog_->borderSize_J, SIGNAL(valueChanged(int)), SIGNAL(changed()));
            
    connect(dialog_->activeColor1_P, SIGNAL(clicked()), SIGNAL(changed()));
    connect(dialog_->activeColor2_P, SIGNAL(clicked()), SIGNAL(changed()));
    connect(dialog_->inactiveColor1_P, SIGNAL(clicked()), SIGNAL(changed()));
    connect(dialog_->inactiveColor2_P, SIGNAL(clicked()), SIGNAL(changed()));
    connect(dialog_->buttonStyle_P, SIGNAL(activated(int)), SIGNAL(changed()));
    connect(dialog_->shapeUL_P, SIGNAL(toggled(bool)), SIGNAL(changed()));
    connect(dialog_->shapeUR_P, SIGNAL(toggled(bool)), SIGNAL(changed()));
    connect(dialog_->shapeLL_P, SIGNAL(toggled(bool)), SIGNAL(changed()));
    connect(dialog_->shapeLR_P, SIGNAL(toggled(bool)), SIGNAL(changed()));
    connect(dialog_->drawIcon_P, SIGNAL(toggled(bool)), SIGNAL(changed()));
    connect(dialog_->titleeffect_P, SIGNAL(activated(int)), SIGNAL(changed()));
    connect(dialog_->i_titleeffect_P, SIGNAL(activated(int)), SIGNAL(changed()));
    connect(dialog_->_3DImpact_P, SIGNAL(valueChanged(int)), SIGNAL(changed()));
    connect(dialog_->LineImpact_P, SIGNAL(valueChanged(int)), SIGNAL(changed()));
   connect(dialog_->borderSize_P, SIGNAL(valueChanged(int)), SIGNAL(changed()));
            
    connect(dialog_->activeColor1_B, SIGNAL(clicked()), SIGNAL(changed()));
    connect(dialog_->activeColor2_B, SIGNAL(clicked()), SIGNAL(changed()));
    connect(dialog_->inactiveColor1_B, SIGNAL(clicked()), SIGNAL(changed()));
    connect(dialog_->inactiveColor2_B, SIGNAL(clicked()), SIGNAL(changed()));
    connect(dialog_->buttonStyle_B, SIGNAL(activated(int)), SIGNAL(changed()));
    connect(dialog_->shapeUL_B, SIGNAL(toggled(bool)), SIGNAL(changed()));
    connect(dialog_->shapeUR_B, SIGNAL(toggled(bool)), SIGNAL(changed()));
    connect(dialog_->shapeLL_B, SIGNAL(toggled(bool)), SIGNAL(changed()));
    connect(dialog_->shapeLR_B, SIGNAL(toggled(bool)), SIGNAL(changed()));
    connect(dialog_->drawIcon_B, SIGNAL(toggled(bool)), SIGNAL(changed()));
    connect(dialog_->titleeffect_B, SIGNAL(activated(int)),  SIGNAL(changed()));
    connect(dialog_->i_titleeffect_B, SIGNAL(activated(int)), SIGNAL(changed()));
    connect(dialog_->_3DImpact_B, SIGNAL(valueChanged(int)), SIGNAL(changed()));
    connect(dialog_->LineImpact_B, SIGNAL(valueChanged(int)), SIGNAL(changed()));
   connect(dialog_->borderSize_B, SIGNAL(valueChanged(int)), SIGNAL(changed()));
   
   connect(dialog_->activeColor1_T, SIGNAL(clicked()), SIGNAL(changed()));
   connect(dialog_->activeColor2_T, SIGNAL(clicked()), SIGNAL(changed()));            
   connect(dialog_->buttonStyle_T, SIGNAL(activated(int)), SIGNAL(changed()));
   connect(dialog_->shapeUL_T, SIGNAL(toggled(bool)), SIGNAL(changed()));
   connect(dialog_->shapeUR_T, SIGNAL(toggled(bool)), SIGNAL(changed()));
   connect(dialog_->shapeLL_T, SIGNAL(toggled(bool)), SIGNAL(changed()));
   connect(dialog_->shapeLR_T, SIGNAL(toggled(bool)), SIGNAL(changed()));
   connect(dialog_->drawIcon_T, SIGNAL(toggled(bool)), SIGNAL(changed()));    
   connect(dialog_->_3DImpact_T, SIGNAL(valueChanged(int)), SIGNAL(changed()));
   connect(dialog_->borderSize_T, SIGNAL(valueChanged(int)), SIGNAL(changed()));
   
   connect(dialog_->activeColor1_S, SIGNAL(clicked()), SIGNAL(changed()));
   connect(dialog_->activeColor2_S, SIGNAL(clicked()), SIGNAL(changed()));
   connect(dialog_->inactiveColor1_S, SIGNAL(clicked()), SIGNAL(changed()));
   connect(dialog_->inactiveColor2_S, SIGNAL(clicked()), SIGNAL(changed()));
   connect(dialog_->buttonStyle_S, SIGNAL(activated(int)), SIGNAL(changed()));
   connect(dialog_->shapeUL_S, SIGNAL(toggled(bool)), SIGNAL(changed()));
   connect(dialog_->shapeUR_S, SIGNAL(toggled(bool)), SIGNAL(changed()));
   connect(dialog_->shapeLL_S, SIGNAL(toggled(bool)), SIGNAL(changed()));
   connect(dialog_->shapeLR_S, SIGNAL(toggled(bool)), SIGNAL(changed()));
   connect(dialog_->drawIcon_S, SIGNAL(toggled(bool)), SIGNAL(changed()));
   connect(dialog_->titleeffect_S, SIGNAL(activated(int)),  SIGNAL(changed()));
   connect(dialog_->i_titleeffect_S, SIGNAL(activated(int)), SIGNAL(changed()));
   connect(dialog_->_3DImpact_S, SIGNAL(valueChanged(int)), SIGNAL(changed()));
   connect(dialog_->LineImpact_S, SIGNAL(valueChanged(int)), SIGNAL(changed()));
   connect(dialog_->borderSize_S, SIGNAL(valueChanged(int)), SIGNAL(changed()));
//     config_->endGroup();

}

//////////////////////////////////////////////////////////////////////////////
// ~BaghiraConfig()
// --------------
// Destructor

BaghiraConfig::~BaghiraConfig()
{
    if (dialog_) delete dialog_;
//     if (config_) delete config_;
}

//////////////////////////////////////////////////////////////////////////////
// load()
// ------
// Load configuration data

void BaghiraConfig::load(KConfig*)
{
    QSettings *config_ = new QSettings;
    config_->beginGroup("/baghira/Deco");
    
    QString value = config_->readEntry("TitleAlignment", "AlignHCenter");
    QRadioButton *button = (QRadioButton*)dialog_->titlealign->
        child((const char *)value.latin1());
    if (button) button->setChecked(true);

    dialog_->minTH->setValue(config_->readNumEntry("minimumTitleHeight",18));
    dialog_->ResizeGrip->setChecked(config_->readBoolEntry("ResizeGrip",false));
    dialog_->allowEasyClosing->setChecked(config_->readBoolEntry("allowEasyClosing",false));
    dialog_->drawComicFrame->setChecked(config_->readBoolEntry("DrawComicFrame",false));
    dialog_->maxResizable->setChecked(config_->readBoolEntry("MaxResizable",false));
    dialog_->fullSpec->setChecked(config_->readBoolEntry("FullSpec",false));
    dialog_->addAutoSpacing->setChecked(config_->readBoolEntry("AddAutoSpacing",true));
    dialog_->defaultMode->setCurrentItem(config_->readNumEntry("defaultMode",1));
    dialog_->noModalDeco->setChecked(config_->readBoolEntry("NoModalDeco",false));
    dialog_->delAppname->setChecked(config_->readBoolEntry("RemoveAppname",false));
        
    dialog_->activeColor1_J->setColor(QColor((unsigned int)config_->readNumEntry("activeColor1_1",QColor(255,255,255).rgb())));
    dialog_->inactiveColor1_J->setColor(QColor((unsigned int)config_->readNumEntry("inactiveColor1_1",QColor(204,214,230).rgb())));
   dialog_->activeColor2_J->setColor(QColor((unsigned int)config_->readNumEntry("activeColor2_1",QColor(238,234,238).rgb())));
    dialog_->inactiveColor2_J->setColor(QColor((unsigned int)config_->readNumEntry("inactiveColor2_1",QColor(194,196,211).rgb())));
    dialog_->buttonStyle_J->setCurrentItem(config_->readNumEntry("ButtonStyle_1",1));
    dialog_->titleeffect_J->setCurrentItem(config_->readNumEntry("TitleEffect_1", 1));
    dialog_->i_titleeffect_J->setCurrentItem(config_->readNumEntry("inactiveTitleEffect_1", 1));
    dialog_->shapeUL_J->setChecked(config_->readBoolEntry("ShapeUL_1",true));
    dialog_->shapeUR_J->setChecked(config_->readBoolEntry("ShapeUR_1",true));
    dialog_->shapeLL_J->setChecked(config_->readBoolEntry("ShapeLL_1",false));
    dialog_->shapeLR_J->setChecked(config_->readBoolEntry("ShapeLR_1",false));
    dialog_->drawIcon_J->setChecked(config_->readBoolEntry("drawIcon_1",true));
    dialog_->_3DImpact_J->setValue(config_->readNumEntry("3DImpact_1",20));
    dialog_->LineImpact_J->setValue(config_->readNumEntry("LineImpact_1",40));
   dialog_->borderSize_J->setValue(config_->readNumEntry("BorderSize_1",0));
    
    dialog_->activeColor1_P->setColor(QColor((unsigned int)config_->readNumEntry("activeColor1_2",QColor(238,238,238).rgb())));
    dialog_->inactiveColor1_P->setColor(QColor((unsigned int)config_->readNumEntry("inactiveColor1_2",QColor(246,242,246).rgb())));
    dialog_->activeColor2_P->setColor(QColor((unsigned int)config_->readNumEntry("activeColor2_2",QColor(205,202,205).rgb())));
    dialog_->inactiveColor2_P->setColor(QColor((unsigned int)config_->readNumEntry("inactiveColor2_2",QColor(238,238,238).rgb())));
    dialog_->buttonStyle_P->setCurrentItem(config_->readNumEntry("ButtonStyle_2",0));
    dialog_->titleeffect_P->setCurrentItem(config_->readNumEntry("TitleEffect_2", 0));
    dialog_->i_titleeffect_P->setCurrentItem(config_->readNumEntry("inactiveTitleEffect_2", 0));
    dialog_->shapeUL_P->setChecked(config_->readBoolEntry("ShapeUL_2",true));
    dialog_->shapeUR_P->setChecked(config_->readBoolEntry("ShapeUR_2",true));
    dialog_->shapeLL_P->setChecked(config_->readBoolEntry("ShapeLL_2",false));
    dialog_->shapeLR_P->setChecked(config_->readBoolEntry("ShapeLR_2",false));
    dialog_->drawIcon_P->setChecked(config_->readBoolEntry("drawIcon_2",true));
    dialog_->_3DImpact_P->setValue(config_->readNumEntry("3DImpact_2",20));
    dialog_->LineImpact_P->setValue(config_->readNumEntry("LineImpact_2",40));
   dialog_->borderSize_P->setValue(config_->readNumEntry("BorderSize_2",0));
    
    dialog_->activeColor1_B->setColor(QColor((unsigned int)config_->readNumEntry("activeColor1_3",QColor(202,202,202).rgb())));
    dialog_->inactiveColor1_B->setColor(QColor((unsigned int)config_->readNumEntry("inactiveColor1_3",QColor(200,200,200).rgb())));
    dialog_->activeColor2_B->setColor(QColor((unsigned int)config_->readNumEntry("activeColor2_3",QColor(150,150,150).rgb())));
   dialog_->inactiveColor2_B->setColor(QColor((unsigned int)config_->readNumEntry("inactiveColor2_3",QColor(150,150,150).rgb())));
    dialog_->buttonStyle_B->setCurrentItem(config_->readNumEntry("ButtonStyle_3",0));
    dialog_->titleeffect_B->setCurrentItem(config_->readNumEntry("TitleEffect_3", 4));
    dialog_->i_titleeffect_B->setCurrentItem(config_->readNumEntry("inactiveTitleEffect_3", 4));
    dialog_->shapeUL_B->setChecked(config_->readBoolEntry("ShapeUL_3",true));
    dialog_->shapeUR_B->setChecked(config_->readBoolEntry("ShapeUR_3",true));
    dialog_->shapeLL_B->setChecked(config_->readBoolEntry("ShapeLL_3",true));
    dialog_->shapeLR_B->setChecked(config_->readBoolEntry("ShapeLR_3",true));
    dialog_->drawIcon_B->setChecked(config_->readBoolEntry("drawIcon_3",true));
    dialog_->_3DImpact_B->setValue(config_->readNumEntry("3DImpact_3",20));
    dialog_->LineImpact_B->setValue(config_->readNumEntry("LineImpact_3",0));
   dialog_->borderSize_B->setValue(config_->readNumEntry("BorderSize_3",6));
   
   dialog_->activeColor1_T->setColor(QColor((unsigned int)config_->readNumEntry("activeColor1_4",QColor(238,238,238).rgb())));
   dialog_->activeColor2_T->setColor(QColor((unsigned int)config_->readNumEntry("activeColor2_4",QColor(205,202,205).rgb())));
   dialog_->buttonStyle_T->setCurrentItem(config_->readNumEntry("ButtonStyle_4",0));
   dialog_->shapeUL_T->setChecked(config_->readBoolEntry("ShapeUL_4",true));
   dialog_->shapeUR_T->setChecked(config_->readBoolEntry("ShapeUR_4",true));
   dialog_->shapeLL_T->setChecked(config_->readBoolEntry("ShapeLL_4",false));
   dialog_->shapeLR_T->setChecked(config_->readBoolEntry("ShapeLR_4",false));
   dialog_->drawIcon_T->setChecked(config_->readBoolEntry("drawIcon_4",true));
   dialog_->_3DImpact_T->setValue(config_->readNumEntry("3DImpact_4",20));
   dialog_->borderSize_T->setValue(config_->readNumEntry("BorderSize_4",0));
   
   dialog_->activeColor1_S->setColor(QColor((unsigned int)config_->readNumEntry("activeColor1_5",QColor(250,250,250).rgb())));
   dialog_->inactiveColor1_S->setColor(QColor((unsigned int)config_->readNumEntry("inactiveColor1_5",QColor(230,230,230).rgb())));
   dialog_->activeColor2_S->setColor(QColor((unsigned int)config_->readNumEntry("activeColor2_5",QColor(230,230,230).rgb())));
   dialog_->inactiveColor2_S->setColor(QColor((unsigned int)config_->readNumEntry("inactiveColor2_5",QColor(250,250,250).rgb())));
   dialog_->buttonStyle_S->setCurrentItem(config_->readNumEntry("ButtonStyle_5",0));
   dialog_->titleeffect_S->setCurrentItem(config_->readNumEntry("TitleEffect_5", 0));
   dialog_->i_titleeffect_S->setCurrentItem(config_->readNumEntry("inactiveTitleEffect_5", 0));
   dialog_->shapeUL_S->setChecked(config_->readBoolEntry("ShapeUL_5",true));
   dialog_->shapeUR_S->setChecked(config_->readBoolEntry("ShapeUR_5",true));
   dialog_->shapeLL_S->setChecked(config_->readBoolEntry("ShapeLL_5",false));
   dialog_->shapeLR_S->setChecked(config_->readBoolEntry("ShapeLR_5",false));
   dialog_->drawIcon_S->setChecked(config_->readBoolEntry("drawIcon_5",true));
   dialog_->_3DImpact_S->setValue(config_->readNumEntry("3DImpact_5",20));
   dialog_->LineImpact_S->setValue(config_->readNumEntry("LineImpact_5",30));
   dialog_->borderSize_S->setValue(config_->readNumEntry("BorderSize_5",0));
   
    buttonDialog_->inactiveColor->setColor(QColor((unsigned int)config_->readNumEntry("InactiveButtonColor", QColor(255,255,255).rgb())));
    buttonDialog_->closeColor->setColor(QColor((unsigned int)config_->readNumEntry("CloseButtonColor", QColor(200,85,70).rgb())));
    buttonDialog_->minColor->setColor(QColor((unsigned int)config_->readNumEntry("MinButtonColor", QColor(230,155,40).rgb())));
    buttonDialog_->         maxColor->setColor(QColor((unsigned int)config_->readNumEntry("MaxButtonColor", QColor(121,180,54).rgb())));
    buttonDialog_->menuColor->setColor(QColor((unsigned int)config_->readNumEntry("MenuButtonColor", QColor(74,140,242).rgb())));
    buttonDialog_->helpColor->setColor(QColor((unsigned int)config_->readNumEntry("HelpButtonColor", QColor(0,0,0).rgb())));
    buttonDialog_->stickyColor->setColor(QColor((unsigned int)config_->readNumEntry("StickyButtonColor", QColor(74,140,242).rgb())));
    buttonDialog_->aboveColor->setColor(QColor((unsigned int)config_->readNumEntry("AboveButtonColor", QColor(74,140,242).rgb())));
    buttonDialog_->behindColor->setColor(QColor((unsigned int)config_->readNumEntry("BehindButtonColor", QColor(74,140,242).rgb())));
    buttonDialog_->shadeColor->setColor(QColor((unsigned int)config_->readNumEntry("ShadeButtonColor", QColor(74,140,242).rgb())));
    buttonDialog_->init();
    config_->endGroup();
    delete config_;

}

//////////////////////////////////////////////////////////////////////////////
// save()
// ------
// Save configuration data

void BaghiraConfig::save(KConfig*)
{
    QSettings *config_ = new QSettings;
    config_->beginGroup("/baghira/Deco");

    QRadioButton *button = (QRadioButton*)dialog_->titlealign->selected();
    if (button) config_->writeEntry("TitleAlignment", QString(button->name()));
    config_->writeEntry("DrawComicFrame", dialog_->drawComicFrame->isChecked());
    config_->writeEntry("AddAutoSpacing", dialog_->addAutoSpacing->isChecked());
    config_->writeEntry("ResizeGrip", dialog_->ResizeGrip->isChecked());
    config_->writeEntry("allowEasyClosing", dialog_->allowEasyClosing->isChecked());
    config_->writeEntry("MaxResizable", dialog_->maxResizable->isChecked());
    config_->writeEntry("FullSpec", dialog_->fullSpec->isChecked());
    config_->writeEntry("defaultMode", dialog_->defaultMode->currentItem());
    config_->writeEntry("minimumTitleHeight", dialog_->minTH->value());
    config_->writeEntry("NoModalDeco", dialog_->noModalDeco->isChecked());
    config_->writeEntry("RemoveAppname", dialog_->delAppname->isChecked());
       
    config_->writeEntry("activeColor1_1", (int)dialog_->activeColor1_J->color().rgb());
    config_->writeEntry("activeColor2_1", (int)dialog_->activeColor2_J->color().rgb());
    config_->writeEntry("inactiveColor1_1", (int)dialog_->inactiveColor1_J->color().rgb());
    config_->writeEntry("inactiveColor2_1", (int)dialog_->inactiveColor2_J->color().rgb());
    config_->writeEntry("ButtonStyle_1", dialog_->buttonStyle_J->currentItem());
    config_->writeEntry("TitleEffect_1", dialog_->titleeffect_J->currentItem());
    config_->writeEntry("inactiveTitleEffect_1", dialog_->i_titleeffect_J->currentItem());
    config_->writeEntry("ShapeUL_1", dialog_->shapeUL_J->isChecked());
    config_->writeEntry("ShapeUR_1", dialog_->shapeUR_J->isChecked());
    config_->writeEntry("ShapeLL_1", dialog_->shapeLL_J->isChecked());
    config_->writeEntry("ShapeLR_1", dialog_->shapeLR_J->isChecked());    
    config_->writeEntry("drawIcon_1", dialog_->drawIcon_J->isChecked());
    config_->writeEntry("3DImpact_1", dialog_->_3DImpact_J->value());
    config_->writeEntry("LineImpact_1", dialog_->LineImpact_J->value());
   config_->writeEntry("BorderSize_1", dialog_->borderSize_J->value());
    
    config_->writeEntry("activeColor1_2", (int)dialog_->activeColor1_P->color().rgb());
    config_->writeEntry("activeColor2_2", (int)dialog_->activeColor2_P->color().rgb());
    config_->writeEntry("inactiveColor1_2", (int)dialog_->inactiveColor1_P->color().rgb());
    config_->writeEntry("inactiveColor2_2", (int)dialog_->inactiveColor2_P->color().rgb());
    config_->writeEntry("ButtonStyle_2", dialog_->buttonStyle_P->currentItem());
    config_->writeEntry("TitleEffect_2", dialog_->titleeffect_P->currentItem());
    config_->writeEntry("inactiveTitleEffect_2", dialog_->i_titleeffect_P->currentItem());
    config_->writeEntry("ShapeUL_2", dialog_->shapeUL_P->isChecked());
    config_->writeEntry("ShapeUR_2", dialog_->shapeUR_P->isChecked());
    config_->writeEntry("ShapeLL_2", dialog_->shapeLL_P->isChecked());
    config_->writeEntry("ShapeLR_2", dialog_->shapeLR_P->isChecked());    
    config_->writeEntry("drawIcon_2", dialog_->drawIcon_P->isChecked());
    config_->writeEntry("3DImpact_2", dialog_->_3DImpact_P->value());
    config_->writeEntry("LineImpact_2", dialog_->LineImpact_P->value());
   config_->writeEntry("BorderSize_2", dialog_->borderSize_P->value());
    
    config_->writeEntry("activeColor1_3", (int)dialog_->activeColor1_B->color().rgb());
    config_->writeEntry("activeColor2_3", (int)dialog_->activeColor2_B->color().rgb());
    config_->writeEntry("inactiveColor1_3", (int)dialog_->inactiveColor1_B->color().rgb());
    config_->writeEntry("inactiveColor2_3", (int)dialog_->inactiveColor2_B->color().rgb());
    config_->writeEntry("ButtonStyle_3", dialog_->buttonStyle_B->currentItem());
    config_->writeEntry("TitleEffect_3", dialog_->titleeffect_B->currentItem());
    config_->writeEntry("inactiveTitleEffect_3", dialog_->i_titleeffect_B->currentItem());
    config_->writeEntry("ShapeUL_3", dialog_->shapeUL_B->isChecked());
    config_->writeEntry("ShapeUR_3", dialog_->shapeUR_B->isChecked());
    config_->writeEntry("ShapeLL_3", dialog_->shapeLL_B->isChecked());
    config_->writeEntry("ShapeLR_3", dialog_->shapeLR_B->isChecked());    
    config_->writeEntry("drawIcon_3", dialog_->drawIcon_B->isChecked());
    config_->writeEntry("3DImpact_3", dialog_->_3DImpact_B->value());
    config_->writeEntry("LineImpact_3", dialog_->LineImpact_B->value());
   config_->writeEntry("BorderSize_3", dialog_->borderSize_B->value());
   
   config_->writeEntry("activeColor1_4", (int)dialog_->activeColor1_T->color().rgb());
   config_->writeEntry("activeColor2_4", (int)dialog_->activeColor2_T->color().rgb());
   config_->writeEntry("ButtonStyle_4", dialog_->buttonStyle_T->currentItem());
   config_->writeEntry("ShapeUL_4", dialog_->shapeUL_T->isChecked());
   config_->writeEntry("ShapeUR_4", dialog_->shapeUR_T->isChecked());
   config_->writeEntry("ShapeLL_4", dialog_->shapeLL_T->isChecked());
   config_->writeEntry("ShapeLR_4", dialog_->shapeLR_T->isChecked());    
   config_->writeEntry("drawIcon_4", dialog_->drawIcon_T->isChecked());
   config_->writeEntry("3DImpact_4", dialog_->_3DImpact_T->value());
   config_->writeEntry("BorderSize_4", dialog_->borderSize_T->value());
   
   config_->writeEntry("activeColor1_5", (int)dialog_->activeColor1_S->color().rgb());
   config_->writeEntry("activeColor2_5", (int)dialog_->activeColor2_S->color().rgb());
   config_->writeEntry("inactiveColor1_5", (int)dialog_->inactiveColor1_S->color().rgb());
   config_->writeEntry("inactiveColor2_5", (int)dialog_->inactiveColor2_S->color().rgb());
   config_->writeEntry("ButtonStyle_5", dialog_->buttonStyle_S->currentItem());
   config_->writeEntry("TitleEffect_5", dialog_->titleeffect_S->currentItem());
   config_->writeEntry("inactiveTitleEffect_5", dialog_->i_titleeffect_S->currentItem());
   config_->writeEntry("ShapeUL_5", dialog_->shapeUL_S->isChecked());
   config_->writeEntry("ShapeUR_5", dialog_->shapeUR_S->isChecked());
   config_->writeEntry("ShapeLL_5", dialog_->shapeLL_S->isChecked());
   config_->writeEntry("ShapeLR_5", dialog_->shapeLR_S->isChecked());    
   config_->writeEntry("drawIcon_5", dialog_->drawIcon_S->isChecked());
   config_->writeEntry("3DImpact_5", dialog_->_3DImpact_S->value());
   config_->writeEntry("LineImpact_5", dialog_->LineImpact_S->value());
   config_->writeEntry("BorderSize_5", dialog_->borderSize_S->value());
    
    if (buttonDialog_->save){
    config_->writeEntry("InactiveButtonColor", (int)buttonDialog_->inactiveColor->Color().rgb());
    config_->writeEntry("CloseButtonColor", (int)buttonDialog_->closeColor->Color().rgb());
    config_->writeEntry("MinButtonColor", (int)buttonDialog_->minColor->Color().rgb());
    config_->writeEntry("MaxButtonColor", (int)buttonDialog_->maxColor->Color().rgb());
    config_->writeEntry("MenuButtonColor", (int)buttonDialog_->menuColor->Color().rgb());
    config_->writeEntry("HelpButtonColor", (int)buttonDialog_->helpColor->Color().rgb());
    config_->writeEntry("StickyButtonColor", (int)buttonDialog_->stickyColor->Color().rgb());
    config_->writeEntry("AboveButtonColor", (int)buttonDialog_->aboveColor->Color().rgb());
    config_->writeEntry("BehindButtonColor", (int)buttonDialog_->behindColor->Color().rgb());
    config_->writeEntry("ShadeButtonColor", (int)buttonDialog_->shadeColor->Color().rgb());
    }
    config_->endGroup();
    delete config_;
        
//     config_->sync();
}

//////////////////////////////////////////////////////////////////////////////
// defaults()
// ----------
// Set configuration defaults

void BaghiraConfig::defaults()
{
    QRadioButton *button = (QRadioButton*)dialog_->titlealign->child("AlignHCenter");
    if (button) button->setChecked(true);
    dialog_->allowEasyClosing->setChecked(false);
    dialog_->minTH->setValue(22);
    dialog_->ResizeGrip->setChecked(false);
    dialog_->drawComicFrame->setChecked(false);
    dialog_->addAutoSpacing->setChecked(true);
    dialog_->maxResizable->setChecked(false);
    dialog_->fullSpec->setChecked(false);
    dialog_->defaultMode->setCurrentItem(1);
   dialog_->noModalDeco->setChecked(false);
   dialog_->delAppname->setChecked(false);

   dialog_->activeColor1_J->setColor(QColor(255,255,255));
   dialog_->inactiveColor1_J->setColor(QColor(204,214,230));
   dialog_->activeColor2_J->setColor(QColor(238,234,238));
   dialog_->inactiveColor2_J->setColor(QColor(194,196,211));
   dialog_->buttonStyle_J->setCurrentItem(1);
   dialog_->titleeffect_J->setCurrentItem(1);
   dialog_->i_titleeffect_J->setCurrentItem(1);
   dialog_->shapeUL_J->setChecked(true);
   dialog_->shapeUR_J->setChecked(true);
   dialog_->shapeLL_J->setChecked(false);
   dialog_->shapeLR_J->setChecked(false);
   dialog_->drawIcon_J->setChecked(true);
   dialog_->_3DImpact_J->setValue(20);
   dialog_->LineImpact_J->setValue(40);
   dialog_->borderSize_J->setValue(0);
   
   dialog_->activeColor1_P->setColor(QColor(238,238,238));
   dialog_->inactiveColor1_P->setColor(QColor(246,242,246));
   dialog_->activeColor2_P->setColor(QColor(205,202,205));
   dialog_->inactiveColor2_P->setColor(QColor(238,238,238));
   dialog_->buttonStyle_P->setCurrentItem(0);
   dialog_->titleeffect_P->setCurrentItem(0);
   dialog_->i_titleeffect_P->setCurrentItem(0);
   dialog_->shapeUL_P->setChecked(true);
   dialog_->shapeUR_P->setChecked(true);
   dialog_->shapeLL_P->setChecked(false);
   dialog_->shapeLR_P->setChecked(false);
   dialog_->drawIcon_P->setChecked(true);
   dialog_->_3DImpact_P->setValue(20);
   dialog_->LineImpact_P->setValue(30);
   dialog_->borderSize_P->setValue(0);
   
   dialog_->activeColor1_B->setColor(QColor(210,210,210));
   dialog_->inactiveColor1_B->setColor(QColor(200,200,200));
   dialog_->activeColor2_B->setColor(QColor(150,150,150));
   dialog_->inactiveColor2_B->setColor(QColor(140,140,140));
   dialog_->buttonStyle_B->setCurrentItem(0);
   dialog_->titleeffect_B->setCurrentItem(4);
   dialog_->i_titleeffect_B->setCurrentItem(4);
   dialog_->shapeUL_B->setChecked(true);
   dialog_->shapeUR_B->setChecked(true);
   dialog_->shapeLL_B->setChecked(false);
   dialog_->shapeLR_B->setChecked(false);
   dialog_->drawIcon_B->setChecked(true);
   dialog_->_3DImpact_B->setValue(20);
   dialog_->LineImpact_B->setValue(0);
   dialog_->borderSize_B->setValue(6);
   
   dialog_->activeColor1_T->setColor(QColor(238,238,238));
   dialog_->activeColor2_T->setColor(QColor(211,208,211));
   dialog_->buttonStyle_T->setCurrentItem(0);
   dialog_->shapeUL_T->setChecked(true);
   dialog_->shapeUR_T->setChecked(true);
   dialog_->shapeLL_T->setChecked(false);
   dialog_->shapeLR_T->setChecked(false);
   dialog_->drawIcon_T->setChecked(true);
   dialog_->_3DImpact_T->setValue(20);
   dialog_->borderSize_T->setValue(0);
   
   dialog_->activeColor1_S->setColor(QColor(250,250,250));
   dialog_->inactiveColor1_S->setColor(QColor(230,230,230));
   dialog_->activeColor2_S->setColor(QColor(230,230,230));
   dialog_->inactiveColor2_S->setColor(QColor(250,250,250));
   dialog_->buttonStyle_S->setCurrentItem(0);
   dialog_->titleeffect_S->setCurrentItem(0);
   dialog_->i_titleeffect_S->setCurrentItem(0);
   dialog_->shapeUL_S->setChecked(true);
   dialog_->shapeUR_S->setChecked(true);
   dialog_->shapeLL_S->setChecked(false);
   dialog_->shapeLR_S->setChecked(false);
   dialog_->drawIcon_S->setChecked(true);
   dialog_->_3DImpact_S->setValue(20);
   dialog_->LineImpact_S->setValue(30);
   dialog_->borderSize_S->setValue(0);
   
//   buttonDialog_->defaults();

    
}   

enum ColorPresets{Aqua = 0, Graphite, GraphiteDark, NUMBEROFCOLORS};

const char * presetColorName[NUMBEROFCOLORS] = {"Aqua", "Graphite", "Graphite (Dark)" };

typedef int ColorTable[10][3];

const int aquaPreset[10][3] = {{255,255,255},{200,85,70},{230,155,40},{121,180,54},{74,140,242},{0,0,0},{74,140,242},{74,140,242},{74,140,242},{74,140,242}};
const int graphitePreset[10][3] = {{255,255,255},{130,170,190},{130,170,190},{130,170,190},{130,170,190},{0,0,0},{130,170,190},{130,170,190},{130,170,190},{130,170,190}};
const int graphiteDarkPreset[10][3] = {{255,255,255},{103,118,134},{103,118,134},{103,118,134},{103,118,134},{0,0,0},{103,118,134},{103,118,134},{103,118,134},{103,118,134}};
const ColorTable* presetColors[NUMBEROFCOLORS] = {&aquaPreset, &graphitePreset, &graphiteDarkPreset};


ButtonColors::ButtonColors(QWidget *parent, const char * name) : QDialog(parent, name){
    save = false;
    layout = new QGridLayout(this,2,2,11,6, "Grid");
    buttonLayout = new QVBoxLayout(0,0,6);
    
    QPixmap tmpPix = QPixmap(uic_findImage("preview"));
    inactiveButton = new AquariusButton(tmpPix,this, "Inactive Button");
    buttonLayout->addWidget(inactiveButton);
    closeButton = new AquariusButton(tmpPix,this, "Close Button");
    buttonLayout->addWidget(closeButton);
    minButton = new AquariusButton(tmpPix,this, "Minimize Button");
    buttonLayout->addWidget(minButton);
    maxButton = new AquariusButton(tmpPix,this, "Maximize Button");
    buttonLayout->addWidget(maxButton);
    stickyButton = new AquariusButton(tmpPix,this, "Sticky Button");
    buttonLayout->addWidget(stickyButton);
    aboveButton = new AquariusButton(tmpPix,this, "Above Button");
    buttonLayout->addWidget(aboveButton);
    behindButton = new AquariusButton(tmpPix,this, "Behind Button");
    buttonLayout->addWidget(behindButton);
    shadeButton = new AquariusButton(tmpPix,this, "Shade Button");
    buttonLayout->addWidget(shadeButton);
    tmpPix = QPixmap(uic_findImage("preview-menu"));
    menuButton = new AquariusButton(tmpPix,this, "Menu Button");
    buttonLayout->addWidget(menuButton);
    tmpPix = QPixmap(uic_findImage("icon_help"));
    helpButton = new AquariusButton(tmpPix,this, "Help Button");
    buttonLayout->addWidget(helpButton);
    
    
    twoButts = new QHBoxLayout(0,0,6);
    presets_ = new QComboBox(this);
    for (int i = 0; i < NUMBEROFCOLORS; i++)
        presets_->insertItem ( presetColorName[i], i );
    twoButts->addWidget(presets_);
    cancel = new QPushButton("Cancel", this);
    cancel->setDefault( true );
    twoButts->addWidget(cancel);
    twoButts->addStretch();
    layout->addLayout(twoButts,1,0);
    ok = new QPushButton("OK", this);
    layout->addWidget(ok,1,1);
    
    layout->addLayout(buttonLayout,0,1);
    
    pickerLayout = new QVBoxLayout(0,0,6,0);
    
    indicator = new QLabel(inactiveButton->name(), this);
    indicator->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter | Qt::ExpandTabs);
    QFont tmpFont = font();
    tmpFont.setBold( true );
    tmpFont.setPointSize( 24 );
    indicator->setFont(tmpFont);
    pickerLayout->addWidget(indicator);
    
    inactiveColor = new ColorPicker(this);
    pickerLayout->addWidget(inactiveColor);
    currentPicker = inactiveColor;
    closeColor = new ColorPicker(this);
    pickerLayout->addWidget(closeColor);
    closeColor->hide();
    minColor = new ColorPicker(this);
    pickerLayout->addWidget(minColor);
    minColor->hide();
    maxColor = new ColorPicker(this);
    pickerLayout->addWidget(maxColor);
    maxColor->hide();
    menuColor = new ColorPicker(this);
    pickerLayout->addWidget(menuColor);
    menuColor->hide();
    helpColor = new ColorPicker(this);
    pickerLayout->addWidget(helpColor);
    helpColor->hide();
    stickyColor = new ColorPicker(this);
    pickerLayout->addWidget(stickyColor);
    stickyColor->hide();
    aboveColor = new ColorPicker(this);
    pickerLayout->addWidget(aboveColor);
    aboveColor->hide();
    behindColor = new ColorPicker(this);
    pickerLayout->addWidget(behindColor);
    behindColor->hide();
    shadeColor = new ColorPicker(this);
    pickerLayout->addWidget(shadeColor);
    shadeColor->hide();
    
    indicator->lower();
    
    layout->addLayout(pickerLayout,0,0);
    
    resize( QSize(485, 177).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
    
    connect(presets_,SIGNAL(activated(int)), this, SLOT(setColorGroup(int)));
    connect(ok, SIGNAL(clicked()), this, SLOT(setSave()));
    connect(ok, SIGNAL(clicked()), this, SLOT(close()) );
    connect(ok, SIGNAL(clicked()), this, SLOT(init()) );
    connect(cancel, SIGNAL(clicked()), this, SLOT(close()) );
    connect(cancel, SIGNAL(clicked()), this, SLOT(reset()) );
    
    connect(inactiveButton, SIGNAL(clicked()), this, SLOT(activateInactive()) );
    connect(closeButton, SIGNAL(clicked()), this, SLOT(activateClose()) );
    connect(minButton, SIGNAL(clicked()), this, SLOT(activateMin()) );
    connect(maxButton, SIGNAL(clicked()), this, SLOT(activateMax()) );
    connect(menuButton, SIGNAL(clicked()), this, SLOT(activateMenu()) );
    connect(helpButton, SIGNAL(clicked()), this, SLOT(activateHelp()) );
    connect(stickyButton, SIGNAL(clicked()), this, SLOT(activateSticky()) );
    connect(aboveButton, SIGNAL(clicked()), this, SLOT(activateAbove()) );
    connect(behindButton, SIGNAL(clicked()), this, SLOT(activateBehind()) );
    connect(shadeButton, SIGNAL(clicked()), this, SLOT(activateShade()) );
    
    connect(inactiveColor, SIGNAL(colorChanged(QColor)), inactiveButton, SLOT(setColor(QColor)) );
    connect(closeColor, SIGNAL(colorChanged(QColor)), closeButton, SLOT(setColor(QColor)) );
    connect(minColor, SIGNAL(colorChanged(QColor)), minButton, SLOT(setColor(QColor)) );
    connect(maxColor, SIGNAL(colorChanged(QColor)), maxButton, SLOT(setColor(QColor)) );
    connect(menuColor, SIGNAL(colorChanged(QColor)), menuButton, SLOT(setColor(QColor)) );
    connect(helpColor, SIGNAL(colorChanged(QColor)), helpButton, SLOT(setColor(QColor)) );
    connect(stickyColor, SIGNAL(colorChanged(QColor)), stickyButton, SLOT(setColor(QColor)) );
    connect(aboveColor, SIGNAL(colorChanged(QColor)), aboveButton, SLOT(setColor(QColor)) );
    connect(behindColor, SIGNAL(colorChanged(QColor)), behindButton, SLOT(setColor(QColor)) );
    connect(shadeColor, SIGNAL(colorChanged(QColor)), shadeButton, SLOT(setColor(QColor)) );

}

ButtonColors::~ButtonColors(){
}

void ButtonColors::setColorGroup(int i){
    inactiveColor->setColor(QColor((*presetColors[i])[0][0],(*presetColors[i])[0][1],(*presetColors[i])[0][2]).rgb());
    closeColor->setColor(QColor((*presetColors[i])[1][0],(*presetColors[i])[1][1],(*presetColors[i])[1][2]).rgb());
    minColor->setColor(QColor((*presetColors[i])[2][0],(*presetColors[i])[2][1],(*presetColors[i])[2][2]).rgb());
    maxColor->setColor(QColor((*presetColors[i])[3][0],(*presetColors[i])[3][1],(*presetColors[i])[3][2]).rgb());
    menuColor->setColor(QColor((*presetColors[i])[4][0],(*presetColors[i])[4][1],(*presetColors[i])[4][2]).rgb());
    helpColor->setColor(QColor((*presetColors[i])[5][0],(*presetColors[i])[5][1],(*presetColors[i])[5][2]).rgb());
    stickyColor->setColor(QColor((*presetColors[i])[6][0],(*presetColors[i])[6][1],(*presetColors[i])[6][2]).rgb());
    aboveColor->setColor(QColor((*presetColors[i])[7][0],(*presetColors[i])[7][1],(*presetColors[i])[7][2]).rgb());
    behindColor->setColor(QColor((*presetColors[i])[8][0],(*presetColors[i])[8][1],(*presetColors[i])[8][2]).rgb());
    shadeColor->setColor(QColor((*presetColors[i])[9][0],(*presetColors[i])[9][1],(*presetColors[i])[9][2]).rgb());
}

void ButtonColors::setPicker(ColorPicker *picker){
    if (currentPicker) currentPicker->hide();
    currentPicker = picker;
    currentPicker->show();
}

void ButtonColors::activateInactive(){
    setPicker(inactiveColor);
    indicator->setText( inactiveButton->name() );
}
void ButtonColors::activateClose(){
    setPicker(closeColor);
    indicator->setText( closeButton->name() );
}
void ButtonColors::activateMin(){
    setPicker(minColor);
    indicator->setText( minButton->name() );
}
void ButtonColors::activateMax(){
    setPicker(maxColor);
    indicator->setText( maxButton->name() );
}
void ButtonColors::activateMenu(){
    setPicker(menuColor);
    indicator->setText( menuButton->name() );
}
void ButtonColors::activateHelp(){
    setPicker(helpColor);
    indicator->setText( helpButton->name() );
}
void ButtonColors::activateSticky(){
    setPicker(stickyColor);
    indicator->setText( stickyButton->name() );
}
void ButtonColors::activateAbove(){
    setPicker(aboveColor);
    indicator->setText( aboveButton->name() );
}
void ButtonColors::activateBehind(){
    setPicker(behindColor);
    indicator->setText( behindButton->name() );
}
void ButtonColors::activateShade(){
    setPicker(shadeColor);
    indicator->setText( shadeButton->name() );
}

void ButtonColors::reset(){
    inactiveColor->reset();
    closeColor->reset();
    minColor->reset();
    maxColor->reset();
    menuColor->reset();
    helpColor->reset();
    stickyColor->reset();
    aboveColor->reset();
    behindColor->reset();
    shadeColor->reset();
}

void ButtonColors::init(){
    inactiveColor->init();
    closeColor->init();
    minColor->init();
    maxColor->init();
    menuColor->init();
    helpColor->init();
    stickyColor->init();
    aboveColor->init();
    behindColor->init();
    shadeColor->init();
}
    
//////////////////////////////////////////////////////////////////////////////
// Plugin Stuff                                                             //
//////////////////////////////////////////////////////////////////////////////
    
extern "C"
{   
    QObject* allocate_config(KConfig* config, QWidget* parent) {
        return(new BaghiraConfig(config, parent));
    }
}   
   
#include "baghiraconfig.moc"
